#include <iostream>
#include "partie.h"
using namespace std;

void menu(Partie& p){
    int choix = -1;
    bool initialise = false;
    cin.exceptions(std::istream::failbit);//Activer module exception dans std::cin

    cout << "Bienvenue !" << endl;

    while (choix != 0) {
        if (initialise) { 
            cout << "Joueur en cours : " << p.getJoueurActif()->getId() << endl;
            break;
        }
        else {
            cout << "Faire votre choix" << endl;

            //Partie Menu
            cout << "0\tQuitter" << endl;
            cout << "1\tInitialisation" << endl;
            cout << "2\tPrendre une carte depuis la réserve" << endl;
            //cout << "2\tInitialisation" << endl;



            try {//Cette partie sert à détecter les erreurs eventuelles de saisie (Exemple : saisir une lettre à la place d'un nombre)
                cin >> choix;
            }
            catch (exception ex) {
                cin.clear();// Reset failbit à 0
                cin.ignore(100, '\n');// Vider buffer
                cout << "Erreur ! Ce que vous avez saisi n'est pas un nombre." << endl;
                choix = -1;
                continue;
            }

            if (choix)


                switch (choix)
                {
                case 0:
                    cout << "Au revoir" << endl;
                    break;
                case 1:
                    cout << "Vous avez choisi -- Initialisation" << endl;
                    p.initialisation();
                    initialise = true;
                    break;
                case 2:
                    cout << *p.getReserve();
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

}

int main()
{
    Partie p;
    menu(p);
    //A CONTINUER

    /* Jeu* j = new Jeu(Extension::Deluxe);//(Extension::Marina);//(Extension::GreenValley);// (Extension::Deluxe);
    cout << *j; */

   /* const Etablissement** e = j->getEtablissements();
    for(unsigned int i=0; i<15;i++)e[i]->afficher();
    return 0;*/
    //j->getEtablissementFromName("Marche de fruits et legumes")->afficher();

 //return EtablissementTest();
//return MonumentTest();
}
