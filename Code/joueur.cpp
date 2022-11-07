#include "joueur.h"

//Getter
int Joueur::getNbDes() const{
    return de;
}

int Joueur::getCompte() const{
    return compte;
}

int Joueur::getPlacement_StartUp() const {
    return placement_StartUp;
}

//Setter
void Joueur::setNbDes(int nbDe) {
    de=nbDe;
}

void Joueur::setCompte(int montant){
    compte=montant;
}

void setPseudo(string pseudo){
    pseudo=pseudo;
}

void setPlacement_StartUp(int placement_StartUp){
    placement_StartUp=placement_StartUp;
}


//Autres méthodes
void Joueur::ajouterMontant(int montant){
    compte+= montant;
}

bool Joueur::victoire(){
    int somme=0;
    for (size_t i=0;i<nb_monuments;i++){
        somme += monuments[i].construit;
    }
    return (somme == nb_monuments);
}

int Joueur::lancerDés(){
    if (de==1) {
        return rand() % 6 + 1;
    } else if (de==2) {
        return rand() % 6 + rand() % 6 + 2;
    } else {
        return -1;// Code d'erreur si on envoie un mauvais nombre
    }
    
}
