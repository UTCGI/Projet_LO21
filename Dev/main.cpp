#include <iostream>
#include "partie.h"
using namespace std;

void menu(Partie& p){
    int choix = -1;
    cin.exceptions(std::istream::failbit);//Activer module exception dans std::cin

    cout << "Bienvenue !" << endl;

    while (choix!=0){
        cout << "Faire votre choix" << endl;

        //Partie Menu
        cout << "0\tQuitter" << endl;
        cout << "1\tInitialisation" << endl;


        try{//Cette partie sert à détecter les erreurs eventuelles de saisie (Exemple : saisir une lettre à la place d'un nombre)
            cin >> choix;
        }catch (exception ex){
            cin.clear();// Reset failbit à 0
            cin.ignore(100, '\n');// Vider buffer
            cout << "Erreur ! Ce que vous avez saisi n'est pas un nombre." << endl;
            choix = -1;
            continue;
        }

        if (choix )


        switch (choix)
        {
        case 0: 
            cout << "Au revoir" << endl;
            break;
        case 1:
            cout << "Vous avez choisi -- Initialisation" << endl;
            p.initialisation();
            break;
        case 2:
            break;
        case 3:
            break;
        
        default:// Les nombres unbound
            cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            break;
        }
        cout << endl;
    }

}

int main()
{   
    cout << "ICI";
    Partie p;
    testPioche();
    Jeu j = Jeu(Extension::Aucune);
    Pioche pioche = Pioche(j);
    // menu(p);
    return 0;
    // return 0;
 //return EtablissementTest();
//return MonumentTest();
}
