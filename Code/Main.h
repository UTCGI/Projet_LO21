#ifndef MAIN_H
#define MAIN_H

#include <string.h>

#include "monument.h"
#include "Main.h"
#include "etablissement.h"

class Main{

    Monument *monuments;
    Pile_Etablissement *etablissements;
    public:
    Main();
    ~Main();
};

#endif