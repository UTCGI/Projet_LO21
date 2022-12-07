#include "sql.h"

/*static*/ int createDB(const char* s) {
	sqlite3* db;
	int exit = 0;
	exit = sqlite3_open(s, &db);
	sqlite3_close(db);
	return 0;
}

/*static*/ int createTable(const char* s) {
	sqlite3* db;
    string sql = "drop table if exists Etablissement;"
        "CREATE TABLE Etablissement("
        "nom varchar PRIMARY KEY,"
        "effet varchar,"
        "couleur varchar NOT NULL CHECK(couleur in ('rouge','bleu', 'vert', 'violet')),"
        "prix integer NOT NULL CHECK(prix>=0),"
        "num_de JSON NOT NULL,"
        "type1 varchar NOT NULL CHECK(type1 in ('agriculture',"
        "'elevage',"
        "'ressources',"
        "'maritime',"
        "'commerce',"
        "'industrie',"
        "'maraichage',"
        "'entreprise',"
        "'restauration',"
        "'special', 'aucun')),"
        "montant_effet NOT NULL," // CHECK(montant_effet>=0)
        "type_effet varchar NOT NULL CHECK(type_effet in ('agriculture',"
        "'elevage',"
        "'ressources',"
        "'maritime',"
        "'commerce',"
        "'industrie',"
        "'maraichage',"
        "'entreprise',"
        "'restauration',"
        "'special', 'aucun')),"
        "payeur bool not null,"
        "extension varchar NOT NULL CHECK(extension in ('Aucune',"
        "'Marina', "
        "'GreenValley')));"

        "drop table if exists PasEtablissementDeluxe;"
        "CREATE TABLE PasEtablissementDeluxe("
        "nom varchar PRIMARY KEY,"
        "effet varchar,"
        "couleur varchar NOT NULL CHECK(couleur in ('rouge','bleu', 'vert', 'violet')),"
        "prix integer NOT NULL CHECK(prix>=0),"
        "num_de JSON NOT NULL,"
        "type1 varchar NOT NULL CHECK(type1 in ('agriculture',"
        "'elevage',"
        "'ressources',"
        "'maritime',"
        "'commerce',"
        "'industrie',"
        "'maraichage',"
        "'entreprise',"
        "'restauration',"
        "'special', 'aucun')),"
        "montant_effet NOT NULL," // CHECK(montant_effet>=0)
        "type_effet varchar NOT NULL CHECK(type_effet in ('agriculture',"
        "'elevage',"
        "'ressources',"
        "'maritime',"
        "'commerce',"
        "'industrie',"
        "'maraichage',"
        "'entreprise',"
        "'restauration',"
        "'special', 'aucun')),"
        "payeur bool not null,"
        "extension varchar NOT NULL CHECK(extension in ('Aucune',"
        "'Marina', "
        "'GreenValley')));"

        "drop table if exists Jeu;"
        "CREATE TABLE Jeu("
        "nom varchar PRIMARY KEY CHECK(nom in ('Aucune','Marina', 'GreenValley', 'Deluxe')),"
        "condition_de_victoire integer NOT NULL CHECK(condition_de_victoire>0),"
        "nb_joueurs_MAX integer NOT NULL CHECK(nb_joueurs_MAX>=2),"
        "nb_pile_reserve_MAX integer NOT NULL CHECK(nb_pile_reserve_MAX>=9),"
        "nb_lignes_reserve_MAX integer NOT NULL CHECK(nb_lignes_reserve_MAX>=2),"
        "nb_colonnes_reserve_MAX integer NOT NULL CHECK(nb_colonnes_reserve_MAX>=3),"
        "nbEtablissements_Depart integer NOT NULL CHECK(nbEtablissements_Depart>=2),"
        "nbEtablissements integer NOT NULL CHECK(nbEtablissements>=15),"
        "nbMonuments integer NOT NULL CHECK(nbMonuments>=4),"
        "nbCartes integer NOT NULL CHECK(nbCartes>=108)"
        ");"
        ;
    try {
        int exit = 0;
        exit = sqlite3_open(s, &db);

        char* messageErreur;
        exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageErreur);

        if (exit != SQLITE_OK) {
            cerr << "Erreur creation de la table" << endl;
            sqlite3_free(messageErreur);
        }
        else
            cout << "Table creee avec succes" << endl;
        sqlite3_close(db);
    }
    catch (const exception& e) {
        cerr << e.what();
    }
    return 0;
}

/*static*/ int insertData(const char* s) {
    sqlite3* db;
        //CARACTERISTIQUES
    string sql = "insert into Jeu VALUES('Aucune', 4, 4, 15, 3, 5, 2, 15, 4, 108);"
        "insert into Jeu VALUES('Marina', 6, 4, 10, 2, 5, 3, 25, 6, 176);"
        "insert into Jeu VALUES('GreenValley', 4, 4, 10, 2, 5, 2, 28, 4, 180);"
        "insert into Jeu VALUES('Deluxe', 5, 5, 9, 3, 3, 2, 28, 6, 165);"

        //SANS EXTENSION
        "insert into Etablissement VALUES ('Champs de ble','Recevez 1 piece de la banque', 'bleu', 1, '[1]', 'agriculture', 1, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Ferme', 'Recevez 1 piece de la banque', 'bleu', 1, '[2]', 'elevage', 1, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Boulangerie','Recevez 1 piece de la banque', 'vert', 1, '[2, 3]', 'commerce', 1, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Cafe','Recevez 1 piece du joueur qui a lance les des', 'rouge', 2, '[3]', 'restauration', 1, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Superette','Recevez 3 pieces de la banque', 'vert', 2, '[4]', 'commerce', 3, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Foret', 'Recevez 1 piece de la banque', 'bleu', 3, '[5]', 'ressources', 1, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Stade', 'Recevez 2 pieces de la part de chaque autre joueur', 'violet', 6, '[6]', 'special', 2, 'aucun', 1, 'Aucune');"
        "insert into Etablissement VALUES('Centre d''affaires', 'Vous pouvez echanger avec le joueur de votre choix un etablissement qui ne soit pas de type special', 'violet', 8, '[6]', 'special', 0, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Chaine de television', 'Recevez 5 pieces du joueur de votre choix', 'violet', 7, '[6]', 'special', 5, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Fromagerie', 'Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez', 'vert', 5, '[7]','industrie', 3, 'elevage', 0, 'Aucune');"
        "insert into Etablissement VALUES('Fabrique de meubles', 'Recevez 3 pieces de la banque pour chaque etablissement de type ressources que vous possedez','vert', 3, '[8]', 'industrie', 3, 'ressources', 0, 'Aucune');"
        "insert into Etablissement VALUES('Mine', 'Recevez 5 pieces de la banque', 'bleu', 6, '[9]', 'ressources', 5, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Restaurant', 'Recevez 2 pieces du joueur qui a lance les des', 'rouge', 3, '[9, 10]', 'restauration', 2, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Verger', 'Recevez 3 pieces de la banque', 'bleu', 3, '[10]', 'agriculture', 3, 'aucun', 0, 'Aucune');"
        "insert into Etablissement VALUES('Marche de fruits et legumes', 'Recevez 2 pieces de la banque pour chaque etablissement de type agriculture que vous possedez', 'vert', 2, '[11, 12]', 'maraichage', 2, 'agriculture', 0, 'Aucune');"


        //MARINA
        "insert into Etablissement VALUES('Sushi bar', 'Si vous avez le Port, recevez 3 pieces du joueur qui a lance les des', 'rouge', 2, '[1]', 'restauration', 3, 'aucun', 0, 'Marina');"
        "insert into Etablissement VALUES('Champ de fleurs', 'Recevez 1 piece de la banque', 'bleu', 2, '[4]','agriculture', 1, 'aucun', 0, 'Marina');"
        "insert into Etablissement VALUES('Fleuriste', 'Recevez 1 piece de la banque pour chaque Champ de fleurs que vous possedez','vert', 1, '[6]', 'commerce', 1, 'aucun', 0, 'Marina');"
        "insert into Etablissement VALUES('Pizzeria', 'Recevez 1 piece du joueur qui a lance les des', 'rouge', 1, '[7]', 'restauration', 1, 'aucun', 0, 'Marina');"
        "insert into Etablissement VALUES('Maison d''edition', 'Recevez 1 piece de chaque joueur pour chaque etablissement de type restauration et commerce qu''il possede', 'violet', 5, '[7]', 'special', 1, 'restauration', 1, 'Marina');"
        "insert into Etablissement VALUES('Moonster burger', 'Recevez 1 piece du joueur qui a lance les des', 'rouge', 1, '[8]', 'restauration', 1, 'aucun', 0, 'Marina');"
        "insert into Etablissement VALUES('Petit bateau de peche', 'Si vous avez le Port, recevez 3 pieces de la banque', 'bleu', 2, '[8]', 'maritime', 3, 'aucun', 0, 'Marina');"
        "insert into Etablissement VALUES('Centre des impots', 'Recevez la moitie (arrondie a l''inferieur) des pieces de chaque joueur qui en possede 10 ou plus', 'violet', 4, '[8, 9]', 'special', 0, 'aucun', 1, 'Marina');"
        "insert into Etablissement VALUES('Halle de marche', 'Recevez 2 pieces de la banque pour chaque etablissement de type restauration que vous possedez', 'vert', 2, '[12, 13]', 'industrie', 2, 'restauration', 0, 'Marina');"
        "insert into Etablissement VALUES('Chalutier', 'Le joueur dont c''est le tour lance 2 des. Si vous avez le Port recevez de la banque autant de pieces que le total des 2 des', 'bleu', 5, '[12, 13, 14]', 'maritime', 0, 'aucun', 0, 'Marina');"
        

        //GREENVALLEY
        "insert into Etablissement VALUES('Epicerie', 'Si vous possedez moins de deux monuments, recevez 2 pieces de la banque', 'vert', 0, '[2]', 'commerce', 2, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Champ de mais', 'Si vous possedez moins de deux monuments, recevez 1 piece de la banque', 'bleu', 2, '[3, 4]','agriculture', 1, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Entreprise de travaux publics', 'Vous devez retourner une de vos cartes monuments sur sa face en travaux. Ce faisant, recevez 8 pieces de la banque','vert', 2, '[4]', 'entreprise', 8, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Restaurant 5 etoiles', 'Recevez 5 pieces du joueur qui a lance les des si celui-ci possede au moins deux monuments construits', 'rouge', 3, '[5]', 'restauration', 5, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Banque de Minivilles', 'Lorsque vous achetez cet etablissement, recevez 5 pieces de la banque. Payez 2 pieces a la banque', 'vert', 0, '[5, 6]', 'entreprise', -2, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Vignoble', 'Recevez 3 pieces de la banque', 'bleu', 3, '[7]', 'agriculture', 3, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Entreprise de renovation', 'Choisissez un etablissement qui ne soit pas de type special. Tous les etablissements identiques de tous les joueurs sont fermes. Puis recevez 1 piece de la banque pour chaque etablissement ainsi ferme', 'violet', 4, '[8]', 'special', 1, 'aucun', 1, 'GreenValley');"
        "insert into Etablissement VALUES('Cave a vin', 'Recevez 6 pieces de la banque pour chaque Vignoble que vous possedez. Puis fermez cette Cave a vin', 'vert', 3, '[9]', 'industrie', 6, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Entreprise de demenagement', 'Donnez a un autre joueur, un de vos etablissements qui ne soit pas de type special. Puis recevez 4 pieces de la banque', 'vert', 2, '[9, 10]', 'entreprise', 4, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Startup', 'Recevez 1 piece de la banque pour chaque piece placee sur l''ensemble des Startups de tous les joueurs. A la fin de votre tour, placez une piece sur votre Startup', 'violet', 1, '[10]', 'special', 1, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Moonster soda', 'Recevez 1 piece de la banque pour chaque etablissement de type restauration que possedent tous les joueurs', 'vert', 5, '[11]', 'industrie', 1, 'restauration', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Arboretum', 'Rassemblez les pieces de tous les joueurs puis redistribuez-les de maniere egale entre tous. La banque completera s''il manque des pieces pour une redistribution egale', 'violet', 3, '[11, 12, 13]', 'special', 0, 'aucun', 0, 'GreenValley');"
        "insert into Etablissement VALUES('Club prive', 'Recevez toutes les pieces du joueur qui a lance les des si celui-ci possede au moins trois etablissements construits', 'rouge', 4, '[12, 13, 14]', 'restauration', 0, 'aucun', 0, 'GreenValley');"


        //PAS dans DELUXE
        "insert into PasEtablissementDeluxe VALUES('Fromagerie', 'Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez', 'vert', 5, '[7]','industrie', 3, 'elevage', 0, 'Aucune');"
        "insert into PasEtablissementDeluxe VALUES('Champ de mais', 'Si vous possedez moins de deux monuments, recevez 1 piece de la banque', 'bleu', 2, '[3, 4]','agriculture', 1, 'aucun', 0, 'GreenValley');"
        "insert into PasEtablissementDeluxe VALUES('Banque de Minivilles', 'Lorsque vous achetez cet etablissement, recevez 5 pieces de la banque. Payez 2 pieces a la banque', 'vert', 0, '[5, 6]', 'entreprise', -2, 'aucun', 0, 'GreenValley');"
        "insert into PasEtablissementDeluxe VALUES('Cave a vin', 'Recevez 6 pieces de la banque pour chaque Vignoble que vous possedez. Puis fermez cette Cave a vin', 'vert', 3, '[9]', 'industrie', 6, 'aucun', 0, 'GreenValley');"
        "insert into PasEtablissementDeluxe VALUES('Sushi bar', 'Si vous avez le Port, recevez 3 pieces du joueur qui a lance les des', 'rouge', 2, '[1]', 'restauration', 3, 'aucun', 0, 'Marina');"
        "insert into PasEtablissementDeluxe VALUES('Champ de fleurs', 'Recevez 1 piece de la banque', 'bleu', 2, '[4]','agriculture', 1, 'aucun', 0, 'Marina');"
        "insert into PasEtablissementDeluxe VALUES('Fleuriste', 'Recevez 1 piece de la banque pour chaque Champ de fleurs que vous possedez','vert', 1, '[6]', 'commerce', 1, 'aucun', 0, 'Marina');"
        "insert into PasEtablissementDeluxe VALUES('Entreprise de renovation', 'Choisissez un etablissement qui ne soit pas de type special. Tous les etablissements identiques de tous les joueurs sont fermes. Puis recevez 1 piece de la banque pour chaque etablissement ainsi ferme', 'violet', 4, '[8]', 'special', 1, 'aucun', 0, 'GreenValley');"
        "insert into PasEtablissementDeluxe VALUES('Startup', 'Recevez 1 piece de la banque pour chaque piece placee sur l''ensemble des Startups de tous les joueurs. A la fin de votre tour, placez une piece sur votre Startup', 'violet', 1, '[10]', 'special', 1, 'aucun', 1, 'GreenValley');"
        "insert into PasEtablissementDeluxe VALUES('Arboretum', 'Rassemblez les pieces de tous les joueurs puis redistribuez-les de maniere egale entre tous. La banque completera s''il manque des pieces pour une redistribution egale', 'violet', 3, '[11, 12, 13]', 'special', 0, 'aucun', 0, 'GreenValley');"
        ;

    try {
        int exit = 0;
        exit = sqlite3_open(s, &db);

        char* messageErreur;
        exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageErreur);

        if (exit != SQLITE_OK) {
            cerr << "Erreur a l'insertion" << endl;
            sqlite3_free(messageErreur);
        }
        else
            cout << "Enregistrements crees avec succes" << endl;
        sqlite3_close(db);
    }
    catch (const exception& e) {
        cerr << e.what();
    }
    return 0;
}


/*static*/ int selectData(const char* s, const string& extension) {
    sqlite3* db;
    string sql;// , sql2;
    int exit = 0;
    exit = sqlite3_open(s, &db);

    sql = "select * from Jeu where (nom='" + extension +  "');";
    exit = sqlite3_exec(db, sql.c_str(), collectCaracteristique, NULL, NULL);

    if (extension != "Deluxe")
	{
        sql = "select * from Etablissement where (extension='Aucune') or (extension='" + extension + "');";
	}
    else
    {
        sql = "SELECT * FROM Etablissement WHERE nom NOT IN(SELECT nom FROM PasEtablissementDeluxe);";
    }

    exit = sqlite3_exec(db, sql.c_str(), collectEtablissement, NULL, NULL);

    return 0;
}

/*static*/ int collectEtablissement(void* NotUsed, int nbselectedlines, char** value, char** columnname) {
    static int n = 0;
    for (int i = 0; i < nbselectedlines; i++)
    {
       if (strcmp(columnname[i], "nom") == 0)
        {
           n++;
           cout << endl; cout << n << endl;
        }
        cout << columnname[i] << " : " << value[i] << endl;
    }
    cout << endl;

    return 0;
}

/*static*/ int collectCaracteristique(void* NotUsed, int nbselectedlines, char** value, char** columnname) {
    cout << endl;
    for (int i = 0; i < nbselectedlines; i++)
    {
        cout << columnname[i] << " : " << value[i] << endl;
    }
    return 0;
}