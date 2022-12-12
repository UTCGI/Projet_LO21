#ifndef __carte__monument__
#define __carte__monument__

#include <iostream>

#include "monument.h"

class Carte_Monument {
 private:
  const Monument *monument;
  bool construit;

 public:
  // Getters
  /*
  Specification: getMonument()
  Entree : None
  Sortie : Retourne le pointeur associé au monument considérer
  Description : Cette methode permet d'accéder au pointeur du monument.
  */
  const Monument *getMonument() const;

  /*
  Specification: estConstruit()
  Entree : None
  Sortie : true si le monument est construit, false sinon
  Description : Cette methode permet de retourner le booléen afin de savoir si
  un monument est construit ou non
  */
  bool estConstruit() const;

  // Constructors and Destructors functions
  /*
Specification: Carte_Monument(const Monument* mo, bool construct = false);
Entree :
    - mo : Pointeur vers un monument
    - construct : booléen indiquant si le monument est construit ou non 
    (false par default) 
Sortie : Classe Carte_Monument Initialisée 
Description : Cette methode permet de construire la classe
*/
  Carte_Monument(const Monument *mo, bool construct = false);
  /*
Specification: ~Carte_Monument()
Entree : None
Sortie : Classe_Monument detruite
Description : Cette methode permet de detruire la classe (utilisation du
destructeur par défault)
*/
  ~Carte_Monument() = default;
  // methods
  /*
Specification: construire()
Entree : None
Sortie : Classe_Monument modifiée
Description : Cette methode permet mettre a true l'attribut contruit
*/
  void construire();
};

/*
Specification: &operator<<(ostream &f, Carte_Monument &carte)
Entree :
- f : flux ostream
- carte : Carte_Monument que l'on souhaite afficher
Sortie : Affichage
Description : Cette fonction permet d'effectuer l'affichage d'une Carte_Monument
sur un flux f
*/
ostream &operator<<(ostream &f, Carte_Monument &carte);

int main_test_carte_monument();
#endif
