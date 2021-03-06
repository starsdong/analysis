int Jin_BJet(
		const int nEvents = 1000,
		char* inputFile,
		char* outputFile, 
		int which_tracking = 0
		)
{
	//===============
	// Input options
	//===============

	//char *inputFile;
	//char *outputFile;
	char *embed_input_file;

	bool do_svtx = true;
	bool do_svtx_cell = true;
	bool do_svtx_track = true;
	bool do_svtx_eval = true;

	bool do_bbc = false;
	bool do_global = false;

	bool do_jet_reco = true;

	embed_input_file = NULL;

	int which_reco = 1;

	// Either:
	// read previously generated g4-hits files, in this case it opens a DST and skips
	// the simulations step completely. The G4Setup macro is only loaded to get information
	// about the number of layers used for the cell reco code
	const bool readhits = false;
	// Or:
	// read files in HepMC format (typically output from event generators like hijing or pythia)
	const bool readhepmc = true; // read HepMC files
	// Or:
	// Use particle generator
	const bool runpythia = false;

	//======================
	// What to run
	//======================


	bool do_pipe = true;

	bool do_preshower = false;

	bool do_cemc = false;
	bool do_cemc_cell = false;
	bool do_cemc_twr = false;
	bool do_cemc_cluster = false;
	bool do_cemc_eval = false;

	bool do_hcalin = false;
	bool do_hcalin_cell = false;
	bool do_hcalin_twr = false;
	bool do_hcalin_cluster = false;
	bool do_hcalin_eval = false;

	bool do_magnet = true;

	bool do_hcalout = false;
	bool do_hcalout_cell = false;
	bool do_hcalout_twr = false;
	bool do_hcalout_cluster = false;
	bool do_hcalout_eval = false;

	bool do_global_fastsim = false;

	bool do_jet_eval = false;

	bool do_dst_compress = false;

	//Option to convert DST to human command readable TTree for quick poke around the outputs
	bool do_DSTReader = false;
	//---------------
	// Load libraries
	//---------------

	gSystem->Load("libfun4all.so");
	gSystem->Load("libg4detectors.so");
	gSystem->Load("libphhepmc.so");
	gSystem->Load("libg4testbench.so");
	gSystem->Load("libg4hough.so");
  gSystem->Load("libg4calo.so");
	gSystem->Load("libg4eval.so");
	gSystem->Load("libg4vertex.so");

	// establish the geometry and reconstruction setup
	gROOT->LoadMacro("G4Setup_sPHENIX.C");
	G4Init(do_svtx,do_preshower,do_cemc,do_hcalin,do_magnet,do_hcalout,do_pipe,which_tracking);

	int absorberactive = 1; // set to 1 to make all absorbers active volumes
	//  const string magfield = "1.5"; // if like float -> solenoidal field in T, if string use as fieldmap name (including path)
	const string magfield = "/phenix/upgrades/decadal/fieldmaps/sPHENIX.2d.root"; // if like float -> solenoidal field in T, if string use as fieldmap name (including path)
	const float magfield_rescale = 1.4/1.5; // scale the map to a 1.4 T field

	//---------------
	// Fun4All server
	//---------------

	Fun4AllServer *se = Fun4AllServer::instance();
	//  se->Verbosity(10);
	// just if we set some flags somewhere in this macro
	recoConsts *rc = recoConsts::instance();
	// By default every random number generator uses
	// PHRandomSeed() which reads /dev/urandom to get its seed
	// if the RANDOMSEED flag is set its value is taken as seed
	// You ca neither set this to a random value using PHRandomSeed()
	// which will make all seeds identical (not sure what the point of
	// this would be:
	//  rc->set_IntFlag("RANDOMSEED",PHRandomSeed());
	// or set it to a fixed value so you can debug your code
	// rc->set_IntFlag("RANDOMSEED", 12345);

	//-----------------
	// Event generation
	//-----------------

	if (readhits)
	{
		// Get the hits from a file
		// The input manager is declared later

		if (embed_input_file)
		{
			cout <<"Do not support read hits and embed background"<<endl;
			exit(1);
		}

	}
	else if (readhepmc)
	{
		// this module is needed to read the HepMC records into our G4 sims
		// but only if you read HepMC input files
		HepMCNodeReader *hr = new HepMCNodeReader();


		if (which_reco == 1)
			hr->Embed( 17 );

		se->registerSubsystem(hr);
	}
	else if (runpythia)
	{
		gSystem->Load("libPHPythia8.so");

		PHPythia8* pythia8 = new PHPythia8();
		// see coresoftware/generators/PHPythia8 for example config
		pythia8->set_config_file("phpythia8.cfg"); 
		se->registerSubsystem(pythia8);

		HepMCNodeReader *hr = new HepMCNodeReader();
		se->registerSubsystem(hr);
	}
	else
	{
		// toss low multiplicity dummy events
		PHG4SimpleEventGenerator *gen = new PHG4SimpleEventGenerator();
		gen->add_particles(inputFile,1); // mu+,e+,proton,pi+,Upsilon
		//      gen->add_particles("e+",5); // mu-,e-,anti_proton,pi-
		if (readhepmc  || embed_input_file) {
			gen->set_reuse_existing_vertex(true);
			gen->set_existing_vertex_offset_vector(0.0,0.0,0.0);
		} else {
			gen->set_vertex_distribution_function(PHG4SimpleEventGenerator::Uniform,
					PHG4SimpleEventGenerator::Uniform,
					PHG4SimpleEventGenerator::Uniform);
			gen->set_vertex_distribution_mean(0.0,0.0,0.0);
			gen->set_vertex_distribution_width(0.0,0.0,0.0);
		}
		gen->set_vertex_size_function(PHG4SimpleEventGenerator::Uniform);
		gen->set_vertex_size_parameters(0.0,0.0);
		gen->set_eta_range(-0, .1);
		//      gen->set_eta_range(.9, 1);
		gen->set_phi_range(-1.0*TMath::Pi(), 1.0*TMath::Pi());
		gen->set_p_range(6, 6);
		//      gen->set_p_range(6, 6);
		gen->Embed(1);
		gen->Verbosity(0);
		se->registerSubsystem(gen);
	}

	if (!readhits)
	{
		//---------------------
		// Detector description
		//---------------------

		G4Setup(absorberactive, magfield, TPythia6Decayer::kAll,
				do_svtx, do_preshower, do_cemc, do_hcalin, do_magnet, do_hcalout, do_pipe, magfield_rescale);
	}

	//---------
	// BBC Reco
	//---------

	if (do_bbc) 
	{
		gROOT->LoadMacro("G4_Bbc.C");
		BbcInit();
		Bbc_Reco();
	}
	//------------------
	// Detector Division
	//------------------

	if (do_svtx_cell) Svtx_Cells();

	if (do_cemc_cell) CEMC_Cells();

	if (do_hcalin_cell) HCALInner_Cells();

	if (do_hcalout_cell) HCALOuter_Cells();

	//-----------------------------
	// CEMC towering and clustering
	//-----------------------------

	if (do_cemc_twr) CEMC_Towers();
	if (do_cemc_cluster) CEMC_Clusters();

	//-----------------------------
	// HCAL towering and clustering
	//-----------------------------

	if (do_hcalin_twr) HCALInner_Towers();
	if (do_hcalin_cluster) HCALInner_Clusters();

	if (do_hcalout_twr) HCALOuter_Towers();
	if (do_hcalout_cluster) HCALOuter_Clusters();

	if (do_dst_compress) ShowerCompress();

	//--------------
	// SVTX tracking
	//--------------

	if (do_svtx_track) Svtx_Reco();

	//-----------------
	// Global Vertexing
	//-----------------

	if (do_global) 
	{
		gROOT->LoadMacro("G4_Global.C");
		Global_Reco();
	}

	else if (do_global_fastsim) 
	{
		gROOT->LoadMacro("G4_Global.C");
		Global_FastSim();
	}  

	//---------
	// Jet reco
	//---------

	if (do_jet_reco) 
	{

		gROOT->LoadMacro("G4_Jets.C");

		//if (embed_input_file) gROOT->LoadMacro("G4_Jets.C(0,true)");
		//else gROOT->LoadMacro("G4_Jets.C(0,false)");
		Jet_Reco();
	}
	//----------------------
	// Simulation evaluation
	//----------------------

	if (do_svtx_eval) Svtx_Eval("g4svtx_eval.root");

	if (do_cemc_eval) CEMC_Eval("g4cemc_eval.root");

	if (do_hcalin_eval) HCALInner_Eval("g4hcalin_eval.root");

	if (do_hcalout_eval) HCALOuter_Eval("g4hcalout_eval.root");

	if (do_jet_eval) Jet_Eval("g4jet_eval.root");

	//-------------- 
	// IO management
	//--------------

	if (readhits)
	{
		// Hits file
		Fun4AllInputManager *hitsin = new Fun4AllDstInputManager("DSTin");
		hitsin->fileopen(inputFile);
		se->registerInputManager(hitsin);
	}
	if (embed_input_file)
	{

		Fun4AllDstInputManager *in1 = new Fun4AllNoSyncDstInputManager("DSTin1");
		in1->AddFile(embed_input_file);
		//in1->AddListFile(embed_input_file);
		se->registerInputManager(in1);

	}
	if (readhepmc)
	{
		Fun4AllInputManager *in = new Fun4AllHepMCInputManager( "DSTIN");
		se->registerInputManager( in );
		se->fileopen( in->Name().c_str(), inputFile );
	}
	else
	{
		// for single particle generators we just need something which drives
		// the event loop, the Dummy Input Mgr does just that
		Fun4AllInputManager *in = new Fun4AllDummyInputManager( "JADE");
		se->registerInputManager( in );
	}

	// HF jet trigger moudle
	assert (gSystem->Load("libHFJetTruthGeneration") == 0);
	{
		if (do_jet_reco)
		{
			HFJetTruthTrigger * jt = new HFJetTruthTrigger(
					"HFJetTruthTrigger.root",5 , "AntiKt_Truth_r07");
			//jt->Verbosity(HFJetTruthTrigger::VERBOSITY_MORE);
			se->registerSubsystem(jt);

			HFJetTruthTrigger * jt = new HFJetTruthTrigger(
					"HFJetTruthTrigger.root",5 , "AntiKt_Truth_r04");
			//jt->Verbosity(HFJetTruthTrigger::VERBOSITY_MORE);
			jt->set_pt_min(20);
			se->registerSubsystem(jt);

			HFJetTruthTrigger * jt = new HFJetTruthTrigger(
					"HFJetTruthTrigger.root",5 , "AntiKt_Truth_r02");
			//jt->Verbosity(HFJetTruthTrigger::VERBOSITY_MORE);
			se->registerSubsystem(jt);
		}
	}

	if (do_DSTReader)
	{
		//Convert DST to human command readable TTree for quick poke around the outputs
		gROOT->LoadMacro("G4_DSTReader.C");

		G4DSTreader( outputFile, //
				/*int*/ absorberactive ,
				/*bool*/ do_svtx ,
				/*bool*/ do_preshower ,
				/*bool*/ do_cemc ,
				/*bool*/ do_hcalin ,
				/*bool*/ do_magnet ,
				/*bool*/ do_hcalout ,
				/*bool*/ do_cemc_twr ,
				/*bool*/ do_hcalin_twr ,
				/*bool*/ do_magnet  ,
				/*bool*/ do_hcalout_twr
				);
	}


	Fun4AllDstOutputManager *out = new Fun4AllDstOutputManager("DSTOUT", outputFile);
	if (do_dst_compress) DstCompress(out);
	se->registerOutputManager(out);

	//-----------------
	// Event processing
	//-----------------
	if (nEvents < 0)
	{
		return;
	}
	// if we run the particle generator and use 0 it'll run forever
	if (nEvents == 0 && !readhits && !readhepmc)
	{
		cout << "using 0 for number of events is a bad idea when using particle generators" << endl;
		cout << "it will run forever, so I just return without running anything" << endl;
		return;
	}
	se->run(nEvents);

	//-----
	// Exit
	//-----

	se->End();
	std::cout << "All done" << std::endl;
	delete se;
	gSystem->Exit(0);
}
