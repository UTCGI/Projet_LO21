#include "pioche.h"

//Getters
unsigned int Pioche::getNb_etablissements() const {return nb_etablissements;}
unsigned int Pioche::getNb_piles()const {return nb_piles;}

//Constructeur et destructeur
Pioche:: Pioche(const Jeu& jeu) {
    nb_piles = jeu.getNbEtablissements();
    piles_etablissement = new *Pile_Etablissement[nb_piles];
    for (unsigned int i = 0; i < nb_piles; i++) {
      Pile_Etablissement[i] = Pile_Etablissement(
          jeu.getEtablissement(i), jeu.getEtablissement(i).getNbExemplaires())
    }
  }
Pioche::~Pioche(){delete[]piles_etablissement;}

//Autres methodes de classe
const Etablissement& Pioche::getRandomEtablissement() const {
    unsigned int numero_etablissement = rand() % nb_etablissements;
    unsigned int nb_etablissements_parcourus = 0;
    unsigned int i = 0;
    while (unsigned int nb_etablissements_parcourus < numero_etablissement) {
      nb_etablissements_parcourus += piles_etablissement[i].getEffectif();
      i++;
    }
    return piles_etablissement[i].getEtablissement();
  }

unsigned int Pioche::getIndexPile(const Etablissement& etablissement)const {
unsigned int i=0;
while (piles_etablissement[i] != etablissement && i<nb_piles) i++;
return i;
}

void Pioche::retirer_Etablissement(const Etablissement& etablissement, unsigned int quantite= 1){
unsigned int indexPile = getIndexPile(etablissement);
piles_etablissement[indexPile].retirerCarte(quantite);
if (piles_etablissement[indexPile].getEffectif()==0){
    for (i=indexPile; i<nb_piles;i++) piles_etablissement[i]=piles_etablissement[i+1];
    delete &piles_etablissement[nb];
    nb_piles--;
}
}//pourrait aussi etre realise avec la librairie <array>

void Pioche::afficher()const{
cout<<"******Pioche******"<<endl<<endl;
for (unsigned int i = 0; i < nb_piles; i++) cout<<piles_etablissement[i];
cout<<"******EndPioche******"<<endl<<endl;
}
//FONCTION DE TEST
int testPioche(){
Jeu jeu1 = Jeu();
Pioche pioche1 = Pioche(jeu1);
pioche1.afficher();
cout<<"test getRandomEtablissement";
const Etablissement& e1 = pioche1.getRandomEtablissement;
cout<<"test retirer etablissement"
pioche1.retirer_Etablissement(e1,2);
pioche1.afficher();
}

