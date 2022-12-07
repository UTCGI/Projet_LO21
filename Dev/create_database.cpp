#include <iostream>
#include "create_database.h"
#include "sqlite3.h"

using namespace std;


void database(const string name)
{
    // Variable Sqlite3
    cout<<"Creation database"<<endl;
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *zErrMsg = 0;
    int rc;
    string sql;
    rc = sqlite3_open(name.data(), &db);

    sql =
"drop table if exists Jeu;     \
CREATE TABLE Jeu(     \
nom varchar PRIMARY KEY CHECK(nom in ('Aucune','Marina', 'GreenValley', 'Deluxe')),     \
condition_de_victoire integer NOT NULL CHECK(condition_de_victoire>0),     \
nb_joueurs_MAX integer NOT NULL CHECK(nb_joueurs_MAX>=2),     \
nb_pile_reserve_MAX integer NOT NULL CHECK(nb_pile_reserve_MAX>=9),     \
nb_lignes_reserve_MAX integer NOT NULL CHECK(nb_lignes_reserve_MAX>=2),     \
nb_colonnes_reserve_MAX integer NOT NULL CHECK(nb_colonnes_reserve_MAX>=3),     \
nbEtablissements_Depart integer NOT NULL CHECK(nbEtablissements_Depart>=2),     \
nbEtablissements integer NOT NULL CHECK(nbEtablissements>=15),     \
nbMonuments integer NOT NULL CHECK(nbMonuments>=4),     \
nbCartes integer NOT NULL CHECK(nbCartes>=108)     \
);     \
insert into Jeu VALUES('Aucune', 4, 4, 15, 3, 5, 2, 15, 4, 108);     \
insert into Jeu VALUES('Marina', 6, 4, 10, 2, 5, 3, 25, 6, 176);     \
insert into Jeu VALUES('GreenValley', 4, 4, 10, 2, 5, 2, 28, 4, 180);     \
insert into Jeu VALUES('Deluxe', 5, 5, 9, 3, 3, 2, 28, 6, 165);     \
  \
  \
  \
  \
drop table if exists AucuneMonument;   \
drop table if exists Marina1Monument;   \
drop view if exists MarinaMonument;   \
create table AucuneMonument(   \
nom varchar PRIMARY KEY,   \
effet varchar not null,   \
prix integer not null check(prix>=0));   \
create table Marina1Monument(   \
nom varchar PRIMARY KEY,   \
effet varchar not null,   \
prix integer not null check(prix>=0));   \
CREATE VIEW MarinaMonument AS SELECT * FROM AucuneMonument UNION SELECT * FROM Marina1Monument;   \
insert into AucuneMonument values('Gare', 'Vous pouvez lancer deux des', 4);   \
insert into AucuneMonument values('Centre commercial','Vos etablissement de type restauration et commerce rapportent une piece de plus', 10);   \
insert into AucuneMonument values('Tour radio','Une fois par tour, vous pouvez choisir de relancer vos des', 22);   \
insert into AucuneMonument values('Parc dattractions','Si votre jet de des est un double, rejouez un tour apres celui-ci', 16);   \
insert into Marina1Monument values('Port','Une fois par tour, vous pouvez choisir de relancer vos des', 22);   \
insert into Marina1Monument values('Aeroport','Si votre jet de des est un double, rejouez un tour apres celui-ci', 16);   \
  \
  \
  \
  \
  \
drop table if exists Aucune;    \
CREATE TABLE Aucune(          \
nom varchar PRIMARY KEY,          \
effet varchar,        \
couleur varchar NOT NULL CHECK(couleur in ('rouge','bleu', 'vert', 'violet')),        \
prix integer NOT NULL CHECK(prix>=0),         \
num_de JSON NOT NULL,         \
type1 varchar NOT NULL CHECK(type1 in ('agriculture',         \
    'elevage',        \
    'ressources',         \
    'maritime',       \
    'commerce',       \
    'industrie',          \
    'maraichage',         \
    'entreprise',         \
    'restauration',       \
    'special', 'aucun')),         \
    montant_effet integer NOT NULL CHECK(montant_effet>=0),       \
type_effet varchar NOT NULL CHECK(type_effet in ('agriculture',       \
    'elevage',        \
    'ressources',         \
    'maritime',       \
    'commerce',       \
    'industrie',          \
    'maraichage',         \
    'entreprise',         \
    'restauration',       \
    'special', 'aucun')),         \
    payeur bool not null,         \
    identificateur integer not null       \
);        \
insert into Aucune VALUES('Champs de ble','Recevez 1 piece de la banque', 'bleu', 0, '[1]', 'agriculture', 1, 'aucun', 0, 0);         \
insert into Aucune VALUES('Boulangerie','Recevez 1 piece de la banque', 'vert', 0, '[2, 3]', 'commerce', 1, 'aucun', 0, 0);       \
insert into Aucune VALUES('Ferme', 'Recevez 1 piece de la banque', 'bleu', 1, '[2]', 'elevage', 1, 'aucun', 0, 1);        \
insert into Aucune VALUES('Cafe','Recevez 1 piece du joueur qui a lance les des', 'rouge', 2, '[3]', 'restauration', 1, 'aucun', 0, 1);       \
insert into Aucune VALUES('Superette','Recevez 3 pieces de la banque', 'vert', 2, '[4]', 'commerce', 3, 'aucun', 0, 1);       \
insert into Aucune VALUES('Foret', 'Recevez 1 piece de la banque', 'bleu', 3, '[5]', 'ressources', 1, 'aucun', 0, 1);         \
insert into Aucune VALUES('Stade', 'Recevez 2 pieces de la part de chaque autre joueur', 'violet', 6, '[6]', 'special', 2, 'aucun', 1, 2);        \
insert into Aucune VALUES('Centre d''affaires', 'Vous pouvez echanger avec le joueur de votre choix un etablissement qui ne soit pas de type special', 'violet', 8, '[6]', 'special', 0, 'aucun', 0, 2);          \
insert into Aucune VALUES('Chaine de television', 'Recevez 5 pieces du joueur de votre choix', 'violet', 7, '[6]', 'special', 5, 'aucun', 0, 2);          \
insert into Aucune VALUES('Fromagerie', 'Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez', 'vert', 5, '[7]','industrie', 3, 'elevage', 0, 1);       \
insert into Aucune VALUES('Fabrique de meubles', 'Recevez 3 pieces de la banque pour chaque etablissement de type ressources que vous possedez','vert', 3, '[8]', 'industrie', 3, 'ressources', 0, 1);        \
insert into Aucune VALUES('Mine', 'Recevez 5 pieces de la banque', 'bleu', 6, '[9]', 'ressources', 5, 'aucun', 0, 1);         \
insert into Aucune VALUES('Restaurant', 'Recevez 2 pieces du joueur qui a lance les des', 'rouge', 3, '[9, 10]', 'restauration', 2, 'aucun', 0, 1);       \
insert into Aucune VALUES('Verger', 'Recevez 3 pieces de la banque', 'bleu', 3, '[10]', 'agriculture', 3, 'aucun', 0, 1);         \
insert into Aucune VALUES('Marche de fruits et legumes', 'Recevez 2 pieces de la banque pour chaque etablissement de type agriculture que vous possedez', 'vert', 2, '[11, 12]', 'maraichage', 2, 'agriculture', 0, 1);       \
  \
  \
drop table if exists MarinaADD;       \
CREATE TABLE MarinaADD(       \
nom varchar PRIMARY KEY,          \
effet varchar,        \
couleur varchar NOT NULL CHECK(couleur in ('rouge','bleu', 'vert', 'violet')),        \
prix integer NOT NULL CHECK(prix>=0),         \
num_de JSON NOT NULL,         \
type1 varchar NOT NULL CHECK(type1 in ('agriculture',         \
    'elevage',        \
    'ressources',         \
    'maritime',       \
    'commerce',       \
    'industrie',          \
    'maraichage',         \
    'entreprise',         \
    'restauration',       \
    'special', 'aucun')),         \
montant_effet integer NOT NULL CHECK(montant_effet>=0),       \
type_effet varchar NOT NULL CHECK(type_effet in ('agriculture',       \
    'elevage',        \
    'ressources',         \
    'maritime',       \
    'commerce',       \
    'industrie',          \
    'maraichage',         \
    'entreprise',         \
    'restauration',       \
    'special', 'aucun')),         \
    payeur bool not null,         \
    identificateur integer not null       \
);        \
insert into MarinaADD VALUES('Hotel de ville','test', 'bleu', 0, '[1]', 'special', 1, 'aucun', 0, 0);       \
insert into MarinaADD VALUES('Sushi bar', 'Si vous avez le Port, recevez 3 pieces du joueur qui a lance les des', 'rouge', 2, '[1]', 'restauration', 3, 'aucun', 0, 1);    \
insert into MarinaADD VALUES('Champ de fleurs', 'Recevez 1 piece de la banque', 'bleu', 2, '[4]','agriculture', 1, 'aucun', 0, 1);    \
insert into MarinaADD VALUES('Fleuriste', 'Recevez 1 piece de la banque pour chaque Champ de fleurs que vous possedez','vert', 1, '[6]', 'commerce', 1, 'aucun', 0, 1);    \
insert into MarinaADD VALUES('Pizzeria', 'Recevez 1 piece du joueur qui a lance les des', 'rouge', 1, '[7]', 'restauration', 1, 'aucun', 0, 1);    \
insert into MarinaADD VALUES('Maison d''edition', 'Recevez 1 piece de chaque joueur pour chaque etablissement de type restauration et commerce qu''il possede', 'violet', 5, '[7]', 'special', 1, 'restauration', 1, 2);    \
insert into MarinaADD VALUES('Moonster burger', 'Recevez 1 piece du joueur qui a lance les des', 'rouge', 1, '[8]', 'restauration', 1, 'aucun', 0, 1);    \
insert into MarinaADD VALUES('Petit bateau de peche', 'Si vous avez le Port, recevez 3 pieces de la banque', 'bleu', 2, '[8]', 'maritime', 3, 'aucun', 0, 1);    \
insert into MarinaADD VALUES('Centre des impots', 'Recevez la moitie (arrondie a l''inferieur) des pieces de chaque joueur qui en possede 10 ou plus', 'violet', 4, '[8, 9]', 'special', 0, 'aucun', 1, 2);    \
insert into MarinaADD VALUES('Halle de marche', 'Recevez 2 pieces de la banque pour chaque etablissement de type restauration que vous possedez', 'vert', 2, '[12, 13]', 'industrie', 2, 'restauration', 0, 1);    \
insert into MarinaADD VALUES('Chalutier', 'Le joueur dont c''est le tour lance 2 des. Si vous avez le Port recevez de la banque autant de pieces que le total des 2 des', 'bleu', 5, '[12, 13, 14]', 'maritime', 0, 'aucun', 0, 1);    \
  \
  \
drop view if exists Marina;       \
CREATE VIEW Marina AS SELECT * FROM Aucune UNION SELECT * FROM MarinaADD;"  \
;

    rc = sqlite3_exec(db, sql.data(), 0, 0, &zErrMsg);
    
    if (rc != SQLITE_OK ) {
        cout<<"Creation failed"<<endl;
    } 
    
    sqlite3_close(db);
}

