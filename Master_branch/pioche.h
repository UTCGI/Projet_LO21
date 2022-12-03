#include "jeu.h"
#include "pile_etablissement.h"

class Pioche {
 private:
  *Pile_Etablissement[] piles_etablissement;
  unsigned int nb_etablissements;
  unsigned int nb_piles;
 public:
  Pioche(const Jeu& jeu);
  unsigned int getNb_etablissements() const;
  unsigned int getNb_piles() const;
  void afficher()const;
  const Etablissement& getRandomEtablissement() const;
  unsigned int getIndexPile(const Etablissement& etablissement);
  void retirer_Etablissement(const Etablissement& etablissement, unsigned int quantité= 1);
  ~Pioche();
}

int testPioche();
