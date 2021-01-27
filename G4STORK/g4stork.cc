/*
#include "StorkInteractStat.hh"
#include "StorkIsoEnerScore.hh"
#include "ElementNames.hh"
#include "NeutronHPModCheck.hh"
    ElementNames elemNames;
    elemNames.SetElementNames();

    NeutronHPModCheck checkNeutHPMod;
    MCNPEnvCheck runLikeMCNP;

	int processID = TOPC_rank();
#else
    int processID=0;
		elemNames.ClearStore();
        elemNames.ClearStore();

    // Set up scoring classes if wanted
    StorkIsoStat isoStat(USER_INPUT);
    if(USER_INPUT->GetScoreIsoCheck())
    {
        isoStat.CreateArrays();
    }
    StorkInteractStat intrctStat(USER_INPUT);
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

