#include <iostream>
#include "etablissement.h"
#include <string>

int main()
{
    const string& txt = "Pendant le tour de n'importe quel joueur recevez une piece de la banque.";
    Etablissement e0=Etablissement("Ferme",txt,Couleur::bleu,1,2,Type::agriculture,1);
    cout<<&e0<<endl;
    return 0;
};
