#include <iostream>

#include "monument.h"

class Pile_Monument {
 private:
  const Monument *monument;
  unsigned int effectif;

 public:
  // Getters
  const Monument *getMonument() const;
  unsigned int getEffectif() const;

  // Constructors and Destructors functions
  Pile_Monument(Monument *mo, unsigned int ef = 1);
  ~Pile_Monument() = default;  // on ne doit pas supprimer le pointeur ?
  // Tobias : Pour moi non, on a pas besoin de supprimer le pointeur
  // Sauf si tu veux totalement supprimer la carte du jeu
  // Dans ce cas la il faut détruire la carte pointée

  // methods
  void retirerCarte(unsigned int nb_cartes = 1);
  void ajouterCarte(unsigned int nb_cartes = 1);

  // Operators
  void operator+(Pile_Monument &p);
};

ostream &operator<<(ostream &f, Pile_Monument &pile);
