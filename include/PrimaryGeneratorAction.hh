#ifndef PrimaryGeneratorAction_h 
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "PrimaryGenerator.hh"
#include "G4Event.hh"
#include "HistoManager.hh"
#include "PrimaryGeneratorActionMessenger.hh"


struct BeamParams
{
    G4double energy;
    G4ThreeVector vtxPosition;
    G4ThreeVector polarization;
    G4ThreeVector momentum;
};

struct IsotopeParams
{
    G4String shape;
};


/**
 * \class PrimaryGeneratorAction
 * \brief heart of simulated physics
 */
class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
    public:
        PrimaryGeneratorAction(HistoManager* histo);
        ~PrimaryGeneratorAction();
        virtual void GeneratePrimaries(G4Event*);

        void SetSourceTypeInfo(G4String);
        G4String GetSourceTypeInfo(){return fGenerateSourceType;};

    private:

        G4String fGenerateSourceType;///< "run", "beam", "isotope" 
        G4String fAllowedSourceTypes[3] = {"run", "beam", "isotope"};

        PrimaryGeneratorActionMessenger* fMessenger; 

        PrimaryGenerator* fPrimaryGenerator; 
        HistoManager* fHisto;

        BeamParams beam;

};
#endif
