/*
ADSConstructor.hh

Created by:		Chengxi Yang
Date:			10-07-2020
Modified:

Header for Accelerator Driven System geometry

*/
#include "StorkVWorldConstructor.hh"
#include "StorkNeutronSD.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include <sstream>

/// Detector construction class to define materials and geometry.

class ADSConstructor : public StorkVWorldConstructor
{
  public:
    ADSConstructor();
    virtual ~ADSConstructor();

  protected:

    virtual G4VPhysicalVolume* ConstructWorld();   
    virtual void ConstructMaterials();


    G4LogicalVolume *coreLogical;
    G4LogicalVolume *sideLogical;
    G4LogicalVolume *topLogical;
    G4LogicalVolume *bottomLogical;
    G4LogicalVolume *channelLogical;
    G4LogicalVolume *middleLogical;
    // G4LogicalVolume *coatingLogical;

    G4VisAttributes *worldVisAtt;
    G4VisAttributes *coreVisAtt;
    G4VisAttributes *refVisAtt;

    G4double latticePitch;
    G4double fuelTemp;
    G4double fuelDensity;
    G4double graphiteTemp;
    G4double graphiteDensity;
    G4double alloyTemp;
    G4double alloyDensity;
};


