#ifndef RESERVE_H
#define RESERVE_H

#include "TypesEnum.h"
#include "pile.h"

class Reserve{
    Extension extension;

public:
    Reserve();
    ~Reserve();
    void retirer_carte(Pile pile);
};

#endif