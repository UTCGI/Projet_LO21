#include "reserve.h"

// Getters
int Reserve::getNbLignes() const{
    return nb_lignes;
}
int Reserve::getNbColonnes() const{
    return nb_colonnes;
}
Pile_Etablissement* Reserve::getGrille() const{
    return *Grille;
}

// Constructors and Destructors
Reserve::Reserve(Jeu& j)
{
    nb_lignes = j.getNb_lignes_reserve_MAX();
    nb_colonnes = j.getNb_colonnes_reserve_MAX();
    Extension e= j.getExtension();
    switch (e){
        case Extension::Aucune:
            break;
        case Extension::Marina:
            
            break;
        case Extension::GreenValley:
            
            break;
        case Extension::Deluxe:
            
            break;
        default:

            break;
    }

}
Reserve::~Reserve(){

}

// Methods
Reserve Reserve::retirer_etablissement(Pile_Etablissement* etablissement){

}


ostream &operator<<(ostream &f, Reserve &carte){
    f << "" << endl;
    return f;
}