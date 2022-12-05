#ifndef __RESERVE_H__
#define __RESERVE_H__

#include "pile_etablissement.h"
#include "jeu.h"
#include "miniville.h"
class Reserve{
    int nb_lignes;
    int nb_colonnes;
    Pile_Etablissement* Grille[];
    public:

    // Getters
    int getNbLignes() const;
    int getNbColonnes() const;
    Pile_Etablissement* getGrille() const;

    // Constructors and Destructors
    Reserve(Jeu& j);
    ~Reserve();

    // Methods
    Reserve retirer_etablissement(Pile_Etablissement* etablissement);


};

ostream &operator<<(ostream &f, Reserve &carte);



#endif