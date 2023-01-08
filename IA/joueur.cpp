#include "joueur.h"
#include <random>
#include "MKrandom.h"
#include <string.h>

int Joueur::nombre_actuel = 0;

Joueur::Joueur(const Jeu& jeu) :
    id(++nombre_actuel)
{
    char num[2];
    pseudo += num;
    const Monument** monuments_temp = jeu.getMonument();
    for (size_t i = 0; i < jeu.getNbMonuments(); i++)
        monuments.push_back(new Carte_Monument(monuments_temp[i]));

    // Partie : Initialisation des piles
    const Etablissement** etablissements_temp = jeu.getEtablissements();
    for (size_t i = 0; i < jeu.getNbEtablissements(); i++) {

        switch (etablissements_temp[i]->getCouleur()) {
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
            break;
        }
    }
    // Partie : Distributions des cartes de départ
    const Etablissement** depart = jeu.getEtablissementsDepart();
    for (size_t i = 0; i < jeu.getNbEtablissements_Depart(); i++) {
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

unsigned int Joueur::getCompte() const { return compte; }

// Setter
void Joueur::setNbDes() { de = de == 1 ? 2 : 1; }

void Joueur::setCompte(int montant) { compte = montant; }

void setPseudo(string pseudo) { pseudo = pseudo; }

// Autres méthodes

void Joueur::initialisation_etablissement_depart(const Etablissement* e)
{
    vector<Pile_Etablissement*>* which = nullptr;
    switch (e->getCouleur()) {
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
    for (auto i = (*which).begin(); i != (*which).end(); i++) {
        if ((*i)->getEtablissement()->getNom() == e->getNom()) {
            (*i)->ajouterCarte();
            (*i)->setMinimum(); //minimum=1 pour etablissement de depart
        } else
            continue;
    }
}

void Joueur::ajouter_etablissement(const Etablissement* e)
{
    vector<Pile_Etablissement*>* which = nullptr;
    switch (e->getCouleur()) {
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
    for (auto i = (*which).begin(); i != (*which).end(); i++) {
        if ((*i)->getEtablissement() == e) {
            (*i)->ajouterCarte();
            break;
        } else
            continue;
    }
}

bool Joueur::retirer_etablissement(const Etablissement* e)
{
    bool temp = false;
    vector<Pile_Etablissement*>* which = nullptr;
    switch (e->getCouleur()) {
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
        break;
    }
    for (auto i = (*which).begin(); i != (*which).end(); i++) {
        if ((*i)->getEtablissement() == e) {
            if ((*i)->getEffectif() == (*i)->getMinimum()) {
                temp = false;
                cout << "Vous ne pouvez pas prendre dans cette pile !" << endl;
            }
            else {
                (*i)->retirerCarte();
                temp = true;
            }
            break;
        } else
            continue;
    }
    return temp;
}

void Joueur::ajouterMontant(int montant) { compte += montant; }

int Joueur::getNombreMonumentsConstruits() const
{
    int k = 0;
    for (auto i : getMonuments()) {
        if (i->estConstruit()) {
            k++;
        }
    }
    return k;
}

bool Joueur::victoire() const
{
    return getNombreMonumentsConstruits() == monuments.size();
}

/*int getRand(int min, int max){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    return distr(gen);
}*/

int Joueur::lancerDes() const
{
    return getRand(1,6);
}



bool Joueur::estPresqueVide(const vector<Pile_Etablissement*>& pile)
{
    for (auto p : pile) {
        if (!p->estPresqueVide())
            return false;
    }
    return true;
}

int nombreDePileActive(const vector<Pile_Etablissement*>& pile)
{
    int c = 0;
    for (auto p : pile) {
        if (p->getEffectif() > p->getMinimum())
            c++;
    }
    return c;
}

void Joueur::printJoueurConcise(ostream& f) const
{
    f << "Monument" << endl
      << endl;
    for (auto i : monuments)
        f << "  " << i->getMonument()->getNom() << "  Construit ? :  " << i->estConstruit() << endl;

    f << endl;
    f << "Etablissement" << endl
      << endl;
    f << "Pile Rouge" << endl;
    for (auto i : pileRouge)
        f << "  " << i->getEtablissement()->getNom() << "  Effectif :  " << i->getEffectif() << endl;// "  Minimum :  " << i->getMinimum() << endl;
    f << "Pile Bleu" << endl;
    for (auto i : pileBleu)
        f << "  " << i->getEtablissement()->getNom() << "  Effectif :  " << i->getEffectif() << endl;// "  Minimum :  " << i->getMinimum() << endl;
    f << "Pile Violet" << endl;
    for (auto i : pileViolet) {
        f << "  " << i->getEtablissement()->getNom() << "  Effectif :  " << i->getEffectif() << endl;// "  Minimum :  " << i->getMinimum() << endl;
    }
    f << "Pile Vert" << endl;
    for (auto i : pileVert)
        f << "  " << i->getEtablissement()->getNom() << "  Effectif :  " << i->getEffectif() << endl;// "  Minimum :  " << i->getMinimum() << endl;
}

void Joueur::printJoueur(ostream& f) const
{
    f << "Joueur id" << endl;
    f << "Pile Rouge" << endl;
    for (auto i : pileRouge) {
        f << *i;
    }
    f << "Pile Bleu" << endl;
    for (auto i : pileBleu) {
        f << *i;
    }
    f << "Pile Violet" << endl;
    for (auto i : pileViolet) {
        f << *i;
    }
    f << "Pile Vert" << endl;
    for (auto i : pileVert) {
        f << *i;
    }
}

ostream& operator<<(ostream& f, const Joueur& j)
{
    j.printJoueur(f);
    return f;
}
