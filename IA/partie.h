#ifndef PARTIE_H
#define PARTIE_H


#include "jeu.h"
#include "joueur.h"
#include "reserve.h"

class Partie {
  int manche;
  int num_de;
  int nb_joueurs;
  //SINGLETON
  int lectureExtension;
  //int nb_monuments; //inutile on les a deja dans jeu !
  //int nb_etablissements; //inutile on les a deja dans jeu !
  // Est ce qu'on a besoin de pointeurs ou pas ??
  //SINGLETON
  //static Jeu& jeu;
  int joueur_actif = 0;//Indice du joueur qui a la main
  vector<Joueur*> joueurs1;
  Reserve* reserve;

  int fonction_service_type(Type t, Joueur* j);//fonction_service_verte, réservée pour find_carte_des()

 public:
  // Getter functions
  int getManche() const;
  int getNumDe() const;
  int getNbJoueurs() const;
  //int getNbMonuments() const; //inutile on les a deja dans jeu !
  //int getNbEtablissements() const; //inutile on les a deja dans jeu !
  //SINGLETON
  //Jeu& getJeu() const;
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

  //Jeu* setJeu(Jeu* jeu);//inutile ?
  //Joueur* setJoueurActif(Joueur* joueur);//inutile
  //Joueur* setEnsenbleJoueurs(Joueur* EnsembreJoueurs);//inutile
  //Reserve* setReserve(Reserve* Reserve);//inutile
 
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
  void joueur_next(bool effet_parc_attration);

  /*A SUPPRIMER ????????????????????????????,
  SPECIFICATION : Partie::regarder_etablissements(Joueur joueur, Couleur
  couleur) Entree: Joueur joueur, Couleur couleur Sortie: Tableau
  d'établissements Objectif: Cette fonction renvoie tout les établissements que
  dispose le joueur selon la couleur passée en paramêtre.
  
  Etablissement* regarder_etablissements(Joueur joueur, Couleur couleur);*/

  /*A SUPPRIMER ????????????????????????????,
  SPECIFICATION : Partie::application_regle_standards(Couleur couleur)
      Entree: Couleur couleur
      Sortie: None
      Objectif: Cette fonction permet d'appliquer les règles ???
      Jsp trop ce que doit faire cette fonction ??
  
  void application_regle_standards(Couleur couleur);*/

  /*
  SPECIFICATION : Partie::application_regle_speciales(Pile pile_joueur)
      Entree: Pile pile_joueur
      Sortie: None
      Objectif: Cette fonction permet d'appliquer les règles ???
      Jsp trop ce que doit faire cette fonction ??
  */
//void achat_carte(Joueur* joueur, Pile_Etablissement* pile);

void transaction_piece(Joueur* emetteur, Joueur*destinataire, unsigned int montant);

void transaction_carte(Joueur* emetteur, Joueur*destinataire, const Etablissement* etab);

void echanger_cartes(Joueur* emetteur, Joueur* destinataire, const Etablissement* etab1, const Etablissement* etab2);

void find_carte_des(int des);//Sert à déterminer quelles cartes à en apporter du profit

int choix(const string& m1, int n = 0, int c = 0, const vector<Pile_Etablissement*>* p = nullptr, const string& m2 = "Choisir 0 pour quitter"); //"Choisir 0 pour quitter"

const vector<Pile_Etablissement*>*/*&*/ choixPile(const string& m1, const string& m2 = "Choisir 0 pour quitter", int cj = 0); //, int c=0);

bool achat_carte(Pile_Etablissement* pile_reserve);

//La raison pour la quelle j'ai choisi const Monument* monument_choisi comme paramètre au lieu d'une Carte_Monument
//est que l'on est pas censé à modifier aucune Carte_Monument sauf celle que le joueurActif possède. Càd on ne peut pas passer n'importe quelle Carte_Monument
bool construire_monument(const Monument* monument_choisi);

//void regarder_etablissements(Joueur* joueur, Couleur couleur);

};
#endif