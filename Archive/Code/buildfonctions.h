#pragma once
#include "miniville.h"
#include "etablissement.h"
#include "monument.h"

void buildmonument(const Monument**liste_monuments);

void buildetablissement(const Etablissement **liste_etablissements, Extension e = Extension::Aucune);

void builddepart(const Etablissement **liste_etablissements);