#ifndef TYPESENUM_H
#define TYPESENUM_H
#include <string>
#include "string.h"
#include "miniville.h"
using namespace std;


Type toType(const char* t) {
      if (strcmp("agriculture", t)==0) return Type::agriculture;
      else if (strcmp("aucun", t)==0) return Type::aucun;
      else if (strcmp("elevage", t)==0) return Type::elevage;
      else if (strcmp("ressources", t)==0) return Type::ressources;
      else if (strcmp("maritime", t)==0) return Type::maritime;
      else if (strcmp("commerce", t)==0) return Type::commerce;
      else if (strcmp("industrie", t)==0) return Type::industrie;
      else if (strcmp("maraichage", t)==0) return Type::maraichage;
      else if (strcmp("entreprise", t)==0) return Type::entreprise;
      else if (strcmp("restauration", t)==0) return Type::restauration;
      else if (strcmp("special", t)==0) return Type::special;
      else throw SetException("Type inconnu");
	}

Couleur toCouleur(const char* t) {
      if (strcmp("bleu", t)==0) return Couleur::bleu;
      else if (strcmp("rouge", t)==0) return Couleur::rouge;
      else if (strcmp("violet", t)==0) return Couleur::violet;
      else if (strcmp("vert", t)==0) return Couleur::vert;
      else throw SetException("Couleur inconnu");
	}
#endif
