#include "monument.h"

Monument::Monument(const string& nom, const string& effet):nom(nom),effet(effet),nb_exemplaires(4){
 
}

ostream& operator<<(ostream& f,const Monument& m){
    f<<"Monument : "<<m.getNom()<<endl<<"Effet : "<<m.getEffet()<<endl;
    return f;
};