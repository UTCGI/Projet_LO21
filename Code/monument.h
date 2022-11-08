#ifndef MONUMENT_H
#define MONUMENT_H
#include<string>
#include<iostream>
#include "exception.h"
using namespace std;

class Monument{
<<<<<<< HEAD
    bool construit;//0:non construit ; 1:construit
public:
    Monument();
    ~Monument();
    bool estConstruit();
    void construire();
=======
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
>>>>>>> 3843fe0ccd43655656d799e059e79e98ad6b8a9a
};

ostream& operator<<(ostream& f,Monument* m);


#endif