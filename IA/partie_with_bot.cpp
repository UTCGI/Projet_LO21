#include "partie_with_bot.h"
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
  if (nb_JH != 0){
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
  }
  //Initialisation IA
    for (size_t i = getNb_JH(); i < getNbJoueurs(); i++)
  { joueurs1.push_back(new Bot(jeu,i));}

  // Initialisation reserve
if(jeu.getExtension()==Extension::Aucune){
reserve = new Reserve(jeu);
}else{
  this->pioche = new Pioche(jeu);
  reserve = new Reserve(jeu,*pioche);
}
}

int PartieWithBot::choisirAction(){
  cout<<this->joueurs1[joueur_actif]->getPseudo()<<" choisit ";
  bool action = 0;
  //Si possible de construire un monument on le construit le moins cher
  Carte_Monument* cheapest = getCheapestMonument();
  if(getJoueurActif()->getCompte()>=cheapest->getMonument()->getPrix()){
    action = construire_monument(cheapest->getMonument());
    cout<<"de construire le monument "<<cheapest->getMonument()->getNom()<<endl;
    cout<<"Nouveau compte de "<<joueurs1[joueur_actif]->getPseudo()<<": "<<joueurs1[joueur_actif]->getCompte()<<endl;
         if (this->getJoueurActif()->victoire())
        {
            cout <<getJoueurActif()->getPseudo()<<" a gagné la partie."<<endl;
            return 4; // 1 : Fin de partie
        }
    return 3;
    }
  else{
    // On prend une carte de la réserve au hasard et on répète l’opération -
    //  jusqu’à en trouver une dans le budget/jusqu’à arriver à 5 tentatives
    bool ok = 1;
    unsigned int i = 0;
    while (ok && i<10){
    srand(time(NULL));
    int random = rand() % getReserve()->getNbPile();
    const Etablissement* etablissement_random = getReserve()->getListeEtablissement()[random]->getEtablissement();
    //Vérification pile non nulle
    while(getReserve()->getListeEtablissement()[random]->getEffectif() == 0){
    srand(time(NULL));
    random = rand() % getReserve()->getNbPile();
    etablissement_random = getReserve()->getListeEtablissement()[random]->getEtablissement();
    }
    if(etablissement_random->getPrix() <= getJoueurActif()->getCompte()){
              
              if(etablissement_random->getCouleur()==Couleur::violet){
                //Si violet, on check s'il n'est pas déjà présent
        bool etablissement_unique = 1;
        for (auto p : getJoueurActif()->getPileViolet()) {
            if (p->getEtablissement()->getNom() == etablissement_random->getNom()) {
              etablissement_unique = 0;
            }
        }
        if(etablissement_unique){action = achat_carte(getReserve()->getListeEtablissement()[random]);}
              }
              else{
              action = achat_carte(getReserve()->getListeEtablissement()[random]);
              if(action == true){
      cout<<"d'acheter la carte "<<etablissement_random->getNom()<<endl;
      cout<<"Nouveau compte de "<<joueurs1[joueur_actif]->getPseudo()<<": "<<joueurs1[joueur_actif]->getCompte()<<endl;
      ok = 0;
      return 2;
      }
              }
    }
    i++;
    }
    cout<<"de passer son tour"<<endl;
    //sinon on passe
    return 1;
  }
}

Carte_Monument* PartieWithBot::getCheapestMonument(){
  Carte_Monument* cheapest = nullptr;
  //Trouver le premier monument non construit
  unsigned int i = 0;
  //utilisation de bool construit pour contourner segmentation fault
    bool construit = getJoueurActif()->getMonuments()[i]->estConstruit();
  while (construit && i<getJoueurActif()->getMonuments().size()){
    i++;
    construit = getJoueurActif()->getMonuments()[i]->estConstruit();
    }
  if (not(construit)) 
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
void PartieWithBot::menu()
{
    int choix = -1;
    bool effet_parc_attraction = false;
    cin.exceptions(std::istream::failbit); // Activer module exception dans std::cin
  
    cout << endl << "Bienvenue !" << endl;

    while (choix != 0)
    {
        cout << "Joueur en cours : " << this->getJoueurActif()->getId() << endl;
        cout << "Montant AVANT : " << this->getJoueurActif()->getCompte() << endl;
        effet_parc_attraction = this->lancer(); // Le menu qui traite le lancement de dès
        cout << "Compte de " << this->getJoueurActif()->getPseudo()<< " : " << this->getJoueurActif()->getCompte() << endl;
    revenir:
      //Détection de bot
   if (dynamic_cast<Bot*>(this->getJoueurs()[joueur_actif])!=nullptr) {
          choix=this->choisirAction();
          if  (choix == 4){
          cout << endl << "Au revoir" << endl;
          exit(0);
          }else{
          this->joueur_next(effet_parc_attraction);
          }
        }else{
        cout << "Faire votre choix" << endl;
        // Partie Menu
        cout << "0\tQuitter" << endl;
        cout << "1\tPasser mon tour" << endl;
        cout << "2\tAcheter une carte de la réserve" << endl;
        cout << "3\tConstruire un monument" << endl;

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

        switch (choix)
        {
        case 0:
            cout << endl << "Au revoir" << endl;
            break;
        case 1:
            //Effet aéroport
            if (this->getJoueurActif()->getEffet_aeroport()){ this->getJoueurActif()->ajouterMontant(10); cout << "Vous gagnez 10 pièces grâce à votre monument Aeroport construit !" <<endl;}
            this->joueur_next(effet_parc_attraction);
            break;
        case 2:
            if(this->choix2()) goto revenir;
            this->joueur_next(effet_parc_attraction);
            break;

        case 3:
            switch (this->choix3())
            {
            case 0:
                this->joueur_next(effet_parc_attraction);
                break;
            case 1:
                choix = 0; // Si qqn gagne, partie terminée
                break;
            case 2:
                goto revenir; // Si quitter, rééssayer
            }
            break;

        default: // Les nombres unbound
            cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            goto revenir;
            break;
        }
        cout << endl;
    }
    }
}

bool PartieWithBot::lancer()
{
    bool effet_tour_radio_applicable = true;

    int des;
    int des2;
    int resultat; //Utile pour effets spéciaux
again:
    des2 = 0;
    resultat = 0;
    int choixNb_des = -1;
    des = this->getJoueurActif()->lancerDes();
    if (this->getJoueurActif()->getNbDes() == 2)
    {
        if (dynamic_cast<Bot*>(this->getJoueurs()[joueur_actif])!=nullptr) {
          srand(time(NULL));
          int random = rand()%(2) + 1;
          int choixNb_des = random;
          cout<<this->getJoueurActif()->getPseudo()<<" choisit de relancer";
          switch(choixNb_des){
            case 1 :
            cout<<" 1 dé."<<endl;
            break;
            case 2 :
            cout<<" 2 dés."<<endl;
            break;
          }
          
        }
        else{
        while (true)
        {
            cout << "Combien de dés voulez-vous lancer ?" << endl;
            cout << "Le nombre de dés doit être compris entre 1 et 2" << endl;

            try
            { // Cette partie sert à détecter les erreurs eventuelles de saisie (Exemple : saisir une lettre à la place d'un nombre)
                cin >> choixNb_des;
            }
            catch (exception ex)
            {
                cin.clear();           // Reset failbit à 0
                cin.ignore(100, '\n'); // Vider buffer
                cout << "Erreur ! Ce que vous avez saisi n'est pas un nombre." << endl;
                choixNb_des = -1;
                continue;
            }

            if (choixNb_des < 1 || choixNb_des > 2)
            {
                cout << "Erreur ! Vous n'avez pas saisi un nombre valide." << endl;
            }
            else
            {
                break;
            }
        }
    }
        //des = this->getJoueurActif()->lancerDes();
        if (choixNb_des == 2) {
            des2 = this->getJoueurActif()->lancerDes();
        }
    }

    resultat = des+des2;
    cout << "Dés obtenus :  " << des << " " << des2 << endl << "Somme : " << resultat << endl;//getNumDe()    
    
    //Effet tour radio
    if (effet_tour_radio_applicable&&this->getJoueurActif()->getEffet_tour_radio()){
      int choix;
        if (dynamic_cast<Bot*>(this->getJoueurs()[joueur_actif])!=nullptr) {
          srand(time(NULL));
          int random = rand()%(1) + 0;
          choix = random;
          cout<<this->getJoueurActif()->getPseudo()<<" choisit de relancer";
        }else{
        cout << "Vous voulez relancer ? Taper 1 si oui, 0 sinon" << endl;
        cin >> choix;
        }
        if (choix==1){ 
            effet_tour_radio_applicable = false;//Effet applicable une fois par tour
            goto again;
        }
    }
    
    //Effet port
    if (this->getJoueurActif()->getEffet_port() && (resultat)>=10){
      int choix;
       if (dynamic_cast<Bot*>(this->getJoueurs()[joueur_actif])!=nullptr) {
          srand(time(NULL));
          int random = rand()%(1) + 0;
          choix = random;
          cout<<this->getJoueurActif()->getPseudo()<<" choisit d'ajouter deux au résultat.";
        }else{
        cout << "Voulez-vous ajouter 2 au résultat obtenu ? Taper 1 si oui, 0 sinon" << endl;
        cin >> choix;
        }
        if (choix==1){ 
            resultat += 2;
        }
    }


    this->find_carte_des(resultat); // Trouver les cartes à appliquer effet
    
    //Effet parc d'attaction
    if (this->getJoueurActif()->getEffet_parc_attaction())
        return des==des2?true:false;
    else
        return false;
}


void test_PWB()
{
    PartieWithBot p;
    p.initialisation(); 
    //p.getCheapestMonument();
    //cout<<p.getCheapestMonument()->getMonument()->getNom()<<endl;
    //int a = p.choisirAction();
    p.menu();
}