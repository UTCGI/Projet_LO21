#ifndef ETABLISSEMENT_H
#define ETABLISSEMENT_H
#include "miniville.h"
#include <string>
#include <typeinfo>
#include <vector>

// class Etablissement

class Etablissement {
private:
    const string nom;
    const string effet;
    Couleur couleur;
    unsigned int prix;
    vector<unsigned int> num_de;
    Type type;
    unsigned int montant_effet;
    unsigned int nb_exemplaires;
    bool isSpecial;

public:
    // Getters
    string getNom() const;
    string getEffet() const;
    Couleur getCouleur() const;
    unsigned int getPrix() const;
    vector<unsigned int> getNumDe() const;
    Type getType() const;
    unsigned int getMontant() const;
    unsigned int getNbExemplaires() const;
    bool getIsSpecial() const;

    // Constructors and destructors functions
    Etablissement(const string& nom1, const string& effet1, Couleur couleur1,
        unsigned int prix1, vector<unsigned int> num_de1, Type type1,
        unsigned int montant_effet1, bool isSpecial1, int nb_exemplaires);
    ~Etablissement() = default;

    // Methods
    bool estActif(unsigned int n);
    bool estSpecial();
    virtual void afficher(std::ostream& f = std::cout) const;
    bool operator==(Etablissement e1) const;
    bool operator!=(Etablissement e1) const;

    virtual Type getTypeEffet() const { return Type::aucun; };
};

class Etablissement_Violet : public Etablissement {
private:
    bool payeur;

public:
    bool getPayeur() const;
    Etablissement_Violet(const string& nom1, const string& effet1, Couleur couleur1,
        unsigned int prix1, vector<unsigned int> num_de1, Type type1,
        unsigned int montant_effet1, bool isSpecial1, int nb_exemplaires, bool payeur1);
    void afficher(std::ostream& f = std::cout) const;
};

class Etablissement_VertTE : public Etablissement {
private:
    const Type type_effet;

public:
    Type getTypeEffet() const;
    Etablissement_VertTE(const string& nom1, const string& effet1, Couleur couleur1,
        unsigned int prix1, vector<unsigned int> num_de1, Type type1,
        unsigned int montant_effet1, bool isSpecial1, int nb_exemplaires, Type type_effet1);
    void afficher(std::ostream& f = std::cout) const;
};

// Ecriture d'un Etablissement sur un flux ostream (UTILISER AFFICHER PLUTOT)
ostream& operator<<(ostream& f, const Etablissement& e);

#endif
