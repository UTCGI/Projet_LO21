#include "jeu.h"
#include "pile_etablissement.h"

class Pioche {
    public:
// private:
  unsigned int nb_etablissements;
  unsigned int nb_piles;
  Pile_Etablissement* piles_etablissement;
// public:
  Pioche(const Jeu& jeu);
  unsigned int getNb_etablissements() const;
  unsigned int getNb_piles() const;
  Pile_Etablissement* getPiles_etablissement() const;
  void afficher()const;
  const Etablissement& getRandomEtablissement() const;
  unsigned int getIndexPile(const Etablissement& etablissement)const;
  void retirer_Etablissement(const Etablissement& etablissement, unsigned int quantite= 1);
  ~Pioche();
};

int testPioche();
