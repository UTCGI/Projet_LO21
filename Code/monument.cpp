#include "monument.h"

Monument::Monument(const string& nom, const string& effet, const unsigned int prix):nom(nom),effet(effet),prix(prix),nb_exemplaires(4){
 
}

ostream& operator<<(ostream& f,const Monument& m){
    f<<"Monument : "<<m.getNom()<<endl<<"Effet : "<<m.getEffet()<<endl<<"Prix : "<<m.getPrix()<<endl<<"Quantite : "<<m.getExemplaire()<<endl;
    return f;
};