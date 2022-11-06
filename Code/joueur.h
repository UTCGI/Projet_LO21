#ifndef JOUEUR_H
#define JOUEUR_H

#include <string.h>
#include <random>

#include "Main.h"

class Joueur{
    int id;
    char* pseudo;
    int de=1;
    int de_lance;
    int compte=3;
    int placement_StartUp;
    static const int max_joueurs = 4;
    static const int min_joueurs = 2;
    Monument* monuments[nb_monuments];
    friend Partie;
    public:
    Joueur();
    ~Joueur();
    int getNbDes() const;
    int getCompte() const;
    static int getNbMaxJoueurs();
    static int getNbMaxJoueurs();
    int setNbDes(int nbDe);
    int setCompte(int montant);
    int getPlacement_StartUp() const;
    void ajouterMontant(int montant);
    bool victoire();
    int lancerDés();
};

#endif
