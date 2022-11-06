#include "joueur.h"


int Joueur::getNbDes() const{
    return de;
}

int Joueur::getCompte() const{
    return compte;
}

int Joueur::getPlacement_StartUp() const {
    return placement_StartUp;
}

void Joueur::ajouterMontant(int montant){
    compte+= montant;
}

bool Joueur::victoire(){
    int somme=0;
    for (size_t i=0;i<nb_monuments;i++){
        somme += monuments[i].construit;
    }
    // Utiliser directement le return du booléen 
    // return (somme == nb_monuments);
    if(somme==nb_monuments) {
        return 1;
    } else {
        return 0;
    }
}

int Joueur::lancerDés(){
    if (de==1) {
        return rand() % 6 + 1;
    } else if (de==2) {
        return rand() % 6 + rand() % 6 + 2;
    } 
    // Code d'erreur si on envoie un mauvais nombre ?
    /*
    else {
        return -1;
    }
    */
}
