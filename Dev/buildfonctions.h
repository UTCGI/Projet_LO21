#pragma once
#include <vector>
#include <cstring>
#include "miniville.h"
#include "etablissement.h"
#include "create_database.h"
#include "monument.h"
#include "sqlite3.h"

void buildmonument(const Monument** liste_monuments);

void buildetablissement(const Etablissement **liste_etablissements, const Etablissement **liste_etablissements_depart/* , const Etablissement **liste_etablissements_speiciaux */, Extension e);

void lancerdatabase(sqlite3 **db);
