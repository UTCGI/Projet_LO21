#include <iostream>
#include "create_database.h"
#include "sqlite3.h"
using namespace std;

bool exists_test (const string name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

void database(const string name)
{
    // Variable Sqlite3
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *zErrMsg = 0;
    int rc;
    string sql;
    // rc = sqlite3_open("%s/projet.db", &db),fs::current_path();
    rc = sqlite3_open(name.c_str(), &db);

    sql =   "drop table if exists monument;"
            "create table monument("
            "nom varchar PRIMARY KEY,"
            "effet varchar not null,"
            "prix integer not null check(prix>=0));"
            "insert into monument values('Gare', 'Vous pouvez lancer deux des', 4);"
            "insert into monument values('Centre commercial','Vos etablissement de type restauration et commerce rapportent une piece de plus', 10);"
            "insert into monument values('Tour radio','Une fois par tour, vous pouvez choisir de relancer vos des', 22);"
            "insert into monument values('Parc dattractions','Si votre jet de des est un double, rejouez un tour apres celui-ci', 16);"
            "drop table if exists Depart;"


            "CREATE TABLE Depart("
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
                "montant_effet NOT NULL CHECK(montant_effet>=0),"
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
                "payeur bool not null"
            ");"

            "insert into Depart VALUES('Champs de ble','Recevez 1 piece de la banque', 'bleu', 0, '[1]', 'agriculture', 1, 'aucun', 0);"
            "insert into Depart VALUES('Boulangerie','Recevez 1 piece de la banque', 'vert', 0, '[2, 3]', 'commerce', 1, 'aucun', 0);"


            "drop table if exists etablissement;"
            "drop table if exists Aucune;"
            "drop table if exists Marina1;"
            "drop view if exists Marina;"
            "CREATE TABLE Aucune("
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
                "montant_effet NOT NULL CHECK(montant_effet>=0),"
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
                "payeur bool not null"
            ");"

            "CREATE TABLE Marina1("
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
                "montant_effet NOT NULL CHECK(montant_effet>=0),"
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
                "payeur bool not null"
            ");"
            "CREATE VIEW Marina AS SELECT * FROM Aucune UNION SELECT * FROM Marina1;"
            "insert into Aucune VALUES('Champs de ble','Recevez 1 piece de la banque', 'bleu', 0, '[1]', 'agriculture', 1, 'aucun', 0);"
            "insert into Aucune VALUES('Ferme', 'Recevez 1 piece de la banque', 'bleu', 1, '[2]', 'elevage', 1, 'aucun', 0);"
            "insert into Aucune VALUES('Boulangerie','Recevez 1 piece de la banque', 'vert', 0, '[2, 3]', 'commerce', 1, 'aucun', 0);"
            "insert into Aucune VALUES('Cafe','Recevez 1 piece du joueur qui a lance les des', 'rouge', 2, '[3]', 'restauration', 1, 'aucun', 0);"
            "insert into Aucune VALUES('Superette','Recevez 3 pieces de la banque', 'vert', 2, '[4]', 'commerce', 3, 'aucun', 0);"
            
            "insert into Aucune VALUES('Foret', 'Recevez 1 piece de la banque', 'bleu', 3, '[5]', 'ressources', 1, 'aucun', 0);"
            //"insert into Aucune VALUES('Stade', 'Recevez 2 pieces de la part de chaque autre joueur', 'violet', 6, '[6]', 'special', 2, 'aucun', 1);"
            //"insert into Aucune VALUES('Foret', 'Recevez 1 piece de la banque', 'bleu', 3, '[5]', 'ressources', 1, 'aucun', 0);"
            "insert into Aucune VALUES('Stade', 'Recevez 2 pieces de la part de chaque autre joueur', 'violet', 6, '[6]', 'special', 2, 'aucun', 1);"
            "insert into Aucune VALUES('Centre d affaires', 'Vous pouvez echanger avec le joueur de votre choix un etablissement qui ne soit pas de type special', 'violet', 8, '[6]', 'special', 0, 'aucun', 0);"
            "insert into Aucune VALUES('Chaine de television', 'Recevez 5 pieces du joueur de votre choix', 'violet', 7, '[6]', 'special', 5, 'aucun', 0);"
            "insert into Aucune VALUES('Fromagerie', 'Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez', 'vert', 5, '[7]','industrie', 3, 'elevage', 0);"
            "insert into Aucune VALUES('Fabrique de meubles', 'Recevez 3 pieces de la banque pour chaque etablissement de type ressources que vous possedez','vert', 3, '[8]', 'industrie', 3, 'ressources', 0);"
            "insert into Aucune VALUES('Mine', 'Recevez 5 pieces de la banque', 'bleu', 6, '[9]', 'ressources', 5, 'aucun', 0);"
            "insert into Aucune VALUES('Restaurant', 'Recevez 2 pieces du joueur qui a lance les des', 'rouge', 3, '[9, 10]', 'restauration', 2, 'aucun', 0);"
            "insert into Aucune VALUES('Verger', 'Recevez 3 pieces de la banque', 'bleu', 3, '[10]', 'agriculture', 3, 'aucun', 0);"
            "insert into Aucune VALUES('Marche de fruits et legumes', 'Recevez 2 pieces de la banque pour chaque etablissement de type agriculture que vous possedez', 'vert', 2, '[11, 12]', 'maraichage', 2, 'agriculture', 0);"


            "insert into Marina1 VALUES('Chaine de television','Recevez 5 pieces du joueur de votre choix', 'violet', 7, '[6]', 'special', 5, 'aucun', 0);"
            "insert into Marina1 VALUES('Fromagerie', 'Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez', 'vert', 5, '[7]', 'industrie', 3, 'elevage', 0);"
            "insert into Marina1 VALUES('Fabrique de meubles', 'Recevez 3 pieces de la banque pour chaque etablissement de type ressources que vous possedez', 'vert',3, '[8]', 'industrie', 3, 'ressources', 0);"
            "insert into Marina1 VALUES('Mine', 'Recevez 5 pieces de la banque','bleu', 6, '[9]', 'ressources', 5, 'aucun', 0);"
    
            "drop table if exists Depart;"


            "CREATE TABLE Depart("
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
                "montant_effet NOT NULL CHECK(montant_effet>=0),"
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
                "payeur bool not null"
            ");"



            "insert into Depart VALUES('Champs de ble','Recevez 1 piece de la banque', 'bleu', 0, '[1]', 'agriculture', 1, 'aucun', 0);"
            "insert into Depart VALUES('Boulangerie','Recevez 1 piece de la banque', 'vert', 0, '[2, 3]', 'commerce', 1, 'aucun', 0);"

        
    ;
    rc = sqlite3_exec(db, sql.data(), 0, 0, &zErrMsg);
    
    if (rc != SQLITE_OK ) {
        cout<<"Creation failed"<<endl;
    } 
    
    sqlite3_close(db);
}

