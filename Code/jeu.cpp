#include "jeu.h"

Jeu::Jeu() {
	//Etablissement(nom,couleur,effet,prix,num_de[],type,nb_piece,type_effet,payeur,nb_exemplaire);
	//rajout num_de[]
	//type_effet=null : possible ?
	//payeur un_joueur:0 tous_les_joueurs:1 la_banque:null
	Etablissement champs_de_ble = new Etablissement("Champs de ble", Couleur::Bleu, "Recevez 1 piece de la banque", 1, 1, Type::agriculture, 1, null, null, 6);
	Etablissement ferme = new Etablissement("Ferme", Couleur::Bleu, "Recevez 1 piece de la banque", 1, 2, Type::elevage, 1, null, null, 6);
	Etablissement boulangerie = new Etablissement("Boulangerie", Couleur::Vert, "Recevez 1 piece de la banque", 1, {2,3}, Type::commerce, 1, null, null, 6);
	Etablissement cafe = new Etablissement("Cafe", Couleur::Rouge, "Recevez 1 piece du joueur qui a lance les des", 2, 3, Type::restauration, 1, null, 0, 6);
	Etablissement superette = new Etablissement("Superette", Couleur::Vert, "Recevez 3 pieces de la banque", 2, 4, Type::commerce, 3, null, null, 6);
	Etablissement foret = new Etablissement("Foret", Couleur::Bleu, "Recevez 1 piece de la banque", 3, 5, Type::ressources, 1, null, null, 6);
	Etablissement stade = new Etablissement("Stade", Couleur::Violet, "Recevez 2 pieces de la part de chaque autre joueur", 6, 6, Type::special, 2, null, 1, 4);
	//centre_d_affaires : type_effet=null ou type_effet=special pour faire un test d'erreur si echange special contre special
	Etablissement centre_d_affaires = new Etablissement("Centre d'affaires", Couleur::Violet, "Vous pouvez echanger avec le joueur de votre choix un etablissement qui ne soit pas de type special", 8, 6, Type::special, 0, null, null, 4);
	Etablissement chaine_de_television = new Etablissement("Chaine de television", Couleur::Violet, "Recevez 5 pieces du joueur de votre choix", 7, 6, Type::special, 5, null, 0, 4);
	Etablissement fromagerie = new Etablissement("Fromagerie", Couleur::Vert, "Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez", 5, 7, Type::industrie, 3, Type::elevage, null, 6);
	Etablissement fabrique_de_meubles = new Etablissement("Fabrique de meubles", Couleur::Vert, "Recevez 3 pieces de la banque pour chaque etablissement de type ressources que vous possedez", 3, 8, Type::industrie, 3, Type::ressources, null, 6);
	Etablissement mine = new Etablissement("Mine", Couleur::Bleu, "Recevez 5 pieces de la banque", 6, 9, Type::ressources, 5, null, null, 6);
	Etablissement restaurant = new Etablissement("Restaurant", Couleur::Rouge, "Recevez 2 pieces du joueur qui a lance les des", 3, {9,10}, Type::restauration, 2, null, 0, 6);
	Etablissement verger = new Etablissement("Verger", Couleur::Bleu, "Recevez 3 pieces de la banque", 3, 10, Type::agriculture, 3, null, null, 6);
	Etablissement marche_de_fruits_et_legumes = new Etablissement("Marche de fruits et legumes", Couleur::Vert, "Recevez 2 pieces de la banque pour chaque etablissement de type agriculture que vous possedez", 2, {11,12}, Type::maraichage, 2, Type::agriculture, null, 6);
	liste_etablissements[0] = &champs_de_ble;
	liste_etablissements[1] = &ferme;
	liste_etablissements[2] = &boulangerie;
	liste_etablissements[3] = &cafe;
	liste_etablissements[4] = &superette;
	liste_etablissements[5] = &foret;
	liste_etablissements[6] = &stade;
	liste_etablissements[7] = &centre_d_affaires;
	liste_etablissements[8] = &chaine_de_television;
	liste_etablissements[9] = &fromagerie;
	liste_etablissements[10] = &fabrique_de_meubles;
	liste_etablissements[11] = &mine;
	liste_etablissements[12] = &restaurant;
	liste_etablissements[13] = &verger;
	liste_etablissements[14] = &marche_de_fruits_et_legumes;

	//type d'un Monument : special mais inutile à mon avis, on le met quand même ?
	//Tour radio, comment interpréter effet : un tour en plus ou alors remplacer un lancer de dés ?
	//rajout cout, nb_piece, type_effet[], payeur
	//Monument(nom,effet,prix,//nb_piece,//type_effet[],//payeur,nb_exemplaire);
	Monument gare = new Monument("Gare", "Vous pouvez lancer deux des", 4, 4);
	Monument centre_commercial = new Monument("Centre commercial", "Vos etablissement de type restauration et commerce rapportent une piece de plus", 10, 4);
	/*1, { Type::restauration, Type::commerce}, null, 4);*/
	Monument tour_radio = new Monument("Tour radio", "Une fois par tour, vous pouvez choisir de relancer vos des", 22, 0, null, null, 4);
	Monument parc_d_attractions = new Monument("Parc d'attractions", "Si votre jet de des est un double, rejouez un tour apres celui-ci", 16, 4);
	liste_monuments[0] = &gare;
	liste_monuments[1] = &centre_commercial;
	liste_monuments[2] = &tour_radio;
	liste_monuments[3] = &parc_d_attractions;

	//rajout const Etablissement* liste_etablissements_depart[2];
	//je ne savais pas s'il y avait des setters alors j'ai créé un nouveau champs de ble et une nouvelle boulangerie
	//setCout(0);setNb_exemplaire(4);
	//Etablissement(nom,couleur,effet,prix,num_de[],type,nb_piece,type_effet,payeur,nb_exemplaire);
	Etablissement champs_de_ble_depart = new Etablissement("Champs de ble", Couleur::Bleu, "Recevez 1 piece de la banque", 0, 1, Type::agriculture, 1, null, null, 4);
	Etablissement boulangerie_depart = new Etablissement("Boulangerie", Couleur::Vert, "Recevez 1 piece de la banque", 0, { 2,3 }, Type::commerce, 1, null, null, 4);
	liste_etablissements_depart[0] = &champs_de_ble_depart;
	liste_etablissements_depart[1] = &boulangerie_depart;
	
}

Jeu::Jeu(Extension e) {//pour créer Minivilles avec une extension
	extension = Extension::Marina;
	condition_de_victoire = 6; //nombre de monuments à construire pour gagner dans le jeu Marina
	//nombre de joueurs max dans Marina est le même que dans le jeu de base
	nb_pile_reserve_MAX = 10; //nombre de piles max dans la réserve du jeu Marina : 2 lignes ; 5 colonnes
}