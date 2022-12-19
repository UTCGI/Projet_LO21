#include "pile_etablissement.h"

// Getters
const Etablissement* Pile_Etablissement::getEtablissement() const
{
    return etablissement;
}
unsigned int Pile_Etablissement::getEffectif() const { return effectif; }

// Constructors and Destructors functions
Pile_Etablissement::Pile_Etablissement(const Etablissement* et, unsigned int ef, unsigned int m)
    : etablissement(et), effectif(ef), minimum(m), montant_effet(et->getMontant()) {};

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

bool Pile_Etablissement::estPresqueVide()
{
    if (getEffectif() > getMinimum())
        return false;
    return true;
}

// Operators
Pile_Etablissement& Pile_Etablissement::operator+(Pile_Etablissement& p)
{
    effectif += p.getEffectif();
    return *this;
}


ostream& operator<<(ostream& f, const Pile_Etablissement& pile)
{
    f << "Pile de " << pile.getEffectif()
        << " exemplaire(s) de l'etablissement suivant :" << endl
        << endl
        << *(pile.getEtablissement()) << endl;
    return f;
}

ostream& operator<<(ostream& f, const vector<Pile_Etablissement*>& pile) //(*(pile.begin()))->getEffectif()
{
    int i = 1;
    for (auto p : pile) {//for *(pile.size());
        if (p->getEffectif() > p->getMinimum())
            f << "N°" << i << "      " << (*p) << endl;
        i++;
    }
    return f;
}
