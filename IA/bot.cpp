#include "bot.h"
void testBot(){
       cout<<"test"<<endl;
       Jeu j(Extension::Aucune);
       Joueur gamer(j);
       Bot ia(j,1);
       //cout<<ia;
       //cout<<ia.getPseudo()<<endl;
       // Bot joueur;
       // if (dynamic_cast<Bot*>(joueur)!=nullptr) cout<< "it's a bot"<<endl;
};