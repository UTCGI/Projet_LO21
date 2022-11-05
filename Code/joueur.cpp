#include "joueur.h"

int Joueur::getNbDes() const{
    return de;
}

int Joueur::getCompte() const{
    return compte;
}

void ajouterMontant(int montant){
    compte+= montant;
}

bool Joueur::victoire(){

}

int Joueur::lancerDés(){
    if (de==1) {
        return rand() % 6 + 1
    } else if (de==2) {
        return rand() % 12 + 1
    }
}
