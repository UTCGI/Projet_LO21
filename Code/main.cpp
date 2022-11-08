#include <iostream>
#include "pile_etablissement.h"
#include <string>

int main()
{
    /* cr�ation et actualisation d'une pile d'�tablissements*/
    const string& txt = "Pendant le tour de n'importe quel joueur recevez une piece de la banque.";
    Etablissement e0=Etablissement("Ferme",txt,Couleur::bleu,1,2,Type::agriculture,1);
    Pile_Etablissement p0=Pile_Etablissement(&e0,6);
    p0.retirerCarte(1);
    cout<<p0;
    return 0;
};
