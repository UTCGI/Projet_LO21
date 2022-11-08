
#include "carte_monument.h"

CarteMonument::CarteMonument(Monument* monument):monument(monument),construit(0){

}


CarteMonument::~CarteMonument(){
    monument = nullptr;
    construit = 0;
}


