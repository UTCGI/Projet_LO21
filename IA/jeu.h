#ifndef JEU_H
#define JEU_H

#include "etablissement.h"
#include "miniville.h"
#include "monument.h"

class Jeu {
private:

    Extension extension; // = Extension::Aucune;
    size_t condition_de_victoire; // = 4;
    size_t nb_joueurs_MAX; // = 4;

    size_t nb_pile_reserve_MAX; // = 15;
    size_t nb_lignes_reserve_MAX; // = 3;
    size_t nb_colonnes_reserve_MAX; // = 5;

    size_t nbEtablissements_Depart; // = 2;
    size_t nbEtablissements; // = 15;
    size_t nbMonuments; // = 4;
    size_t nbCartes; // = 108;

    const Etablissement** liste_etablissements;
    const Monument** liste_monuments;
    const Etablissement** liste_etablissements_depart;

    friend void buildcaracteristics1(Jeu* j, Extension e);

    //SINGLETON
    struct Handler {
        Jeu* instance = nullptr;
        ~Handler() { delete instance; instance = nullptr; }
    };
    static Handler handler;
    Jeu(Extension e = Extension::Aucune);
    ~Jeu()=default;

public:
    //SINGLETON
    static Jeu& getInstance(Extension e = Extension::Aucune);
    static void libererInstance();
    Jeu(const Jeu&) = delete;
    Jeu& operator=(const Jeu&) = delete;
    //Jeu(Extension e = Extension::Aucune);
    //~Jeu() = default;

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
