#include "pioche.h"
#include "time.h"
// Getters
unsigned int Pioche::getNb_etablissements() const { return nb_etablissements; }
unsigned int Pioche::getNb_piles() const { return nb_piles; }
Pile_Etablissement* Pioche::getPiles_etablissement() const { return piles_etablissement; }

// Constructeur et destructeur
Pioche::Pioche(const Jeu& jeu)
{
    nb_piles = jeu.getNbEtablissements();
    nb_etablissements = 0;
    piles_etablissement = new Pile_Etablissement[nb_piles];
    for (unsigned int i = 0; i < nb_piles; i++) {
        piles_etablissement[i] = Pile_Etablissement(jeu.getEtablissements()[i], jeu.getEtablissements()[i]->getNbExemplaires());
        nb_etablissements += jeu.getEtablissements()[i]->getNbExemplaires();
    }
}

Pioche::~Pioche() { 
    for (unsigned int i = 0; i < nb_piles; i++)
        delete &piles_etablissement[i];
        }

// Autres methodes de classe
const Etablissement* Pioche::getRandomEtablissement() const
{
    unsigned int numero_etablissement = 0;
    srand(time(NULL));
    numero_etablissement = rand() % (nb_etablissements-1);
    unsigned int nb_etablissements_parcourus = 0;
    unsigned int i = 0;
    while (nb_etablissements_parcourus < numero_etablissement) {
        nb_etablissements_parcourus += piles_etablissement[i].getEffectif();
        i++;
    }
    return piles_etablissement[i].getEtablissement();
}

unsigned int Pioche::getIndexPile(const Etablissement& etablissement) const
{
    unsigned int i = 0;
    while (i < nb_piles && *piles_etablissement[i].getEtablissement() != etablissement)
        i++;
    if (*piles_etablissement[i].getEtablissement() != etablissement)
        SetException("l'etablissement n'est pas dans la pioche");
    return i;
}

void Pioche::retirer_Etablissement(const Etablissement& etablissement, unsigned int quantite)
{
    unsigned int indexPile = getIndexPile(etablissement);
    piles_etablissement[indexPile].retirerCarte(quantite);
    nb_etablissements -= quantite;
    if (piles_etablissement[indexPile].getEffectif() == 0) {
        for (unsigned int i = indexPile; i < nb_piles - 1; i++)
            piles_etablissement[i] = piles_etablissement[i + 1];
        nb_piles--;
    }
}

const Etablissement* Pioche::retirerRandomEtablissement()
{
    const Etablissement* random_etablissement = getRandomEtablissement();
    retirer_Etablissement(*random_etablissement, 1);
    return random_etablissement;
}

void Pioche::afficher() const
{
    cout << "******Pioche******" << endl;
    for (unsigned int i = 0; i < nb_piles; i++) {
        cout << piles_etablissement[i].getEtablissement()->getNom();
        cout << " (" << piles_etablissement[i].getEffectif() << ")" << endl;
    }
    cout << "******EndPioche******" << endl
         << endl;
}