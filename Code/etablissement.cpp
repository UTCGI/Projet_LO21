#include "etablissement.h"

string Etablissement::getNom() const { return nom; }

string Etablissement::getEffet() const { return effet; }

Couleur Etablissement::getCouleur() const { return couleur; }

unsigned int Etablissement::getPrix() const { return prix; }

unsigned int Etablissement::getNumDe() const { return num_de; }

Type Etablissement::getType() const { return type; }

unsigned int Etablissement::getMontant() const { return montant_effet; }

Type Etablissement::getTypeEffet() const { return type_effet; }

bool Etablissement::getPayeur() const { return payeur; }

unsigned int Etablissement::getNbExemplaires() const { return nb_exemplaires; }

Etablissement::Etablissement(const string& n, const string& e, Couleur color,
                             unsigned int p, unsigned int d, Type t,
                             unsigned int m, Type te, bool paye = 0)
    : nom(n),
      effet(e),
      couleur(color),
      prix(p),
      num_de(d),
      type(t),
      montant_effet(m),
      type_effet(te),
      payeur(paye) {
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
}

bool Etablissement::estActif(unsigned int n) { return num_de == n; }

bool Etablissement::estSpecial() {
  // TODO: To Implement
}

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
}