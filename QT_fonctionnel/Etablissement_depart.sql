-- SQLite
drop table if exists depart;


 CREATE TABLE Depart(
   nom varchar PRIMARY KEY,
   effet varchar,
   couleur varchar NOT NULL CHECK(couleur in ("rouge","bleu", "vert", "violet")),
   prix integer NOT NULL CHECK(prix>=0),
   num_de JSON NOT NULL,
   type1 varchar NOT NULL CHECK(type1 in ("agriculture",
    "elevage",
    "ressources",
    "maritime",
    "commerce",
    "industrie",
    "maraichage",
    "entreprise",
    "restauration",
    "special", "aucun")),
    montant_effet NOT NULL CHECK(montant_effet>=0),
   type_effet varchar NOT NULL CHECK(type_effet in ("agriculture",
    "elevage",
    "ressources",
    "maritime",
    "commerce",
    "industrie",
    "maraichage",
    "entreprise",
    "restauration",
    "special", "aucun")),
    payeur bool not null
);



insert into Depart VALUES("Champs de ble","Recevez 1 piece de la banque", "bleu", 0, '[1]', "agriculture", 1, "aucun", 0);
insert into Depart VALUES("Boulangerie","Recevez 1 piece de la banque", "vert", 0, '[2, 3]', "commerce", 1, "aucun", 0);



        