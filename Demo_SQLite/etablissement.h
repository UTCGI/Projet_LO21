#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H

#include "miniville.h"
#include <vector>
class Etablissement {
 private:
  string nom;
  string effet;
  Couleur couleur;
  unsigned int prix;
  //unsigned int num_de;  // from_1_to_12
  vector<unsigned int> num_de;
  Type type;
  unsigned int montant_effet;
  Type type_effet;              // nouveau
  bool payeur;                  // nouveau
  unsigned int nb_exemplaires;  // nouveau

 public:
  // Getters
  string getNom() const;
  string getEffet() const;
  Couleur getCouleur() const;
  unsigned int getPrix() const;
  vector<unsigned int> getNumDe() const;
  Type getType() const;
  unsigned int getMontant() const;
  Type getTypeEffet() const;
  bool getPayeur() const;
  unsigned int getNbExemplaires() const;

  // Constructors and destructors functions
  Etablissement(const string& n, const string& e, Couleur color, unsigned int p,
                vector<unsigned int> d, Type t, unsigned int m, Type te,
                bool payeur = 0);

  ~Etablissement() = default;

  // Methods
  bool estActif(unsigned int n);

  // TODO : Implement estSpecial Function
  // Que fait cette fonction ?
  bool estSpecial();
};

// �criture d'un �tablissement sur un flux ostream
ostream& operator<<(ostream& f, const Etablissement& e);

#endif
