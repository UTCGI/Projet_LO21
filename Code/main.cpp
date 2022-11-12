#include <iostream>
#include "miniville.h"
#include "etablissement.h"
#include "monument.h"
#include "jeu.h"

using namespace std;

int main() {
    //MAIN pour tester l'affichage !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //je sais c'est une fonction de la classe Partie...
    cout << "A quelle version du jeu souhaitez-vous jouer ?" << endl << endl;
    printExtensions();
    cout << "Vous allez jouer a ";
    cout << Extension::Aucune << endl;
    /*cout << Type::agriculture << endl;
    Type RU = Type::restauration;
    cout << toString(RU) << endl;*/
    cout << endl << endl;

    Jeu* jeuuu = new Jeu();
    cout << "Voici le contenu du jeu de base Minivilles : " << endl << endl;
    cout << *jeuuu;
    //cout << endl << endl;
    //cout << endl << endl;
    return 0;
}

//#include <iostream>
//#include "pile_etablissement.h"
//#include <string>
//
//int main()
//{
//    /* cr�ation et actualisation d'une pile d'�tablissements*/
//    const string& txt = "Pendant le tour de n'importe quel joueur recevez une piece de la banque.";
//    Etablissement e0=Etablissement("Ferme",txt,Couleur::bleu,1,2,Type::agriculture,1);
//    Pile_Etablissement p0=Pile_Etablissement(&e0,6);
//    p0.retirerCarte(1);
//    cout<<p0;
//    return 0;
//};
