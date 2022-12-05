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

int Partie::getNbMonuments() const { return nb_monuments; }

int Partie::getNbEtablissements() const { return nb_etablissements; }

Jeu *Partie::getJeu() const { return jeu; }

const Joueur *Partie::getJoueurActif() const { return joueurs1[joueur_actif]; }

Reserve *Partie::getReserve() const { return reserve; }
const vector<Joueur*>& Partie::getJoueurs() const {return joueurs1;}


// ----------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------

// ce n'est pas plutôt des void le type de retour des setters ?
int Partie::setManche(int nbManche) { manche = nbManche; }

int Partie::setNumDe(int nbDe) { num_de = nbDe; }

int Partie::setNbJoueurs(int nbJoueurs) { nb_joueurs = nbJoueurs; }

int Partie::setNbMonuments(int nbMonuments) { nb_monuments = nbMonuments; }

int Partie::setNbEtablissements(int nbEtablissements)
{
  nb_etablissements = nbEtablissements;
}


// ----------------------------------------------------------------
// Constructors and destructors functions
// ----------------------------------------------------------------
Partie::Partie()
    : manche(0),
      num_de(1),
      nb_joueurs(2),
      nb_monuments(4),
      nb_etablissements(15)
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
  cout << "Entrez le nombre de joueurs :" << endl;
  int lecture = 0;
  while (lecture < 2 || lecture > 4)
  {
    cin >> lecture;
  } 
  setNbJoueurs(lecture);

  // TODO: A completer
  // Il faut recuperer l'extention ? Pour pouvoir initialiser les varianles aux
  // bonnes valeurs
  int lectureExtention;
  cout << "Entrez l'extention à laquelle vous voulez jouer \t0. Originale\t1. Marina \t2. GreenValley\t3. Deluxe)"
       << endl;
  do
  {
    cin >> lectureExtention;

  } while (lectureExtention < 0 || lectureExtention > 3);
  switch (lectureExtention)
  {
  case 0:
    setNbMonuments(4);       // TODO Vérifier le nb de monuments exact
    setNbEtablissements(15); // TODO Vérifier le nb de etablissements exact

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
  }
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

Etablissement *Partie::regarder_etablissements(Joueur joueur, Couleur couleur)
{
  // TODO: A completer
}

void Partie::application_regle_standards(Couleur couleur)
{
  // TODO: A completer
} */
