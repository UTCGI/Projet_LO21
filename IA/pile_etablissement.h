#ifndef __PILE_ETABLISSEMENT__
#define __PILE_ETABLISSEMENT__

#include <iostream>

#include "etablissement.h"

class Pile_Etablissement {
private:
    const Etablissement* etablissement;
    unsigned int effectif;
    unsigned int minimum; // Utile pour les établissement de départ
    unsigned int montant_effet;
public:
    // Setters

    void setMinimum() { minimum = 1; }

    // Getters
    unsigned int getMinimum()const { return minimum; }

    int getPrix()const
    {
        return effectif == minimum ? 0 : etablissement->getPrix();
    }

    int getMontant()const{return montant_effet;}

    void augmenterMontant(int a){montant_effet += a;}//Pour Hotel de ville
    /*
    Specification: getEtablissement()
    Entree : None
    Sortie : Retourne le pointeur associé a l'etablissement considérer
    Description : Cette methode permet d'accéder au pointeur de l'etablissement.
    */
    const Etablissement* getEtablissement() const;

    /*
    Specification: getEffectif()
    Entree : None
    Sortie : Valeur correpondante a l'effectif de l'etablissement considere
    Description : Cette methode permet de retourner le nombre de monuments présent
    dans la pile
    */
    unsigned int getEffectif() const;

    // Constructors and Destructors functions

    Pile_Etablissement();

    Pile_Etablissement(const Etablissement* et, unsigned int ef = 0, unsigned int m = 0);

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
  Elle déclanche une exception si le nombre de carte a retirer est supérieur au
  nombre de carte présents dans la pile
  */
    bool retirerCarte(unsigned int nb_cartes = 1);

    /*
  Specification: ajouterCarte(unsigned int nb_cartes = 1)
  Entree : nb_carte : représente le nombre de cartes que l'on veut ajouter
            (valeur par défault 1)
  Sortie : attribut effectif de la pile d'etablissement modifiée
  Description : Cette methode permet mettre a jour l'effectif d'une pile
  */
    void ajouterCarte(unsigned int nb_cartes = 1);

    /*
    Specification: estPresqueVide();
    Entree : aucune
    Sortie : true=pile vide ou avec seulement 1 etablissement de depart
    false=pile avec au moins 1 etablissement qui n'est pas de depart
    Description : Cette methode permet de savoir si l'effectif 
    d'une pile est superieur au minimum
    Utilité : Centre d'affaires
    */
    bool estPresqueVide();

    // Operators

    /*
  Specification: &operator+(Pile_Etablissement &p)
  Entree : Référence vers une pile d'etablissement
  Sortie : Référence vers une pile d'etablissement de l'objet modifie
  Description : Cette methode permet de surcharger l'opérateur + afin de
  "fusioner" 2 piles d'etablissement
  */
    Pile_Etablissement& operator+(Pile_Etablissement& p);
};

/*
Specification: &operator<<(ostream &f, Pile_Etablissement &pile)
Entree :
- f : flux ostream
- pile : Pile_Etablissement que l'on souhaite afficher
Sortie : Affichage
Description : Cette fonction permet d'effectuer l'affichage d'une
Pile_Etablissement sur un flux f
*/
ostream& operator<<(ostream& f, const Pile_Etablissement& pile);

ostream& operator<<(ostream& f, const vector<Pile_Etablissement*>& pile);

const Pile_Etablissement* getPileFromName(const string& name, const vector<Pile_Etablissement*>& pile);

#endif