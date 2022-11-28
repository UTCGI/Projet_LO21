#include <iostream>
#include "miniville.h"
#include "etablissement.h"
#include "monument.h"
#include "jeu.h"
#include "partie.h"
#include "buildfonctions.h"

#include "create_database.h"//Au cas où

using namespace std;

int main() {
    Partie* partie1 = new Partie();
    partie1->initialisation();
    //cout<<*(partie1->getJeu());
    //cout<<*(partie1->getReserve());
    //cout<<*(partie1->getJeu());
    /* for (auto i :partie1->getJoueurs())
        cout<<*(i); */

    /* La distribution des cartes à la réserve et aux joueurs est fonctionnelle (règle optionelle de Marina non définie) */




}



/* int main() {

    
    cout << endl << endl;

    Jeu* jeuuu = new Jeu(Extension::Aucune);
    cout << "Voici le contenu du jeu de base Minivilles : " << endl << endl;
    cout << *jeuuu;
    //cout << endl << endl;
    //cout << endl << endl;
    return 0;
} */

