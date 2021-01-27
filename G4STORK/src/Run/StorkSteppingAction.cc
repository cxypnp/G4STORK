//
//  StorkSteppingAction.cc
//  G4-Stork_AT
//
//  Created by Andrew Tan on 2014-07-12.
//  Copyright (c) 2014 andrewtan. All rights reserved.
//

#include "StorkSteppingAction.hh"

//Constructor
StorkSteppingAction::StorkSteppingAction(StorkEventAction* eventAction): G4UserSteppingAction()
{
    SteppingMan = new G4SteppingManager;
    myEventAction = eventAction;
}
//Destructor
StorkSteppingAction::~StorkSteppingAction()
{
    delete SteppingMan;
}

/*void StorkSteppingAction::UserSteppingAction(const G4Step* theStep)
{

    G4cout << "Step is limited by "
    << theStep->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName()
    << G4endl;
    G4cout << "Processes involved to the step" << G4endl;
    G4StepStatus stepStatus = fpSteppingManager->GetfStepStatus();

    if(stepStatus==fAtRestDoItProc)
    {
        G4ProcessVector* procAtRest = fpSteppingManager->GetfAtRestDoItVector();
        G4SelectedAtRestDoItVector* selProcAtRest
        = fpSteppingManager->GetfSelectedAtRestDoItVector();
        size_t MAXofAtRestLoops = fpSteppingManager->GetMAXofAtRestLoops();
        for(size_t i1=0;i1<MAXofAtRestLoops;i1++)
        {
            if((*selProcAtRest)[MAXofAtRestLoops-i1-1]==2)
            { G4cout << "  At rest : " << (*procAtRest)[i1]->GetProcessName() << " (forced)" << G4endl; }
            else if((*selProcAtRest)[MAXofAtRestLoops-i1-1]==1)
            { G4cout << "  At rest : " << (*procAtRest)[i1]->GetProcessName() << G4endl; }
        }
    }

    if(stepStatus!=fExclusivelyForcedProc && stepStatus!=fAtRestDoItProc)
    {
        G4ProcessVector* procAlong = fpSteppingManager->GetfAlongStepDoItVector();
        size_t MAXofAlongStepLoops = fpSteppingManager->GetMAXofAlongStepLoops();
        for(size_t i2=0;i2<MAXofAlongStepLoops;i2++)
        {
            if((*procAlong)[i2]!=0)
                G4cout << "  Along step : " << (*procAlong)[i2]->GetProcessName() << G4endl;
        }
    }

    if(stepStatus!=fAtRestDoItProc)
    {
        G4ProcessVector* procPost = fpSteppingManager->GetfPostStepDoItVector();
        G4SelectedPostStepDoItVector* selProcPost
        = fpSteppingManager->GetfSelectedPostStepDoItVector();
        size_t MAXofPostStepLoops = fpSteppingManager->GetMAXofPostStepLoops();
        for(size_t i3=0;i3<MAXofPostStepLoops;i3++)
        {
            if((*selProcPost)[MAXofPostStepLoops-i3-1]==2)
            { G4cout << "  Post step : " << (*procPost)[i3]->GetProcessName() << " (forced)" << G4endl; }
            else if((*selProcPost)[MAXofPostStepLoops-i3-1]==1)
            { G4cout << "  Post step : " << (*procPost)[i3]->GetProcessName() << G4endl; }
        }
    }

    G4int nSecAtRest = fpSteppingManager->GetfN2ndariesAtRestDoIt();
    G4int nSecAlong  = fpSteppingManager->GetfN2ndariesAlongStepDoIt();
    G4int nSecPost   = fpSteppingManager->GetfN2ndariesPostStepDoIt();
    G4int nSecTotal  = nSecAtRest+nSecAlong+nSecPost;
    G4TrackVector* secVec = fpSteppingManager->GetfSecondary();

    if(nSecTotal>0)
    {
        G4cout << "  :----- List of 2ndaries - " << std::setw(3) << nSecTotal
        << " (Rest=" << std::setw(2) << nSecAtRest
        << ",Along=" << std::setw(2) << nSecAlong
        << ",Post="  << std::setw(2) << nSecPost << ")" << G4endl;

        for(size_t lp1=(*secVec).size()-nSecTotal; lp1<(*secVec).size(); lp1++)
        {
            G4cout << "    : "
            << G4BestUnit((*secVec)[lp1]->GetPosition(), "Length") << " "
            << std::setw( 9) << G4BestUnit((*secVec)[lp1]->GetKineticEnergy() , "Energy") << " "
            << std::setw(18) << (*secVec)[lp1]->GetDefinition()->GetParticleName()
            << " generated by " << (*secVec)[lp1]->GetCreatorProcess()->GetProcessName() << G4endl;
        }
}
*/




