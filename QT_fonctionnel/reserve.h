#include "pile_etablissement.h"
#include "jeu.h"
class Reserve {
 private:
  /* unsigned int nb_piles;
  unsigned int nbmax_piles; */
  vector<Pile_Etablissement*> carteBase;
  vector<Pile_Etablissement*> carteSpeciale;

 public:
  Reserve(Jeu& jeu);
  const vector<Pile_Etablissement*>& getCarteBase() const;
  const vector<Pile_Etablissement*>& getCarteSpeciale() const;
  void retirer_etablissement(Pile_Etablissement* etablissement);
  void printReserve(ostream& f = std::cout) const;                  
};

ostream& operator<<(ostream& f, const Reserve& r);
