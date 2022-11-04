#ifndef JOUEUR_H
#define JOUEUR_H

#include <string.h>

#include "Main.h"

class Joueur{
    int id;
    char* pseudo;
    int de;
    int de_lance;
    Main main;
    int compte;

    public:
    Joueur();
    ~Joueur();
    int getNbDes();
    int getCompte();
    void payer(int montant);
    void encaisser(int montant);
    bool victoire();
    int lancerDés();
};

#endif