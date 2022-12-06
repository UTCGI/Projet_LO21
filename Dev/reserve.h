#ifndef __RESERVE_H__
#define __RESERVE_H__

#include "pile_etablissement.h"
#include "jeu.h"
#include "miniville.h"
#include "etablissement.h"
#include "pioche.h"

class Reserve{
    // int nb_lignes;
    // int nb_colonnes;
    int nb_etablissements;
    int nb_piles;
    Pile_Etablissement* liste_etablissements;
    public:

    // Getters
    int getNbPile() const;
    int getNbEtablissements() const;

    // int getNbLignes() const;
    // int getNbColonnes() const;
    Pile_Etablissement* getListeEtablissement() const;

    // Constructors and Destructors
    // Constructeur pour les extensions
    Reserve(Pioche& p);
    // constructeur pour le jeu de base
    Reserve(Jeu& j);
    ~Reserve();

    // Methods
    void retirer_etablissement(const Etablissement& etablissement);
    void ajouter_etablissement(const Etablissement& etablissement);

};

ostream &operator<<(ostream &f, Reserve &carte);



#endif