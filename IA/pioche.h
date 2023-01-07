#include "jeu.h"
#include "pile_etablissement.h"

class Pioche {
    private:
    unsigned int nb_etablissements;
    unsigned int nb_piles;
    Pile_Etablissement* piles_etablissement;
    public:
    Pioche():nb_etablissements(0),nb_piles(0),piles_etablissement(nullptr){};
    Pioche(const Jeu& jeu);
    unsigned int getNb_etablissements() const;
    unsigned int getNb_piles() const;
    Pile_Etablissement* getPiles_etablissement() const;
    void afficher() const;
    const Etablissement& getRandomEtablissement() const; // fonction de service
    unsigned int getIndexPile(const Etablissement& etablissement) const; // fonction de service
    void retirer_Etablissement(const Etablissement& etablissement, unsigned int quantite = 1); // fonction de service
    const Etablissement& retirerRandomEtablissement();
    ~Pioche();
};
