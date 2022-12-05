#include "etablissement.h"

string Etablissement::getNom() const { return nom; }

string Etablissement::getEffet() const { return effet; }

Couleur Etablissement::getCouleur() const { return couleur; }

unsigned int Etablissement::getPrix() const { return prix; }

vector<unsigned int> Etablissement::getNumDe() const { return num_de; }

Type Etablissement::getType() const { return type; }

unsigned int Etablissement::getMontant() const { return montant_effet; }

Type Etablissement::getTypeEffet() const { return type_effet; }

bool Etablissement::getPayeur() const { return payeur; }

unsigned int Etablissement::getNbExemplaires() const { return nb_exemplaires; }

Etablissement::Etablissement(const string& n, const string& e, Couleur color,
    unsigned int p, vector<unsigned int> d, Type t,
    unsigned int m, Type te, bool payeur) :
    nom(n),
    effet(e),
    couleur(color),
    prix(p),
    num_de(d),
    type(t),
    montant_effet(m),
    type_effet(te),
    payeur(payeur) {
    const string& etablissement_depart1 = "Champs de ble";
    const string& etablissement_depart2 = "Boulangerie";
    if ((couleur == Couleur::violet) || ((prix == 0)
        && (nom == etablissement_depart1 || nom == etablissement_depart2)))
        nb_exemplaires = 4;
    else
        nb_exemplaires = 6;
    //cout << "construit";
}

bool Etablissement::estActif(unsigned int n) {
    bool test = 0;
    vector<unsigned int> temp_vec = getNumDe();
    for (auto v : temp_vec){
        if(v==n)
            test = 1;
    }
    return test;

}
//1: vrai ; 0: faux

bool Etablissement::estSpecial() {
    return getType() == Type::special;
}
//FAUX ? -> faire une liste des etablissements 'Cas particuliers' ?

ostream& operator<<(ostream& f, const Etablissement& e) { 
     f << "Nom \t\t\t: " << e.getNom() << endl
        << "Effet \t\t\t: " << e.getEffet() << endl
        << "Prix \t\t\t: " << e.getPrix() << " piece";
    if (e.getPrix() > 1)    f << "s";
    f<<endl<< "Numero de de \t\t: ";
    for (auto v : e.getNumDe()){
        f<<v<<" ";
    }
    f<<endl<<"Type \t\t\t: " << e.getType() << endl
        << "Couleur \t\t: " << e.getCouleur() << endl
        << "Montant effet \t\t: " << e.getMontant() << " piece";
    if (e.getMontant() > 1)    f << "s";
    f << endl << "Nombre d exemplaires \t: " 
        << e.getNbExemplaires() << endl << endl;
    return f;
}