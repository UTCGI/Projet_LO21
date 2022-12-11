#include <iostream>
#include "partie.h"
using namespace std;

bool choix2(Partie &p)
{ // Cette fonction traite achatcarte
    p.getReserve()->afficher();
    cout << "Choisir 0 pour quitter" <<endl;
    int choix = -1;
    bool etatAchat = false; // Drapeau, pour voir si l'achat a réussi
    bool quitter;
retry:
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
        if (choix == 0)
        {
            quitter = true;
            break;
        }

        else if (choix < 1 || choix > p.getReserve()->getNbPile() + 1)
        {
            cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
        }
        else
        {
            quitter = false;
            break;
        }
    }

    if (!quitter)
    {
        try
        {
            etatAchat = p.achat_carte(*(p.getReserve()->getListeEtablissement() + choix - 1));
        }
        catch (SetException &ex)
        {
            cout << ex.getInfo();
        }

        // Si achat échoué, donne encore une fois
        if (!etatAchat)
            goto retry;

        p.getReserve()->afficher();

        // cout << *p.getJoueurActif();
        p.getJoueurActif()->printJoueurConcise(cout);

        cout << "Compte après achat :  " << p.getJoueurActif()->getCompte() << endl
             << endl;

        p.joueur_next(); // changer de joueur, un peu arbitaire de laisser juste cette ligne pour l'instant mais suffit pour voir les résultats attendus
    }

    return quitter;
}

size_t choix3(Partie &p)
{ // Cette fonction traite achat monument

    cout << "Monument" << endl
         << endl;
    int count = 1;
    cout << "  0 : Quitter" << endl;
    for (auto i : p.getJoueurActif()->getMonuments())
        cout << "  " << count++ << " : " << i->getMonument()->getNom() << "  Construit ? :  " << i->estConstruit() << endl;

    int choix = -1;
    bool etatAchat = false;
    bool quitter;

retry:
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
        if (choix == 0)
        {
            quitter = true;
            break;
        }
        else if (choix < 1 || choix > p.getJoueurActif()->getMonuments().size())
        {
            cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
        }
        else
        {
            quitter = false;
            break;
        }
    }

    if (!quitter) // Construction normale
    {
        try
        {
            etatAchat = p.construire_monument(p.getJoueurActif()->getMonuments()[choix - 1]->getMonument());
        }
        catch (SetException &ex)
        {
            cout << ex.getInfo();
        }

        if (!etatAchat) // Si achat échoué, donne encore une fois
            goto retry;

        // cout << *p.getJoueurActif();
        p.getJoueurActif()->printJoueurConcise(cout);

        cout << "Compte après achat :  " << p.getJoueurActif()->getCompte() << endl
             << endl;
        if (p.getJoueurActif()->victoire())
        {
            cout << "Bravo ! Vous avez gagne !" << endl;
            return 1; // 1 : Fin de partie
        }
        else
        {
            p.joueur_next(); // changer de joueur, un peu arbitaire de laisser juste cette ligne pour l'instant mais suffit pour voir les résultats attendus
            return 0;        // 0 : Cas normal
        }
    }
    else          // Si l'utilisateur choisi de ne pas en construire un
        return 2; // Reçu par menu pour redonner un choix
}

void lancer(Partie &p)
{
    int des;
    if (p.getJoueurActif()->getNbDes() == 1)
    {
        des = p.getJoueurActif()->lancerDes(1);
    }
    else
    {
        int choix = -1;
        while (true)
        {
            cout << "Combien de dès vous voulez lancer ?" << endl;

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

            if (choix < 1 || choix > p.getJoueurActif()->getNbDes())
            {
                cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            }
            else
            {
                break;
            }
        }
        des = p.getJoueurActif()->lancerDes(choix);
    }
    cout << "Le dès obtenu est :  " << des << endl;

    p.find_carte_des(des); // Trouver les cartes à appliquer effet
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
        cout << "Montant avant : " << p.getJoueurActif()->getCompte() << endl;

        lancer(p); // Le menu qui traite le lancement de dès

        cout << "Montant après : " << p.getJoueurActif()->getCompte() << endl;
    revenir:
        cout << "Faire votre choix" << endl;
        // Partie Menu
        cout << "0\tQuitter" << endl;
        cout << "1\tPasser mon tour" << endl;
        cout << "2\tPrendre une carte depuis la réserve" << endl;
        cout << "3\tConstruire un monument" << endl;

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
            p.joueur_next();
            break;
        case 2:
            if(choix2(p)) goto revenir;
            break;

        case 3:
            switch (choix3(p))
            {
            case 1:
                choix = 0; // Si qqn gagne, partie terminée
            case 2:
                goto revenir; // Si quitter, rééssayer
            }
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

    // Jeu * j = new Jeu;//(Extension::Deluxe);//(Extension::Marina);//(Extension::GreenValley);// (Extension::Deluxe);
    // cout << *j;

    /* const Etablissement** e = j->getEtablissements();
     for(unsigned int i=0; i<15;i++)e[i]->afficher();
     return 0;*/
    // j->getEtablissementFromName("Marche de fruits et legumes")->afficher();

    // return EtablissementTest();
    // return MonumentTest();
}
