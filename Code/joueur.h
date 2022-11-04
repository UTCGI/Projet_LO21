#ifndef JOUEUR_H
#define JOUEUR_H

#include <string.h>

#include "Main.h"

class Joueur{
    int id;
    char* pseudo;
    int de=1;
    int de_lance;
    Main main;
    int compte=3;

    public:
    Joueur();
    ~Joueur();
    int getNbDes();
    int getCompte();
    void ajouterMontant(int montant);
    bool victoire();
    int lancerDés();
};

#endif