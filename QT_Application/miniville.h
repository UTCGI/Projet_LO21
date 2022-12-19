#pragma once
#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// classe pour g�rer les exceptions dans les caracteristiques des etablissements
class SetException {
public:
    SetException(const string& i)
        : info(i)
    {
    }
    string getInfo() const { return info; }

private:
    string info;
};

// caract�ristiques
enum class Couleur {
    bleu,
    rouge,
    violet,
    vert
};
enum class Type {
    aucun,
    agriculture,
    elevage,
    ressources,
    maritime,
    commerce,
    industrie,
    maraichage,
    entreprise,
    restauration,
    special
};
// versions du jeu
enum class Extension {
    Aucune,
    Marina,
    GreenValley,
    Deluxe
};

// conversion d'une caract�ristique en string
string toString(Couleur c);
string toString(Type t);
// conversion d'une version du jeu en string
string toString(Extension e);

// Nouveaux trucs introduits pour SQLite3
string toString1(Extension e);
Type toType(const char* t);
Couleur toCouleur(const char* t);

// �criture d'une caract�ristique sur un flux ostream
ostream& operator<<(ostream& f, Couleur c);
ostream& operator<<(ostream& f, Type t);
// Ecriture d'une extension sur un flux ostream
ostream& operator<<(ostream& f, Extension e);

// listes contenant les valeurs possibles pour chacune des caract�ristiques
extern initializer_list<Couleur> Couleurs;
extern initializer_list<Type> Types;
// liste contenant les valeurs possibles pour chaque extension
// extern std::initializer_list<Extension> Extensions;
extern vector<Extension> Extensions;

// affichage des valeurs possibles pour chaque caract�ristique
void printCouleurs(std::ostream& f = cout);
void printTypes(std::ostream& f = cout);
// affichage des valeurs possibles pour chaque version du jeu
void printExtensions(std::ostream& f = cout);
