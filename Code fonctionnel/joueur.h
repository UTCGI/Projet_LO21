#pragma once

#include <string>
#include "miniville.h"
#include "Carte_Monument.h"
#include "pile_etablissement.h"
#include "jeu.h"
#include <random>

class Joueur
{
  static int id;
  string pseudo;
  int de = 1;
  int de_lance;
  int compte = 3;
  int placement_StartUp = 0;
  /*   static const int max_joueurs = 4;
    static const int min_joueurs = 2; */
  // A faire Pile Monument
  std::vector<Carte_Monument *> monuments; // A discuter. Pas besoin de pile mais il faut autre chose
  std::vector<Pile_Etablissement *> pileRouge;
  std::vector<Pile_Etablissement *> pileBleu;
  std::vector<Pile_Etablissement *> pileVert;
  std::vector<Pile_Etablissement *> pileViolet;

public:
  Joueur(const Jeu* jeu);
  ~Joueur();

  // Getter
  int getNbDes() const;
  int getCompte() const;
  int getPlacement_StartUp() const;
  static int getNbMaxJoueurs();

  const vector<Carte_Monument *> &getMonuments() const { return monuments; }
  const vector<Pile_Etablissement *> &getPileRouge() const { return pileRouge; }
  const vector<Pile_Etablissement *> &getPileBleu() const { return pileBleu; }
  const vector<Pile_Etablissement *> &getPileVert() const { return pileVert; }
  const vector<Pile_Etablissement *> &getPileViolet() const { return pileViolet; }

  // Setter
  void setPseudo(string pseudo);
  void setPlacement_StartUp(int placement_StartUp);
  void setNbDes(int nbDe);
  void setCompte(int montant);

  // Autres méthodes
  void ajouter_etablissement(const Etablissement *e);
  void retirer_etablissement(const Etablissement *e);

  void ajouterMontant(int montant);
  int getNombreMonumentsConstruits();
  // bool victoire();
  int lancerDés();

  void printJoueur(ostream &f = std::cout) const;
};
ostream &operator<<(ostream &f, const Joueur &j);


