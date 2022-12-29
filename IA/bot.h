#ifndef BOT_H
#define BOT_H
#include "joueur.h"
#include "jeu.h"
#include "miniville.h"
#include "string"
class Bot : public Joueur{
       public:
       Bot(const Jeu& jeu, unsigned int i):Joueur(jeu){
              string ps="IA ";
              ps+=to_string(i);
              setPseudo(ps);
       }

};
void testBot();
#endif