#ifndef __RESERVE_H__
#define __RESERVE_H__

#include "pile_etablissement.h"
#include "jeu.h"
#include "miniville.h"
#include "etablissement.h"
#include "pioche.h"
#include <vector>

class Reserve{
    unsigned int nb_etablissements;
    unsigned int nb_piles;
    unsigned int nb_piles_max;
    //Pile_Etablissement** liste_etablissements;
    std::vector<Pile_Etablissement*> liste_etablissements;

    public:
    // Getters
    unsigned int getNbPile() const;
    unsigned int getNbEtablissements() const;
    unsigned int getNbPileMax() const;

    Pile_Etablissement** getListeEtablissement() const;

    // Constructors and Destructors
    // Constructeur pour les extensions
    Reserve(Jeu& j,Pioche& p);
    // constructeur pour le jeu de base
    Reserve(Jeu& j);
    ~Reserve();

    // Methods
    void retirer_etablissement(const Etablissement& etablissement, unsigned int quantite = 1);
    void ajouter_etablissement(const Etablissement& etablissement, unsigned int quantite = 1);
    void afficher()const;
};

ostream &operator<<(ostream &f, Reserve &carte);

void testReserve();



#endif
