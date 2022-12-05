
#include "carte_monument.h"

CarteMonument::CarteMonument(Monument* monument)
    : monument(monument), construit(0) {}

// Getters
bool CarteMonument::estConstruit() const { return construit; }

// Methods
void CarteMonument::construire() { construit = 1; }