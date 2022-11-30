#include "pile_etablissement.h"

// Getters
const Etablissement* Pile_Etablissement::getEtablissement() const {
  return etablissement;
}
unsigned int Pile_Etablissement::getEffectif() const { return effectif; }

// Constructors and Destructors functions
Pile_Etablissement::Pile_Etablissement(const Etablissement* et, unsigned int ef)
    : etablissement(et), effectif(ef){};

// Methods
void Pile_Etablissement::retirerCarte(unsigned int nb_cartes) {
  if (nb_cartes > effectif)
    throw SetException("nombre de cartes a retirer trop eleve");
  else
    effectif -= nb_cartes;
}
void Pile_Etablissement::ajouterCarte(unsigned int nb_cartes) {
  if (nb_cartes < 0)
    throw SetException(
        "Il n'est pas possible d'ajouter un nombre de carte négatif");
  else
    effectif += nb_cartes;
}

// Operators
Pile_Etablissement& Pile_Etablissement::operator+(Pile_Etablissement& p) {
  effectif += p.getEffectif();
  return *this;
}

ostream& operator<<(ostream& f, Pile_Etablissement& pile) {
  f << "Pile de " << pile.getEffectif()
    << " exemplaire(s) de l'etablissement suivant :" << endl
    << endl
    << *(pile.getEtablissement()) << endl;
  return f;
}

/* int main_test_pile_etablissement() {
  Jeu* j = new Jeu(Extension::Aucune);
  const Etablissement** listeE =
      new const Etablissement*[j->getNbEtablissements()];
  buildetablissement(listeE, Extension::Aucune);
  cout << (listeE[1])->getNom() << endl;
  for (int i = 0; i < j->getNbMonuments(); i++) {
    Pile_Etablissement* p = new Pile_Etablissement((listeE[i]), i);

    cout << *p;
    try {
      p->ajouterCarte(1);
      cout << *p;
      p->retirerCarte(2);
      cout << *p;

    } catch (const SetException e) {
      cout << e.getInfo() << endl;
    }
  }

  Pile_Etablissement* p1 = new Pile_Etablissement((listeE[2]), 2);
  Pile_Etablissement* p2 = new Pile_Etablissement((listeE[2]), 4);
  Pile_Etablissement& p3 = *p2;
  Pile_Etablissement& p4 = *p1;
  cout << p3;
  cout << p4;
  Pile_Etablissement& p = p4 + p3;
  cout << p;

  return 0;
} */
