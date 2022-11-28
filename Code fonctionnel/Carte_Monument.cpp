#include "Carte_Monument.h"

// Ces includes int été ajoutés pour le test
#include "monument.h"
#include "jeu.h"
#include "buildfonctions.h"
// Getters
const Monument* Carte_Monument::getMonument() const { 
  return monument; 
}

bool Carte_Monument::estConstruit() const { 
  return construit; 
}

// Constructors and Destructors functions
Carte_Monument::Carte_Monument(const Monument* mo, bool construct)
    : monument(mo), construit(construct){};

// Methods
void Carte_Monument::construire(){
  construit = true;
}

// Operators
ostream& operator<<(ostream& f, Carte_Monument& carte) {
  if(carte.estConstruit()){
  f << "Monument : " << carte.getMonument()->getNom() << endl
    << "Effet  : " <<carte.getMonument()->getEffet() << endl
    << "Prix : " << carte.getMonument()->getPrix() << endl
    << "Ce monument est déjà construit. " << endl;
  } else {
      f << "Monument : " << carte.getMonument()->getNom() << endl
    << "Effet  : " <<carte.getMonument()->getEffet() << endl
    << "Prix : " << carte.getMonument()->getPrix() << endl
    << "Ce monument n'est pas construit. "  << endl << endl;
  }
  return f;
}

int main_test_carte_monument(){
  Jeu *j = new Jeu(Extension::Aucune);
  const Monument ** listeM = new const Monument* [j->getNbMonuments()];
  buildmonument(listeM);
  cout << (listeM[1])->getNom() << endl;
  for(int i = 0 ; i < j->getNbMonuments(); i++) {
    Carte_Monument *carte = new Carte_Monument( (listeM[i]) , false);
    cout << *carte;
    // carte->construire();
    // cout << *carte;
  }
  // Monument *gare = new Monument("Gare", "Ajoute un dé lorsque la carte est construite", 4);
  // Carte_Monument *carte2 = new Carte_Monument( gare, false);
  // cout << *carte2;
  // carte2->construire();
  // cout << *carte2;
  return 0;
}

