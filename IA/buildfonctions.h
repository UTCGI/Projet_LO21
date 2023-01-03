#pragma once
#include "create_database.h"
#include "etablissement.h"
#include "jeu.h"
#include "miniville.h"
#include "monument.h"
#include "sqlite3.h"
#include <cstring>
#include <vector>

void buildmonument(const Monument** liste_monuments, Extension e);

void buildetablissement(const Etablissement** liste_etablissements, const Etablissement** liste_etablissements_depart /* , const Etablissement **liste_etablissements_speiciaux */, Extension e);

void lancerdatabase(sqlite3** db);
void buildcaracteristics1(Jeu* j, Extension e);