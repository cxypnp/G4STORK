/*g4stork.ccCreated by:		Liam RussellDate:			22-06-2011Modified:		11-03-2013Main driver file for G4-Stork code.  Instantiates run manager, required classesand optional classes.  Also instantiates the parse input class (inputvariables).*/// G4-Stork header files#include "StorkRunManager.hh"#include "StorkWorld.hh"#include "StorkNeutronPhysicsList.hh"#include "StorkPrimaryGeneratorAction.hh"#include "StorkRunAction.hh"#include "StorkEventAction.hh"#include "StorkParseInput.hh"
#include "StorkInteractStat.hh"
#include "StorkIsoEnerScore.hh"
#include "ElementNames.hh"
#include "NeutronHPModCheck.hh"// Geant4 header files#include "G4Timer.hh"#include "G4VisExecutive.hh"#include "G4UIExecutive.hh"#include "G4UImanager.hh"#include "G4UIsession.hh"#include "G4UIterminal.hh"#include "G4ThreeVector.hh"#include "G4UnitsTable.hh"#include "G4EventManager.hh"#include "G4TrackingManager.hh"#include "Randomize.hh"#include "G4RunManager.hh"#include "G4VUserActionInitialization.hh"// Other header files#include <fstream>// Include parallel processing file#include "g4stork.icc"#ifdef G4USE_TOPC	#include "topc.h"#endifint main(int argc, char **argv){// SIMULATION VARIABLES --------------------------------------------------------
    ElementNames elemNames;
    elemNames.SetElementNames();

    NeutronHPModCheck checkNeutHPMod;
    MCNPEnvCheck runLikeMCNP;
    // Set up and start the timer    G4Timer mainTimer;    mainTimer.Start();    std::ostream *output = NULL;    G4bool master = true;    G4bool readInput = false;#ifdef G4USE_TOPC	master = G4bool(TOPC_is_master());
	int processID = TOPC_rank();
#else
    int processID=0;#endif// USER GEOMETRY ---------------------------------------------------------------    // ***** INSTANTIATE USER DEFINED GEOMETRIES HERE *****    // *****// USER INPUT FILE -------------------------------------------------------------	// Check that an input file was given	if(argc == 1)	{		G4cerr << "No input file given.  Exiting." << G4endl;
		elemNames.ClearStore();		return 1;	}	// Create parse input object	StorkParseInput *infile = new StorkParseInput;	// ***** ADD USER GEOMETRY TO PARSE INPUT HERE *****	// *****    // Parse input file	readInput = infile->ReadInputFile(G4String(argv[1]));	if(!readInput)	{		G4cerr << "*** ERROR: Invalid input in " << G4String(argv[1])			   << ". Exiting." << G4endl;
        elemNames.ClearStore();		return 1;	}	// Create a constant pointer to the parse input object    const StorkParseInput* USER_INPUT = infile;    // Set output stream in main function	output = USER_INPUT->GetLogOutputStream();// RANDOM NUMBER GENERATOR -----------------------------------------------------    // Set up random engine    CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);    if(master)    {		CLHEP::HepRandom::setTheSeed(USER_INPUT->GetRandomSeed());		CLHEP::HepRandom::showEngineStatus();		CLHEP::HepRandom::saveEngineStatus();    }// SIMULATION STRUCTURES -------------------------------------------------------    StorkRunManager* runManager = new StorkRunManager(USER_INPUT);	runManager->SetVerboseLevel(0);	// Set version string in the StorkParseInput object	infile->SetG4VersionString(runManager->GetVersionString());  	// Construct the world    StorkWorld *theWorld = new StorkWorld(USER_INPUT);    // ***** ADD USER GEOMETRY TO StorkWORLD HERE *****	// *****	runManager->SetUserInitialization(theWorld);	// Construct the physics list    runManager->SetUserInitialization(new StorkNeutronPhysicsList(USER_INPUT));  	// Construct the primary generator  	StorkPrimaryGeneratorAction * genAction;    genAction = new StorkPrimaryGeneratorAction(USER_INPUT, master);	runManager->SetUserAction(genAction);    // Set optional user action class    // Construct the run action only if this is the master    StorkRunAction *runAction = NULL;	if(master)	{        runAction = new StorkRunAction(genAction, USER_INPUT);	}	runManager->SetUserAction(runAction);    // Construct the event action	StorkEventAction* eventAction = new StorkEventAction();	runManager->SetUserAction(eventAction);// START SIMULATION ------------------------------------------------------------    // Initialize the run    runManager->Initialize();

    // Set up scoring classes if wanted
    StorkIsoStat isoStat(USER_INPUT);
    if(USER_INPUT->GetScoreIsoCheck())
    {
        isoStat.CreateArrays();
    }
    StorkInteractStat intrctStat(USER_INPUT);    if(USER_INPUT->GetScoreReacCheck())
    {
        intrctStat.CreateArrays();
    }
    StorkIsoReacScore isoReacScore(processID,USER_INPUT);
    if(USER_INPUT->GetScoreIsoReacCheck())
    {
        isoReacScore.InitData();
    }
    StorkIsoEnerScore isoEnerScore(processID,USER_INPUT);
    if(USER_INPUT->GetScoreIsoEnerCheck())
    {
        isoEnerScore.InitData();
    }

    // Record the initialization time and restart the timer for the computation    mainTimer.Stop();    if(master)    {//		theWorld->DumpGeometricalTree();		// Set world size in run action now that the world is built		runAction->SetWorldDimensions(theWorld->GetWorldBoxDimensions());		USER_INPUT->PrintInput(output);		*output << "# Initialization time:  " << mainTimer << G4endl				<< "#" << G4endl				<< "# ---------------------------------------------------------"				<< G4endl << "# " << G4endl				<< "# Starting Simulation" << G4endl				<< "#" << G4endl;	}	mainTimer.Start();#ifdef G4VISUALIZE_USE    //Visualization manager    G4VisManager* visManager = new G4VisExecutive("warnings");    visManager->Initialize();    // Define (G)UI    G4UImanager* UImanager = G4UImanager::GetUIpointer();    G4UIExecutive* ui = new G4UIExecutive(argc, argv);    UImanager->ApplyCommand("/control/execute VisCommands.mac");    //G4UIsession *ui = new G4UIterminal;    ui->SessionStart();    delete ui;#endif#ifdef G4VERBOSE_TRACKING_USE    G4EventManager *eventMan = G4EventManager::GetEventManager();    G4TrackingManager *trackMan = eventMan->GetTrackingManager();    trackMan->SetVerboseLevel(1);#endif#ifndef G4VISUALIZE_USE    // set to zero so function will go to terminal    if(USER_INPUT->GetNumberOfEvents())    {        runManager->BeamOn(USER_INPUT->GetNumberOfEvents());    }    else    {        G4UIsession *ui = new G4UIterminal;        ui->SessionStart();        delete ui;    }#endif// WRAP-UP SIMULATION ----------------------------------------------------------    // Output the source convergence results    if(master) runManager->OutputResults();#ifdef G4VISUALIZE_USE    delete visManager;#endif	// Stop the timer for the total computation time	mainTimer.Stop();    if(master)    {		*output << "#" << G4endl << "# Total computation time:  "		        << mainTimer << G4endl;	}	delete infile;    delete runManager;

    // Delete scoring classes
    if(USER_INPUT->GetScoreIsoCheck())
    {
        isoStat.DeleteArrays();
    }
    if(USER_INPUT->GetScoreIsoReacCheck())
    {
        isoReacScore.DeleteData();
    }
    if(USER_INPUT->GetScoreIsoEnerCheck())
    {
        isoEnerScore.DeleteData();
    }
    elemNames.ClearStore();
    return 0;}