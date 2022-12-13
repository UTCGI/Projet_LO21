#include "etablissement.h"
#include <vector>

// Methodes de classe mere Etablissement

Etablissement::Etablissement(const string& nom1, const string& effet1, Couleur couleur1,
    unsigned int prix1, vector<unsigned int> num_de1, Type type1,
    unsigned int montant_effet1, bool isSpecial1, int nb_exemplaires)
    : nom(nom1)
    , effet(effet1)
    , couleur(couleur1)
    , prix(prix1)
    , num_de(num_de1)
    , type(type1)
    , montant_effet(montant_effet1)
    , isSpecial(isSpecial1)
    , nb_exemplaires(nb_exemplaires)
{
}

string Etablissement::getNom() const { return nom; }
string Etablissement::getEffet() const { return effet; }
Couleur Etablissement::getCouleur() const { return couleur; }
unsigned int Etablissement::getPrix() const { return prix; }
vector<unsigned int> Etablissement::getNumDe() const { return num_de; }
Type Etablissement::getType() const { return type; }
unsigned int Etablissement::getMontant() const { return montant_effet; }
unsigned int Etablissement::getNbExemplaires() const { return nb_exemplaires; }
bool Etablissement::getIsSpecial() const { return isSpecial; }

bool Etablissement::estActif(unsigned int n)
{
    bool test = 0;
    vector<unsigned int> temp_vec = getNumDe();
    for (auto v : temp_vec) {
        if (v == n)
            test = 1;
    }
    return test;
}

bool Etablissement::estSpecial()
{
    return getType() == Type::special;
}

void Etablissement::afficher(std::ostream& f) const
{
    f << endl
      << "Nom \t\t\t: " << nom << endl
      << "Effet \t\t\t: " << effet << endl
      << "Prix \t\t\t: " << prix << " piece";
    if (prix > 1)
        cout << "s";
    f << endl
      << "Numero de de \t\t: ";
    for (auto v : num_de) {
        f << v << " ";
    }
    f << endl
      << "Type  \t\t\t: " << type << endl
      << "Couleur \t\t: " << couleur << endl
      << "Montant effet \t\t: " << montant_effet << " piece";
    if (montant_effet > 1)
        f << "s";
    f << endl
      << "Nombre d exemplaires \t: "
      << nb_exemplaires << endl;
    if (isSpecial)
        f << "carte\t\t\t: speciale" << endl;
    else {
        f << "carte\t\t\t: standard" << endl;
    }
}

// Methodes de classes Etalissement_VertTE
Etablissement_VertTE::Etablissement_VertTE(const string& nom1, const string& effet1, Couleur couleur1,
    unsigned int prix1, vector<unsigned int> num_de1, Type type1,
    unsigned int montant_effet1, bool isSpecial1, int nb_exemplaires, Type type_effet1)
    : Etablissement(nom1, effet1, couleur1, prix1, num_de1, type1, montant_effet1, isSpecial1, nb_exemplaires)
    , type_effet(type_effet1) {};

Type Etablissement_VertTE::getTypeEffet() const { return type_effet; }

void Etablissement_VertTE::Etablissement_VertTE::afficher(std::ostream& f) const
{
    Etablissement::afficher(f);
    f << "Type effet \t\t: " << type_effet << endl;
}

// Methodes de classes Etalissement_Violet
Etablissement_Violet::Etablissement_Violet(const string& nom1, const string& effet1, Couleur couleur1,
    unsigned int prix1, vector<unsigned int> num_de1, Type type1,
    unsigned int montant_effet1, bool isSpecial1, int nb_exemplaires, bool payeur1)
    : Etablissement(nom1, effet1, couleur1, prix1, num_de1, type1, montant_effet1, isSpecial1, nb_exemplaires)
    , payeur(payeur1) {};
bool Etablissement_Violet::Etablissement_Violet::getPayeur() const { return payeur; }

void Etablissement_Violet::Etablissement_Violet::afficher(std::ostream& f) const
{
    Etablissement::afficher(f);
    f << "Payeur \t\t\t: ";
    if (payeur)
        f << "Un joueur de votre choix" << endl;
    else
        f << "Tous les autres joueurs" << endl;
}

// AUTRES METHODES
// UTILISER DE PREFERENCE LA METHODE DE CLASSE AFFICHEE POUR AVOIR TOUTES LES DONNES
ostream& operator<<(ostream& f, const Etablissement& e)
{

    f << "Nom \t\t\t: " << e.getNom() << endl
      << "Effet \t\t\t: " << e.getEffet() << endl
      << "Prix \t\t\t: " << e.getPrix() << " piece";
    if (e.getPrix() > 1)
        f << "s";
    f << endl
      << "Numero de de \t\t: ";
    for (auto v : e.getNumDe()) {
        f << v << " ";
    }
    f << endl
      << "Type  \t\t\t: " << e.getType() << endl
      << "Couleur \t\t: " << e.getCouleur() << endl
      << "Montant effet \t\t: " << e.getMontant() << " piece";
    if (e.getMontant() > 1)
        f << "s";
    f << endl
      << "Nombre d exemplaires \t: "
      << e.getNbExemplaires() << endl;
    return f;
}

bool Etablissement::operator==(Etablissement e1) const { return this->nom.compare(e1.getNom()) == 0; }
bool Etablissement::operator!=(Etablissement e1) const { return this->nom.compare(e1.getNom()) != 0; }
