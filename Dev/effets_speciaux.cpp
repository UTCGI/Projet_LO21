#include "effets_speciaux.h"

void effetHotelDeVille(Partie& p){
    for (auto i : p.getJoueurActif()->getPileRouge()){
        if (i->getEtablissement()->getType()==Type::commerce || i->getEtablissement()->getType()==Type::restauration)
            i->augmenterMontant(1);  
    }
    for (auto i : p.getJoueurActif()->getPileVert()){
        if (i->getEtablissement()->getType()==Type::commerce || i->getEtablissement()->getType()==Type::restauration)
            i->augmenterMontant(1);  
    }
}