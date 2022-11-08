#ifndef MONUMENT_H
#define MONUMENT_H

class Monument{
    bool construit;//0:non construit ; 1:construit
public:
    Monument();
    ~Monument();
    bool estConstruit();
    void construire();
};

#endif