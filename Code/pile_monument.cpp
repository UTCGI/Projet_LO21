#include "pile_monument.h"

// Getters
const Monument* Pile_Monument::getMonument() const { return monument; }
unsigned int Pile_Monument::getEffectif() const { return effectif; }

// Constructors and Destructors functions
Pile_Monument::Pile_Monument(Monument* mo, unsigned int ef = 1)
    : monument(mo), effectif(ef){};

// Methods
void Pile_Monument::retirerCarte(unsigned int nb_cartes = 1) {
  if (nb_cartes > effectif)
    throw SetException("nombre de cartes a retirer trop eleve");
  else
    effectif -= nb_cartes;
}
void Pile_Monument::ajouterCarte(unsigned int nb_cartes = 1) {
  effectif += nb_cartes;
}

// Operators
void Pile_Monument::operator+(Pile_Monument& p) { effectif += p.getEffectif(); }

ostream& operator<<(ostream& f, Pile_Monument& pile) {
  f << "Pile de " << pile.getEffectif()
    << " exemplaire(s) de l'monument suivant :" << endl
    << endl
    << pile.getMonument() << endl;
  // Tobias : Tu veux vraiment afficher tout l'monument
  // ou juste afficher le nom ?
  // Pour afficher que le nom : pile.getMonument()->getNom()

  //<<endl<<pile.getMonument();
  return f;
}