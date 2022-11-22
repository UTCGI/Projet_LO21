#ifndef JEU_H
#define JEU_H
#include <iostream>
#include <cstdlib>
#include "TypesEnum.h"
#include "etablissement.h"
#include "monument.h"

// Changer enum class Extension en 3 struct ????????????????

class Jeu {
  const Etablissement** liste_etablissements = new const Etablissement*[15];
  // const Etablissement* liste_etablissements[15];
  const Monument** liste_monuments = new const Monument*[4];
  // const Monument* liste_monuments[4];
  const Etablissement** liste_etablissements_depart =
      new const Etablissement*[2];
  // const Etablissement* liste_etablissements_depart[2];
  Extension extension = nullptr;  // Extension::Standard;
  // Extension::Marina;
  size_t condition_de_victoire =
      4;  // nombre de monuments � construire pour gagner dans le jeu de base
  //=6;
  size_t nb_joueurs_MAX = 4;  // nombre de joueurs max dans le jeu de base
  //=4;
  size_t nb_pile_reserve_MAX = 15;  // nombre de piles max dans la r�serve du
                                    // jeu de base : 3 lignes ; 5 colonnes
  //=10; //2 lignes ; 5 colonnes
 public:
  Jeu();                     // pour cr�er Minivilles de base SANS extension
  Jeu(Extension extension);  // pour cr�er Minivilles avec une extension
  ~Jeu();
};

#endif