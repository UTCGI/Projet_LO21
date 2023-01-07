#include "etablissements_speciaux.h"

void traiterEtablissementSpecial(const string& nom, const vector<Joueur*>& joueurs, Joueur* joueur,  Pile_Etablissement* pile){
  if(nom == "Chaine de television")traiterChaineDeTelevision();
  else if (nom == "Centre d'affaires")traiterCentredAffaire();
  else if (nom == "Stade")traiterStade(joueurs, joueur,pile);
}
void traiterChaineDeTelevision(){

}
void traiterCentredAffaire(){

};
void traiterStade(const vector<Joueur*>& joueurs, Joueur* joueur, Pile_Etablissement* p){
                cout << "      *" << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
                cout << "      " << p->getEtablissement()->getEffet() << endl;
                if (p->getEffectif() == 1) {
                    cout << "Voici les comptes des autres joueurs" << endl;
                    int j = 1;
                    for (auto joueurADebiter : joueurs) {
                        if (joueur != joueurADebiter) {
                            cout << "J" << j++ << endl;
                            cout << "AVANT : " << joueurADebiter->getCompte() << endl;

                            if (joueurADebiter->getCompte() >= p->getEtablissement()->getMontant()) {
                                joueurADebiter->ajouterMontant((-1) * p->getEtablissement()->getMontant());
                                joueur->ajouterMontant(p->getEtablissement()->getMontant());
                            }
                            else {
                                joueur->ajouterMontant(joueurADebiter->getCompte());
                                joueurADebiter->ajouterMontant((-1) * joueurADebiter->getCompte());
                            }
                            cout << "APRES : " << joueurADebiter->getCompte() << endl << endl;
                        }
                        else j++;
                    }
                }
}