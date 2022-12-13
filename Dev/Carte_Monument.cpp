#include "Carte_Monument.h"

// Ces includes int été ajoutés pour le test
#include "buildfonctions.h"
// #include "jeu.h"
#include "monument.h"
// Getters
const Monument* Carte_Monument::getMonument() const { return monument; }

bool Carte_Monument::estConstruit() const { return construit; }

// Constructors and Destructors functions
Carte_Monument::Carte_Monument(const Monument* mo, bool construct)
    : monument(mo)
    , construit(construct) {};

// Methods
void Carte_Monument::construire() { construit = true; }

// Operators
ostream& operator<<(ostream& f, Carte_Monument& carte)
{
    if (carte.estConstruit()) {
        f << "Monument : " << carte.getMonument()->getNom() << endl
          << "Effet  : " << carte.getMonument()->getEffet() << endl
          << "Prix : " << carte.getMonument()->getPrix() << endl
          << "Ce monument est déjà construit. " << endl;
    } else {
        f << "Monument : " << carte.getMonument()->getNom() << endl
          << "Effet  : " << carte.getMonument()->getEffet() << endl
          << "Prix : " << carte.getMonument()->getPrix() << endl
          << "Ce monument n'est pas construit. " << endl
          << endl;
    }
    return f;
}

