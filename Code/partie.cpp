#include "partie.h"


// ----------------------------------------------------------------
// Getter functions
// ----------------------------------------------------------------
int Partie::getManche() { 
    return manche; 
}

int Partie::getNumDe() {
    return num_de; 
}

int Partie::getNbJoueurs() { 
    return nb_joueurs; 
}

int Partie::getNbMonuments() { 
    return nb_monuments; 
}

int Partie::getNbEtablissements() { 
    return nb_etablissements; 
}

Jeu* Partie::getJeu() { 
    return jeu; 
}

Joueur* Partie::getJoueurActif() { 
    return joueur_actif; 
}

Joueur* Partie::getEnsenbleJoueurs() { 
    return joueurs; 
}

Reserve* Partie::getReserve() {
    return reserve;
}

// ----------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------

int Partie::setManche(int nbManche){
    manche = nbManche;
}

int Partie::setNumDe(int nbDe){
    num_de = nbDe;
}

int Partie::setNbJoueurs(int nbJoueurs){
    nb_joueurs = nbJoueurs;
}

int Partie::setNbMonuments(int nbMonuments){
    nb_monuments = nbMonuments;
}

int Partie::setNbEtablissements(int nbEtablissements){
    nb_etablissements = nbEtablissements;
}

Jeu* Partie::setJeu(Jeu* jeu){
    this->jeu = jeu;
}

Joueur* Partie::setJoueurActif(Joueur* joueur){
    joueur_actif = joueur;
}

Joueur* Partie::setEnsenbleJoueurs(Joueur* EnsembreJoueurs){
    joueurs = EnsembreJoueurs;
}

Reserve* Partie::setReserve(Reserve* Reserve){
    reserve = Reserve;
}

// ----------------------------------------------------------------
// Constructors and destructors functions
// ----------------------------------------------------------------
Partie::Partie(){

}

Partie::~Partie(){

}

// ----------------------------------------------------------------
// Methods
// ----------------------------------------------------------------
void Partie::initialisation(){

}

void Partie::distribuer(){

}

void Partie::tour_joueur(Joueur joueur){

}

Etablissement* Partie::regarder_etablissements(Joueur joueur, Couleur couleur){

}

void Partie::application_regle_standards(Couleur couleur){

}

void Partie::application_regle_speciales(Pile pile_joueur){

}

void Partie::transaction_piece(Joueur emeteur, Joueur destinataire, int montant){

}

void Partie::transaction_carte(Joueur emeteur, Joueur destinataire, Pile pile){

}

void Partie::achat_carte(Joueur joueur, Pile pile_reserve){

}