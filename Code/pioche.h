#include "pile_etablissement.h"
#include "jeu.h"

class Pioche{
*Pile_Etablissement[] piles_etablissement;
unsigned int nb_etablissements;
unsigned int nb_piles;
}
Pioche(&Jeu jeu){
nb_piles=jeu.getNbEtablissements();
piles_etablissement=new *Pile_Etablissement[nb_piles];
for (i=0;i<nb_piles;i++){
        Pile_Etablissement[i]= Pile_Etablissement(jeu.getEtablissement(i),jeu.getEtablissement(i).getNbExemplaires())
        }
}
//nécessite itérateur dans jeu
*Etablissement getRandomEtablissement(){ //a transformer en iterateur ?
    unsigned int numero_etablissement = rand() % nb_etablissements;
    unsigned int nb_etablissements_parcourus =0;
    unsigned int i=0;
    while (unsigned int nb_etablissements_parcourus<numero_etablissement){
        nb_etablissements_parcourus+=piles_etablissement[i].getEffectif();
        i++;
    }
    return piles_etablissement[i].getEtablissement();
}
*Pile_Etablissement getPile(*Etablissement etablissement);
void retirer_Etablissement(*Etablissement etablissement, unsigned int quantité=1);//appelle getPile
}
