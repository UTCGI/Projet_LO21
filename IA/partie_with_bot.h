#ifndef PARTIE_WITH_BOT_H
#include "bot.h"
#include "partie.h"

class PartieWithBot:public Partie{
private:
    size_t nb_IA = 0;
public:
const size_t getNb_IA()const{return nb_IA;}
void setNb_IA(size_t n){nb_IA=n;}
int choisirCarteAAcheter();
int choisirMonumentAConstruire();
int choisirNbDesALancer();
bool choisirRelancer();
bool choisirPlusDeux();
int choisirAction();
};
#endif