// ----------------------------------------------------------------------------
// 'SCorrelatorJetTree.constituents.h'
// Derek Anderson
// 01.18.2023
//
// Class to construct a tree of
// jets from a specified set of
// events.
//
// Methods relevant to the jet
// constituents are collected
// here.
//
// Derived from code by Antonio
// Silva (thanks!!)
// ----------------------------------------------------------------------------

#pragma once

using namespace std;
using namespace findNode;



// constituent methods --------------------------------------------------------

bool SCorrelatorJetTree::isAcceptableParticleFlow(ParticleFlowElement *pfPart) {

  // print debug statement
  if (m_doDebug && (Verbosity() > 1)) {
    cout << "SCorrelatorJetTree::isAcceptableParticleFlow(ParticleFlowElement*) Checking if particle flow element is good..." << endl;
  }

  // TODO: explore particle flow cuts
  const double pfEta         = pfPart -> get_eta();
  const bool   isInEtaRange  = ((pfEta > m_particleflow_mineta) && (pfEta < m_particleflow_maxeta));
  const bool   isGoodElement = isInEtaRange;
  return isGoodElement;

}  // end 'isAcceptableParticleFlow(ParticleFlowElement*)'



bool SCorrelatorJetTree::isAcceptableTrack(SvtxTrack *track) {

  // print debug statement
  if (m_doDebug && (Verbosity() > 1)) {
    cout << "SCorrelatorJetTree::isAcceptableTrack(SvtxTrack*) Checking if track is good..." << endl;
  }

  const double trkPt        = track -> get_pt();
  const double trkEta       = track -> get_eta();
  const bool   isInPtRange  = ((trkPt > m_track_minpt)   && (trkPt < m_track_maxpt));
  const bool   isInEtaRange = ((trkEta > m_track_mineta) && (trkEta < m_track_maxeta));
  const bool   isGoodTrack  = (isInPtRange && isInEtaRange);
  return isGoodTrack;

}  // end 'isAcceptableTrack(SvtxTrack*)'



bool SCorrelatorJetTree::isAcceptableEMCalCluster(CLHEP::Hep3Vector &E_vec_cluster) {

  // print debug statement
  if (m_doDebug && (Verbosity() > 1)) {
    cout << "SCorrelatorJetTree::isAcceptableEMCalCluster(CLHEP::Hep3Vector&) Checking if ECal cluster is good..." << endl;
  }

  const double clustPt      = E_vec_cluster.perp();
  const double clustEta     = E_vec_cluster.pseudoRapidity();
  const bool   isInPtRange  = ((clustPt > m_EMCal_cluster_minpt)   && (clustPt < m_EMCal_cluster_maxpt));
  const bool   isInEtaRange = ((clustEta > m_EMCal_cluster_mineta) && (clustEta < m_EMCal_cluster_maxeta));
  const bool   isGoodClust  = (isInPtRange && isInEtaRange);
  return isGoodClust;

}  // end 'isAcceptableEMCalCluster(CLHEP::Hep3Vector&)'



bool SCorrelatorJetTree::isAcceptableHCalCluster(CLHEP::Hep3Vector &E_vec_cluster) {

  // print debug statement
  if (m_doDebug && (Verbosity() > 1)) {
    cout << "SCorrelatorJetTree::isAcceptableHCalCluster(CLHEP::Hep3Vector&) Checking if HCal cluster is good..." << endl;
  }

  // TODO: explore particle cuts. These should vary with particle charge/species.
  const double clustPt      = E_vec_cluster.perp();
  const double clustEta     = E_vec_cluster.pseudoRapidity();
  const bool   isInPtRange  = ((clustPt > m_HCal_cluster_minpt)   && (clustPt < m_HCal_cluster_maxpt));
  const bool   isInEtaRange = ((clustEta > m_HCal_cluster_mineta) && (clustEta < m_HCal_cluster_maxeta));
  const bool   isGoodClust  = (isInPtRange && isInEtaRange);
  return isGoodClust;

}  // end 'isAcceptableHCalCluster(CLHEP::Hep3Vector&)'



bool SCorrelatorJetTree::isAcceptableParticle(HepMC::GenParticle *part) {

  // print debug statement
  if (m_doDebug && (Verbosity() > 1)) {
    cout << "SCorrelatorJetTree::isAcceptableParticle(HepMC::GenParticle*) Checking if MC particle is good..." << endl;
  }

  // check charge if needed
  int   parID;
  bool  isGoodCharge;
  float parChrg;
  if (m_jetType != 1) {
    parID        = part -> pdg_id();
    parChrg      = getParticleCharge(parID);
    isGoodCharge = (parChrg != 0.);
  } else {
    isGoodCharge = true;
  }

  const double parEta       = part -> momentum().eta();
  const double parPx        = part -> momentum().px();
  const double parPy        = part -> momentum().py();
  const double parPt        = sqrt((parPx * parPx) + (parPy * parPy));
  const bool   isInPtRange  = ((parPt > m_MC_particle_minpt)   && (parPt < m_MC_particle_maxpt));
  const bool   isInEtaRange = ((parEta > m_MC_particle_mineta) && (parEta < m_MC_particle_maxeta));
  const bool   isGoodPar    = (isGoodCharge && isInPtRange && isInEtaRange);
  return isGoodPar;

}  // end 'isAcceptableParticle(HepMC::GenParticle*)'



float SCorrelatorJetTree::getParticleCharge(const int pid) {

  // print debug statement
  if (m_doDebug && (Verbosity() > 2)) {
    cout << "SCorrelatorJetTree::getParticleCharge(int) Grabbing MC particle charge..." << endl;
  }

  // particle charge
  float charge(-999.);

  switch (abs(pid)) {
    // e+/e-
    case 11:
      charge = 1.;
      break;
    // e neutrinos
    case 12:
      charge = 0.;
      break;
    // mu-/mu+
    case 13:
      charge = -1.;
      break;
    // mu neutrinos
    case 14:
      charge = 0.;
      break;
    // tau-/tau+
    case 15:
      charge = -1.;
      break;
    // tau neutrinos
    case 16:
      charge = 0.;
      break;
    // photon
    case 22:
      charge = 0.;
      break;
    // Z0
    case 23:
      charge = 0.;
      break;
    // W+/W-
    case 24:
      charge = 1.;
      break;
    // pi0
    case 111:
      charge = 0.;
      break;
    // pi+/pi-
    case 211:
      charge = 1.;
      break;
    // K0 (long)
    case 130:
      charge = 0.;
      break;
    // K0 (short)
    case 310:
      charge = 0.;
      break;
    // K+/K-
    case 321:
      charge = 1.;
      break;
    // D+/D-
    case 441:
      charge = 1.;
      break;
    // D0
    case 421:
      charge = 0.;
      break;
    // DS+/DS-
    case 431:
      charge = 1.;
      break;
    // eta
    case 221:
      charge = 0.;
      break;
    // proton/antiproton
    case 2212:
      charge = 1.;
      break;
    // neutron
    case 2112:
      charge = 0.;
      break;
    // lambda
    case 3122:
      charge = 0.;
      break;
    // sigma+/antisigma+
    case 3222:
      charge = 1.;
      break;
    // sigma0
    case 3212:
      charge = 0.;
      break;
    // sigma-/antisigma-
    case 3112:
      charge = -1.;
      break;
    // xi0
    case 3322:
      charge = 0.;
      break;
    // deuteron
    case 700201:
      charge = 0.;
      break;
    // alpha
    case 700202:
      charge = 2.;
      break;
    // triton
    case 700301:
      charge = 0.;
      break;
    case 700302:
      charge = 3.;
      break;
    default:
      charge = 0.;
      if (m_doDebug && (Verbosity() > 1)) {
        cerr << "SCorrelatorJetTree::getParticleCharge(int) WARNING: trying to determine charge of unknown particle (PID = " << pid << ")..." << endl;
      }
      break;
  }  // end switch (abs(pid))

  // if antiparticle, flip charge and return
  if (pid < 0) {
    charge *= -1.;
  }
  return charge;

}  // end 'getParticleCharge(int)'

// end ------------------------------------------------------------------------