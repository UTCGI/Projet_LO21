#ifndef CARTE_MONUMENT_H
#define CARTE_MONUMENT_H
#include "monument.h"
class CarteMonument{
    const Monument* monument;
    bool construit;
public:
    CarteMonument(Monument* monument);
    ~CarteMonument();
    CarteMonument(const CarteMonument& c) = delete;
    CarteMonument& operator=(const CarteMonument& c) = delete;
    
    
    bool estConstruit()const{
        return construit;
    }
    void construire(){
        construit = 1;
    }
};
#endif
