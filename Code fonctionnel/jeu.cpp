#include "jeu.h"
#include "buildfonctions.h"

Jeu::Jeu(Extension e, const size_t& cdv, size_t nbj, size_t nbpr,
    size_t nblr, size_t nbcr, size_t nbed, size_t nbe, size_t nbm, size_t nbc) :
    extension(e),
    condition_de_victoire(cdv),
    nb_joueurs_MAX(nbj),
    nb_pile_reserve_MAX(nbpr),
    nb_lignes_reserve_MAX(nblr),
    nb_colonnes_reserve_MAX(nbcr),
    nbEtablissements_Depart(nbed),
    nbEtablissements(nbe),
    nbMonuments(nbm),
    nbCartes(nbc) {
    switch (e) {
    case Extension::Aucune:
        cout << "STANDARD" << endl;
            builddepart(liste_etablissements_depart);
            buildetablissement(liste_etablissements, e);
            buildmonument(liste_monuments);
        break;
    case Extension::Marina:
        cout << "MARINA" << endl;
            builddepart(liste_etablissements_depart);//FAUX : TO DO
            buildetablissement(liste_etablissements, e);//FAUX : TO DO
            buildmonument(liste_monuments);//FAUX : TO DO
        break;
    case Extension::GreenValley:
        cout << "GREENVALLEY" << endl;
            builddepart(liste_etablissements_depart);//FAUX : TO DO
            buildetablissement(liste_etablissements, e);//FAUX : TO DO
            buildmonument(liste_monuments);//FAUX : TO DO
        break;
    case Extension::Deluxe:
        cout << "DELUXE" << endl;
            builddepart(liste_etablissements_depart);//FAUX : TO DO
            buildetablissement(liste_etablissements, e);//FAUX : TO DO
            buildmonument(liste_monuments);//FAUX : TO DO
        break;
    default:
        cout << "DEFAUT" << endl;
        throw SetException("Extension inconnue");
    }
}


//Jeu::Jeu(Extension extension) {
//    /*------------------ETABLISSEMENTS DE DEPART------------------*/
//    // champs_de_ble_depart != champs_de_ble : prix(0) ; Nb_exemplaire(4);
//    // idem pour boulangerie_depart et boulangerie
//    builddepart(liste_etablissements_depart);
//
//
//    /*----------------------ETABLISSEMENTS----------------------*/
//    // Etablissement(nom,effet,couleur,prix,num_de[],type,nb_piece,
//    // type_effet,payeur,nb_exemplaire);
//    // TO DO : /!\ gerer nume_de[]
//    //Jingfang 13/11 : num_de peut se faire à travers vector<unsigned int>
//    // payeur un_joueur:0 ou /!\ la banque  |  tous_les_joueurs:1
//    buildetablissement(liste_etablissements, extension);
//
//
//    /*------------------------MONUMENTS-------------------------*/
//    //Monument(nom,effet,prix);
//    //type d'un Monument : special mais inutile � mon avis, on le met quand m�me ?
//    /*Tour radio, comment interpr�ter effet : un tour en plus ou alors
//    remplacer un lancer de d�s ? */
//    buildmonument(liste_monuments);
//}

void Jeu::printE_D(std::ostream& f) const {
    for (size_t i = 0; i < getNbEtablissements_Depart(); i++)
        f << "ETABLISSEMENTS DE DEPART" << endl << i + 1 
        << endl << *liste_etablissements_depart[i];
    f << endl;
}
void Jeu::printE(std::ostream& f) const {
    for (size_t i = 0; i < getNbEtablissements(); i++)
        f << "ETABLISSEMENTS" << endl << i + 1 << endl << *liste_etablissements[i];
    f << endl;
}
void Jeu::printM(std::ostream& f) const {
    for (size_t i = 0; i < getNbMonuments(); i++)
        f << "MONUMENTS" << endl << i + 1 << endl << *liste_monuments[i];
    f << endl;
}

void Jeu::afficher(std::ostream& f) const {
    f << "\t " << extension << endl
        << "Condition de victoire \t\t: " << condition_de_victoire << endl
        << "Nombre de joueurs MAX \t\t: " << nb_joueurs_MAX << endl
        << "Nombre de pile_reserve MAX \t: " << nb_pile_reserve_MAX << endl
        << "soit " << nb_lignes_reserve_MAX << " lignes et "
        << nb_colonnes_reserve_MAX << " colonnes" << endl
        << "Nombre d'etablissements de depart : " << nbEtablissements_Depart << endl
        << "Nombre d'etablissements \t: " << nbEtablissements << endl
        << "Nombre de monuments \t\t: " << nbMonuments << endl
        << "Nombre total de cartes \t\t: " << nbCartes << endl << endl;
}

ostream& operator<<(ostream& f, const Jeu& j) {
    j.afficher(f);
    j.printE_D(f);
    j.printE(f);
    j.printM(f);
    //f << endl;
    return f;
}