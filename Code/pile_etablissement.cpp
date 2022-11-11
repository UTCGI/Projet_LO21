#include "pile_etablissement.h"

// Getters
const Etablissement* Pile_Etablissement::getEtablissement() const {
  return etablissement;
}
unsigned int Pile_Etablissement::getEffectif() const { return effectif; }

// Constructors and Destructors functions
Pile_Etablissement::Pile_Etablissement(Etablissement* et, unsigned int ef = 1)
    : etablissement(et), effectif(ef){};

// Methods
void Pile_Etablissement::retirerCarte(unsigned int nb_cartes = 1) {
  if (nb_cartes > effectif)
    throw SetException("nombre de cartes a retirer trop eleve");
  else
    effectif -= nb_cartes;
}
void Pile_Etablissement::ajouterCarte(unsigned int nb_cartes = 1) {
  effectif += nb_cartes;
}

// Operators
void Pile_Etablissement::operator+(Pile_Etablissement& p) {
  effectif += p.getEffectif();
}

ostream& operator<<(ostream& f, Pile_Etablissement& pile) {
  f << "Pile de " << pile.getEffectif()
    << " exemplaire(s) de l'etablissement suivant :" << endl
    << endl
    << pile.getEtablissement() << endl;
  // Tobias : Tu veux vraiment afficher tout l'etablissement
  // ou juste afficher le nom ?
  // Pour afficher que le nom : pile.getEtablissement()->getNom()

  //<<endl<<pile.getEtablissement();
  return f;
}