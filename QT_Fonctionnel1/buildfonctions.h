#pragma once
#include "miniville.h"
#include "etablissement.h"
#include "monument.h"
#include "sqlite3.h"

void buildmonument(vector<const Monument*>& liste_monuments);

void buildetablissement(vector<const Etablissement*>& liste_etablissements, Extension e = Extension::Aucune);
void buildetablissementSpecial(vector<const Etablissement*>& liste_etablissements, Extension e = Extension::Aucune);

void builddepart(vector<const Etablissement*>& liste_etablissements_depart);

void lancerdatabase(sqlite3 **db);
