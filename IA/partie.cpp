#include "partie.h"
#include "effets_monuments.h"
#include <iostream>

#include <vector>

using namespace std;
// ----------------------------------------------------------------
// Getter functions
// ----------------------------------------------------------------
int Partie::getManche() const { return manche; }

int Partie::getNumDe() const { return num_de; }

int Partie::getNbJoueurs() const { return nb_joueurs; }

//SINGLETON
//Jeu *Partie::getJeu() const { return jeu; }

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
Partie::Partie() : manche(0), num_de(1),  nb_joueurs(2) {//,
    initialisation();
}

Partie::~Partie() {}

// ----------------------------------------------------------------
// Methods
// ----------------------------------------------------------------
void Partie::initialisation()
{
  cout << "Bonjour, bienvenue dans le jeu MachiKoro" << endl;
  // Lire l'extension
  //int lectureExtension;
//retry:
  cout << "Entrez l'extension à laquelle vous voulez jouer" << endl;
  cout << "\t0. Originale\t1. Marina \t2. GreenValley\t3. Deluxe" << endl;
  do
  {
    cout << "L'extension doit être comprise entre 0 et 3" << endl;
    cin >> lectureExtension;

  } while (lectureExtension < 0 || lectureExtension > 3);
  Jeu& jeu = Jeu::getInstance(Extensions[lectureExtension]);
  //jeu = new Jeu(Extensions[lectureExtension]);
  // Lire le nombre de joueurs
  cout << "Entrez le nombre de joueurs :" << endl;
  int lectureNbJoueurs = 0;
  while (lectureNbJoueurs < 2 || lectureNbJoueurs > jeu.getNb_joueurs_MAX())
  {
    cout << "Le nombre de joueur doit être compris entre 2 et " << jeu.getNb_joueurs_MAX() << endl;
    cin >> lectureNbJoueurs;
  }
  setNbJoueurs(lectureNbJoueurs);

  //renseigner les pseudos
  int choixPseudo = choix("Voulez-vous renseigner les pseudos des joueurs ?\nTaper ", 1, 0, nullptr, " si oui, 0 sinon");

  // Initialisation joueur
  for (size_t i = 0; i < getNbJoueurs(); i++)
  {
      joueurs1.push_back(new Joueur(jeu));
      if (choixPseudo) {
          string pseudo;
          cout << endl << getJoueurs()[i]->getPseudo() << " Quel est votre pseudo ?" << endl;
          cin >> pseudo;
          getJoueurs()[i]->setPseudo(pseudo);
      }
  }

  // Initialisation reserve
  reserve = new Reserve(jeu);

  // TODO : initialisation pioche
}

void Partie::joueur_next(bool effet_parc_attration)
{
  if (!effet_parc_attration)
  {if (joueur_actif == joueurs1.size() - 1) // Quand c'est le dernier joueur
    joueur_actif = 0;
  else
    joueur_actif++;}
}

/*
void Partie::application_regle_standards(Couleur couleur)
{
  // TODO: A completer
} */

void Partie::transaction_piece(Joueur *emetteur, Joueur *destinataire, unsigned int montant)
{
    if (montant != 0) {
        cout << "      " << emetteur->getPseudo() << endl;//endl << 
        cout << "      AVANT : " << emetteur->getCompte() << endl;
        if (emetteur->getCompte() >= montant) {
            emetteur->ajouterMontant(0 - montant);
            destinataire->ajouterMontant(montant);
        }
        else
        {
            cout << "      " << emetteur->getPseudo() << " n'a pas assez de pieces pour tout payer !" << endl;
            destinataire->ajouterMontant(emetteur->getCompte());
            emetteur->ajouterMontant(0 - emetteur->getCompte());
        }
        cout << "      APRES : " << emetteur->getCompte() << endl;
    }
}
/* {
  if (montant > emetteur->getCompte())
    cout << "Erreur ! Le joueur " << emetteur->getPseudo() << " n'a pas assez de ressources pour effectuer la transaction.";
  else
  {
    emetteur->ajouterMontant(montant * (-1));
    destinataire->ajouterMontant(montant);
  }
}*/

void Partie::transaction_carte(Joueur* emetteur, Joueur*destinataire, const Etablissement* etab){
  if (emetteur->retirer_etablissement(etab))
    destinataire->ajouter_etablissement(etab);
}
//J2 //J3
void Partie::echanger_cartes(Joueur* emetteur, Joueur* destinataire, const Etablissement* etab1, const Etablissement* etab2) {
    if (emetteur == nullptr || destinataire == nullptr || etab1 == nullptr || etab2 == nullptr) {
        cout << "Echange impossible : un des joueurs ou un des établissements n'est pas correctement choisi" << endl;
        return;
    }
    transaction_carte(emetteur, destinataire, etab1);
    transaction_carte(destinataire, emetteur, etab2);
    cout << endl << "J" << emetteur->getId() << endl;
    emetteur->printJoueurConcise();
    cout << endl << "J" << destinataire->getId() << endl;
    destinataire->printJoueurConcise();
}

bool Partie::achat_carte(Pile_Etablissement *pile_reserve)
{
  if (pile_reserve->getEffectif() > 0)
  {
    if (pile_reserve->getEtablissement()->getPrix() <= getJoueurActif()->getCompte())
    {
        //check s'il a pas déjà cet établissement violet
        for (auto p : getJoueurActif()->getPileViolet()) {
            if (p->getEtablissement()->getNom() == pile_reserve->getEtablissement()->getNom() && p->getEffectif() == 1) {
                cout << "Achat impossible : vous ne pouvez posséder qu'un SEUL exemplaire de chaque établissement violet !" << endl;
                return false;
            }
        }
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
  Jeu& jeu = Jeu::getInstance(Extensions[lectureExtension]);
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
      else if (monument_choisi->getNom() == "Centre commercial"){
          effetHotelDeVille(this);
      }
      else if (monument_choisi->getNom() == "Parc d'attractions"){
          effetParcDAttractions(this);
      }
      else if (monument_choisi->getNom() == "Tour radio"){
          effetTourRadio(this);
      }

      if (jeu.getExtension()==Extension::Marina){
        if (monument_choisi->getNom() == "Tour radio") effetHotelDeVille(this); //En cours de développement. Faut déterminer la signification "Utilisé comme établissement de départ"
      }
      if (jeu.getExtension()==Extension::Marina || jeu.getExtension()==Extension::Deluxe){
        if (monument_choisi->getNom() == "Port") effetPort(this);
        else if (monument_choisi->getNom() == "Aeroport") effeAeroport(this);
      }
      
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


int Partie::choix(const string& m1, int n, int c, const vector<Pile_Etablissement*>* p, const string& m2) {
    int choix = -1;
    while (true)
    {
        cout << m1 << n; if (m2 == "Choisir 0 pour quitter") cout << endl;
        cout << m2 << endl; //"Choisir 0 pour quitter"
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
        else if (p==nullptr) {
            if (choix < 1 || choix > n || choix == c)
            {
                cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            }
            else
                break;
        }
        else
        {
            if (choix < 1 || choix > n || (*p)[choix - 1]->getEffectif() <= (*p)[choix - 1]->getMinimum())
            {
                cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            }
            else
                break;
        }
    }
    return choix;//false;
}


const vector<Pile_Etablissement*>*/*&*/ Partie::choixPile(const string & m1, const string & m2, int cj) { //, int c){
    int choixPile = -1;
    const vector<Pile_Etablissement*>* pile=nullptr;
    while (choixPile != 0)
    {
        cout << m1; 
        if (cj == 0)
            cj = getJoueurActif()->getId();
        cout << m2 << endl;
        //fonction_service_verte(Type::special);//etablissement de type special interdit à l'échange : ils se trouvent tous dans la PileViolet
        try
        { // Cette partie sert à détecter les erreurs eventuelles de saisie (Exemple : saisir une lettre à la place d'un nombre)
            cin >> choixPile;
        }
        catch (exception ex)
        {
            cin.clear();           // Reset failbit à 0
            cin.ignore(100, '\n'); // Vider buffer
            cout << "Erreur ! Ce que vous avez saisi n'est pas un nombre." << endl;
            choixPile = -1;
            continue;
        }
        cout << endl;
        switch (choixPile)
        {
        case 0:
            break;
        case 1:
            if (!(getJoueurs()[cj - 1]->estPresqueVide(getJoueurs()[cj - 1]->getPileRouge()))) {
                cout << getJoueurs()[cj - 1]->getPileRouge();// [0] [0] ;
                pile = &getJoueurs()[cj - 1]->getPileRouge();
                choixPile = 0;
            }
            else cout << "Rien à échanger dans cette pile !" << endl;
            break;
        case 2:
            if (!(getJoueurs()[cj - 1]->estPresqueVide(getJoueurs()[cj - 1]->getPileBleu()))) {
                cout << getJoueurs()[cj - 1]->getPileBleu();// [0] [0] ;
                pile = &getJoueurs()[cj - 1]->getPileBleu();
                choixPile = 0;
            }
            else cout << "Rien à échanger dans cette pile !" << endl;
            break;
        case 3:
            if (!(getJoueurs()[cj - 1]->estPresqueVide(getJoueurs()[cj - 1]->getPileVert()))) {
                cout << getJoueurs()[cj - 1]->getPileVert();// [0] [0] ;
                pile = &getJoueurs()[cj - 1]->getPileVert();
                choixPile = 0;
            }
            else cout << "Rien à échanger dans cette pile !" << endl;
            break;

        default: // Les nombres unbound
            cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            break;
        }
    }
    return pile;
}

// TODO: renommer CompterNbEtablissementdeType()
int Partie::fonction_service_type(Type t, Joueur* j)
{
  if (t == Type::aucun)
    return 1;
  else{
    int nombreactive=0;
    for (auto p : j->getPileBleu()){
        if (p->getEtablissement()->getType() == t) {
            nombreactive += p->getEffectif(); //nombreactive++;
            cout << "            " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
      }
    }
    for (auto p : j->getPileRouge()){
      if (p->getEtablissement()->getType()==t) {
          nombreactive += p->getEffectif(); //nombreactive++;
          cout << "            " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
      }
    }
    for (auto p : j->getPileVert()){
      if (p->getEtablissement()->getType()==t) {
          nombreactive += p->getEffectif(); //nombreactive++;
          cout << "            " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
      }
    }
    for (auto p : j->getPileViolet()){
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

    /* La partie pile rouge est désormais extraite pour assurer un déroulement en sens inverse */
  cout << "      " << "**********************Partie avant transaction**********************" << endl;
  int id_sens_inverse = joueur_actif;
  id_sens_inverse = id_sens_inverse == 0 ? getNbJoueurs() - 1 : id_sens_inverse - 1;
  while (id_sens_inverse != joueur_actif)
  {
      cout << "  " << id_sens_inverse + 1 << " " << getJoueurs()[id_sens_inverse]->getPseudo() << endl;
      cout << "  " << "Montant AVANT : " << getJoueurs()[id_sens_inverse]->getCompte() << endl;
      cout << "    " << "Cartes activées :" << endl;
      for (auto pileRouge : getJoueurs()[id_sens_inverse]->getPileRouge())
      {
          if (pileRouge->getEtablissement()->estActif(des))
          {
              //cout << "hello" << endl;
              if (pileRouge->getEffectif()>0){
              cout << "      " << pileRouge->getEtablissement()->getNom() << " (" << pileRouge->getEffectif() <<")"<< endl;
              cout << "      " << pileRouge->getEtablissement()->getEffet() << endl;
              }
              if (pileRouge->getEtablissement()->getNom() == "Sushi bar") {
                  if (getJoueurs()[id_sens_inverse]->getEffet_port())
                      transaction_piece(getJoueurActif(), getJoueurs()[id_sens_inverse], pileRouge->getMontant() * pileRouge->getEffectif());
                  else
                      cout << "      " << "L'effet ne s'applique pas : vous n'avez pas le port !" << endl;
              }
              else if (pileRouge->getEtablissement()->getNom() == "Restaurant 5 etoiles") {
                  //getNombreMonumentsConstruits()/*'Recevez 5 pieces du joueur qui a lance les des si celui-ci possede au moins deux monuments construits'*/
                  if (getJoueurActif()->getNombreMonumentsConstruits() > 1)
                      transaction_piece(getJoueurActif(), getJoueurs()[id_sens_inverse], pileRouge->getMontant() * pileRouge->getEffectif());
                  else
                      cout << "      " << "L'effet ne s'applique pas : " << getJoueurActif()->getPseudo() << " possède moins de 2 monuments construits !" << endl;
              }
              else if (pileRouge->getEtablissement()->getNom() == "Club prive" && pileRouge->getEffectif() == 1) {
                  //getNombreMonumentsConstruits()/*'Recevez toutes les pieces du joueur qui a lance les des si celui-ci possede au moins trois etablissements construits'*/
                  if (getJoueurActif()->getNombreMonumentsConstruits() > 2)
                      transaction_piece(getJoueurActif(), getJoueurs()[id_sens_inverse], getJoueurActif()->getCompte());
                  else
                      cout << "      " << "L'effet ne s'applique pas : " << getJoueurActif()->getPseudo() << " possède moins de 3 monuments construits !" << endl;
              }
              else
                  transaction_piece(getJoueurActif(), getJoueurs()[id_sens_inverse], pileRouge->getMontant() * pileRouge->getEffectif());
          }
      }
      cout << "    " << "Montant APRES : " << getJoueurs()[id_sens_inverse]->getCompte() << endl << endl;
      id_sens_inverse = id_sens_inverse == 0 ? getNbJoueurs() - 1 : id_sens_inverse - 1;
  }


  cout << "      " << "**********************Partie après transaction**********************" << endl;





    for (auto joueur : getJoueurs())
    {
        cout << "  " << joueur->getId() << " " << joueur->getPseudo() << endl;
        cout << "  " << "Montant AVANT : " << joueur->getCompte() << endl;
        cout << "    " << "Cartes activées :" << endl;

        // Pile Verte
        if (joueur == getJoueurActif())
        {
            for (auto p : joueur->getPileVert())
            {
                if (p->getEtablissement()->estActif(des))
                {
                    cout << "      " << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
                    cout << "      " << p->getEtablissement()->getEffet() << endl;
                    if (Jeu::getInstance().getExtension() == Extension::Aucune) {
                        joueur->ajouterMontant(p->getMontant() * p->getEffectif() * fonction_service_type(p->getEtablissement()->getTypeEffet(),joueur));
                        break;//car toutes les cartes vertes ont un num de de différent dans la version de base
                    }
                    else if (p->getEtablissement()->getNom() == "Fleuriste") {
                        /*'Recevez 1 piece de la banque pour chaque Champ de fleurs que vous possedez'*/
                        auto pileChamps_de_fleurs = getPileFromName("Champ de fleurs", joueur->getPileBleu());
                        unsigned int nbChamps_de_fleurs = pileChamps_de_fleurs->getEffectif();
                        cout << "            " << pileChamps_de_fleurs->getEtablissement()->getNom() << "  Quantité : " << nbChamps_de_fleurs << endl;
                        joueur->ajouterMontant(p->getMontant() * p->getEffectif() * nbChamps_de_fleurs);
                    }
                    else if (p->getEtablissement()->getNom() == "Epicerie") {
                        /*'Si vous possedez moins de deux monuments, recevez 2 pieces de la banque'*/
                        /*if (getJoueurActif()->getNombreMonumentsConstruits() > 1)
                            joueur->ajouterMontant(p->getMontant() * p->getEffectif() * fonction_service_type(p->getEtablissement()->getTypeEffet(),joueur));
                        else
                            cout << "      " << "L'effet ne s'applique pas : " << getJoueurActif()->getPseudo() << " possède moins de 2 monuments construits !" << endl;*/
                    }
                    else if (p->getEtablissement()->getNom() == "Entreprise de travaux publics") {
                        /*'Vous devez retourner une de vos cartes monuments sur sa face en travaux. Ce faisant, recevez 8 pieces de la banque'*/
                        /*if (getJoueurActif()->getNombreMonumentsConstruits() > 1)
                            joueur->ajouterMontant(p->getMontant() * p->getEffectif() * fonction_service_type(p->getEtablissement()->getTypeEffet(),joueur));
                        else
                            cout << "      " << "L'effet ne s'applique pas : " << getJoueurActif()->getPseudo() << " possède moins de 2 monuments construits !" << endl;*/
                    }
                    else if (p->getEtablissement()->getNom() == "Entreprise de demenagement") {
                        /*'Donnez a un autre joueur, un de vos etablissements qui ne soit pas de type special. Puis recevez 4 pieces de la banque'*/
                        /*if (getJoueurActif()->getNombreMonumentsConstruits() > 1)
                            joueur->ajouterMontant(p->getMontant() * p->getEffectif() * fonction_service_type(p->getEtablissement()->getTypeEffet(),joueur));
                        else
                            cout << "      " << "L'effet ne s'applique pas : " << getJoueurActif()->getPseudo() << " possède moins de 2 monuments construits !" << endl;*/
                    }
                    else if (p->getEtablissement()->getNom() == "Moonster soda") {
                        /*'Recevez 1 piece de la banque pour chaque etablissement de type restauration que possedent tous les joueurs'*/
                        /*if (getJoueurActif()->getNombreMonumentsConstruits() > 1)
                            joueur->ajouterMontant(p->getMontant() * p->getEffectif() * fonction_service_type(p->getEtablissement()->getTypeEffet(),joueur));
                        else
                            cout << "      " << "L'effet ne s'applique pas : " << getJoueurActif()->getPseudo() << " possède moins de 2 monuments construits !" << endl;*/
                    }
                    else
                        joueur->ajouterMontant(p->getMontant()* p->getEffectif()* fonction_service_type(p->getEtablissement()->getTypeEffet(), joueur));

                    
                }
            }
        }

        // Pile Bleue
        for (auto p : joueur->getPileBleu())
        {
            if (p->getEtablissement()->estActif(des) && p->getEffectif()>0)
            {
                    cout << "      " << p->getEtablissement()->getNom() << "  (" << p->getEffectif() << ")"<<endl;
                
                if (Jeu::getInstance().getExtension() == Extension::Aucune)
                    joueur->ajouterMontant(p->getMontant() * p->getEffectif());
                else if (p->getEtablissement()->getNom() == "Petit bateau de peche") {
                    /*'Si vous avez le Port, recevez 3 pieces de la banque'*/
                    cout << "      " << p->getEtablissement()->getEffet() << endl;
                    if (joueur->getEffet_port())
                        joueur->ajouterMontant(p->getMontant() * p->getEffectif());
                    else
                        cout << "      " << "L'effet ne s'applique pas : vous n'avez pas le port !" << endl;
                }
                else if (p->getEtablissement()->getNom() == "Chalutier") {
                    /*'Le joueur dont c''est le tour lance 2 des. Si vous avez le Port recevez de la banque autant de pieces que le total des 2 des'*/
                    cout << "      " << p->getEtablissement()->getEffet() << endl;
                    if (joueur->getEffet_port()) {
                        srand(time(NULL));
                        int DeuxDes = rand() % 11 + 2;
                        cout << "      Somme des deux dés : " << DeuxDes << endl;
                        joueur->ajouterMontant(DeuxDes * p->getEffectif());
                    }
                    else
                        cout << "      " << "L'effet ne s'applique pas : vous n'avez pas le port !" << endl;
                }
                else
                    joueur->ajouterMontant(p->getMontant() * p->getEffectif());
                break;//car toutes les cartes bleues ont un num de de différent toutes versions confondues

            }

        }

        // Pile Violette
        if (joueur == getJoueurActif())
        {
            for (auto p : joueur->getPileViolet()) // à discuter, maintenant je liste simplement les 3 cartes dans la version basique
            {

                if (p->getEtablissement()->estActif(des) && p->getEffectif()>0)
                {
                    cout << "      *" << p->getEtablissement()->getNom() << "  Quantité : " << p->getEffectif() << endl;
                    cout << "      " << p->getEtablissement()->getEffet() << endl;
                    // joueur->ajouterMontant(p->getMontant() * (getNbJoueurs() - 1) * p->getEffectif());
                    // joueur->ajouterMontant(p->getMontant() * p->getEffectif());
                    // pas obligé de faire * p->getEffectif() car on ne peut avoir qu'un SEUL établissement spécial !!!!!!!!!!!!!!!!!!!!!!!!!

                    if (p->getEtablissement()->getNom() == "Maison d'edition" && p->getEffectif() == 1)
                    {
                        /*'Recevez 1 piece de chaque joueur pour chaque etablissement de type restauration et commerce qu''il possede'*/
                        int nbEtRestauration, nbEtCommerce;
                        for (auto joueurADebiter : getJoueurs())
                        {
                            if (joueur != joueurADebiter){ //cout << "TypeEffet : " << p->getEtablissement()->getTypeEffet() << endl; TRES BIZARRE
                                cout << "      " << "Voici les établissements de type restauration et commerce que possède ";
                                cout << joueurADebiter->getPseudo() << endl;
                                nbEtRestauration = 0; nbEtCommerce = 0;
                                nbEtRestauration = fonction_service_type(Type::restauration, joueurADebiter);
                                nbEtCommerce = fonction_service_type(Type::commerce, joueurADebiter);
                                transaction_piece(joueurADebiter, joueur, p->getMontant() * (nbEtRestauration + nbEtCommerce));
                            }
                        }
                        break;//car cette carte violette a un num de dé différent toutes versions confondues
                    }

                    if (p->getEtablissement()->getNom() == "Centre des impots" && p->getEffectif() == 1)
                    {
                        /*'Recevez la moitie (arrondie a l''inferieur) des pieces de chaque joueur qui en possede 10 ou plus'*/
                        for (auto joueurADebiter : getJoueurs())
                        {
                            if (joueur != joueurADebiter && joueurADebiter->getCompte() > 9)
                                transaction_piece(joueurADebiter, joueur, joueurADebiter->getCompte()/2);
                        }
                        break;//car cette carte violette a un num de dé différent toutes versions confondues
                    }

                    if (p->getEtablissement()->getNom() == "Stade" && p->getEffectif() == 1)
                    {
                        cout << "      " << "Voici les comptes des autres joueurs" << endl;
                        for (auto joueurADebiter : getJoueurs())
                        {
                            if (joueur != joueurADebiter)
                                transaction_piece(joueurADebiter, joueur, p->getMontant());
                        }
                    }

                    if (p->getEtablissement()->getNom() == "Centre d'affaires" && p->getEffectif() == 1)
                    {
                        cout << "      " << "Voici les cartes des autres joueurs" << endl;
                        for (auto joueurAEchanger : getJoueurs())
                        {
                            if (joueur != joueurAEchanger) {
                                cout << "J" << joueurAEchanger->getId() << endl;
                                joueurAEchanger->printJoueurConcise();
                                cout << endl << endl;
                            }
                        }
                        int choixJoueur = choix("Avec quel joueur souhaitez-vous échanger une de vos cartes ?\nLe numéro du joueur doit être compris entre 1 et ", getNbJoueurs(), getJoueurActif()->getId());
                        if (choixJoueur != 0) {
                            auto pileChoisie = choixPile("Dans quelle pile du joueur choisi se trouve la carte à échanger contre l'une des vôtres ?\nFaire votre choix\n1\tPile Rouge\n2\tPile Bleu\n3\tPile Vert\n", "Choisir 0 pour quitter", choixJoueur);
                            if (pileChoisie != nullptr) {
                                int choixCarte = choix("Quel est le numéro de la pile dans laquelle se trouve la carte à échanger contre l'une des vôtres ? \nLe numéro de la pile doit être compris entre 1 et ", (*pileChoisie).size(), 0, pileChoisie);
                                if (choixCarte != 0) { //cout << pileChoisie[choixCarte - 1]->getEtablissement()[0];
                                    cout << "Voici vos cartes" << endl;
                                    joueur->printJoueurConcise(); cout << endl << endl;
                                    auto pile2Choisie = choixPile("Dans laquelle de vos piles se trouve la carte à échanger ?\nFaire votre choix\n1\tPile Rouge\n2\tPile Bleu\n3\tPile Vert\n");
                                    if (pile2Choisie != nullptr) {
                                        int choixCarte2 = choix("Quel est le numéro de la pile dans laquelle se trouve la carte à échanger ? \nLe numéro de la pile doit être compris entre 1 et ", (*pile2Choisie).size(), 0, pile2Choisie); //nombreDePileActive(pile2Choisie)
                                        if (choixCarte2 != 0)
                                            echanger_cartes(getJoueurs()[choixJoueur - 1], getJoueurActif(), (*pileChoisie)[choixCarte - 1]->getEtablissement(), (*pile2Choisie)[choixCarte2 - 1]->getEtablissement());
                                    }
                                }
                            }
                        }
                    }

                    if (p->getEtablissement()->getNom() == "Chaine de television" && p->getEffectif() == 1)
                    {
                        cout << "      " << "Voici les comptes de chaque joueur" << endl;
                        for (auto joueurADepouiller : getJoueurs())
                        {
                            cout << "J" << joueurADepouiller->getId(); if (joueurADepouiller == getJoueurActif()) cout << " (vous)"; cout << endl;
                            cout << joueurADepouiller->getCompte() << endl
                                << endl;
                        }
                        int c = choix("De quel joueur souhaitez-vous obtenir 5 pieces ?\nLe numéro du joueur doit être compris entre 1 et ", getNbJoueurs(), getJoueurActif()->getId());
                        if (c > 0)
                            transaction_piece(getJoueurs()[c - 1], joueur, p->getMontant());
                    }
                    //break;
                }
            }
        }
        cout << "  " << "Montant APRES : " << joueur->getCompte() << endl;
        cout << endl;
    }
}

