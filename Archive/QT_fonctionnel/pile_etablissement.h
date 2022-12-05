#ifndef __PILE_ETABLISSEMENT__
#define __PILE_ETABLISSEMENT__

#include <iostream>

#include "etablissement.h"

// Include permettent de tester dans le main_test_pile_etablissement()
#include "buildfonctions.h"
#include "etablissement.h"
#include "jeu.h"
class Pile_Etablissement {
 private:
  const Etablissement *etablissement;
  unsigned int effectif;

 public:
  // Getters

  /*
  Specification: getEtablissement()
  Entree : None
  Sortie : Retourne le pointeur associé a l'etablissement considérer
  Description : Cette methode permet d'accéder au pointeur de l'etablissement.
  */
  const Etablissement *getEtablissement() const;

  /*
  Specification: getEffectif()
  Entree : None
  Sortie : Valeur correpondante a l'effectif de l'etablissement considere
  Description : Cette methode permet de retourner le nombre de monuments présent dans la pile
  */
  unsigned int getEffectif() const;

  // Constructors and Destructors functions

    /*
Specification: Pile_Etablissement(const Etablissement *et, unsigned int ef = 1)
Entree :
    - et : Pointeur vers un etablissement
    - ef : entier indiquant le nombre d'etablissements presents dans la pile
Sortie : Classe Pile_Etablissement Initialisée 
Description : Cette methode permet de construire la classe
*/
  Pile_Etablissement(const Etablissement *et, unsigned int ef = 1);
  
    /*
Specification: ~Pile_Etablissement()
Entree : None
Sortie : Pile_Etablissement detruite
Description : Cette methode permet de detruire la classe (utilisation du
destructeur par défault)
*/
  ~Pile_Etablissement() = default;

  // methods

    /*
Specification: retirerCarte(unsigned int nb_cartes = 1)
Entree : nb_carte : représente le nombre de cartes que l'on veut retirer
            (valeur par défault 1)
Sortie : attribut effectif de la pile d'etablissement modifiée
Description : Cette methode permet mettre a jour l'effectif d'une pile
Elle déclanche une exception si le nombre de carte a retirer est supérieur au nombre
de carte présents dans la pile
*/
  void retirerCarte(unsigned int nb_cartes = 1);

    /*
Specification: ajouterCarte(unsigned int nb_cartes = 1)
Entree : nb_carte : représente le nombre de cartes que l'on veut ajouter
            (valeur par défault 1)
Sortie : attribut effectif de la pile d'etablissement modifiée
Description : Cette methode permet mettre a jour l'effectif d'une pile
*/
  void ajouterCarte(unsigned int nb_cartes = 1);

  // Operators

    /*
Specification: &operator+(Pile_Etablissement &p)
Entree : Référence vers une pile d'etablissement
Sortie : Référence vers une pile d'etablissement de l'objet modifie
Description : Cette methode permet de surcharger l'opérateur + afin de "fusioner" 2 piles d'etablissement
*/
  Pile_Etablissement &operator+(Pile_Etablissement &p);
};

/*
Specification: &operator<<(ostream &f, Pile_Etablissement &pile)
Entree :
- f : flux ostream
- pile : Pile_Etablissement que l'on souhaite afficher
Sortie : Affichage
Description : Cette fonction permet d'effectuer l'affichage d'une Pile_Etablissement
sur un flux f
*/
ostream &operator<<(ostream &f, Pile_Etablissement &pile);

int main_test_pile_etablissement();

#endif