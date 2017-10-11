
double no_overlapp = 0.0001; // added to radii to avoid overlapping volumes
bool overlapcheck = false; // set to true if you want to check for overlaps

void G4Init(bool do_magnet = true,
            bool do_pipe = true,
	    bool do_ExtendedIR = true
	    ) {

  // load detector/material macros and execute Init() function
  if (do_pipe)
    {
      gROOT->LoadMacro("G4_Pipe.C");
      PipeInit();
    }

  if (do_magnet)
    {
      gROOT->LoadMacro("G4_Magnet.C");
      MagnetInit();
    }

  if (do_ExtendedIR)
    {
      gROOT->LoadMacro("G4_IR_EIC.C");
      IRInit();
    }

}


int G4Setup(const int absorberactive = 0,
            const string &field ="1.5",
            const EDecayType decayType = TPythia6Decayer::kAll,
            const bool do_magnet = true,
            const bool do_pipe = true,
	    const bool do_ExtendedIR = true,
            const float magfield_rescale = 1.0) {

  //---------------
  // Load libraries
  //---------------

  gSystem->Load("libg4detectors.so");
  gSystem->Load("libg4testbench.so");

  //---------------
  // Fun4All server
  //---------------

  Fun4AllServer *se = Fun4AllServer::instance();

  PHG4Reco* g4Reco = new PHG4Reco();
  g4Reco->set_rapidity_coverage(1.1); // according to drawings

  /* Set World Volume material to G4Galactic for beam line studies
   * (beam would be inside vacuum tubes) */
  g4Reco->SetWorldMaterial("G4_Galactic");

  if (decayType != TPythia6Decayer::kAll) {
    g4Reco->set_force_decay(decayType);
  }

  double fieldstrength;
  istringstream stringline(field);
  stringline >> fieldstrength;
  if (stringline.fail()) { // conversion to double fails -> we have a string

    if (field.find("sPHENIX.root") != string::npos) {
      g4Reco->set_field_map(field, 1);
    } else {
      g4Reco->set_field_map(field, 2);
    }
  } else {
    g4Reco->set_field(fieldstrength); // use const soleniodal field
  }
  g4Reco->set_field_rescale(magfield_rescale);

  double radius = 0.;

  //----------------------------------------
  // PIPE
  if (do_pipe) radius = Pipe(g4Reco, radius, absorberactive);

  //----------------------------------------
  // MAGNET

  if (do_magnet) radius = Magnet(g4Reco, radius, 0, absorberactive);

  //----------------------------------------
  // Extended IR
  if ( do_ExtendedIR )
    IRSetup(g4Reco);


  // discs to track very forward protons
  PHG4CylinderSubsystem *fwd_disc;
  for ( unsigned i = 0; i < 900; i++ )
    {
      fwd_disc = new PHG4CylinderSubsystem("FWDDISC", i);
      fwd_disc->set_int_param("lengthviarapidity",0);
      fwd_disc->set_double_param("length",1);
      fwd_disc->set_double_param("radius",0);
      fwd_disc->set_double_param("thickness",200.0);
      fwd_disc->set_double_param("place_z",450+i*10.0); // cm
      fwd_disc->set_string_param("material","G4_Galactic");
      fwd_disc->SetActive(true);
      fwd_disc->SuperDetector("FWDDISC");
      fwd_disc->OverlapCheck(overlapcheck);
      g4Reco->registerSubsystem(fwd_disc);
    }


  // sPHENIX forward flux return(s)
  /* PHG4CylinderSubsystem *flux_return_plus = new PHG4CylinderSubsystem("FWDFLUXRET", 0);
  flux_return_plus->set_int_param("lengthviarapidity",0);
  flux_return_plus->set_double_param("length",10.2);
  flux_return_plus->set_double_param("radius",2.1);
  flux_return_plus->set_double_param("thickness",263.5-5.0);
  flux_return_plus->set_double_param("place_z",335.9);
  flux_return_plus->set_string_param("material","G4_Fe");
  flux_return_plus->SetActive(false);
  flux_return_plus->SuperDetector("FLUXRET_ETA_PLUS");
  flux_return_plus->OverlapCheck(overlapcheck);
  g4Reco->registerSubsystem(flux_return_plus);

   PHG4CylinderSubsystem *flux_return_minus = new PHG4CylinderSubsystem("FWDFLUXRET", 0);
  flux_return_minus->set_int_param("lengthviarapidity",0);
  flux_return_minus->set_double_param("length",10.2);
  flux_return_minus->set_double_param("radius",90.0);
  flux_return_minus->set_double_param("place_z",-335.9);
  flux_return_minus->set_double_param("thickness",263.5-5.0 - (90-2.1));
  flux_return_minus->set_string_param("material","G4_Fe");
  flux_return_minus->SetActive(false);
  flux_return_minus->SuperDetector("FLUXRET_ETA_MINUS");
  flux_return_minus->OverlapCheck(overlapcheck);
  g4Reco->registerSubsystem(flux_return_minus);*/

  //----------------------------------------
  // BLACKHOLE

  // swallow all particles coming out of the backend of sPHENIX
  /*  PHG4CylinderSubsystem *blackhole = new PHG4CylinderSubsystem("BH", 1);
  blackhole->set_double_param("radius",radius + 100); // add 100 cm

  blackhole->set_int_param("lengthviarapidity",0);
  blackhole->set_double_param("length",g4Reco->GetWorldSizeZ() - no_overlapp); // make it cover the world in length
  blackhole->BlackHole();
  blackhole->set_double_param("thickness",0.1); // it needs some thickness
  blackhole->SetActive(); // always see what leaks out
  blackhole->OverlapCheck(overlapcheck);
  g4Reco->registerSubsystem(blackhole);

  //----------------------------------------
  // FORWARD BLACKHOLEs
  // +Z
  blackhole = new PHG4CylinderSubsystem("BH_FORWARD_PLUS", 1);
  blackhole->SuperDetector("BH_FORWARD_PLUS");
  blackhole->set_double_param("radius",0); // add 10 cm
  blackhole->set_int_param("lengthviarapidity",0);
  blackhole->set_double_param("length",0.1); // make it cover the world in length
  //blackhole->set_double_param("place_z",g4Reco->GetWorldSizeZ()/2. - 0.1  - no_overlapp);
  blackhole->set_double_param("place_z",10000);
  blackhole->BlackHole();
  blackhole->set_double_param("thickness",radius - no_overlapp); // it needs some thickness
  blackhole->SetActive(); // always see what leaks out
  blackhole->OverlapCheck(overlapcheck);
  g4Reco->registerSubsystem(blackhole);

   blackhole = new PHG4CylinderSubsystem("BH_FORWARD_NEG", 1);
  blackhole->SuperDetector("BH_FORWARD_NEG");
  blackhole->set_double_param("radius",0); // add 10 cm
  blackhole->set_int_param("lengthviarapidity",0);
  blackhole->set_double_param("length",0.1); // make it cover the world in length
  blackhole->set_double_param("place_z", - g4Reco->GetWorldSizeZ()/2. +0.1  + no_overlapp);
  blackhole->BlackHole();
  blackhole->set_double_param("thickness",radius - no_overlapp); // it needs some thickness
  blackhole->SetActive(); // always see what leaks out
  blackhole->OverlapCheck(overlapcheck);
  g4Reco->registerSubsystem(blackhole);


  /* Add truth system */
  PHG4TruthSubsystem *truth = new PHG4TruthSubsystem();
  g4Reco->registerSubsystem(truth);

  /* add reco to server */
  se->registerSubsystem( g4Reco );
}


//void ShowerCompress(int verbosity = 0) {
//
//  gSystem->Load("libfun4all.so");
//  gSystem->Load("libg4eval.so");
//
//  Fun4AllServer *se = Fun4AllServer::instance();
//
//  PHG4DstCompressReco* compress = new PHG4DstCompressReco("PHG4DstCompressReco");
//  compress->AddHitContainer("G4HIT_PIPE");
//  compress->AddHitContainer("G4HIT_SVTXSUPPORT");
//  compress->AddHitContainer("G4HIT_CEMC_ELECTRONICS");
//  compress->AddHitContainer("G4HIT_CEMC");
//  compress->AddHitContainer("G4HIT_ABSORBER_CEMC");
//  compress->AddHitContainer("G4HIT_CEMC_SPT");
//  compress->AddHitContainer("G4HIT_ABSORBER_HCALIN");
//  compress->AddHitContainer("G4HIT_HCALIN");
//  compress->AddHitContainer("G4HIT_HCALIN_SPT");
//  compress->AddHitContainer("G4HIT_MAGNET");
//  compress->AddHitContainer("G4HIT_ABSORBER_HCALOUT");
//  compress->AddHitContainer("G4HIT_HCALOUT");
//  compress->AddHitContainer("G4HIT_BH_1");
//  compress->AddHitContainer("G4HIT_BH_FORWARD_PLUS");
//  compress->AddHitContainer("G4HIT_BH_FORWARD_NEG");
//  compress->AddCellContainer("G4CELL_CEMC");
//  compress->AddCellContainer("G4CELL_HCALIN");
//  compress->AddCellContainer("G4CELL_HCALOUT");
//  compress->AddTowerContainer("TOWER_SIM_CEMC");
//  compress->AddTowerContainer("TOWER_RAW_CEMC");
//  compress->AddTowerContainer("TOWER_CALIB_CEMC");
//  compress->AddTowerContainer("TOWER_SIM_HCALIN");
//  compress->AddTowerContainer("TOWER_RAW_HCALIN");
//  compress->AddTowerContainer("TOWER_CALIB_HCALIN");
//  compress->AddTowerContainer("TOWER_SIM_HCALOUT");
//  compress->AddTowerContainer("TOWER_RAW_HCALOUT");
//  compress->AddTowerContainer("TOWER_CALIB_HCALOUT");
//
//  compress->AddHitContainer("G4HIT_FEMC");
//  compress->AddHitContainer("G4HIT_ABSORBER_FEMC");
//  compress->AddHitContainer("G4HIT_FHCAL");
//  compress->AddHitContainer("G4HIT_ABSORBER_FHCAL");
//  compress->AddCellContainer("G4CELL_FEMC");
//  compress->AddCellContainer("G4CELL_FHCAL");
//  compress->AddTowerContainer("TOWER_SIM_FEMC");
//  compress->AddTowerContainer("TOWER_RAW_FEMC");
//  compress->AddTowerContainer("TOWER_CALIB_FEMC");
//  compress->AddTowerContainer("TOWER_SIM_FHCAL");
//  compress->AddTowerContainer("TOWER_RAW_FHCAL");
//  compress->AddTowerContainer("TOWER_CALIB_FHCAL");
//
//  compress->AddHitContainer("G4HIT_EEMC");
//  compress->AddHitContainer("G4HIT_ABSORBER_EEMC");
//  compress->AddCellContainer("G4CELL_EEMC");
//  compress->AddTowerContainer("TOWER_SIM_EEMC");
//  compress->AddTowerContainer("TOWER_RAW_EEMC");
//  compress->AddTowerContainer("TOWER_CALIB_EEMC");
//
//  se->registerSubsystem(compress);
//
//  return;
//}
//
//void DstCompress(Fun4AllDstOutputManager* out) {
//  if (out) {
//    out->StripNode("G4HIT_PIPE");
//    out->StripNode("G4HIT_SVTXSUPPORT");
//    out->StripNode("G4HIT_CEMC_ELECTRONICS");
//    out->StripNode("G4HIT_CEMC");
//    out->StripNode("G4HIT_ABSORBER_CEMC");
//    out->StripNode("G4HIT_CEMC_SPT");
//    out->StripNode("G4HIT_ABSORBER_HCALIN");
//    out->StripNode("G4HIT_HCALIN");
//    out->StripNode("G4HIT_HCALIN_SPT");
//    out->StripNode("G4HIT_MAGNET");
//    out->StripNode("G4HIT_ABSORBER_HCALOUT");
//    out->StripNode("G4HIT_HCALOUT");
//    out->StripNode("G4HIT_BH_1");
//    out->StripNode("G4HIT_BH_FORWARD_PLUS");
//    out->StripNode("G4HIT_BH_FORWARD_NEG");
//    out->StripNode("G4CELL_CEMC");
//    out->StripNode("G4CELL_HCALIN");
//    out->StripNode("G4CELL_HCALOUT");
//
//    out->StripNode("G4HIT_FEMC");
//    out->StripNode("G4HIT_ABSORBER_FEMC");
//    out->StripNode("G4HIT_FHCAL");
//    out->StripNode("G4HIT_ABSORBER_FHCAL");
//    out->StripNode("G4CELL_FEMC");
//    out->StripNode("G4CELL_FHCAL");
//
//    out->StripNode("G4HIT_EEMC");
//    out->StripNode("G4HIT_ABSORBER_EEMC");
//    out->StripNode("G4CELL_EEMC");
//  }
//}