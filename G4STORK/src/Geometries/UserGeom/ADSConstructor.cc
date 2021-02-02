// ADSConstructor.cc
// Created by:		Chengxi Yang
// Date:			10-07-2020
// Modified:

// source code for Accelerator Driven System geometry

#include "ADSConstructor.hh"

ADSConstructor::ADSConstructor()
    : StorkVWorldConstructor(), channelLogical(0), coreLogical(0),
      middleLogical(0), bottomLogical(0), sideLogical(0), topLogical(0) /*, coatingLogical(0)*/
{
    worldVisAtt = NULL;
    refVisAtt = NULL;
    coreVisAtt = NULL;
    latticePitch = 17 * cm;

    // fuelTemp = 750 * kelvin;
    // fuelDensity = 3.479983 * g / cm3;

    // fuelTemp = 800 * kelvin;
    // fuelDensity = 3.438983 * g / cm3;

    // fuelTemp = 850 * kelvin;
    // fuelDensity = 3.397983 * g / cm3;

    // fuelTemp = 900 * kelvin;
    // fuelDensity = 3.356983 * g / cm3;

    // fuelTemp = 950 * kelvin;
    // fuelDensity = 3.315983 * g / cm3;

    fuelTemp = 1000 * kelvin;
    fuelDensity = 3.274983 * g / cm3;

    graphiteTemp = fuelTemp;
    graphiteDensity = 1.80 * g / cm3;

    alloyTemp = fuelTemp;
    alloyDensity = 8.86 * g / cm3;

    // Set up variable property map
    variablePropMap[MatPropPair(fuel, temperature)] = &fuelTemp;
    variablePropMap[MatPropPair(fuel, density)] = &fuelDensity;
    variablePropMap[MatPropPair(moderator, temperature)] = &graphiteTemp;
    variablePropMap[MatPropPair(moderator, density)] = &graphiteDensity;
    variablePropMap[MatPropPair(all, dimension)] = &latticePitch;
}

ADSConstructor::~ADSConstructor()
{
    //delete any existing visualization attributes
    if (worldVisAtt)
        delete worldVisAtt;
    if (coreVisAtt)
        delete coreVisAtt;
    if (refVisAtt)
        delete refVisAtt;
}

G4VPhysicalVolume *ADSConstructor::ConstructWorld()
{
    G4SolidStore *theSolids = G4SolidStore::GetInstance();

    // Active Core Parameters
    //radius and height
    G4double core_r = 4.5 * latticePitch, core_h = 13.5 * latticePitch;
    //thickness of the reflectors
    G4double ref_top = 2 * latticePitch, ref_bott = 2 * latticePitch, ref_side = 2 * latticePitch;
    // Fuel Channel Parameters
    G4double chan_r = 1.7 * cm, chan_h = core_h; //radius and length of the fuel channel
    // Reflector Parameters
    G4double ref_rmin = 0, ref_rmax = core_r + ref_side, ref_h = core_h;
    // Coating Parameters
    // G4double coat_rmin = ref_rmax, coat_rmax = 1.01*coat_rmin, coat_h = core_h + ref_top + ref_bott;
    // World Parameters
    reactorDim = G4ThreeVector(ref_rmax, ref_rmax, 0.5 * (core_h + ref_top + ref_bott));
    encWorldDim = G4ThreeVector(2.01 * ref_rmax, 2.01 * ref_rmax, 2.01 * 0.5 * (core_h + ref_top + ref_bott));

    if (matChanged)
    {
        // Delete any existing materials
        DestroyMaterials();
        // Create the materials
        ConstructMaterials();
    }

    //Build Solids if necessary
    if (geomChanged)
    {
        //world
        new G4Box("worldBox", 0.5 * encWorldDim[0], 0.5 * encWorldDim[1], 0.5 * encWorldDim[2]);
        //core
        new G4Tubs("coreSolid", 0, core_r, 0.5 * core_h, 0., 2.0 * CLHEP::pi);
        //side reflector
        new G4Tubs("sideSolid", core_r, ref_rmax, 0.5 * ref_h, 0., 2.0 * CLHEP::pi);
        //top reflector
        new G4Tubs("topSolid", ref_rmin, ref_rmax, 0.5 * ref_top, 0., 2.0 * CLHEP::pi);
        //bottom reflector
        new G4Tubs("bottomSolid", 0, ref_rmax, 0.5 * ref_bott, 0., 2.0 * CLHEP::pi);
        //fuel channel
        new G4Tubs("channelSolid", 0, chan_r, 0.5 * chan_h, 0., 2.0 * CLHEP::pi);
        //coating
        // new G4Tubs("coatingSolid", coat_rmin, coat_rmax, 0.5 * coat_h, 0, 2.0 * CLHEP::pi);
        geomChanged = false;
    }

    worldLogical = new G4LogicalVolume(theSolids->GetSolid("worldBox"), matMap["Galactic"], "worldLogical", 0, 0, 0);

    coreLogical = new G4LogicalVolume(theSolids->GetSolid("coreSolid"), matMap["Graphite"], "coreLogical", 0, 0, 0);

    sideLogical = new G4LogicalVolume(theSolids->GetSolid("sideSolid"), matMap["Graphite"], "sideLogical", 0, 0, 0);
    //top reflector
    topLogical = new G4LogicalVolume(theSolids->GetSolid("topSolid"), matMap["Graphite"], "topLogical", 0, 0, 0);
    //bottom reflector
    bottomLogical = new G4LogicalVolume(theSolids->GetSolid("bottomSolid"), matMap["Graphite"], "bottomLogical", 0, 0, 0);
    //fuel channel
    channelLogical = new G4LogicalVolume(theSolids->GetSolid("channelSolid"), matMap["Fuel"], "channnelLogical", 0, 0, 0);
    //coating
    // coatingLogical = new G4LogicalVolume(theSolids->GetSolid("coatingSolid"), matMap["Alloy"], "coatingLogical", 0, 0, 0);

    //delete any existing visualization attributes
    if (worldVisAtt)
        delete worldVisAtt;
    if (coreVisAtt)
        delete coreVisAtt;
    if (refVisAtt)
        delete refVisAtt;

    //Vision Attributes Set Visibility and Color
    worldVisAtt = new G4VisAttributes(false, G4Colour(0, 1, 0));
    coreVisAtt = new G4VisAttributes(true, G4Colour(0, 1, 0));
    coreVisAtt->SetForceSolid(true);
    // coreVisAtt->SetForceWireframe(true);
    refVisAtt = new G4VisAttributes(true, G4Colour(0, 1, 0));
    // refVisAtt->SetForceSolid(true);
    refVisAtt->SetForceWireframe(true);

    worldLogical->SetVisAttributes(worldVisAtt);
    coreLogical->SetVisAttributes(coreVisAtt);
    sideLogical->SetVisAttributes(refVisAtt);
    topLogical->SetVisAttributes(refVisAtt);
    bottomLogical->SetVisAttributes(refVisAtt);
    // coatingLogical->SetVisAttributes(refVisAtt);

    //Placement
    //world
    worldPhysical = new G4PVPlacement(0, G4ThreeVector(0, 0, 0), worldLogical, "worldPhysical", 0, 0, 0, 0);
    //core
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), coreLogical, "corePhysical", worldLogical, 0, 0, 0);
    //sideReflector
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), sideLogical, "sidePhysical", worldLogical, 0, 0, 0);
    //topReflector
    new G4PVPlacement(0, G4ThreeVector(0, 0, 0.5 * (ref_top + core_h)), topLogical, "topPhysical", worldLogical, 0, 0, 0);
    //bottomReflector
    new G4PVPlacement(0, G4ThreeVector(0, 0, -0.5 * (core_h + ref_bott)), bottomLogical, "bottomPhysical", worldLogical, 0, 0, 0);
    //Coating
    // new G4PVPlacement(0, G4ThreeVector(0, 0, 0), coatingLogical, "coatingPhysical", worldLogical, 0, 0, 0);

    //fuel channels
    G4double dPhi = 60 * deg;
    G4int num = 1;
    for (G4int i = 2; i < 6; i++)
    {
        for (G4int j = 0; j < 6; j++)
        {
            G4double phi = j * dPhi;
            G4ThreeVector unit1 = G4ThreeVector(std::cos(phi), std::sin(phi), 0.);
            G4ThreeVector unit2 = G4ThreeVector(std::cos(phi + 120 * deg), std::sin(phi + 120 * deg), 0.);

            if (i == 5)
            {
                for (G4int k = 2; k <= i - 1; k++)
                {
                    G4ThreeVector position = latticePitch * (i - 1) * unit1 + latticePitch * (k - 1) * unit2;
                    new G4PVPlacement(0, position, channelLogical, "channels", coreLogical, 0, num++);
                }
            }
            else
            {
                for (G4int k = 1; k <= i - 1; k++)
                {
                    G4ThreeVector position = latticePitch * (i - 1) * unit1 + latticePitch * (k - 1) * unit2;
                    new G4PVPlacement(0, position, channelLogical, "channels", coreLogical, 0, num++);
                }
            }
        }
    }
    worldLogical->SetSensitiveDetector(sDReactor);
    coreLogical->SetSensitiveDetector(sDReactor);
    topLogical->SetSensitiveDetector(sDReactor);
    sideLogical->SetSensitiveDetector(sDReactor);
    bottomLogical->SetSensitiveDetector(sDReactor);
    channelLogical->SetSensitiveDetector(sDReactor);
    // coatingLogical->SetSensitiveDetector(sDReactor);

    return worldPhysical;
}

void ADSConstructor::ConstructMaterials()
{
    //Isotopes
    G4Isotope *Be9, *B10, *B11, *C12, *C13, *F19, *Na23, *Al27, *Si28, *Si29, *Si30,
        *Ti46, *Ti47, *Ti48, *Ti49, *Ti50, *Cr50, *Cr52, *Cr53, *Cr54, *Mn55, *Fe54, *Fe56, *Fe57, *Fe58,
        *Co59, *Ni58, *Ni60, *Ni64, *Mo92, *Mo94, *Mo95, *Mo96, *Mo97, *Mo98, *Mo100, *U234, *U235, *U238;
    //Elements
    G4Element *Be, *B, *C, *F, *Na, *Al, *Si, *Ti, *Cr, *Mn, *Fe, *Co, *Ni, *Mo, *U;
    //Materials
    G4Material *World, *Fuel, *Graphite, *Alloy;

    //Be
    Be9 = new G4Isotope("Be9", 4, 9, 9.012183065 * g / mole);
    Be = new G4Element("Beryllium", "Be", 1);
    Be->AddIsotope(Be9, 1);

    //B
    B10 = new G4Isotope("B10", 5, 10, 10.01293695 * g / mole);
    B11 = new G4Isotope("B11", 5, 11, 11.00930536 * g / mole);
    B = new G4Element("Boron", "B", 2);
    B->AddIsotope(B10, 19.9 * perCent);
    B->AddIsotope(B11, 80.1 * perCent);

    //C
    C12 = new G4Isotope("C12", 6, 12, 12.0 * g / mole);
    C13 = new G4Isotope("C13", 6, 13, 13.00335 * g / mole);
    C = new G4Element("Carbon", "C", 2);
    C->AddIsotope(C12, 98.93 * perCent);
    C->AddIsotope(C13, 1.07 * perCent);

    //F
    F19 = new G4Isotope("F19", 9, 19, 18.99840316273 * g / mole);
    F = new G4Element("F", "f", 1);
    F->AddIsotope(F19, 1);

    //Na
    Na23 = new G4Isotope("Na23", 11, 23, 22.9897692820 * g / mole);
    Na = new G4Element("sodium", "Na", 1);
    Na->AddIsotope(Na23, 1);

    //Al
    Al27 = new G4Isotope("Al27", 13, 27, 26.98153853 * g / mole);
    Al = new G4Element("Aluminum", "Al", 1);
    Al->AddIsotope(Al27, 1);

    //Si
    Si28 = new G4Isotope("Si28", 14, 28, 27.9769271 * g / mole);
    Si29 = new G4Isotope("Si29", 14, 29, 28.9764949 * g / mole);
    Si30 = new G4Isotope("Si30", 14, 30, 29.9737707 * g / mole);
    Si = new G4Element("Silicon", "Si", 3);
    Si->AddIsotope(Si28, 92.223 * perCent);
    Si->AddIsotope(Si29, 4.685 * perCent);
    Si->AddIsotope(Si30, 3.092 * perCent);

    //Ti
    Ti46 = new G4Isotope("Ti46", 22, 46, 45.9526294 * g / mole);
    Ti47 = new G4Isotope("Ti47", 22, 47, 46.9517640 * g / mole);
    Ti48 = new G4Isotope("Ti48", 22, 48, 47.9479473 * g / mole);
    Ti49 = new G4Isotope("Ti49", 22, 49, 48.9478711 * g / mole);
    Ti50 = new G4Isotope("Ti50", 22, 50, 49.9447921 * g / mole);
    Ti = new G4Element("Titanium", "Zn", 5);
    Ti->AddIsotope(Ti46, 8.25 * perCent);
    Ti->AddIsotope(Ti47, 7.44 * perCent);
    Ti->AddIsotope(Ti48, 73.72 * perCent);
    Ti->AddIsotope(Ti49, 5.41 * perCent);
    Ti->AddIsotope(Ti50, 5.18 * perCent);

    //Cr
    Cr50 = new G4Isotope("Cr50", 24, 50, 49.9460422 * g / mole);
    Cr52 = new G4Isotope("Cr52", 24, 52, 51.9405075 * g / mole);
    Cr53 = new G4Isotope("Cr53", 24, 53, 52.9406494 * g / mole);
    Cr54 = new G4Isotope("Cr54", 24, 54, 53.9388804 * g / mole);
    Cr = new G4Element("Chromium", "Cr", 4);
    Cr->AddIsotope(Cr50, 4.1737 * perCent);
    Cr->AddIsotope(Cr52, 83.7003 * perCent);
    Cr->AddIsotope(Cr53, 9.6726 * perCent);
    Cr->AddIsotope(Cr54, 2.4534 * perCent);

    //Mn
    Mn55 = new G4Isotope("Mn55", 25, 55, 54.9380 * g / mole);
    Mn = new G4Element("Manganese", "Mn", 1);
    Mn->AddIsotope(Mn55, 100. * perCent);

    //Fe
    Fe54 = new G4Isotope("Fe54", 26, 54, 53.9396105 * g / mole);
    Fe56 = new G4Isotope("Fe56", 26, 56, 55.9349375 * g / mole);
    Fe57 = new G4Isotope("Fe57", 26, 57, 56.9353940 * g / mole);
    Fe58 = new G4Isotope("Fe58", 26, 58, 57.9332756 * g / mole);
    Fe = new G4Element("Iron", "Fe", 4);
    Fe->AddIsotope(Fe54, 5.80 * perCent);
    Fe->AddIsotope(Fe56, 91.72 * perCent);
    Fe->AddIsotope(Fe57, 2.20 * perCent);
    Fe->AddIsotope(Fe58, 0.28 * perCent);

    //Co
    Co59 = new G4Isotope("Co59", 27, 59, 58.93319429 * g / mole);
    Co = new G4Element("cobalt", "Co", 1);
    Co->AddIsotope(Co59, 1);

    //Ni
    Ni58 = new G4Isotope("Ni58", 28, 58, 57.9353429 * g / mole);
    Ni60 = new G4Isotope("Ni60", 28, 60, 59.9307864 * g / mole);
    Ni64 = new G4Isotope("Ni64", 28, 64, 63.9279660 * g / mole);
    Ni = new G4Element("Nickel", "Ni", 3);
    Ni->AddIsotope(Ni58, 70.913 * perCent);
    Ni->AddIsotope(Ni60, 28.044 * perCent);
    Ni->AddIsotope(Ni64, 1.043 * perCent);

    //Mo
    Mo92 = new G4Isotope("Mo92", 42, 92, 91.9068 * g / mole);
    Mo94 = new G4Isotope("Mo94", 42, 94, 93.9051 * g / mole);
    Mo95 = new G4Isotope("Mo95", 42, 95, 94.9058 * g / mole);
    Mo96 = new G4Isotope("Mo96", 42, 96, 95.9047 * g / mole);
    Mo97 = new G4Isotope("Mo97", 42, 97, 96.9060 * g / mole);
    Mo98 = new G4Isotope("Mo98", 42, 98, 97.9054 * g / mole);
    Mo100 = new G4Isotope("Mo100", 42, 100, 99.9075 * g / mole);
    Mo = new G4Element("Molybdenum", "Mo", 7);
    Mo->AddIsotope(Mo92, 14.77 * perCent);
    Mo->AddIsotope(Mo94, 9.23 * perCent);
    Mo->AddIsotope(Mo95, 15.9 * perCent);
    Mo->AddIsotope(Mo96, 16.68 * perCent);
    Mo->AddIsotope(Mo97, 9.56 * perCent);
    Mo->AddIsotope(Mo98, 24.19 * perCent);
    Mo->AddIsotope(Mo100, 9.67 * perCent);

    //U
    U234 = new G4Isotope("U235", 92, 234, 234.0409523 * g / mole);
    U235 = new G4Isotope("U235", 92, 235, 235.0439301 * g / mole);
    U238 = new G4Isotope("U238", 92, 238, 238.0507884 * g / mole);
    U = new G4Element("enrichedUranium", "U", 3);
    U->AddIsotope(U234, 0.03 * perCent);
    U->AddIsotope(U235, 3.5 * perCent);
    U->AddIsotope(U238, 96.47 * perCent);

    //Material of World-Vaccum
    World = new G4Material("Galactic", 1, 1, 1.e-25 * g / cm3, kStateGas, 2.73 * kelvin, 3.e-18 * pascal);

    //Fuel Salt
    Fuel = new G4Material("Fuel", fuelDensity, 4, kStateLiquid, fuelTemp);
    Fuel->AddElement(Na, 70);
    Fuel->AddElement(Be, 15);
    Fuel->AddElement(F, 160);
    Fuel->AddElement(U, 15);

    //Graphite
    Graphite = new G4Material("Graphite", graphiteDensity, 2, kStateSolid, graphiteTemp);
    Graphite->AddElement(C, 99.9999982 * perCent);
    Graphite->AddElement(B, 0.0000018 * perCent);

    //Hastelloy-N alloy
    Alloy = new G4Material("Alloy", alloyDensity, 10, kStateSolid, alloyDensity);
    Alloy->AddElement(Ni, 70.941 * perCent);
    Alloy->AddElement(Mo, 16.8 * perCent);
    Alloy->AddElement(Cr, 7.01 * perCent);
    Alloy->AddElement(Fe, 4.16 * perCent);
    Alloy->AddElement(Co, 0.002 * perCent);
    Alloy->AddElement(Mn, 0.52 * perCent);
    Alloy->AddElement(Al, 0.15 * perCent);
    Alloy->AddElement(Ti, 0.002 * perCent);
    Alloy->AddElement(Si, 0.36 * perCent);
    Alloy->AddElement(C, 0.055 * perCent);

    //Material Map
    matMap["Galactic"] = World;
    matMap["Fuel"] = Fuel;
    matMap["Graphite"] = Graphite;
    matMap["Alloy"] = Alloy;

    matChanged = false;

    return;
}