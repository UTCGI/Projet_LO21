#include "monument.h"




int main(){

    const Monument** liste_monuments = new const Monument * [4];
    liste_monuments[0] = new Monument("this", "that");
   cout<<*liste_monuments[0];
    //cout<<liste_monuments[0]->getNom()<<" "<<liste_monuments[0]->getEffet()<<liste_monuments[0]->getExemplaire()<<endl;
    return 0;
}