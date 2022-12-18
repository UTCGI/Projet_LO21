#ifndef PARTIE_H
#define PARTIE_H
#include "jeu.h"
#include "joueur.h"
#include "reserve.h"
#include "etablissement.h"
#include "joueur.h"
#include "pile_etablissement.h"

void traiterEtablissementSpecial(const string& nom,const Joueur& joueur);
void traiterChaineDeTelevision();
void traiterCentredAffaire();
void traiterStade(const vector<Joueur*>& joueurs,Joueur* j, Pile_Etablissement* p);
#endif