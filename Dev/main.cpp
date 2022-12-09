#include <iostream>
#include "partie.h"
using namespace std;

void choix2(Partie &p){//Cette fonction traite achatcarte
    p.getReserve()->afficher();
    int choix = -1;
    while (true)
    {
        cout << "Faire votre choix" << endl;

        try
        { // Cette partie sert à détecter les erreurs eventuelles de saisie (Exemple : saisir une lettre à la place d'un nombre)
            cin >> choix;
        }
        catch (exception ex)
        {
            cin.clear();           // Reset failbit à 0
            cin.ignore(100, '\n'); // Vider buffer
            cout << "Erreur ! Ce que vous avez saisi n'est pas un nombre." << endl;
            choix = -1;
            continue;
        }
        if (choix<1 || choix >p.getReserve()->getNbPile()+1){
            cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
        }else{
            break;
        }
    }

    try{
    p.achat_carte(p.getJoueurActif(), *(p.getReserve()->getListeEtablissement()+choix-1));
    // Partie tester si trop de demande à piocher
    /* p.achat_carte(p.getJoueurActif(), *(p.getReserve()->getListeEtablissement()+choix-1));
    p.achat_carte(p.getJoueurActif(), *(p.getReserve()->getListeEtablissement()+choix-1));
    p.achat_carte(p.getJoueurActif(), *(p.getReserve()->getListeEtablissement()+choix-1));
    p.achat_carte(p.getJoueurActif(), *(p.getReserve()->getListeEtablissement()+choix-1));
    p.achat_carte(p.getJoueurActif(), *(p.getReserve()->getListeEtablissement()+choix-1));
    p.achat_carte(p.getJoueurActif(), *(p.getReserve()->getListeEtablissement()+choix-1)); */
    }
    catch (SetException& ex){
        cout << ex.getInfo();
    }
    p.getReserve()->afficher();
    cout << *p.getJoueurActif();
}

void menu(Partie &p)
{
    p.initialisation();
    int choix = -1;
    cin.exceptions(std::istream::failbit); // Activer module exception dans std::cin

    cout << "Bienvenue !" << endl;

    while (choix != 0)
    {

        cout << "Joueur en cours : " << p.getJoueurActif()->getId() << endl;

        cout << "Faire votre choix" << endl;

        // Partie Menu
        cout << "0\tQuitter" << endl;
        cout << "1\tPrendre une carte depuis la réserve" << endl;

        try
        { // Cette partie sert à détecter les erreurs eventuelles de saisie (Exemple : saisir une lettre à la place d'un nombre)
            cin >> choix;
        }
        catch (exception ex)
        {
            cin.clear();           // Reset failbit à 0
            cin.ignore(100, '\n'); // Vider buffer
            cout << "Erreur ! Ce que vous avez saisi n'est pas un nombre." << endl;
            choix = -1;
            continue;
        }

        switch (choix)
        {
        case 0:
            cout << "Au revoir" << endl;
            break;
        case 1:
            choix2(p);
            break;

        case 3:
            break;

        default: // Les nombres unbound
            cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            break;
        }
        cout << endl;
    }
}

int main()
{
    Partie p;
    menu(p);
    // A CONTINUER

    /* Jeu* j = new Jeu(Extension::Deluxe);//(Extension::Marina);//(Extension::GreenValley);// (Extension::Deluxe);
    cout << *j; */

    /* const Etablissement** e = j->getEtablissements();
     for(unsigned int i=0; i<15;i++)e[i]->afficher();
     return 0;*/
    // j->getEtablissementFromName("Marche de fruits et legumes")->afficher();

    // return EtablissementTest();
    // return MonumentTest();
}
