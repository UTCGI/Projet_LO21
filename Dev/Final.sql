/*  
    Comment sont structurées les données ?
        1 Monument est la base pour les cartes Monument dans la version basique du jeu
        2 Aucune est la base pour les cartes établissement dans la version basique du jeu
        3 Chaque extension doit être construite de la façon suivant (Exemple : Marina)
            1 Une table sera déclarée, intitulée MarinaADD, qui contient les cartes établissement que l'on rajoute à la version basique
            2 Une vue sera créée, intitulée Marina, qui sélectionne et combine les tables nécessaires pour la constituer
            3 En cas où l'exclusion de cartes est nécessaire, utiliser EXCEPT ou faire une réstriction sur la VALUES
        


*/


drop table if exists Jeu;     
CREATE TABLE Jeu(     
nom varchar PRIMARY KEY CHECK(nom in ('Aucune','Marina', 'GreenValley', 'Deluxe')),     
condition_de_victoire integer NOT NULL CHECK(condition_de_victoire>0),     
nb_joueurs_MAX integer NOT NULL CHECK(nb_joueurs_MAX>=2),     
nb_pile_reserve_MAX integer NOT NULL CHECK(nb_pile_reserve_MAX>=9),     
nb_lignes_reserve_MAX integer NOT NULL CHECK(nb_lignes_reserve_MAX>=2),     
nb_colonnes_reserve_MAX integer NOT NULL CHECK(nb_colonnes_reserve_MAX>=3),     
nbEtablissements_Depart integer NOT NULL CHECK(nbEtablissements_Depart>=2),     
nbEtablissements integer NOT NULL CHECK(nbEtablissements>=15),     
nbMonuments integer NOT NULL CHECK(nbMonuments>=4),     
nbCartes integer NOT NULL CHECK(nbCartes>=108)     
);     
insert into Jeu VALUES('Aucune', 4, 4, 15, 3, 5, 2, 15, 4, 108);     
insert into Jeu VALUES('Marina', 6, 4, 10, 2, 5, 3, 25, 6, 176);     
insert into Jeu VALUES('GreenValley', 4, 4, 10, 2, 5, 2, 28, 4, 180);     
insert into Jeu VALUES('Deluxe', 5, 5, 9, 3, 3, 2, 28, 6, 165);     
  
  
  
  
drop table if exists AucuneMonument;   
drop table if exists Marina1Monument;   
drop view if exists MarinaMonument;   
create table AucuneMonument(   
nom varchar PRIMARY KEY,   
effet varchar not null,   
prix integer not null check(prix>=0));   
create table Marina1Monument(   
nom varchar PRIMARY KEY,   
effet varchar not null,   
prix integer not null check(prix>=0));   
CREATE VIEW MarinaMonument AS SELECT * FROM AucuneMonument UNION SELECT * FROM Marina1Monument;   
insert into AucuneMonument values('Gare', 'Vous pouvez lancer deux des', 4);   
insert into AucuneMonument values('Centre commercial','Vos etablissements de type restauration et commerce rapportent une piece de plus', 10);   
insert into AucuneMonument values('Tour radio','Une fois par tour, vous pouvez choisir de relancer vos des', 22);   
insert into AucuneMonument values('Parc d''attractions','Si votre jet de des est un double, rejouez un tour apres celui-ci', 16);   
insert into Marina1Monument values('Port','Si le resultat de votre jet de des est de 10 ou plus, vous pouvez ajouter 2 a ce resultat', 2);   
insert into Marina1Monument values('Aeroport','Si vous n''avez rien construit pendant votre tour, recevez 10 pieces de la banque', 30);   

drop view if exists GreenValleyMonument;   
CREATE VIEW GreenValleyMonument AS SELECT * FROM AucuneMonument;   

drop view if exists DeluxeMonument;   
CREATE VIEW DeluxeMonument AS SELECT * FROM MarinaMonument;   

  
  
  
  
drop table if exists Aucune;    
CREATE TABLE Aucune(          
nom varchar,          
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
    identificateur integer not null,       
    PRIMARY KEY(nom, identificateur)       
);        
insert into Aucune VALUES('Champs de ble','Recevez 1 piece de la banque', 'bleu', 0, '[1]', 'agriculture', 1, 'aucun', 0, 0);         
insert into Aucune VALUES('Boulangerie','Recevez 1 piece de la banque', 'vert', 0, '[2, 3]', 'commerce', 1, 'aucun', 0, 0);       

insert into Aucune VALUES('Champs de ble','Recevez 1 piece de la banque', 'bleu', 1, '[1]', 'agriculture', 1, 'aucun', 0, 1);         
insert into Aucune VALUES('Boulangerie','Recevez 1 piece de la banque', 'vert', 1, '[2, 3]', 'commerce', 1, 'aucun', 0, 1);       
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
nom varchar,          
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
    identificateur integer not null,       
    PRIMARY KEY(nom, identificateur)       
);        
insert into MarinaADD VALUES('Hotel de ville','Avant de construire un etablissement ou un monument, si vous n''avez pas de piece, recevez 1 piece de la banque', 'violet', 0, '[0]', 'special', 1, 'aucun', 0, 0);       
insert into MarinaADD VALUES('Sushi bar', 'Si vous avez le Port, recevez 3 pieces du joueur qui a lance les des', 'rouge', 2, '[1]', 'restauration', 3, 'aucun', 0, 1);    
insert into MarinaADD VALUES('Champ de fleurs', 'Recevez 1 piece de la banque', 'bleu', 2, '[4]','agriculture', 1, 'aucun', 0, 1);    
insert into MarinaADD VALUES('Fleuriste', 'Recevez 1 piece de la banque pour chaque Champ de fleurs que vous possedez','vert', 1, '[6]', 'commerce', 1, 'aucun', 0, 1);    
insert into MarinaADD VALUES('Pizzeria', 'Recevez 1 piece du joueur qui a lance les des', 'rouge', 1, '[7]', 'restauration', 1, 'aucun', 0, 1);    
insert into MarinaADD VALUES('Maison d''edition', 'Recevez 1 piece de chaque joueur pour chaque etablissement de type restauration et commerce qu''il possede', 'violet', 5, '[7]', 'special', 1, 'restauration', 1, 2);    
insert into MarinaADD VALUES('Moonster burger', 'Recevez 1 piece du joueur qui a lance les des', 'rouge', 1, '[8]', 'restauration', 1, 'aucun', 0, 1);    
insert into MarinaADD VALUES('Petit bateau de peche', 'Si vous avez le Port, recevez 3 pieces de la banque', 'bleu', 2, '[8]', 'maritime', 3, 'aucun', 0, 1);    
insert into MarinaADD VALUES('Centre des impots', 'Recevez la moitie (arrondie a l''inferieur) des pieces de chaque joueur qui en possede 10 ou plus', 'violet', 4, '[8, 9]', 'special', 0, 'aucun', 1, 2);    
insert into MarinaADD VALUES('Halle de marche', 'Recevez 2 pieces de la banque pour chaque etablissement de type restauration que vous possedez', 'vert', 2, '[12, 13]', 'industrie', 2, 'restauration', 0, 1);    
insert into MarinaADD VALUES('Chalutier', 'Le joueur dont c''est le tour lance 2 des. Si vous avez le Port recevez de la banque autant de pieces que le total des 2 des', 'bleu', 5, '[12, 13, 14]', 'maritime', 0, 'aucun', 0, 1);    
  
  
drop view if exists Marina;       
CREATE VIEW Marina AS SELECT * FROM Aucune UNION SELECT * FROM MarinaADD;  
  
  
drop table if exists GreenValleyADD;       
CREATE TABLE GreenValleyADD(
nom varchar, 
effet varchar, 
couleur varchar NOT NULL CHECK(couleur in('rouge', 'bleu', 'vert', 'violet')), 
prix integer NOT NULL CHECK(prix >= 0), 
num_de JSON NOT NULL, 
type1 varchar NOT NULL CHECK(type1 in('agriculture', 
    'elevage', 
    'ressources', 
    'maritime', 
    'commerce', 
    'industrie', 
    'maraichage', 
    'entreprise', 
    'restauration', 
    'special', 'aucun')), 
montant_effet integer NOT NULL CHECK(montant_effet >= -2), 
type_effet varchar NOT NULL CHECK(type_effet in('agriculture', 
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
identificateur integer not null, 
PRIMARY KEY(nom, identificateur)       
);        
insert into GreenValleyADD VALUES('Epicerie', 'Si vous possedez moins de deux monuments, recevez 2 pieces de la banque', 'vert', 0, '[2]', 'commerce', 2, 'aucun', 0, 1);        
insert into GreenValleyADD VALUES('Champ de mais', 'Si vous possedez moins de deux monuments, recevez 1 piece de la banque', 'bleu', 2, '[3, 4]','agriculture', 1, 'aucun', 0, 1);        
insert into GreenValleyADD VALUES('Entreprise de travaux publics', 'Vous devez retourner une de vos cartes monuments sur sa face en travaux. Ce faisant, recevez 8 pieces de la banque','vert', 2, '[4]', 'entreprise', 8, 'aucun', 0, 1);        
insert into GreenValleyADD VALUES('Restaurant 5 etoiles', 'Recevez 5 pieces du joueur qui a lance les des si celui-ci possede au moins deux monuments construits', 'rouge', 3, '[5]', 'restauration', 5, 'aucun', 0, 1);        
insert into GreenValleyADD VALUES('Banque de Minivilles', 'Lorsque vous achetez cet etablissement, recevez 5 pieces de la banque. Payez 2 pieces a la banque', 'vert', 0, '[5, 6]', 'entreprise', -2, 'aucun', 0, 1);        
insert into GreenValleyADD VALUES('Vignoble', 'Recevez 3 pieces de la banque', 'bleu', 3, '[7]', 'agriculture', 3, 'aucun', 0, 1);        
insert into GreenValleyADD VALUES('Entreprise de renovation', 'Choisissez un etablissement qui ne soit pas de type special. Tous les etablissements identiques de tous les joueurs sont fermes. Puis recevez 1 piece de la banque pour chaque etablissement ainsi ferme', 'violet', 4, '[8]', 'special', 1, 'aucun', 1, 2);        
insert into GreenValleyADD VALUES('Cave a vin', 'Recevez 6 pieces de la banque pour chaque Vignoble que vous possedez. Puis fermez cette Cave a vin', 'vert', 3, '[9]', 'industrie', 6, 'aucun', 0, 1);        
insert into GreenValleyADD VALUES('Entreprise de demenagement', 'Donnez a un autre joueur, un de vos etablissements qui ne soit pas de type special. Puis recevez 4 pieces de la banque', 'vert', 2, '[9, 10]', 'entreprise', 4, 'aucun', 0, 1);        
insert into GreenValleyADD VALUES('Startup', 'Recevez 1 piece de la banque pour chaque piece placee sur l''ensemble des Startups de tous les joueurs. A la fin de votre tour, placez une piece sur votre Startup', 'violet', 1, '[10]', 'special', 1, 'aucun', 0, 2);        
insert into GreenValleyADD VALUES('Moonster soda', 'Recevez 1 piece de la banque pour chaque etablissement de type restauration que possedent tous les joueurs', 'vert', 5, '[11]', 'industrie', 1, 'restauration', 0, 1);        
insert into GreenValleyADD VALUES('Arboretum', 'Rassemblez les pieces de tous les joueurs puis redistribuez-les de maniere egale entre tous. La banque completera s''il manque des pieces pour une redistribution egale', 'violet', 3, '[11, 12, 13]', 'special', 0, 'aucun', 0, 2);        
insert into GreenValleyADD VALUES('Club prive', 'Recevez toutes les pieces du joueur qui a lance les des si celui-ci possede au moins trois etablissements construits', 'rouge', 4, '[12, 13, 14]', 'restauration', 0, 'aucun', 0, 1);        


drop view if exists GreenValley;       
CREATE VIEW GreenValley AS SELECT * FROM Aucune UNION SELECT * FROM GreenValleyADD;  
  
  
drop table if exists DeluxeEXCEPT;       
CREATE TABLE DeluxeEXCEPT(
nom varchar, 
effet varchar, 
couleur varchar NOT NULL CHECK(couleur in('rouge', 'bleu', 'vert', 'violet')), 
prix integer NOT NULL CHECK(prix >= 0), 
num_de JSON NOT NULL, 
type1 varchar NOT NULL CHECK(type1 in('agriculture', 
    'elevage', 
    'ressources', 
    'maritime', 
    'commerce', 
    'industrie', 
    'maraichage', 
    'entreprise', 
    'restauration', 
    'special', 'aucun')), 
montant_effet integer NOT NULL CHECK(montant_effet >= -2), 
type_effet varchar NOT NULL CHECK(type_effet in('agriculture', 
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
identificateur integer not null, 
PRIMARY KEY(nom, identificateur)       
);        

insert into DeluxeEXCEPT VALUES('Hotel de ville','Avant de construire un etablissement ou un monument, si vous n''avez pas de piece, recevez 1 piece de la banque', 'violet', 0, '[0]', 'special', 1, 'aucun', 0, 0);        
insert into DeluxeEXCEPT VALUES('Fromagerie', 'Recevez 3 pieces de la banque pour chaque etablissement de type elevage que vous possedez', 'vert', 5, '[7]','industrie', 3, 'elevage', 0, 1);        
insert into DeluxeEXCEPT VALUES('Champ de mais', 'Si vous possedez moins de deux monuments, recevez 1 piece de la banque', 'bleu', 2, '[3, 4]','agriculture', 1, 'aucun', 0, 1);        
insert into DeluxeEXCEPT VALUES('Banque de Minivilles', 'Lorsque vous achetez cet etablissement, recevez 5 pieces de la banque. Payez 2 pieces a la banque', 'vert', 0, '[5, 6]', 'entreprise', -2, 'aucun', 0, 1);        
insert into DeluxeEXCEPT VALUES('Cave a vin', 'Recevez 6 pieces de la banque pour chaque Vignoble que vous possedez. Puis fermez cette Cave a vin', 'vert', 3, '[9]', 'industrie', 6, 'aucun', 0, 1);        
insert into DeluxeEXCEPT VALUES('Sushi bar', 'Si vous avez le Port, recevez 3 pieces du joueur qui a lance les des', 'rouge', 2, '[1]', 'restauration', 3, 'aucun', 0, 1);        
insert into DeluxeEXCEPT VALUES('Champ de fleurs', 'Recevez 1 piece de la banque', 'bleu', 2, '[4]','agriculture', 1, 'aucun', 0, 1);        
insert into DeluxeEXCEPT VALUES('Fleuriste', 'Recevez 1 piece de la banque pour chaque Champ de fleurs que vous possedez','vert', 1, '[6]', 'commerce', 1, 'aucun', 0, 1);        
insert into DeluxeEXCEPT VALUES('Entreprise de renovation', 'Choisissez un etablissement qui ne soit pas de type special. Tous les etablissements identiques de tous les joueurs sont fermes. Puis recevez 1 piece de la banque pour chaque etablissement ainsi ferme', 'violet', 4, '[8]', 'special', 1, 'aucun', 1, 2);        
insert into DeluxeEXCEPT VALUES('Startup', 'Recevez 1 piece de la banque pour chaque piece placee sur l''ensemble des Startups de tous les joueurs. A la fin de votre tour, placez une piece sur votre Startup', 'violet', 1, '[10]', 'special', 1, 'aucun', 0, 2);        
insert into DeluxeEXCEPT VALUES('Arboretum', 'Rassemblez les pieces de tous les joueurs puis redistribuez-les de maniere egale entre tous. La banque completera s''il manque des pieces pour une redistribution egale', 'violet', 3, '[11, 12, 13]', 'special', 0, 'aucun', 0, 2);        


drop view if exists Deluxe;       
CREATE VIEW Deluxe AS SELECT * FROM Marina UNION SELECT * FROM GreenValleyADD EXCEPT SELECT * FROM DeluxeEXCEPT;



  