#include "partie_with_bot.h"
PartieWithBot::PartieWithBot() : Partie(){
}
void PartieWithBot::initialisation()
{
  cout << "Bonjour, bienvenue dans le jeu MachiKoro." << endl;
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
  cout << "Entrez le nombre total de joueurs (humains et IA):" << endl;
  int lectureNbJoueurs = 0;
  while (lectureNbJoueurs < 2 || lectureNbJoueurs > jeu.getNb_joueurs_MAX())
  {
    cout << "Le nombre de joueur doit être compris entre 2 et " << jeu.getNb_joueurs_MAX() << endl;
    cin >> lectureNbJoueurs;
  }
  setNbJoueurs(lectureNbJoueurs);
  //lire le nombre d'IA 
  int choixIA = choix("Voulez-vous jouer avec IA ?\nTaper ", 1, 0, nullptr, " si oui, 0 sinon");
  if(choixIA){
    int lectureNbIA = 0;
    cout<<"Entrez le nombre d'IA"<<endl;
    cin>> lectureNbIA;
      while (lectureNbIA > nb_joueurs)
  {
    cout << "Le nombre d'IA doit être inférieur ou égal à " << nb_joueurs << endl;
    cin >> lectureNbIA;
  }
    setNb_IA(lectureNbIA);
  }
  setNb_JH(getNbJoueurs()-getNb_IA());
  //renseigner les pseudos
  int choixPseudo = choix("Voulez-vous renseigner les pseudos des joueurs ?\nTaper ", 1, 0, nullptr, " si oui, 0 sinon");

  // Initialisation joueur
  for (size_t i = 0; i < getNb_JH(); i++)
  {
      joueurs1.push_back(new Joueur(jeu));
      if (choixPseudo) {
          string pseudo;
          cout << endl << getJoueurs()[i]->getPseudo() << " Quel est votre pseudo ?" << endl;
          cin >> pseudo;
          getJoueurs()[i]->setPseudo(pseudo);
      }
      else{
          getJoueurs()[i]->setPseudo("J"+to_string(i+1));
      }
  }
  //Initialisation IA
    for (size_t i = getNb_JH(); i < getNbJoueurs(); i++)
  { joueurs1.push_back(new Bot(jeu,i));}

  // Initialisation reserve
  reserve = new Reserve(jeu);

  // TODO : initialisation pioche
}

int PartieWithBot::choisirAction(){
  bool action;
  //Si possible de construire un monument on le construit le moins cher
  Carte_Monument* cheapest = getCheapestMonument();
  if(getJoueurActif()->getCompte()>=cheapest->getMonument()->getPrix()){
    action = construire_monument(cheapest->getMonument());
    //TODO : affichage
    return 3;
    }
  else{
    //On prend une carte de la réserve au hasard et on répète l’opération -
     //jusqu’à en trouver une dans le budget/jusqu’à arriver à 5 tentatives
    bool ok = 1;
    unsigned int i = 5;
    while (ok && i<5){
    int random = rand() % getReserve()->getNbPile();
    if(getReserve()->getListeEtablissement()[random]->getEtablissement()->getPrix() <= getJoueurActif()->getCompte()){
      action = achat_carte(getReserve()->getListeEtablissement()[random]);
      //TODO : affichage
      ok = 0;
      return 2;
    }
    i++;
    }
    //sinon on passe
    return 1;
  }
}

Carte_Monument* PartieWithBot::getCheapestMonument(){
  Carte_Monument* cheapest = nullptr;
  //Trouver le premier monument non construit
  unsigned int i = 0;
  while (not(getJoueurActif()->getMonuments()[i]->estConstruit()) && i<getJoueurActif()->getMonuments().size()){i++;}
  if (not(getJoueurActif()->getMonuments()[i]->estConstruit())) 
  {
    cheapest = getJoueurActif()->getMonuments()[i];
  //Le remplacer éventuellement par le moins cher
  for (unsigned int j = i; j<getJoueurActif()->getMonuments().size();j++){
     if (not(getJoueurActif()->getMonuments()[j]->estConstruit()) && 
         getJoueurActif()->getMonuments()[j]->getMonument()->getPrix()<cheapest->getMonument()->getPrix()){
          cheapest=getJoueurActif()->getMonuments()[j];
         }
  }
  }
  return cheapest;
}


void test_PWB()
{
    PartieWithBot p;
    p.initialisation(); 
    p.menu();
}