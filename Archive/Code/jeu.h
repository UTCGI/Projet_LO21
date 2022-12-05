#ifndef JEU_H
#define JEU_H
<<<<<<< HEAD
#include <iostream>
#include <cstdlib>
#include "TypesEnum.h"
=======

#include "miniville.h"
>>>>>>> 1eeef22b9004e55c9d23ac9e8022f3f4bcf109cc
#include "etablissement.h"
#include "monument.h"

// Changer enum class Extension en 3 struct ????????????????

class Jeu {
  const Etablissement** liste_etablissements = new const Etablissement*[15];
  //const Etablissement* liste_etablissements[15];
  
  const Monument** liste_monuments = new const Monument*[4];
  //const Monument* liste_monuments[4];
  
  const Etablissement** liste_etablissements_depart =
      new const Etablissement*[2];
  // const Etablissement* liste_etablissements_depart[2];
  
  Extension extension = Extension::Aucune;

  size_t condition_de_victoire = 4;  
  // nombre de monuments � construire pour gagner dans le jeu de base

  size_t nb_joueurs_MAX = 4;  
  // nombre de joueurs max dans le jeu de base

  size_t nb_pile_reserve_MAX = 15;
  // nombre de piles max dans la r�serve du jeu de base : 3 lignes ; 5 colonnes

 public:
  Jeu(Extension extension);  // pour cr�er Minivilles avec une extension
  ~Jeu();

  size_t getNbEtablissements_Depart() const { return 2; }
  void printE_D(std::ostream& f = cout) const;

  size_t getNbEtablissements() const { return 15; }
  void printE(std::ostream& f = cout) const;

  size_t getNbMonuments() const { return 4; }
  void printM(std::ostream& f = cout) const;
  size_t getNbCartes() const { return 108; }
  //2*4 etablissements de depart, 4*4 monuments, 12*6+3*4 etablissements
};

ostream& operator<<(ostream& f, const Jeu& j);
#endif