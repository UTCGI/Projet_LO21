#include "partie.h"

#include <iostream>

#include <vector>

using namespace std;
// ----------------------------------------------------------------
// Getter functions
// ----------------------------------------------------------------
int Partie::getManche() const { return manche; }

int Partie::getNumDe() const { return num_de; }

int Partie::getNbJoueurs() const { return nb_joueurs; }

//int Partie::getNbMonuments() const { return nb_monuments; }

//int Partie::getNbEtablissements() const { return nb_etablissements; }

Jeu *Partie::getJeu() const { return jeu; }

Joueur *Partie::getJoueurActif()  { return joueurs1[joueur_actif]; }

Reserve *Partie::getReserve() const { return reserve; }
const vector<Joueur*>& Partie::getJoueurs() const {return joueurs1;}


// ----------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------

// ce n'est pas plutôt des void le type de retour des setters ?
void  Partie::setManche(int nbManche) { manche = nbManche; }

void  Partie::setNumDe(int nbDe) { num_de = nbDe; }//inutile ?

void  Partie::setNbJoueurs(int nbJoueurs) { nb_joueurs = nbJoueurs; }

//void  Partie::setNbMonuments(int nbMonuments) { nb_monuments = nbMonuments; }

/*void  Partie::setNbEtablissements(int nbEtablissements)
{
  nb_etablissements = nbEtablissements;
}*/


// ----------------------------------------------------------------
// Constructors and destructors functions
// ----------------------------------------------------------------
Partie::Partie()
    : manche(0),
      num_de(1),
      nb_joueurs(2)//,
      //nb_monuments(4),
      //nb_etablissements(15)
      /* joueur_actif(new Joueur),
      joueurs(new Joueur[nb_joueurs])*/
{ 
}

Partie::~Partie() {}

// ----------------------------------------------------------------
// Methods
// ----------------------------------------------------------------
void Partie::initialisation()
{
  cout << "Bonjour, bienvenu dans le jeu MachiKoro" << endl;

  // TODO: A completer
  // Il faut recuperer l'extension ? Pour pouvoir initialiser les variables aux
  // bonnes valeurs
  int lectureExtension;
retry:  
  cout << "Entrez l'extension a laquelle vous voulez jouer \t0. Originale\t1. Marina \t2. GreenValley\t3. Deluxe"
       << endl;
  do
  {
      cout << "L'extension doit etre comprise entre 0 et 3" << endl;
      cin >> lectureExtension;

  } while (lectureExtension < 0 || lectureExtension > 3);
  jeu = new Jeu(Extensions[lectureExtension]);
  /*switch (lectureExtension)
  {
  case 0:
    setNbMonuments(4);       // TODO Vérifier le nb de monuments exact
    setNbEtablissements(15); // TODO Vérifier le nb de etablissements exact
    //jeu = new Jeu(lectureExtension);
    jeu = new Jeu(Extension::Aucune);
    break;
  case 1:
    setNbMonuments(4);       // TODO Vérifier le nb de monuments exact
    setNbEtablissements(15); // TODO Vérifier le nb de etablissements exact

    jeu = new Jeu(Extension::Marina);
    break;
  case 2:
    setNbMonuments(4);       // TODO Vérifier le nb de monuments exact
    setNbEtablissements(15); // TODO Vérifier le nb de etablissements exact

    jeu = new Jeu(Extension::GreenValley);
    break;
  case 3:
    setNbMonuments(4);       // TODO Vérifier le nb de monuments exact
    setNbEtablissements(15); // TODO Vérifier le nb de etablissements exact

    jeu = new Jeu(Extension::Deluxe);
    break;
  }*/

  cout << "Entrez le nombre de joueurs :" << endl;
  int lecture = 0;
  while (lecture < 2 || lecture > jeu->getNb_joueurs_MAX())
  {
      cout << "Le nombre de joueur doit etre compris entre 2 et " << jeu->getNb_joueurs_MAX() << endl;
      cin >> lecture;
  } 
  //cout << jeu->getEtablissementsDepart()[0]->getNbExemplaires();
  if ( (jeu->getEtablissementsDepart()[0]->getNbExemplaires()) < lecture) goto retry;// Si pas assez de cartes départ

  setNbJoueurs(lecture);

//Initialisation reserve
  reserve = new Reserve(*jeu);
//Initialisation joueur
  for(size_t i=0;i<getNbJoueurs();i++){
    joueurs1.push_back(new Joueur(jeu));
  }
}

void Partie::distribuer()
{
  // TODO: A completer
}

void Partie::joueur_next(){
  if (joueur_actif==joueurs1.size()-1)//Quand c'est le dernier joueur
    joueur_actif = 0;
  else
    joueur_actif++;
}

/* Joueur Partie::tour_joueur(Joueur joueur)
{
  int i = 0;
  while (i < getNbJoueurs() && getJoueurActif()!= joueur)
  {
    i++;
  }
  int indice = (i + 1) % getNbJoueurs();
  return getJoueurI(indice);
}
Etablissement* Partie::regarder_etablissements(Joueur joueur, Couleur couleur)
{
  //???
}


void Partie::application_regle_standards(Couleur couleur)
{
  // TODO: A completer
} */



void Partie::transaction_piece(Joueur* emetteur, Joueur*destinataire, int montant){
  if (montant>emetteur->getCompte())
    cout << "Erreur ! Le joueur " << emetteur->getPseudo() << " n'a pas de ressource suffisante pour effectuer la transaction.";
  else{
    emetteur->ajouterMontant(montant*(-1));
    destinataire->ajouterMontant(montant);
  }
}

void Partie::transaction_carte(Joueur* emetteur, Joueur*destinataire, const Etablissement* etab){
  if (destinataire->retirer_etablissement(etab))
    emetteur->ajouter_etablissement(etab);
}

void Partie::achat_carte(Joueur* joueur, Pile_Etablissement* pile_reserve) {
    if (pile_reserve->getEffectif()>0){
        if (pile_reserve->getEtablissement()->getPrix()<=joueur->getCompte()){
             joueur->ajouterMontant(0-pile_reserve->getEtablissement()->getPrix());
             joueur->ajouter_etablissement(pile_reserve->getEtablissement());
             pile_reserve->retirerCarte();
        }
        else cout<<"Prix de l'etablissement superieur au montant de votre compte !"<<endl;
    }
    else cout<<"La pile est vide !"<<endl;
}
//ACHAT MONUMENTS ??????????

void Partie::regarder_etablissements(Joueur* joueur, Couleur couleur) {

/*=======
void Partie::achat_carte(Joueur* joueur, Pile_Etablissement* pile){
  if (joueur->getCompte()>=pile->getPrix()){
    if (pile->retirerCarte(1)){
      joueur->ajouter_etablissement(pile->getEtablissement());
      cout << "Achat terminé !" << endl;
    }else{
      cout << "Plus de carte disponible !" << endl;
    }
  }else{
      cout << "Le joueur" << joueur->getId() << "n'a pas de ressource suffisante !" << endl;
  }
>>>>>>> d8489d4924454ca45983749775183e7466f36ea2*/
}