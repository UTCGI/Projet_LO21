#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H
#include <iostream>
#include <string>

#include "TypesEnum.h"
#include "exception.h"

using namespace std;

class Etablissement {
 private:
  string nom;
  string effet;
  Couleur couleur;
  unsigned int prix;
  unsigned int num_de;  // from_1_to_12
  Type type;
  unsigned int montant_effet;
  Type type_effet;              // nouveau
  bool payeur;                  // nouveau
  unsigned int nb_exemplaires;  // nouveau

 public:
  string getNom() const { return nom; }
  string getEffet() const { return effet; }
  Couleur getCouleur() const { return couleur; }
  unsigned int getPrix() const { return prix; }
  unsigned int getNumDe() const { return num_de; }
  Type getType() const { return type; }
  unsigned int getMontant() const { return montant_effet; }
  Type getTypeEffet() const { return type_effet; }
  bool getPayeur() const { return payeur; }
  unsigned int getNbExemplaires() const { return nb_exemplaires; }

  Etablissement(const string& n, const string& e, Couleur color, unsigned int p,
                unsigned int d, Type t, unsigned int m, unsigned int te = 0,
                bool payeur = 0)
      : nom(n),
        effet(e),
        prix(p),
        num_de(d),
        type(t),
        couleur(color),
        montant_effet(m) {
    const string& etablissement_depart1 = "Champs de ble";
    const string& etablissement_depart2 = "Boulangerie";
    if (couleur == Couleur::violet)
      nb_exemplaires = 4;
    else {
      if (nom == etablissement_depart1 || nom == etablissement_depart2)
        nb_exemplaires = 8;
      else
        nb_exemplaires = 6;
    }
  };
  ~Etablissement() = default;
  bool estActif(unsigned int n) { return num_de == n; }
};

ostream& operator<<(ostream& f, const Etablissement* Etablissement) {
  f << "Nom : " << Etablissement->getNom() << endl
    << "Effet : " << Etablissement->getEffet() << endl
    << "Cout : " << Etablissement->getPrix() << endl
    << "Numero de de : " << Etablissement->getNumDe() << endl
    << "Type : " << toString(Etablissement->getType()) << endl
    << "Couleur : " << toString(Etablissement->getCouleur()) << endl
    << "Montant effet : " << Etablissement->getMontant() << " piece(s)" << endl;
  //<<"Nombre d exemplaires total : "<<Etablissement->getNbExemplaires()<<endl;
  return f;
};

#endif
