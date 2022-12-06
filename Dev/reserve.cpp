#include "reserve.h"

// Getters
int Reserve::getNbPile() const{
    return nb_piles;
}

int Reserve::getNbEtablissements() const{
    return nb_etablissements;
}

// int Reserve::getNbLignes() const{
//     return nb_lignes;
// }
// int Reserve::getNbColonnes() const{
//     return nb_colonnes;
// }
Pile_Etablissement* Reserve::getListeEtablissement() const{
    return liste_etablissements;
}



// Constructors and Destructors
Reserve::Reserve(Jeu& j) 
{


}

Reserve::Reserve(Pioche& p){
    
}

Reserve::~Reserve(){

}

// Methods
void Reserve::retirer_etablissement(const Etablissement& etablissement){

}

void Reserve::ajouter_etablissement(const Etablissement& etablissement){
    for(int i = 0; i < getNbPile(); i++){
        if( etablissement == *liste_etablissements[i].getEtablissement()){
            liste_etablissements[i].ajouterCarte();
        }
    }
    // Pile_Etablissement();
}


ostream &operator<<(ostream &f, Reserve &carte){
    f << "" << endl;
    return f;
}