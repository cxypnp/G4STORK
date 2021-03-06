//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
//
#ifndef G4NeutronHPRestrictedSimpleEvapSpectrum_h
#define G4NeutronHPRestrictedSimpleEvapSpectrum_h 1

#include <fstream>
#include <CLHEP/Units/SystemOfUnits.h>

#include "globals.hh"
#include "G4ios.hh"
#include "Randomize.hh"
#include "G4NeutronHPVector.hh"
#include "G4VNeutronHPEDis.hh"

// we will need a List of these .... one per term.

class G4NeutronHPRestrictedSimpleEvapSpectrum : public G4VNeutronHPEDis
{
  public:
  G4NeutronHPRestrictedSimpleEvapSpectrum()
  {
    expm1 = std::exp(-1.);
  }
  ~G4NeutronHPRestrictedSimpleEvapSpectrum()
  {
  }

  inline void Init(std::istream & aDataFile)
  {
    theFractionalProb.Init(aDataFile, CLHEP::eV);
    theThetaDist.Init(aDataFile, CLHEP::eV);
    aDataFile >> restrictEner;
  }

  inline G4double GetFractionalProbability(G4double anEnergy)
  {
    return theFractionalProb.GetY(anEnergy);
  }

  inline G4double Sample(G4double anEnergy)
  {
    G4double theta = theThetaDist.GetY(anEnergy)*CLHEP::eV;
    G4double max, result, a1;
//    max = 10.*theta;
    max = std::max((anEnergy-restrictEner),0.001*CLHEP::eV);
    a1 = 1 - std::exp(-max/theta);
    do
    {
      result = -theta*std::log((1-a1*G4UniformRand())*(1-a1*G4UniformRand()));
    }
    while(result>max);
    return result;
  }

  private:

  inline G4double Evapo(G4double anEnergy, G4double theta)
  {
    G4double result = (anEnergy*CLHEP::eV)*std::exp(-anEnergy*CLHEP::eV/theta);
    return result;
  }

  private:

  G4double expm1, restrictEner;

  G4NeutronHPVector theFractionalProb;

  G4NeutronHPVector theThetaDist;

};

#endif
