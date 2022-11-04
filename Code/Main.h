#ifndef Main_H
#define Main_H

#include <string.h>

#include "monument.h"
#include "Main.h"
#include "etablissement.h"

class Main{

    Monument *monuments;
    Etablissement *etablissements;
    public:
    Main();
    ~Main();
};

#endif