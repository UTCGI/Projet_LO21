#include "joueur.h"

int Joueur::id = 0;

Joueur::Joueur(const Jeu* jeu)
{
    //Partie : Distributions des cartes monument (pile) 
    const Monument **monuments_temp = jeu->getMonument();
    for (size_t i = 0; i < jeu->getNbMonuments(); i++)
        monuments.push_back(new Carte_Monument(monuments_temp[i]));

    //Partie : Initialisation des piles
    const Etablissement **etablissements_temp = jeu->getEtablissements();
    for (size_t i = 0; i < jeu->getNbEtablissements(); i++)
    {

        switch (etablissements_temp[i]->getCouleur())
        {
        case Couleur::bleu:
            pileBleu.push_back(new Pile_Etablissement(etablissements_temp[i], 0));
            break;
        case Couleur::rouge:
            pileRouge.push_back(new Pile_Etablissement(etablissements_temp[i], 0));
            break;
        case Couleur::vert:
            pileVert.push_back(new Pile_Etablissement(etablissements_temp[i], 0));
            break;
        case Couleur::violet:
            pileViolet.push_back(new Pile_Etablissement(etablissements_temp[i], 0));
            break;

        default:
            // A compléter
            break;
        }
    }

    //Partie : Distributions des cartes de départ 
    const Etablissement **depart= jeu->getEtablissementsDepart();
    for (size_t i = 0; i < jeu->getNbEtablissements_Depart(); i++){
        ajouter_etablissement(depart[i]);
    }

    

}

// Getter
int Joueur::getNbDes() const { return de; }

int Joueur::getCompte() const { return compte; }

int Joueur::getPlacement_StartUp() const { return placement_StartUp; }


// Setter
void Joueur::setNbDes(int nbDe) { de = nbDe; }

void Joueur::setCompte(int montant) { compte = montant; }

void setPseudo(string pseudo) { pseudo = pseudo; }

void setPlacement_StartUp(int placement_StartUp)
{
    placement_StartUp = placement_StartUp;
}

// Autres méthodes
void Joueur::ajouter_etablissement(const Etablissement *e)
{
    vector<Pile_Etablissement *> *which;
    switch (e->getCouleur())
    {
    case Couleur::bleu:
        which = &pileBleu;
        break;
    case Couleur::rouge:
        which = &pileRouge;
        break;
    case Couleur::vert:
        which = &pileVert;
        break;
    case Couleur::violet:
        which = &pileViolet;
        break;
    default:
        // A compléter
        break;
    }
    for (auto i = (*which).begin(); i != (*which).end(); i++)
    {
        if ((*i)->getEtablissement() == e)
        {   
            if ((*i)->getEffectif()==e->getNbExemplaires())
                throw SetException("Cette pile est déjà pleine !");
            else
                (*i)->ajouterCarte();
            break;
        }
        else
            continue;
    }
}

void Joueur::retirer_etablissement(const Etablissement *e)
{ // pas sûr s'il faut faire comme ça
    vector<Pile_Etablissement *> *which;
    switch (e->getCouleur())
    {
    case Couleur::bleu:
        which = &pileBleu;
        break;
    case Couleur::rouge:
        which = &pileRouge;
        break;
    case Couleur::vert:
        which = &pileVert;
        break;
    case Couleur::violet:
        which = &pileViolet;
        break;
    default:
        // A compléter
        break;
    }
    for (auto i = (*which).begin(); i != (*which).end(); i++)
    {
        if ((*i)->getEtablissement() == e)
        {   
            if ((*i)->getEffectif()==0)
                throw SetException("Cette pile est déjà vide !");
            else
                (*i)->retirerCarte();
            break;
        }
        else
            continue;
    }
}

void Joueur::ajouterMontant(int montant) { compte += montant; }

int Joueur::getNombreMonumentsConstruits()
{
    return monuments.size();
}

// Partie
/*bool Joueur::victoire(){
    int somme=0;
    for (size_t i=0;i<nb_monuments;i++){
        somme += monuments[i].construit;
    }
    return (somme == nb_monuments);
}*/

int Joueur::lancerDés()
{
    if (de == 1)
    {
        return rand() % 6 + 1;
    }
    else if (de == 2)
    {
        return rand() % 6 + rand() % 6 + 2;
    }
    else
    {
        return -1; // Code d'erreur si on envoie un mauvais nombre
    }
}

void Joueur::printJoueur(ostream &f) const
{
    /* f<<"Pile Rouge"<<endl;
    for(auto i : pileRouge){
      f<<i->getEtablissement()->getNom()<<"\tNombre  \t"<<i->getEffectif()<<endl;
    }
    f<<"Pile Bleu"<<endl;
    for(auto i : pileBleu){
      f<<i->getEtablissement()->getNom()<<"\tNombre  \t"<<i->getEffectif()<<endl;
    }
    f<<"Pile Violet"<<endl;
    for(auto i : pileViolet){
      f<<i->getEtablissement()->getNom()<<"\tNombre  \t"<<i->getEffectif()<<endl;
    }
    f<<"Pile Vert"<<endl;
    for(auto i : pileVert){
      f<<i->getEtablissement()->getNom()<<"\tNombre  \t"<<i->getEffectif()<<endl;
    } */
    f << "Joueur id" << endl;
    f << "Pile Rouge" << endl;
    for (auto i : pileRouge)
    {
        f << *i;
    }
    f << "Pile Bleu" << endl;
    for (auto i : pileBleu)
    {
        f << *i;
    }
    f << "Pile Violet" << endl;
    for (auto i : pileViolet)
    {
        f << *i;
    }
    f << "Pile Vert" << endl;
    for (auto i : pileVert)
    {
        f << *i;
    }
}

ostream &operator<<(ostream &f, const Joueur &j)
{
    j.printJoueur(f);
    return f;
}


