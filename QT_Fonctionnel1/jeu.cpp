#include "jeu.h"
#include "buildfonctions.h"

Jeu::Jeu(Extension e, const size_t& cdv, size_t nbj, size_t nbpr,
    size_t nblr, size_t nbcr) :
    extension(e),
    condition_de_victoire(cdv),
    nb_joueurs_MAX(nbj),
    nb_pile_reserve_MAX(nbpr),
    nb_lignes_reserve_MAX(nblr),
    nb_colonnes_reserve_MAX(nbcr)
    {
    /*------------------ETABLISSEMENTS DE DEPART------------------*/
    // champs_de_ble_depart != champs_de_ble : prix(0) ; Nb_exemplaire(4);
    // idem pour boulangerie_depart et boulangerie
    builddepart(liste_etablissements_depart);


    /*----------------------ETABLISSEMENTS----------------------*/
    // Etablissement(nom,effet,couleur,prix,num_de[],type,nb_piece,
    // type_effet,payeur,nb_exemplaire);
    // TO DO : /!\ gerer nume_de[]
    //Jingfang 13/11 : num_de peut se faire à travers vector<unsigned int>
    // payeur un_joueur:0 ou /!\ la banque  |  tous_les_joueurs:1
    buildetablissement(liste_etablissements, extension);
    buildetablissementSpecial(liste_etablissements_speciaux, extension);


    /*------------------------MONUMENTS-------------------------*/
    //Monument(nom,effet,prix);
    //type d'un Monument : special mais inutile � mon avis, on le met quand m�me ?
    /*Tour radio, comment interpr�ter effet : un tour en plus ou alors
    remplacer un lancer de d�s ? */
    buildmonument(liste_monuments);


    nbEtablissements = liste_etablissements.size();
    nbEtablissementsSP = liste_etablissements_speciaux.size();
    nbMonuments = liste_monuments.size();
    nbEtablissements_Depart = liste_etablissements_depart.size();

}




void Jeu::printE_D(std::ostream& f) const {
    for(auto i : liste_etablissements_depart)
        f << "ETABLISSEMENTS DE DEPART"
        << endl << *i;
    f << endl;
}
void Jeu::printE(std::ostream& f) const {
    for(auto i : liste_etablissements)
        f << "ETABLISSEMENTS"
        << endl << *i;
    for(auto i : liste_etablissements_speciaux)
        f << "ETABLISSEMENTS SPECIAUX"
        << endl << *i;
    f << endl;
}
void Jeu::printM(std::ostream& f) const {
    for(auto i : liste_monuments)
        f << "MONUMENTS"
        << endl << *i;
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
        << "Nombre d'etablissements spéciaux \t: " << nbEtablissementsSP << endl
        << "Nombre de monuments \t\t: " << nbMonuments << endl;
        //<< "Nombre total de cartes \t\t: " << nbCartes << endl << endl;
}

ostream& operator<<(ostream& f, const Jeu& j) {
    j.afficher(f);
    j.printE_D(f);
    j.printE(f);
    j.printM(f);
    //f << endl;
    return f;
}
