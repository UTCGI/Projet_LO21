#include "effets_monuments.h"

void effetHotelDeVille(Partie* p){
    for (auto i : p->getJoueurActif()->getPileRouge()){
        if (i->getEtablissement()->getType()==Type::commerce || i->getEtablissement()->getType()==Type::restauration)
            i->augmenterMontant(1);  
    }
    for (auto i : p->getJoueurActif()->getPileVert()){
        if (i->getEtablissement()->getType()==Type::commerce || i->getEtablissement()->getType()==Type::restauration)
            i->augmenterMontant(1);  
    }
}

void effetParcDAttractions(Partie* p){
    p->getJoueurActif()->setEffet_parc_attaction();
}

void effetTourRadio(Partie* p){
    p->getJoueurActif()->setEffet_tour_radio();
}

void effetPort(Partie* p){
    p->getJoueurActif()->setEffet_port();
}