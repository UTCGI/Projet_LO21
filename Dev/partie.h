#ifndef PARTIE_H
#define PARTIE_H


#include "jeu.h"
#include "joueur.h"
#include "reserve.h"

class Partie {
  int manche;
  int num_de;
  int nb_joueurs;
  //int nb_monuments; //inutile on les a deja dans jeu !
  //int nb_etablissements; //inutile on les a deja dans jeu !
  // Est ce qu'on a besoin de pointeurs ou pas ??
  Jeu* jeu;
  int joueur_actif = 0;//Indice du joueur qui a la main
  vector<Joueur*> joueurs1;
  Reserve* reserve;

 public:
  // Getter functions
  int getManche() const;
  int getNumDe() const;
  int getNbJoueurs() const;
  //int getNbMonuments() const; //inutile on les a deja dans jeu !
  //int getNbEtablissements() const; //inutile on les a deja dans jeu !
  Jeu* getJeu() const;
    Joueur* getJoueurActif() ;
  //Joueur* getEnsenbleJoueurs() const;
  //Joueur getJoueurI(const int i) const; // C'EST QUOI ?
  Reserve* getReserve() const;
  const vector<Joueur*>& getJoueurs() const;


  // Setter functions
  void setManche(int nbManche);
  void setNumDe(int nbDe);//inutile ?
  void setNbJoueurs(int nbJoueurs);
  //void setNbMonuments(int nbMonuments); //inutile on les a deja dans jeu !
  //void setNbEtablissements(int nbEtablissements); //inutile on les a deja dans jeu !
  Jeu* setJeu(Jeu* jeu);//inutile ?
  Joueur* setJoueurActif(Joueur* joueur);
  Joueur* setEnsenbleJoueurs(Joueur* EnsembreJoueurs);
  Reserve* setReserve(Reserve* Reserve);
  // Constructors and destructors functions
  /*
  SPECIFICATION : Partie::Partie()
      Entree: None
      Sortie: None
      Objectif: Cette fonction à pour but d'initialiser la partie
      Elle devra initialiser chaque attributs de la classe partie avec des
  valeurs par default.
  */
  Partie();

  /*
  SPECIFICATION : Partie::~Partie()
      Entree: None
      Sortie: None
      Objectif: Cette fonction à pour but de détruire la partie.
      Pour cela, elle libérera les joueurs, jeu et réserves allouées
  dynamiquement.
  */
  ~Partie();

  // Methods
  /*
  SPECIFICATION : Partie::initialisation()
      Entree: None
      Sortie: None
      Objectif: ??? Cette fonction est elle vraiment utilise ?? puisque
  l'initialisation se faire déjà dans le construicteur de la classe partie. A
  vérifier
      -> Si elle est vraiment utile, je n'ai pas compris ce qu'elle devais
  faire.
  */
  void initialisation();

  /*
  SPECIFICATION : Partie::distribuer()
      Entree: None
      Sortie: None
      Objectif: Cette fonction distribueras les cartes de base dans les piles
  des joueurs au début de la partie A savoir : La ferme et Le champ de blé
  */
  void distribuer();

  /*
  SPECIFICATION : Partie::tour_joueur(Joueur joueur)
      Entree: Joueur joueur
      Sortie: Retourne le joueur suivant
      Objectif: Cette fonction revoie le joueur suivant du joueur passé en
  argument Elle permet de passer d'un joueur à l'autre.
  */
  void joueur_next();

  /*
  SPECIFICATION : Partie::regarder_etablissements(Joueur joueur, Couleur
  couleur) Entree: Joueur joueur, Couleur couleur Sortie: Tableau
  d'établissements Objectif: Cette fonction renvoie tout les établissements que
  dispose le joueur selon la couleur passée en paramêtre.
  */
  Etablissement* regarder_etablissements(Joueur joueur, Couleur couleur);

  /*
  SPECIFICATION : Partie::application_regle_standards(Couleur couleur)
      Entree: Couleur couleur
      Sortie: None
      Objectif: Cette fonction permet d'appliquer les règles ???
      Jsp trop ce que doit faire cette fonction ??
  */
  void application_regle_standards(Couleur couleur);

  /*
  SPECIFICATION : Partie::application_regle_speciales(Pile pile_joueur)
      Entree: Pile pile_joueur
      Sortie: None
      Objectif: Cette fonction permet d'appliquer les règles ???
      Jsp trop ce que doit faire cette fonction ??
  */
void transaction_piece(Joueur* emetteur, Joueur*destinataire, int montant);

void transaction_carte(Joueur* emetteur, Joueur*destinataire, const Etablissement* etab);
};
#endif