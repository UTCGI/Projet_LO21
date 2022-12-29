#include "miniville.h"
#include <cstring>

initializer_list<Couleur> Couleurs = { 
    Couleur::bleu,                           
    Couleur::rouge,
    Couleur::violet, 
    Couleur::vert 
};
initializer_list<Type> Types = { 
    Type::aucun, 
    Type::agriculture, 
    Type::elevage,
    Type::ressources, 
    Type::maritime, 
    Type::commerce, 
    Type::industrie,
    Type::maraichage, 
    Type::entreprise, 
    Type::restauration, 
    Type::special 
};
// initializer_list<Extension> Extensions = {Extension::Aucune, Extension::Marina,
//										  Extension::GreenValley, Extension::Deluxe};
vector<Extension> Extensions = { 
    Extension::Aucune, 
    Extension::Marina,
    Extension::GreenValley, 
    Extension::Deluxe 
};

string toString(Couleur c)
{
    switch (c) {
    case Couleur::bleu:
        return "bleu";
    case Couleur::rouge:
        return "rouge";
    case Couleur::violet:
        return "violet";
    case Couleur::vert:
        return "vert";
    default:
        throw SetException("Couleur inconnue");
    }
}

string toString(Type t)
{
    switch (t) {
    case Type::aucun:
        return "";
    case Type::agriculture:
        return "agriculture";
    case Type::elevage:
        return "elevage";
    case Type::ressources:
        return "ressources";
    case Type::maritime:
        return "maritime";
    case Type::commerce:
        return "commerce";
    case Type::industrie:
        return "industrie";
    case Type::maraichage:
        return "maraichage";
    case Type::entreprise:
        return "entreprise";
    case Type::restauration:
        return "restauration";
    case Type::special:
        return "special";
    default:
        throw SetException("Type inconnu");
    }
}

string toString(Extension e)
{
    switch (e) {
    case Extension::Aucune:
        return "Minivilles sans extension";
    case Extension::Marina:
        return "Minivilles Marina";
    case Extension::GreenValley:
        return "Minivilles GreenValley";
    case Extension::Deluxe:
        return "Minivilles Deluxe";
    default:
        throw SetException("Extension inconnue");
    }
}

string toString1(Extension e)
{
    switch (e) {
    case Extension::Aucune:
        return "Aucune";
    case Extension::Marina:
        return "Marina";
    case Extension::GreenValley:
        return "GreenValley";
    case Extension::Deluxe:
        return "Deluxe";
    default:
        throw SetException("Extension inconnue");
    }
}

Type toType(const char* t)
{
    if (strcmp("agriculture", t) == 0)
        return Type::agriculture;
    else if (strcmp("aucun", t) == 0)
        return Type::aucun;
    else if (strcmp("elevage", t) == 0)
        return Type::elevage;
    else if (strcmp("ressources", t) == 0)
        return Type::ressources;
    else if (strcmp("maritime", t) == 0)
        return Type::maritime;
    else if (strcmp("commerce", t) == 0)
        return Type::commerce;
    else if (strcmp("industrie", t) == 0)
        return Type::industrie;
    else if (strcmp("maraichage", t) == 0)
        return Type::maraichage;
    else if (strcmp("entreprise", t) == 0)
        return Type::entreprise;
    else if (strcmp("restauration", t) == 0)
        return Type::restauration;
    else if (strcmp("special", t) == 0)
        return Type::special;
    else
        throw SetException("Type inconnu");
}

Couleur toCouleur(const char* t)
{
    if (strcmp("bleu", t) == 0)
        return Couleur::bleu;
    else if (strcmp("rouge", t) == 0)
        return Couleur::rouge;
    else if (strcmp("violet", t) == 0)
        return Couleur::violet;
    else if (strcmp("vert", t) == 0)
        return Couleur::vert;
    else
        throw SetException("Couleur inconnu");
}

std::ostream& operator<<(std::ostream& f, Couleur c)
{
    f << toString(c);
    return f;
}
std::ostream& operator<<(std::ostream& f, Type t)
{
    f << toString(t);
    return f;
}
std::ostream& operator<<(std::ostream& f, Extension e)
{
    f << toString(e);
    return f;
}

void printCouleurs(std::ostream& f)
{
    for (auto c : Couleurs)
        f << c << " ";
    f << "\n";
}

void printTypes(std::ostream& f)
{
    for (auto t : Types)
        f << t << " ";
    f << "\n";
}

void printExtensions(std::ostream& f)
{
    size_t i = 0;
    for (auto e : Extensions)
        f << "[" << ++i << "] " << e << "\n";
    f << "\n\n";
}
