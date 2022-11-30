/*  
    Comment sont structurées les données ?
        1 Monument est la base pour les cartes Monument dans la version basique du jeu
        2 Aucune est la base pour les cartes établissement dans la version basique du jeu
        3 Chaque extension doit être construite de la façon suivant (Exemple : Marina)
            1 Une table sera déclarée, intitulée MarinaADD, qui contient les cartes établissement que l'on rajoute à la version basique
            2 Une vue sera créée, intitulée Marina, qui sélectionne et combine les tables nécessaires pour la constituer
            3 En cas où l'exclusion de cartes est nécessaire, utiliser EXCEPT ou faire une réstriction sur la VALUES
        


*/


drop table if exists Monument;
create table Monument(
nom varchar PRIMARY KEY,
effet varchar not null,
prix integer not null check(prix>=0));
insert into Monument values('Gare', 'Vous pouvez lancer deux des', 4);
insert into Monument values('Centre commercial','Vos etablissement de type restauration et commerce rapportent une piece de plus', 10);
insert into Monument values('Tour radio','Une fois par tour, vous pouvez choisir de relancer vos des', 22);
insert into Monument values('Parc dattractions','Si votre jet de des est un double, rejouez un tour apres celui-ci', 16);



drop table if exists Aucune;
CREATE TABLE Aucune(
nom varchar PRIMARY KEY,
effet varchar,
couleur varchar NOT NULL CHECK(couleur in ('rouge','bleu', 'vert', 'violet')),
prix integer NOT NULL CHECK(prix>=0),
num_de JSON NOT NULL,
type1 varchar NOT NULL CHECK(type1 in ('agriculture',
    'elevage',
    'ressources',
    'maritime',
    'commerce',
    'industrie',
    'maraichage',
    'entreprise',
    'restauration',
    'special', 'aucun')),
    montant_effet integer NOT NULL CHECK(montant_effet>=0),
type_effet varchar NOT NULL CHECK(type_effet in ('agriculture',
    'elevage',
    'ressources',
    'maritime',
    'commerce',
    'industrie',
    'maraichage',
    'entreprise',
    'restauration',
    'special', 'aucun')),
    payeur bool not null,
    identificateur integer not null
);

insert into Aucune VALUES('Champs de ble','Recevez 1 piece de la banque', 'bleu', 0, '[1]', 'agriculture', 1, 'aucun', 0, 0);
insert into Aucune VALUES('Boulangerie','Recevez 1 piece de la banque', 'vert', 0, '[2, 3]', 'commerce', 1, 'aucun', 0, 0);

insert into Aucune VALUES('Ferme', 'Recevez 1 piece de la banque', 'bleu', 1, '[2]', 'elevage', 1, 'aucun', 0, 1);
insert into Aucune VALUES('Cafe','Recevez 1 piece du joueur qui a lance les des', 'rouge', 2, '[3]', 'restauration', 1, 'aucun', 0, 1);
insert into Aucune VALUES('Superette','Recevez 3 pieces de la banque', 'vert', 2, '[4]', 'commerce', 3, 'aucun', 0, 1);
insert into Aucune VALUES('Foret', 'Recevez 1 piece de la banque', 'bleu', 3, '[5]', 'ressources', 1, 'aucun', 0, 1);
insert into Aucune VALUES('Stade', 'Recevez 2 pieces de la part de chaque autre joueur', 'violet', 6, '[6]', 'special', 2, 'aucun', 1, 2);
insert into Aucune VALUES('Centre d''affaires', 'Vous pouvez echanger avec le joueur de votre choix un etablissement qui ne soit pas de type special', 'violet', 8, '[6]', 'special', 0, 'aucun', 0, 2);
insert into Aucune VALUES('Chaine de television', 'Recevez 5 pieces du joueur de votre choix', 'violet', 7, '[6]', 'special', 5, 'aucun', 0, 2);
insert into Aucune VALUES('Fromagerie', 'Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez', 'vert', 5, '[7]','industrie', 3, 'elevage', 0, 1);
insert into Aucune VALUES('Fabrique de meubles', 'Recevez 3 pieces de la banque pour chaque etablissement de type ressources que vous possedez','vert', 3, '[8]', 'industrie', 3, 'ressources', 0, 1);
insert into Aucune VALUES('Mine', 'Recevez 5 pieces de la banque', 'bleu', 6, '[9]', 'ressources', 5, 'aucun', 0, 1);
insert into Aucune VALUES('Restaurant', 'Recevez 2 pieces du joueur qui a lance les des', 'rouge', 3, '[9, 10]', 'restauration', 2, 'aucun', 0, 1);
insert into Aucune VALUES('Verger', 'Recevez 3 pieces de la banque', 'bleu', 3, '[10]', 'agriculture', 3, 'aucun', 0, 1);
insert into Aucune VALUES('Marche de fruits et legumes', 'Recevez 2 pieces de la banque pour chaque etablissement de type agriculture que vous possedez', 'vert', 2, '[11, 12]', 'maraichage', 2, 'agriculture', 0, 1);




drop table if exists MarinaADD;
CREATE TABLE MarinaADD(
nom varchar PRIMARY KEY,
effet varchar,
couleur varchar NOT NULL CHECK(couleur in ('rouge','bleu', 'vert', 'violet')),
prix integer NOT NULL CHECK(prix>=0),
num_de JSON NOT NULL,
type1 varchar NOT NULL CHECK(type1 in ('agriculture',
    'elevage',
    'ressources',
    'maritime',
    'commerce',
    'industrie',
    'maraichage',
    'entreprise',
    'restauration',
    'special', 'aucun')),
montant_effet integer NOT NULL CHECK(montant_effet>=0),
type_effet varchar NOT NULL CHECK(type_effet in ('agriculture',
    'elevage',
    'ressources',
    'maritime',
    'commerce',
    'industrie',
    'maraichage',
    'entreprise',
    'restauration',
    'special', 'aucun')),
    payeur bool not null,
    identificateur integer not null
);
insert into MarinaADD VALUES('Chaine de television1','Recevez 5 pieces du joueur de votre choix', 'violet', 7, '[6]', 'special', 5, 'aucun', 0, 1);
insert into MarinaADD VALUES('Fromagerie1', 'Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez', 'vert', 5, '[7]', 'industrie', 3, 'elevage', 0, 1);
insert into MarinaADD VALUES('Fabrique de meubles1', 'Recevez 3 pieces de la banque pour chaque etablissement de type ressources que vous possedez', 'vert',3, '[8]', 'industrie', 3, 'ressources', 0, 1);
insert into MarinaADD VALUES('Mine1', 'Recevez 5 pieces de la banque','bleu', 6, '[9]', 'ressources', 5, 'aucun', 0, 1);


drop view if exists Marina;
CREATE VIEW Marina AS SELECT * FROM Aucune UNION SELECT * FROM MarinaADD;






