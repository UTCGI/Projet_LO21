#include <clocale>
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

    }

    return quitter;
}

size_t choix3(Partie &p)
{ // Cette fonction traite achat monument

    cout << "Monument" << endl
         << endl;
    int count = 1;
    for (auto i : p.getJoueurActif()->getMonuments()){
        cout << "\t" << count++;
        cout.width(30);
        cout << i->getMonument()->getNom(); if (i->estConstruit() == 0) cout << " NON"; else cout << "    "; cout << " construit";
        cout.width(20);
        cout << "Prix : " <<i->getMonument()->getPrix() << endl;
    }
    cout << endl;
    cout << "Choisir 0 pour quitter" << endl;
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
            cout << "Bravo ! Vous avez gagné !" << endl;
            return 1; // 1 : Fin de partie
        }
        else
        {
            return 0;        // 0 : Cas normal
        }
    }
    else          // Si l'utilisateur choisi de ne pas en construire un
        return 2; // Reçu par menu pour redonner un choix
}

bool lancer(Partie &p)
{
    bool effet_tour_radio_applicable = true;

    int des;
    int des2;
    int resultat; //Utile pour effets spéciaux
again:
    des2 = 0;
    resultat = 0;
    if (p.getJoueurActif()->getNbDes() == 1)
    {
        des = p.getJoueurActif()->lancerDes();
    }
    else
    {
        int choix = -1;
        while (true)
        {
            cout << "Combien de dés voulez-vous lancer ?" << endl; 
            cout << "Le nombre de dés doit être compris entre 1 et 2" << endl;


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

            if (choix < 1 || choix > 2)
            {
                cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            }
            else
            {
                break;
            }
        }
        des = p.getJoueurActif()->lancerDes();
        if (choix==2){
            des2 = p.getJoueurActif()->lancerDes();
        }
    }
    resultat = des+des2;
    cout << "Le dé obtenu est :  " << resultat << endl;//getNumDe()
    
    
    //Effet tour radio
    if (effet_tour_radio_applicable&&p.getJoueurActif()->getEffet_tour_radio()){
        cout << "Vous voulez relancer ? Taper 1 si oui, 0 sinon" << endl;
        int choix;
        cin >> choix;
        if (choix==1){ 
            effet_tour_radio_applicable = false;//Effet applicable une fois par tour
            goto again;
        }
    }
    
    //Effet port
    if (p.getJoueurActif()->getEffet_port() && (resultat)>=10){
        cout << "Vous voulez ajouter 2 à au résultat obtenu ? Taper 1 si oui, 0 sinon" << endl;
        int choix;
        cin >> choix;
        if (choix==1){ 
            resultat += 2;
        }
    }


    p.find_carte_des(resultat); // Trouver les cartes à appliquer effet
    
    //Effet parc d'attaction
    if (p.getJoueurActif()->getEffet_parc_attaction())
        return des==des2?true:false;
    else
        return false;
}

void menu(Partie &p)
{
    p.initialisation();
    int choix = -1;
    bool effet_parc_attraction = false;
    cin.exceptions(std::istream::failbit); // Activer module exception dans std::cin

    cout << endl << "Bienvenue !" << endl;

    while (choix != 0)
    {
        cout << "Joueur en cours : " << p.getJoueurActif()->getId() << endl;
        cout << "Montant AVANT : " << p.getJoueurActif()->getCompte() << endl;

        //cout << "\tCombien de dés souhaitez-vous lancer ?" << endl;
        effet_parc_attraction = lancer(p); // Le menu qui traite le lancement de dès
        cout << "Compte de J" << p.getJoueurActif()->getId() << " : " << p.getJoueurActif()->getCompte() << endl;
    revenir:
        cout << "Faire votre choix" << endl;
        // Partie Menu
        cout << "0\tQuitter" << endl;
        cout << "1\tPasser mon tour" << endl;
        cout << "2\tAcheter une carte de la réserve" << endl;
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
            cout << endl << "Au revoir" << endl;
            break;
        case 1:
            //Effet aéroport
            if (p.getJoueurActif()->getEffet_aeroport()){ p.getJoueurActif()->ajouterMontant(10); cout << "Vous gagnez 10 pièces grâce à votre monument Aeroport construit !" <<endl;}
            p.joueur_next(effet_parc_attraction);
            break;
        case 2:
            if(choix2(p)) goto revenir;
            p.joueur_next(effet_parc_attraction);
            break;

        case 3:
            switch (choix3(p))
            {
            case 0:
                p.joueur_next(effet_parc_attraction);
                break;
            case 1:
                choix = 0; // Si qqn gagne, partie terminée
                break;
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
    setlocale(LC_ALL, "fr_FR.UTF-8");
    //setlocale(LC_ALL, "");
    Partie p;
    menu(p);

    //TEST CENTRE D'AFFAIRES
    /*Partie p;
    p.initialisation();

    //---------------------------------------------------------------------------------------------------------------------
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!/!\CHOISIR AU MOINS 3 JOUEURS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //---------------------------------------------------------------------------------------------------------------------

    p.achat_carte(p.getReserve()->getListeEtablissement()[3]);//J1 : Cafe
    p.joueur_next();
    p.getJoueurActif()->ajouterMontant(30);
    cout<<p.getJoueurActif()->getCompte()<<endl;//J2 : 33
    p.achat_carte(p.getReserve()->getListeEtablissement()[6]);//J2 : Stade
    p.achat_carte(p.getReserve()->getListeEtablissement()[7]);//J2 : Centre d'affaires
    p.achat_carte(p.getReserve()->getListeEtablissement()[3]);//J2 : Cafe
    p.achat_carte(p.getReserve()->getListeEtablissement()[3]);//J2 : Cafe
    p.achat_carte(p.getReserve()->getListeEtablissement()[11]);//J2 : Mine
    cout << p.getJoueurActif()->getCompte() << endl;//J2 : 9
    p.getJoueurActif()->printJoueurConcise();
    p.joueur_next();
    p.getJoueurActif()->ajouterMontant(4);
    cout << p.getJoueurActif()->getCompte() << endl;//J3 : 7
    p.achat_carte(p.getReserve()->getListeEtablissement()[0]);//J3 : Champ de ble
    p.achat_carte(p.getReserve()->getListeEtablissement()[0]);//J3 : Champ de ble
    p.achat_carte(p.getReserve()->getListeEtablissement()[1]);//J3 : Boulangerie //2 : Ferme
    cout << p.getJoueurActif()->getCompte() << endl;//J3 : 4
    p.transaction_carte(p.getJoueurs()[2], p.getJoueurs()[1], p.getJeu()->getEtablissements()[0]);//J3 donne Champ de ble à J2
    cout << endl << endl << endl << "J3 donne Champ de ble à J2" << endl;
    p.getJoueurs()[1]->printJoueurConcise();//J2
    p.getJoueurs()[2]->printJoueurConcise();//J3
    p.transaction_carte(p.getJoueurs()[1], p.getJoueurs()[2], p.getJeu()->getEtablissements()[6]);//J2 donne Stade à J3
    cout << endl << endl << endl << "J2 donne Stade à J3" << endl;
    p.getJoueurs()[1]->printJoueurConcise();//J2
    p.getJoueurs()[2]->printJoueurConcise();//J3
    p.getJoueurActif()->ajouterMontant(20);
    cout << p.getJoueurActif()->getCompte() << endl;//J3 : 24
    p.achat_carte(p.getReserve()->getListeEtablissement()[7]);//J3 : Centre d'affaires
    p.achat_carte(p.getReserve()->getListeEtablissement()[8]);//J3 : Chaine de television
    cout << p.getJoueurActif()->getCompte() << endl;//J3 : 9
    cout << endl << endl << endl << "Je souhaite débiter 7 du compte de J3" << endl;
    p.getJoueurActif()->ajouterMontant(-7);
    cout << endl << "Resultat" << endl;
    cout << p.getJoueurActif()->getCompte() << endl;//J3 : 2
    p.getJoueurs()[2]->printJoueurConcise();//J3
    //p.find_carte_des(3);
    p.find_carte_des(6);*/

    //TEST DON DE CARTES
    /*Jeu* j = new Jeu;//(Extension::Deluxe);//(Extension::Marina);//(Extension::GreenValley);// (Extension::Deluxe);
    cout << *j;
    Joueur* Josephine = new Joueur(j);
    cout << "JOSEPHINE" << endl;
    Josephine->printJoueurConcise();
    Joueur* Jingfang = new Joueur(j);
    cout << "JINGFANG" << endl;
    Jingfang->printJoueurConcise();
    cout << j->getEtablissements()[0][0];
    p.transaction_carte(Josephine, Jingfang, j->getEtablissements()[0]);
    cout << "JOSEPHINE" << endl;
    Josephine->printJoueurConcise();
    cout << "JINGFANG" << endl;
    Jingfang->printJoueurConcise();
    cout << Josephine->getNbDes() << endl;
    Josephine->setNbDes();
    cout << Josephine->getNbDes() << endl;*/

    /* const Etablissement** e = j->getEtablissements();
     for(unsigned int i=0; i<15;i++)e[i]->afficher();
     return 0;*/
    // j->getEtablissementFromName("Marche de fruits et legumes")->afficher();

    // return EtablissementTest();
    // return MonumentTest();
    return 0;
}
