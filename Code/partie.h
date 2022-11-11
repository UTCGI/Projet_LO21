#ifndef PARTIE_H
#define PARTIE_H

#include "TypesEnum.h"
#include "jeu.h"
#include "joueur.h"
#include "reserve.h"

class Partie {
  int manche;
  int num_de;
  int nb_joueurs;
  int nb_monuments;
  int nb_etablissements;
  // Est ce qu'on a besoin de pointeurs ou pas ??
  Jeu* jeu;
  Joueur* joueur_actif;
  Joueur* joueurs;
  Reserve* reserve;

 public:
  // Getter functions
  int getManche() const;
  int getNumDe() const;
  int getNbJoueurs() const;
  int getNbMonuments() const;
  int getNbEtablissements() const;
  Jeu* getJeu() const;
  Joueur* getJoueurActif() const;
  Joueur* getEnsenbleJoueurs() const;
  Joueur getJoueurI(const int i);
  Reserve* getReserve() const;

  // Setter functions
  int setManche(int nbManche);
  int setNumDe(int nbDe);
  int setNbJoueurs(int nbJoueurs);
  int setNbMonuments(int nbMonuments);
  int setNbEtablissements(int nbEtablissements);
  Jeu* setJeu(Jeu* jeu);
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
  Joueur tour_joueur(Joueur joueur);

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
  void application_regle_speciales(Pile pile_joueur);

  /*
  SPECIFICATION : Partie::transaction_piece(Joueur emeteur, Joueur destinataire,
  int montant) Entree: Joueur emeteur, Joueur destinataire, int montant Sortie:
  None Objectif: Cette fonction effectue une transaction entre le joueur emeteur
  et le joueur destinataire Le joueur emeteur perd une somme correspondante au
  montant et le joueur destinataire gagne cette somme.
  */
  void transaction_piece(Joueur& emeteur, Joueur& destinataire, int montant);

  /*
  SPECIFICATION : Partie::transaction_carte(Joueur emeteur, Joueur destinataire,
  Pile pile) Entree: Joueur emeteur, Joueur destinataire, Pile pile Sortie: None
      Objectif: Cette fonction effectue une transaction entre le joueur emeteur
  et le joueur destinataire Le joueur emeteur perd la carte représentée dans la
  pile et le joueur destinataire la gagne.
  */
  void transaction_carte(Joueur& emeteur, Joueur& destinataire, Pile& pile);

  /*
  SPECIFICATION : Partie::achat_carte(Joueur joueur, Pile pile_reserve)
      Entree: Joueur joueur, Pile pile_reserve
      Sortie: None
      Objectif: Cette fonction permet à un joueur d'acheter une carte.
      Pour cela, elle retirera une carte dans la pile_reserve,
      qu'elle ajoutera ensuite dans la pile correpondante au joueur
      Et retirera la somme équivalente au montant de la carte demandée.
  */
  void achat_carte(Joueur& joueur, Pile& pile_reserve);
};

#endif