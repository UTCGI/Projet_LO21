#ifndef PARTIE_H
#define PARTIE_H

#include "joueur.h"
#include "jeu.h"
#include "reserve.h"

class Partie{
    int manche;
    Joueur *joueur_arctif;
    int num_de;
    Jeu* jeu;
    Joueur *joueurs;
    Reserve *reserve;
    int nb_joueurs;
    int nb_monuments;
    int nb_etablissements;
    public:
    Partie();
    ~Partie();
};

#endif