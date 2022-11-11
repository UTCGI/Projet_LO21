#include <iostream>

#include "etablissement.h"

class Pile_Etablissement {
 private:
  const Etablissement* etablissement;
  unsigned int effectif;

 public:
  void retirerCarte(unsigned int nb_cartes = 1) {
    if (nb_cartes > effectif)
      throw SetException("nombre de cartes a retirer trop eleve");
    else
      effectif -= nb_cartes;
  }
  void ajouterCarte(unsigned int nb_cartes = 1) { effectif += nb_cartes; }
  const Etablissement* getEtablissement() const { return etablissement; }
  unsigned int getEffectif() const { return effectif; }
  ~Pile_Etablissement() = default;  // on ne doit pas supprimer le pointeur ?
  Pile_Etablissement(Etablissement* et, unsigned int ef = 1)
      : etablissement(et), effectif(ef){};
  void operator+(Pile_Etablissement& p) { effectif += p.getEffectif(); }
};

ostream& operator<<(ostream& f, Pile_Etablissement& pile) {
  f << "Pile de " << pile.getEffectif()
    << " exemplaire(s) de l'etablissement suivant :" << endl
    << endl
    << pile.getEtablissement() << endl;
  //<<endl<<pile.getEtablissement();
  return f;
};
