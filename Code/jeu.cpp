#include "jeu.h"

Jeu::Jeu() {
    /*------------------ETABLISSEMENTS DE DEPART------------------*/
    // champs_de_ble_depart != champs_de_ble : prix(0) ; Nb_exemplaire(4);
    // idem pour boulangerie_depart et boulangerie
    Etablissement* champs_de_ble_depart = new Etablissement("Champs de ble",
        "Recevez 1 piece de la banque", Couleur::bleu, 0, 1, Type::agriculture, 
        1, Type::aucun);
    Etablissement* boulangerie_depart = new Etablissement("Boulangerie",
        "Recevez 1 piece de la banque", Couleur::vert, 0, 23, Type::commerce, 
        1, Type::aucun);
    liste_etablissements_depart[0] = champs_de_ble_depart;
    liste_etablissements_depart[1] = boulangerie_depart;


    /*----------------------ETABLISSEMENTS----------------------*/
    // Etablissement(nom,effet,couleur,prix,num_de[],type,nb_piece,
    // type_effet,payeur,nb_exemplaire);
    // TO DO : /!\ gerer nume_de[]
    //Jingfang 13/11 : num_de peut se faire à travers vector<unsigned int>
    // payeur un_joueur:0 ou /!\ la banque  |  tous_les_joueurs:1
    Etablissement* champs_de_ble = new Etablissement("Champs de ble",
        "Recevez 1 piece de la banque", Couleur::bleu, 1, 1, Type::agriculture, 
        1, Type::aucun);
    Etablissement* ferme = new Etablissement("Ferme",
        "Recevez 1 piece de la banque", Couleur::bleu, 1, 2, Type::elevage, 
        1, Type::aucun);
    Etablissement* boulangerie = new Etablissement("Boulangerie",
        "Recevez 1 piece de la banque", Couleur::vert, 1, 23, Type::commerce, 
        1, Type::aucun);
    Etablissement* cafe = new Etablissement("Cafe",
        "Recevez 1 piece du joueur qui a lance les des", Couleur::rouge, 
        2, 3, Type::restauration, 1, Type::aucun);
    Etablissement* superette = new Etablissement("Superette",
        "Recevez 3 pieces de la banque", Couleur::vert, 2, 4, Type::commerce, 
        3, Type::aucun);
    Etablissement* foret = new Etablissement("Foret",
        "Recevez 1 piece de la banque", Couleur::bleu, 3, 5, Type::ressources, 
        1, Type::aucun);
    Etablissement* stade = new Etablissement("Stade",
        "Recevez 2 pieces de la part de chaque autre joueur", Couleur::violet, 
        6, 6, Type::special, 2, Type::aucun, 1);
    // centre_d_affaires : type_effet=null ou type_effet=special pour faire un
    // test d'erreur si echange special contre special
    Etablissement* centre_d_affaires = new Etablissement("Centre d'affaires", 
        "Vous pouvez echanger avec le joueur de votre "
        "choix un etablissement qui ne soit pas de type special", Couleur::violet,
        8, 6, Type::special, 0, Type::aucun);
    Etablissement* chaine_de_television = new Etablissement("Chaine de television",
        "Recevez 5 pieces du joueur de votre choix", Couleur::violet, 
        7, 6, Type::special, 5, Type::aucun, 0);
    Etablissement* fromagerie = new Etablissement("Fromagerie", 
        "Recevez 3 pieces de la banque pour chaque etablissement de "
        "type elevage que vous possedez", Couleur::vert, 
        5, 7, Type::industrie, 3, Type::elevage);
    Etablissement* fabrique_de_meubles = new Etablissement("Fabrique de meubles", 
        "Recevez 3 pieces de la banque pour chaque "
        "etablissement de type ressources que vous possedez", Couleur::vert,
        3, 8, Type::industrie, 3, Type::ressources);
    Etablissement* mine = new Etablissement("Mine", "Recevez 5 pieces de la banque",
        Couleur::bleu, 6, 9, Type::ressources, 5, Type::aucun);
    Etablissement* restaurant = new Etablissement("Restaurant", 
        "Recevez 2 pieces du joueur qui a lance les des",
        Couleur::rouge, 3, 910, Type::restauration, 2, Type::aucun, 0);
    Etablissement* verger = new Etablissement("Verger", 
        "Recevez 3 pieces de la banque", Couleur::bleu, 3, 10,
        Type::agriculture, 3, Type::aucun);
    Etablissement* marche_de_fruits_et_legumes = new Etablissement("Marche de "
        "fruits et legumes", "Recevez 2 pieces de la banque pour chaque "
        "etablissement de type agriculture que vous possedez", 
        Couleur::vert, 2, 1112, Type::maraichage, 2, Type::agriculture);
    liste_etablissements[0] = champs_de_ble;
    liste_etablissements[1] = ferme;
    liste_etablissements[2] = boulangerie;
    liste_etablissements[3] = cafe;
    liste_etablissements[4] = superette;
    liste_etablissements[5] = foret;
    liste_etablissements[6] = stade;
    liste_etablissements[7] = centre_d_affaires;
    liste_etablissements[8] = chaine_de_television;
    liste_etablissements[9] = fromagerie;
    liste_etablissements[10] = fabrique_de_meubles;
    liste_etablissements[11] = mine;
    liste_etablissements[12] = restaurant;
    liste_etablissements[13] = verger;
    liste_etablissements[14] = marche_de_fruits_et_legumes;


    /*------------------------MONUMENTS-------------------------*/
    //Monument(nom,effet,prix);
    //type d'un Monument : special mais inutile � mon avis, on le met quand m�me ?
    /*Tour radio, comment interpr�ter effet : un tour en plus ou alors
    remplacer un lancer de d�s ? */
    Monument* gare = new Monument("Gare", "Vous pouvez lancer deux des", 4);
    Monument* centre_commercial = new Monument("Centre commercial",
        "Vos etablissement de type restauration et commerce "
        "rapportent une piece de plus", 10);
    /*TO DO : / !\ gerer type_effet de centre_commercial :
    faire une fonction avec { Type::restauration, Type::commerce}*/
    Monument* tour_radio = new Monument("Tour radio",
        "Une fois par tour, vous pouvez choisir de relancer vos des", 22);
    Monument* parc_d_attractions = new Monument("Parc d'attractions",
        "Si votre jet de des est un double, rejouez un tour apres celui-ci", 16);
    liste_monuments[0] = gare;
    liste_monuments[1] = centre_commercial;
    liste_monuments[2] = tour_radio;
    liste_monuments[3] = parc_d_attractions;
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