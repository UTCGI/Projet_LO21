-- SQLite
drop table if exists monument;

create table monument(
    nom varchar PRIMARY KEY,
    effet varchar not null,
    prix integer not null check(prix>=0)
);

insert into monument values("Gare", "Vous pouvez lancer deux des", 4);
insert into monument values("Centre commercial","Vos etablissement de type restauration et commerce rapportent une piece de plus", 10);
insert into monument values("Tour radio","Une fois par tour, vous pouvez choisir de relancer vos des", 22);
insert into monument values("Parc d'attractions","Si votre jet de des est un double, rejouez un tour apres celui-ci", 16);
