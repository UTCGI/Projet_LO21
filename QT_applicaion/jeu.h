#ifndef JEU_H
#define JEU_H

#include "etablissement.h"
#include "miniville.h"
#include "monument.h"

class Jeu {
    Extension extension; // = Extension::Aucune;
    size_t condition_de_victoire; // = 4;
    // nombre de monuments à construire pour gagner dans le jeu de base

    size_t nb_joueurs_MAX; // = 4;
    // nombre de joueurs max dans le jeu de base

    size_t nb_pile_reserve_MAX; // = 15;
    size_t nb_lignes_reserve_MAX; // = 3;
    size_t nb_colonnes_reserve_MAX; // = 5;
    // nombre de piles max dans la réserve du jeu de base : 3 lignes ; 5 colonnes

    size_t nbEtablissements_Depart; // = 2;
    // nombre d'etablissments de depart du jeu de base : 1 champs de ble et une boulangerie

    size_t nbEtablissements; // = 15;
    // nombre d'etablissments DIFFERENTS du jeu de base

    size_t nbMonuments; // = 4;
    // nombre de monuments DIFFERENTS du jeu de base

    size_t nbCartes; // = 108;
    // nombre total de cartes du jeu de base
    // 2*4 etablissements de depart, 4*4 monuments, 12*6+3*4 etablissements

    const Etablissement** liste_etablissements;
    // const Etablissement* liste_etablissements[15];

    const Monument** liste_monuments;
    // const Monument* liste_monuments[4];

    const Etablissement** liste_etablissements_depart;

    friend void buildcaracteristics1(Jeu* j, Extension e);

public:
    // Jeu(Extension extension);  // pour creer Minivilles avec une extension
    Jeu(Extension e = Extension::Aucune);
    ~Jeu() = default;

    Extension getExtension() const { return extension; }
    size_t getCondition_de_victoire() const { return condition_de_victoire; }
    size_t getNb_joueurs_MAX() const { return nb_joueurs_MAX; }
    size_t getNb_pile_reserve_MAX() const { return nb_pile_reserve_MAX; }
    size_t getNb_lignes_reserve_MAX() const { return nb_lignes_reserve_MAX; }
    size_t getNb_colonnes_reserve_MAX() const { return nb_colonnes_reserve_MAX; }
    size_t getNbEtablissements_Depart() const { return nbEtablissements_Depart; }
    size_t getNbEtablissements() const { return nbEtablissements; }
    size_t getNbMonuments() const { return nbMonuments; }
    size_t getNbCartes() const { return nbCartes; }

    const Monument** getMonument() const { return liste_monuments; }
    const Etablissement** getEtablissements() const { return liste_etablissements; }
    const Etablissement** getEtablissementsDepart() const { return liste_etablissements_depart; }

    void afficher(std::ostream& f = std::cout) const;

    void printE_D(std::ostream& f = cout) const;
    void printE(std::ostream& f = cout) const;
    void printM(std::ostream& f = cout) const;

    const Etablissement* getEtablissementFromName(const string& name) const;
};

ostream& operator<<(ostream& f, const Jeu& j);
#endif
