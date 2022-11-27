#pragma once
#include <iostream>

#include "etablissement.h"

class Pile_Etablissement {
 private:
  const Etablissement *etablissement;
  unsigned int effectif;

 public:
  // Getters
  const Etablissement *getEtablissement() const;
  unsigned int getEffectif() const;

  // Constructors and Destructors functions
  Pile_Etablissement(const Etablissement *et, unsigned int ef = 1);
  ~Pile_Etablissement() = default;  // on ne doit pas supprimer le pointeur ?
  // Tobias : Pour moi non, on a pas besoin de supprimer le pointeur
  // Sauf si tu veux totalement supprimer la carte du jeu
  // Dans ce cas la il faut détruire la carte pointée

  // methods
  void retirerCarte(unsigned int nb_cartes = 1);
  void ajouterCarte(unsigned int nb_cartes = 1);

  // Operators
  void operator+(Pile_Etablissement &p);
};

ostream &operator<<(ostream &f, Pile_Etablissement &pile);
