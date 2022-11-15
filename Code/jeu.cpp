#include "jeu.h"
#include "buildfonctions.h"

Jeu::Jeu(Extension extension) {
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


    /*------------------------MONUMENTS-------------------------*/
    //Monument(nom,effet,prix);
    //type d'un Monument : special mais inutile � mon avis, on le met quand m�me ?
    /*Tour radio, comment interpr�ter effet : un tour en plus ou alors
    remplacer un lancer de d�s ? */
    buildmonument(liste_monuments);
}

Jeu::Jeu(Extension e) {
  extension = Extension::Marina;
  condition_de_victoire = 6;  
  // nombre de monuments � construire pour gagner dans le jeu Marina
  // nombre de joueurs max dans Marina est le m�me que dans le jeu de base
  nb_pile_reserve_MAX = 10;
  // nombre de piles max dans la r�serve du jeu
  // Marina : 2 lignes ; 5 colonnes
}

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

ostream& operator<<(ostream& f, const Jeu& j) {
    j.printE_D(f);
    j.printE(f);
    j.printM(f);
    //f << endl;
    return f;
}