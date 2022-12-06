#ifndef MONUMENT_H
#define MONUMENT_H

#include "miniville.h"

class Monument {
 private:
  const string nom;
  const string effet;
  const unsigned int prix;
  const unsigned int nb_exemplaires;

 public:
  Monument(const string& nom, const string& effet, const unsigned int prix);
  ~Monument() = default;
  Monument(const Monument& m) = delete;
  Monument& operator=(const Monument& m) = delete;

  string getNom() const;
  string getEffet() const;
  unsigned int getPrix() const;
  unsigned int getExemplaire() const;
};

ostream& operator<<(ostream& f, const Monument& m);

//TEST
int MonumentTest();

#endif
