#include "partie.h"

#include <iostream>

#include <vector>

using namespace std;
// ----------------------------------------------------------------
// Getter functions
// ----------------------------------------------------------------
int Partie::getManche() const { return manche; }

int Partie::getNumDe() const { return num_de; }

int Partie::getNbJoueurs() const { return nb_joueurs; }

Jeu *Partie::getJeu() const { return jeu; }

Joueur *Partie::getJoueurActif() { return joueurs1[joueur_actif]; }

Reserve *Partie::getReserve() const { return reserve; }
const vector<Joueur *> &Partie::getJoueurs() const { return joueurs1; }

// ----------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------

// ce n'est pas plutôt des void le type de retour des setters ?
void Partie::setManche(int nbManche) { manche = nbManche; }

void Partie::setNumDe(int nbDe) { num_de = nbDe; } // inutile ?

void Partie::setNbJoueurs(int nbJoueurs) { nb_joueurs = nbJoueurs; }

// ----------------------------------------------------------------
// Constructors and destructors functions
// ----------------------------------------------------------------
Partie::Partie()
    : manche(0),
      num_de(1),
      nb_joueurs(2) //,
{
}

Partie::~Partie() {}

// ----------------------------------------------------------------
// Methods
// ----------------------------------------------------------------
void Partie::initialisation()
{
  cout << "Bonjour, bienvenue dans le jeu MachiKoro" << endl;
  // Lire l'extension
  int lectureExtension;
retry:
  cout << "Entrez l'extension à laquelle vous voulez jouer" << endl;
  cout << "\t0. Originale\t1. Marina \t2. GreenValley\t3. Deluxe" << endl;
  do
  {
    cout << "L'extension doit être comprise entre 0 et 3" << endl;
    cin >> lectureExtension;

  } while (lectureExtension < 0 || lectureExtension > 3);
  jeu = new Jeu(Extensions[lectureExtension]);
  // Lire le nombre de joueurs
  cout << "Entrez le nombre de joueurs :" << endl;
  int lectureNbJoueurs = 0;
  while (lectureNbJoueurs < 2 || lectureNbJoueurs > jeu->getNb_joueurs_MAX())
  {
    cout << "Le nombre de joueur doit être compris entre 2 et " << jeu->getNb_joueurs_MAX() << endl;
    cin >> lectureNbJoueurs;
  }
  setNbJoueurs(lectureNbJoueurs);

  // Initialisation reserve
  reserve = new Reserve(*jeu);
  // Initialisation joueur
  for (size_t i = 0; i < getNbJoueurs(); i++)
  {
    joueurs1.push_back(new Joueur(jeu));
  }
  // TODO : initialisation pioche
}

void Partie::joueur_next()
{
  if (joueur_actif == joueurs1.size() - 1) // Quand c'est le dernier joueur
    joueur_actif = 0;
  else
    joueur_actif++;
}

/*
void Partie::application_regle_standards(Couleur couleur)
{
  // TODO: A completer
} */

void Partie::transaction_piece(Joueur *emetteur, Joueur *destinataire, int montant)
{
  if (montant > emetteur->getCompte())
    cout << "Erreur ! Le joueur " << emetteur->getPseudo() << " n'a pas assez de ressources pour effectuer la transaction.";
  else
  {
    emetteur->ajouterMontant(montant * (-1));
    destinataire->ajouterMontant(montant);
  }
}

void Partie::transaction_carte(Joueur* emetteur, Joueur*destinataire, const Etablissement* etab){
  if (emetteur->retirer_etablissement(etab))
    destinataire->ajouter_etablissement(etab);
}

bool Partie::achat_carte(Pile_Etablissement *pile_reserve)
{
  if (pile_reserve->getEffectif() > 0)
  {
    if (pile_reserve->getEtablissement()->getPrix() <= getJoueurActif()->getCompte())
    {
      getJoueurActif()->ajouterMontant(0 - pile_reserve->getEtablissement()->getPrix());
      getJoueurActif()->ajouter_etablissement(pile_reserve->getEtablissement());
      pile_reserve->retirerCarte();
      return true;
    }
    else
      cout << "Prix de l'etablissement superieur au montant de votre compte !" << endl;
  }
  else
    cout << "La pile est vide !" << endl;
  return false;
}

// ACHAT MONUMENTS
bool Partie::construire_monument(const Monument *monument_choisi)
{
  Carte_Monument *cible = nullptr;
  for (auto i : getJoueurActif()->getMonuments())
  {
    if (monument_choisi == i->getMonument())
    {
      cible = i;
      break;
    }
  }

  if (cible->estConstruit())
    return false;
  else
  {
    if (cible->getMonument()->getPrix() > getJoueurActif()->getCompte())
    {
      cout << "Construction échouée" << endl;
      return false;
    }
    else
    {
      cible->construire();
      getJoueurActif()->ajouterMontant((-1) * cible->getMonument()->getPrix());
      if (monument_choisi->getNom() == "Gare")
        getJoueurActif()->setNbDes();
      return true;
    }
  }
}

// void Partie::regarder_etablissements(Joueur* joueur, Couleur couleur) {

/*
void Partie::achat_carte(Joueur *joueur, Pile_Etablissement *pile)
{
  if (joueur->getCompte() >= pile->getPrix())
  {
    if (pile->retirerCarte(1))
    {
      joueur->ajouter_etablissement(pile->getEtablissement());
      joueur->ajouterMontant((-1)*pile->getPrix());
      cout << "Achat terminé !" << endl;
    }
    else
    {
      cout << "Plus de carte disponible !" << endl;
    }
  }
  else
  {
    cout << "Le joueur" << joueur->getId() << "n'a pas de ressource suffisante !" << endl;
  }
*/

// TODO: renommer CompterNbEtablissementdeType()
int Partie::fonction_service_verte(Type t)
{
  if (t == Type::aucun)
    return 1;
  else{
    int nombreactive=0;
    for (auto p : getJoueurActif()->getPileBleu()){
        if (p->getEtablissement()->getType() == t) {
            nombreactive += p->getEffectif(); //nombreactive++;
            cout << "            " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
      }
    }
    for (auto p : getJoueurActif()->getPileRouge()){
      if (p->getEtablissement()->getType()==t) {
          nombreactive += p->getEffectif(); //nombreactive++;
          cout << "            " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
      }
    }
    for (auto p : getJoueurActif()->getPileVert()){
      if (p->getEtablissement()->getType()==t) {
          nombreactive += p->getEffectif(); //nombreactive++;
          cout << "            " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
      }
    }
    for (auto p : getJoueurActif()->getPileViolet()){
      if (p->getEtablissement()->getType()==t) {
          nombreactive += p->getEffectif(); //nombreactive++;
          cout << "            " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
      }
    }
    return nombreactive;
  }
}

// TODO : renommer
void Partie::find_carte_des(int des)
{
  cout << endl
       << "Bilan des comptes :" << endl;
  for (auto joueur : getJoueurs())
  {
    cout << "  " << joueur->getId() << " Montant AVANT : " << joueur->getCompte() << endl;
    cout << "    "
         << "Cartes activées :" << endl;

    // Pile Rouge
    if (joueur != getJoueurActif())
    {
      for (auto pileRouge : joueur->getPileRouge())
      {
        int montant;
        if (pileRouge->getEtablissement()->estActif(des))
        {
          montant = pileRouge->getEtablissement()->getMontant() * pileRouge->getEffectif();
          joueur->ajouterMontant(montant);
          cout << "      " << pileRouge->getEtablissement()->getNom() << "  Quantité : " << pileRouge->getEffectif() << endl;

          getJoueurActif()->ajouterMontant((-1) * montant); // Le joueur en cours paye
        }
      }
    }

    // Pile Verte
    if (joueur == getJoueurActif())
    {
      for (auto p : joueur->getPileVert())
      {
        if (p->getEtablissement()->estActif(des))
        {
          //if (k == des)
          //{
            cout << "      " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
            cout << "      " << p->getEtablissement()->getEffet() << endl;
            joueur->ajouterMontant(p->getEtablissement()->getMontant() * p->getEffectif()*fonction_service_verte(p->getEtablissement()->getTypeEffet()));
            break;
          //}
        }
      }
    }

    // Pile Bleue
    for (auto p : joueur->getPileBleu())
    {
      if (p->getEtablissement()->estActif(des))
        {
          joueur->ajouterMontant(p->getEtablissement()->getMontant() * p->getEffectif());
          cout << "      " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
          break;
        }
      
    }

    // Pile Violette
    if (joueur == getJoueurActif())
    {
      for (auto p : joueur->getPileViolet()) // à discuter, maintenant je liste simplement les 3 cartes dans la version basique
      {

        if (p->getEtablissement()->estActif(des))
        {
            cout << "      *" << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
            cout << "      " << p->getEtablissement()->getEffet() << endl;
            // joueur->ajouterMontant(p->getEtablissement()->getMontant() * (getNbJoueurs() - 1) * p->getEffectif());
            // joueur->ajouterMontant(p->getEtablissement()->getMontant() * p->getEffectif());
            // pas obligé de faire * p->getEffectif() car on ne peut avoir qu'un SEUL établissement spécial !!!!!!!!!!!!!!!!!!!!!!!!!

            if (p->getEtablissement()->getNom() == "Stade" && p->getEffectif() == 1)
            {
                cout << "Voici les comptes des autres joueurs" << endl;
                int j = 1;
                for (auto joueurADebiter : getJoueurs())
                {
                  if (joueur != joueurADebiter)
                  {
                    cout << "J" << j++ << endl;
                    cout << "AVANT : " << joueurADebiter->getCompte() << endl;

                    if (joueurADebiter->getCompte() >= p->getEtablissement()->getMontant())
                    {
                      joueurADebiter->ajouterMontant((-1) * p->getEtablissement()->getMontant());
                      joueur->ajouterMontant(p->getEtablissement()->getMontant()); //* p->getEffectif());
                    }
                    else
                    {
                      joueur->ajouterMontant(joueurADebiter->getCompte());
                      joueurADebiter->ajouterMontant((-1) * joueurADebiter->getCompte());
                    }
                    cout << "APRES : " << joueurADebiter->getCompte() << endl
                         << endl;
                  }
                  else
                    j++;
                }
            }
            if (p->getEtablissement()->getNom() == "Centre d'affaires" && p->getEffectif() == 1)
            {
                cout << "Voici les cartes de chaque joueur" << endl;
                int i = 1;
                for (auto joueurAEchanger : getJoueurs())
                {
                    if (joueur != joueurAEchanger) {
                        cout << "J" << i++ << endl;
                        joueurAEchanger->printJoueurConcise();
                        cout << endl
                            << endl;
                    }
                    else i++;
                }
                cout << "Voici vos cartes" << endl;
                joueur->printJoueurConcise(); cout << endl << endl;

                // getJoueurs()[choix]->printJoueurConcise(cout);
                // p.getJoueurActif()->printJoueurConcise(cout);
                int choix = -1;
                while (true)
                {
                  cout << "Avec quel joueur souhaitez-vous échanger une de vos cartes ?" << endl;
                  cout << "Le numéro du joueur doit être compris entre 1 et " << getNbJoueurs() << endl;
                  cout << "Choisir 0 pour quitter" << endl;

                  try
                  { // Cette partie sert à détecter les erreurs eventuelles de saisie (Exemple : saisir une lettre à la place d'un nombre)
                    cin >> choix;
                  }
                  catch (exception ex)
                  {
                    cin.clear();           // Reset failbit à 0
                    cin.ignore(100, '\n'); // Vider buffer
                    cout << "Erreur ! Ce que vous avez saisi n'est pas un nombre." << endl;
                    choix = -1;
                    continue;
                  }
                  if (choix == 0)
                  {
                    break;
                  }
                  else if (choix < 1 || choix > getNbJoueurs() || choix == getJoueurActif()->getId())
                  {
                    cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
                  }
                  else
                  {
                    break;
                  }
                // getJoueurs()[choix - 1]->getPileBleu();
                // getJoueurs()[choix - 1]->getPileVert();
                // getJoueurs()[choix - 1]->getPileRouge();
                //
                //  TO DO : à continuer
                //
                // getJoueurs()[choix - 1]->printJoueurConcise(cout);
                // transaction_carte(Joueur * emetteur, Joueur * destinataire, const Etablissement * etab);
                // transaction_carte(getJoueurs()[choix - 1], getJoueurActif(), const Etablissement * etab);
              }
            }
            if (p->getEtablissement()->getNom() == "Chaine de television" && p->getEffectif() == 1)
            {
                cout << "Voici les comptes de chaque joueur" << endl;
                int i = 1;
                for (auto joueurADepouiller : getJoueurs())
                {
                  cout << "J" << i; if (i == getJoueurActif()->getId()) cout << " (vous)"; cout << endl; i++;
                  cout << joueurADepouiller->getCompte() << endl
                       << endl;
                }

                // getJoueurs()[choix]->printJoueurConcise(cout);
                // p.getJoueurActif()->printJoueurConcise(cout);
                int choix = -1;
                while (true)
                {
                  cout << "De quel joueur souhaitez-vous obtenir 5 pieces ?" << endl;
                  cout << "Le numéro du joueur doit être compris entre 1 et " << getNbJoueurs() << endl;
                  cout << "Choisir 0 pour quitter" << endl;

                  try
                  { // Cette partie sert à détecter les erreurs eventuelles de saisie (Exemple : saisir une lettre à la place d'un nombre)
                    cin >> choix;
                  }
                  catch (exception ex)
                  {
                    cin.clear();           // Reset failbit à 0
                    cin.ignore(100, '\n'); // Vider buffer
                    cout << "Erreur ! Ce que vous avez saisi n'est pas un nombre." << endl;
                    choix = -1;
                    continue;
                  }
                  if (choix == 0)
                  {
                    break;
                  }
                  else if (choix < 1 || choix > getNbJoueurs() || choix == getJoueurActif()->getId())
                  {
                    cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
                  }
                  else
                  {
                    break;
                  }
                }

                if (choix > 0)
                {
                  if (getJoueurs()[choix - 1]->getCompte() >= p->getEtablissement()->getMontant())
                  {
                    getJoueurs()[choix - 1]->ajouterMontant((-1) * p->getEtablissement()->getMontant());
                    joueur->ajouterMontant(p->getEtablissement()->getMontant()); //* p->getEffectif());
                  }
                  else
                  {
                    joueur->ajouterMontant(getJoueurs()[choix - 1]->getCompte());
                    getJoueurs()[choix - 1]->ajouterMontant((-1) * getJoueurs()[choix - 1]->getCompte());
                  }
                }
            }
            //break;
        }
        
      }
    }

    cout << "    "
         << "Montant APRES : " << joueur->getCompte() << endl;
    cout << endl;
  }
}

// TO DO :
// 1 acheter donc construire monument !!!! : OK
// 2 checker UN SEUL exemplaire d'établissement special !!!
