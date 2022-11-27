#include "reserve.h"

Reserve::Reserve(Jeu &jeu)
{
    /* switch (extension)
    {
    case Extension::Aucune:
        nombreCartes_tas = 6;
        break;

    default:
        nombreCartes_tas = 6;
        break;
    } */

    for (auto i : jeu.getEtablissements())
        carteBase.push_back(new Pile_Etablissement(i, 6));

    for (auto i : jeu.getEtablissementsSP())
        carteSpeciale.push_back(new Pile_Etablissement(i, 4));
}

const vector<Pile_Etablissement*>& Reserve::getCarteBase() const{
    return carteBase;
}
const vector<Pile_Etablissement*>& Reserve::getCarteSpeciale() const{
    return carteSpeciale;
}

void Reserve::retirer_etablissement(Pile_Etablissement *etablissement)
{
    etablissement->retirerCarte();
}

void Reserve::printReserve(ostream& f) const{
    for (Pile_Etablissement* i : carteBase)
        f<<*i<<endl;
    for (Pile_Etablissement* i : carteSpeciale)
        f<<*i<<endl;
} 

ostream& operator<<(ostream& f, const Reserve& r) {
    r.printReserve(f);
    //f << endl;
    return f;
}