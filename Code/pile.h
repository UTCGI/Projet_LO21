#ifndef PILE_H
#define PILE_H

#include "TypesEnum.h"


class Pile{
    char* nom;
    char* effet;
    int cout;
    int num_de;
    Type type;
    int nb_pieces;
    int effectif;
    Type type_effet_vert;
    Couleur color;
    public:
    Pile();
    ~Pile();

};



#endif