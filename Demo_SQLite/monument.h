#ifndef MONUMENT_H
#define MONUMENT_H
#include<string>
#include<iostream>
#include "exception.h"
using namespace std;

class Monument{
private : 
    const string nom;
    const string effet;
    const unsigned int nb_exemplaires;
public :
    Monument(const string& nom, const string& effet);
    ~Monument() = default;
    Monument(const Monument& m) = delete;
    Monument& operator=(const Monument& m) = delete;

    string getNom()const {return nom;}
    string getEffet()const {return effet;}
    unsigned int getExemplaire()const {return nb_exemplaires;}
};

ostream& operator<<(ostream& f,const Monument& m);


#endif