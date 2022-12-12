#include "joueur.h"
#include <random>
#include "time.h"
int Joueur::nombre_actuel = 0;

Joueur::Joueur(const Jeu *jeu) : id(++nombre_actuel)
{
    // Partie : Distributions des cartes monument (pile)
    const Monument **monuments_temp = jeu->getMonument();
    for (size_t i = 0; i < jeu->getNbMonuments(); i++)
        monuments.push_back(new Carte_Monument(monuments_temp[i]));

    // Partie : Initialisation des piles
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
    // Partie : Distributions des cartes de départ
    const Etablissement **depart = jeu->getEtablissementsDepart();
    for (size_t i = 0; i < jeu->getNbEtablissements_Depart(); i++)
    {
        initialisation_etablissement_depart(depart[i]);
    }
}

Joueur::~Joueur()
{
    for (auto i : monuments)
        delete i;
    for (auto i : pileBleu)
        delete i;
    for (auto i : pileRouge)
        delete i;
    for (auto i : pileVert)
        delete i;
    for (auto i : pileViolet)
        delete i;
}

// Getter
int Joueur::getNbDes() const { return de; }

int Joueur::getCompte() const { return compte; }

// int Joueur::getPlacement_StartUp() const { return placement_StartUp; }

// Setter
void Joueur::setNbDes() { de = de == 1 ? 2 : 1; }

void Joueur::setCompte(int montant) { compte = montant; }

void setPseudo(string pseudo) { pseudo = pseudo; }

/* void setPlacement_StartUp(int placement_StartUp)
{
    placement_StartUp = placement_StartUp;
} */

// Autres méthodes

void Joueur::initialisation_etablissement_depart(const Etablissement *e)
{
    vector<Pile_Etablissement *> *which = nullptr;
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
        if ((*i)->getEtablissement()->getNom() == e->getNom())
        {
            (*i)->ajouterCarte();
        }
        else
            continue;
    }
}

void Joueur::ajouter_etablissement(const Etablissement *e)
{
    vector<Pile_Etablissement *> *which = nullptr;
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
            (*i)->ajouterCarte();
            break;
        }
        else
            continue;
    }
}

bool Joueur::retirer_etablissement(const Etablissement *e)
{ // pas sûr s'il faut faire comme ça
    bool temp = false;
    vector<Pile_Etablissement *> *which = nullptr;
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
            if ((*i)->getEffectif() == (*i)->getMinimum())
            {
                throw SetException("Cette pile est déjà vide !");
                temp = false;
            }

            else
            {
                (*i)->retirerCarte();
                temp = true;
            }
            break;
        }
        else
            continue;
    }
    return temp;
}

void Joueur::ajouterMontant(int montant) { compte += montant; }

int Joueur::getNombreMonumentsConstruits() const
{
    int k = 0;
    for (auto i : getMonuments())
    {
        if (i->estConstruit())
        {
            k++;
        }
    }
    return k;
}

bool Joueur::victoire() const
{
    /* bool win = true;
    for(auto i : getMonuments()){
        if (!i->estConstruit()){
            win = false;
            break;
        }
    }
    return win; */
    return getNombreMonumentsConstruits() == monuments.size();
}
// Jingfang : Je pense que le nombre de dès à lancer doit être directement passé en paramètre car finalement
// c'est un bouton dans appli QT qui demande à l'utilisateur de le saisir
int Joueur::lancerDes(int desALancer) const
{
    srand(time(NULL));
    if (desALancer == 1)
    {
        return rand() % 6 + 1;
    }
    else if (desALancer == 2)
    {
        return +rand() % 6 + 2;
    }
    else
    {
        throw SetException("Nombre de dés non autorisé !");
        return -1; // Code d'erreur si on envoie un mauvais nombre
    }
}


void Joueur::printJoueurConcise(ostream &f) const
{
    f << "Monument" << endl
      << endl;
    for (auto i : monuments)
        f << "  " << i->getMonument()->getNom() << "  Construit ? :  " << i->estConstruit()<< endl;

    f << endl;
        f << "Etablissement" << endl
          << endl;
    f << "Pile Rouge" << endl;
    for (auto i : pileRouge)
        f << "  " << i->getEtablissement()->getNom() << "  Effectif :  " << i->getEffectif() << endl;
    f << "Pile Bleu" << endl;
    for (auto i : pileBleu)
        f << "  " << i->getEtablissement()->getNom() << "  Effectif :  " << i->getEffectif() << endl;
    f << "Pile Violet" << endl;
    for (auto i : pileViolet)
    {
        f << "  " << i->getEtablissement()->getNom() << "  Effectif :  " << i->getEffectif() << endl;
    }
    f << "Pile Vert" << endl;
    for (auto i : pileVert)
        f << "  " << i->getEtablissement()->getNom() << "  Effectif :  " << i->getEffectif() << endl;
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
