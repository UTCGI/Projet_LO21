#include "partie.h"
#include <iostream>

using namespace std;
// ----------------------------------------------------------------
// Getter functions
// ----------------------------------------------------------------
int Partie::getManche() const { 
    return manche; 
}

int Partie::getNumDe() const{
    return num_de; 
}

int Partie::getNbJoueurs() const{ 
    return nb_joueurs; 
}

int Partie::getNbMonuments() const{ 
    return nb_monuments; 
}

int Partie::getNbEtablissements() const{ 
    return nb_etablissements; 
}

Jeu* Partie::getJeu() const{ 
    return jeu; 
}

Joueur* Partie::getJoueurActif() const{ 
    return joueur_actif; 
}

Joueur* Partie::getEnsenbleJoueurs() const{ 
    return joueurs; 
}

Joueur Partie::getJoueurI(const int i) {
    return joueurs[i];
}

Reserve* Partie::getReserve() const{
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
Partie::Partie(): manche(0), num_de(1), nb_joueurs(2), 
nb_monuments(4), nb_etablissements(15), jeu(new Jeu), 
joueur_actif(new Joueur), joueurs(new Joueur[nb_joueurs]), 
reserve(new Reserve){

}

Partie::~Partie(){

}

// ----------------------------------------------------------------
// Methods
// ----------------------------------------------------------------
void Partie::initialisation(){
    cout<< "Bonjour, bienvenu dans le jeu MachiKoro"<< endl;
    cout << "Entrez le nombre de joueurs :"<< endl;
    int lecture = 0;
    do {
        cin >> lecture;
    }
    while (lecture <= Joueur.min_joueurs || lecture >= Joueur.max_joueurs);
    setNbJoueurs(lecture);
    // TODO: A completer
    // Il faut recuperer l'extention ? Pour pouvoir initialiser les varianles aux bonnes valeurs
    string lectureExtention;
    cout << "Entrez l'extention à laquelle vous voulez jouer (Marina, GreenValley, Deluxe) :"<< endl;
    do {
        cin >> lectureExtention;
        // Allow us to have a maj word
        for(int i = 0; i < lectureExtention.length(); i++){
            lectureExtention[i] =toupper (lectureExtention[i]);
        }
    }
    while (lectureExtention != "MARINA" || lectureExtention != "GREENVALLEY" ||  lectureExtention != "DELUXE");
    switch (lectureExtention){
        case "MARINA":
            jeu.setExtention(Extension.Marina);
            setNbMonuments(4); // TODO Vérifier le nb de monuments exact
            setNbEtablissements(15); // TODO Vérifier le nb de etablissements exact
            break;
        case "GREENVALLEY":
            Jeu.setExtention(Extension.GreenValley);
            setNbMonuments(4); // TODO Vérifier le nb de monuments exact
            setNbEtablissements(15); // TODO Vérifier le nb de etablissements exact
            break;
        case "DELUXE":
            Jeu.setExtention(Extension.Deluxe);
            setNbMonuments(4); // TODO Vérifier le nb de monuments exact
            setNbEtablissements(15); // TODO Vérifier le nb de etablissements exact
            break;
    } 
}

void Partie::distribuer(){
    // TODO: A completer
}

Joueur Partie::tour_joueur(Joueur joueur){
    int i = 0;
    while (i < getNbJoueurs() && getJoueurActif() != joueur){ i++; }
    int indice = (i+1) % getNbJoueurs();
    return getJoueurI(indice);
}

Etablissement* Partie::regarder_etablissements(Joueur joueur, Couleur couleur){
    // TODO: A completer
}

void Partie::application_regle_standards(Couleur couleur){
    // TODO: A completer
}

void Partie::application_regle_speciales(Pile pile_joueur){
    // TODO: A completer
}

void Partie::transaction_piece(Joueur& emeteur, Joueur& destinataire, int montant){
    int compte_emeteur = emeteur.getCompte();
    int compte_destinataire = destinataire.getCompte();
    emeteur.setCompte(compte_emeteur - montant);
    destinataire.setCompte(compte_emeteur + montant);
}

void Partie::transaction_carte(Joueur& emeteur, Joueur& destinataire, Pile& pile){
    // TODO: A completer
}

void Partie::achat_carte(Joueur& joueur, Pile& pile_reserve){
    // TODO: A completer
}