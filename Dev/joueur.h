#pragma once
#include <string>
#include "miniville.h"
#include "Carte_Monument.h"
#include "pile_etablissement.h"
#include "jeu.h"


/* Note : Jingfang Yuan 01/12
    1 La vérification du montant restant dans le compte devrait se faire ailleurs que dans les fonctions de la classe Joueur
    2 La fonction setNbDes() n'a plus de paramètre, le nombre de dès bascule à chaque appel entre 1 et 2
    3 Constructeur :  Initialisation des description du joueur
                    Création des Pile_Etablissements et Carte_Monuments
                    Distribution des cartes de départ
    4 Déstrcuteur : résponsable des durées de vie des piles ?
      Pour moi oui mais sur l'UML le lien est marqué agrégation.
      Maintenant dans le code je considère qu'il s'agit d'une composition
    5 static const int max_joueurs = 4; static const int min_joueurs = 2; si besoin, doit être gérés par partie/jeu 
 */


class Joueur
{
  static int nombre_actuel;//Compteur du nombre actuel de joueur
  int id;
  string pseudo;
  int de = 1;
  //int de_lance;
  int compte = 3;
  //int placement_StartUp = 0;
  std::vector<Carte_Monument *> monuments;
  std::vector<Pile_Etablissement *> pileRouge;
  std::vector<Pile_Etablissement *> pileBleu;
  std::vector<Pile_Etablissement *> pileVert;
  std::vector<Pile_Etablissement *> pileViolet;

public:
  /**
   * @brief Construct a new Joueur object
   * 
   * @param jeu 
   */
  Joueur(const Jeu* jeu);
  /**
   * @brief Destroy the Joueur object
   * 
   */
  ~Joueur();

  // Getter
  /**
   * @brief Get the Nb Des object
   * 
   * @return int 
   */
  int getNbDes() const;
  /**
   * @brief Get the Compte object
   * 
   * @return int 
   */
  int getCompte() const;
  //int getPlacement_StartUp() const;
  //Cette fonction vraiment besoin ?
  /**
   * @brief Get the Nombre Monuments Construits object
   * 
   * @return int 
   */
  int getNombreMonumentsConstruits() const;
  /**
   * @brief Get the Nb Max Joueurs object
   * 
   * @return int 
   */
  static int getNbMaxJoueurs();
  /**
   * @brief Get the Monuments object
   * 
   * @return const vector<Carte_Monument *>& 
   */
  const vector<Carte_Monument *> &getMonuments() const { return monuments; }
  /**
   * @brief Get the Pile Rouge object
   * 
   * @return const vector<Pile_Etablissement *>& 
   */
  const vector<Pile_Etablissement *> &getPileRouge() const { return pileRouge; }
  /**
   * @brief Get the Pile Bleu object
   * 
   * @return const vector<Pile_Etablissement *>& 
   */
  const vector<Pile_Etablissement *> &getPileBleu() const { return pileBleu; }
  /**
   * @brief Get the Pile Vert object
   * 
   * @return const vector<Pile_Etablissement *>& 
   */
  const vector<Pile_Etablissement *> &getPileVert() const { return pileVert; }
  /**
   * @brief Get the Pile Violet object
   * 
   * @return const vector<Pile_Etablissement *>& 
   */
  const vector<Pile_Etablissement *> &getPileViolet() const { return pileViolet; }

  // Setter

  /**
   * @brief Set the Pseudo object
   * 
   * @param pseudo 
   */
  void setPseudo(string pseudo);
  //void setPlacement_StartUp(int placement_StartUp);
  /**
   * @brief Set the Nb Des object
   * 
   */
  void setNbDes();
  /**
   * @brief Set the Compte object
   * 
   * @param montant 
   */
  void setCompte(int montant);

  // Autres méthodes
  /**
   * @brief 
   * 
   * @param e 
   */
  void ajouter_etablissement(const Etablissement *e);
  /**
   * @brief 
   * 
   * @param e 
   */
  void retirer_etablissement(const Etablissement *e);
  /**
   * @brief 
   * 
   * @param montant 
   */
  void ajouterMontant(int montant);
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  bool victoire() const;
  /**
   * @brief 
   * 
   */
  int lancerDés(int desALancer)const;
  /**
   * @brief 
   * 
   * @param f 
   */
  void printJoueur(ostream &f = std::cout) const;
  
};
/**
 * @brief 
 * 
 * @param f 
 * @param j 
 * @return ostream& 
 */
ostream &operator<<(ostream &f, const Joueur &j);



