#ifndef TYPESENUM_H
#define TYPESENUM_H

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
  special,
};

enum class Extension { Aucune, Marina, GreenValley, Deluxe };

string toString(Type t) {
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
};

enum Couleur { bleu, rouge, violet, vert };
string toString(Couleur c) {
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
};

#endif
