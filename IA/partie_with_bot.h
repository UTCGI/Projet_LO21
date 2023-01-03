#ifndef PARTIE_WITH_BOT_H
#include "bot.h"
#include "partie.h"

class PartieWithBot:public Partie{
private:
    size_t nb_IA = 0;
    size_t nb_JH = 0;
public:
//surcharges
//PartieWithBot();
virtual void initialisation();
//virtual int choix(const string& m1, int n = 0, int c = 0, const vector<Pile_Etablissement*>* p = nullptr, const string& m2 = "Choisir 0 pour quitter"); 
//virtual const vector<Pile_Etablissement*>*/*&*/ choixPile(const string& m1, const string& m2 = "Choisir 0 pour quitter", int cj = 0);
virtual void menu();
//nouvelles fonctions
const size_t getNb_IA()const{return nb_IA;}
const size_t getNb_JH()const{return nb_JH;}
void setNb_IA(size_t n){nb_IA=n;}
void setNb_JH(size_t n){nb_JH=n;}
int choisirCarteAAcheter();
int choisirMonumentAConstruire();
int choisirNbDesALancer();
bool choisirRelancer();
bool choisirPlusDeux();
int choisirAction();
Carte_Monument* getCheapestMonument();
};
void test_PWB();

# endif