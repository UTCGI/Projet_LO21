#include "monument.h"

string Monument::getNom() const { return nom; }
string Monument::getEffet() const { return effet; }
unsigned int Monument::getPrix() const { return prix; }
unsigned int Monument::getExemplaire() const { return nb_exemplaires; }

Monument::Monument(const string& nom, const string& effet,
                   const unsigned int prix) :
    nom(nom), effet(effet), prix(prix), nb_exemplaires(4) {}

ostream& operator<<(ostream& f, const Monument& m) {
  f << "Nom \t\t\t: " << m.getNom() << endl
    << "Effet \t\t\t: " << m.getEffet() << endl
    << "Prix \t\t\t: " << m.getPrix() << " piece";
  if (m.getPrix() > 1)    f << "s";
  f << endl << "Quantite \t\t: " << m.getExemplaire() << endl << endl;
  return f;
};

//TEST
int MonumentTest(){
    Monument* m1=new Monument("Gare","Vous pouvez lancer deux des",4);
    cout<<*m1;
    return 0;
}
