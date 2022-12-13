#include "pile_etablissement.h"

// Getters
const Etablissement* Pile_Etablissement::getEtablissement() const
{
    return etablissement;
}
unsigned int Pile_Etablissement::getEffectif() const { return effectif; }

// Constructors and Destructors functions
Pile_Etablissement::Pile_Etablissement(const Etablissement* et, unsigned int ef)
    : etablissement(et)
    , effectif(ef) {};

// Methods
bool Pile_Etablissement::retirerCarte(unsigned int nb_cartes)
{
    if (nb_cartes > effectif) {
        throw SetException("nombre de cartes a retirer trop eleve");
        return false;
    } else {
        effectif -= nb_cartes;
        return true;
    }
}


void Pile_Etablissement::ajouterCarte(unsigned int nb_cartes)
{
    if (nb_cartes < 0)
        throw SetException(
            "Il n'est pas possible d'ajouter un nombre de carte négatif");
    else
        effectif += nb_cartes;
}

// Operators
Pile_Etablissement& Pile_Etablissement::operator+(Pile_Etablissement& p)
{
    effectif += p.getEffectif();
    return *this;
}


ostream& operator<<(ostream& f, Pile_Etablissement& pile)
{
    f << "Pile de " << pile.getEffectif()
      << " exemplaire(s) de l'etablissement suivant :" << endl
      << endl
      << *(pile.getEtablissement()) << endl;
    return f;
}
