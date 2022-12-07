#include "jeu.h"
#include "buildfonctions.h"

Jeu::Jeu(Extension e) :
    extension(e){
    buildcaracteristics1(this, extension);
    buildetablissement(liste_etablissements, liste_etablissements_depart/* , liste_etablissements_speciaux */, extension);
    buildmonument(liste_monuments, extension);
}



void Jeu::printE_D(std::ostream& f) const {
    for (size_t i = 0; i < getNbEtablissements_Depart(); i++)
        f << "ETABLISSEMENTS DE DEPART" << endl << i + 1
        << endl << *liste_etablissements_depart[i];
    f << endl;
}
void Jeu::printE(std::ostream& f) const {
    for (size_t i = 0; i < getNbEtablissements(); i++)
        f << "ETABLISSEMENTS" << endl << i + 1 << endl << *liste_etablissements[i];
    f << endl;
}
void Jeu::printM(std::ostream& f) const {
    for (size_t i = 0; i < getNbMonuments(); i++)
        f << "MONUMENTS" << endl << i + 1 << endl << *liste_monuments[i];
    f << endl;
}

void Jeu::afficher(std::ostream& f) const {
    f << "\t " << extension << endl
        << "Condition de victoire \t\t: " << condition_de_victoire << endl
        << "Nombre de joueurs MAX \t\t: " << nb_joueurs_MAX << endl
        << "Nombre de pile_reserve MAX \t: " << nb_pile_reserve_MAX << endl
        << "soit " << nb_lignes_reserve_MAX << " lignes et "
        << nb_colonnes_reserve_MAX << " colonnes" << endl
        << "Nombre d'etablissements de depart : " << nbEtablissements_Depart << endl
        << "Nombre d'etablissements \t: " << nbEtablissements << endl
        << "Nombre de monuments \t\t: " << nbMonuments << endl
        << "Nombre total de cartes \t\t: " << nbCartes << endl << endl;
}

/*  const Etablissement* Jeu::getEtablissementFromName(const string& name)const {
      unsigned int i = 0;
      while (i<nbEtablissements && liste_etablissements[i]->getNom().compare(name) != 0) i++;
      if (liste_etablissements[i]->getNom().compare(name) != 0) {SetException("Cette carte n'existe pas");}
      else return liste_etablissements[i];
  } */

ostream& operator<<(ostream& f, const Jeu& j) {
    j.afficher(f);
    j.printE_D(f);
    j.printE(f);
    j.printM(f);
    //f << endl;
    return f;
}

