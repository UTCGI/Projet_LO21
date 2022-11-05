#ifndef JOUEUR_H
#define JOUEUR_H

#include <string.h>

#include "Main.h"

class Joueur{
    int id;
    char* pseudo;
    int de=1;
    int de_lance;
    int compte=3;
    int placement_StartUp;

    public:
    Joueur();
    ~Joueur();
    int getNbDes() const;
    int getCompte() const;
    int getPlacement_StartUp() const;
    void ajouterMontant(int montant);
    bool victoire();
    int lancerDés();
};

#endif
