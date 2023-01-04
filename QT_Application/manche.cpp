#include "manche.h"

#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>

#include <QVBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QVBoxLayout>


Manche::Manche(QWidget *parent,Partie* p)
    : QWidget{parent}, p(p)
{

    couche = new QHBoxLayout();
    //Première colonne
    layoutCartes = new QGridLayout();
    couche->addLayout(layoutCartes);

    //Deuxième colonne
    layoutJoueur = new QVBoxLayout();
    layoutMonument = new QGridLayout();
    layoutCartesJoueur = new QGridLayout();
    layoutJoueur->addLayout(layoutMonument);
    layoutJoueur->addLayout(layoutCartesJoueur);
    couche->addLayout(layoutJoueur);

    //Troisième colonne
    layoutButtons = new QVBoxLayout();
    couche->addLayout(layoutButtons);

    //Première colonne
    reserveGroup = new QButtonGroup();
    reserveGroup->exclusive();// Seul un bouton checked à un instant donné
    int indice = 0;//Pour donner chaque VueCarte un id, aussi pour la mise en forme
    VueCarte* temp;//Stocker vuecarte reserve temporairement
    for(auto reserve = p->getReserve()->get_Iterator();reserve.contiditon();reserve.next()){
        temp = new VueCarte(*reserve);
        vueCartesReserve.push_back(temp);
        layoutCartes->addWidget(temp,indice/5,indice%5);
        reserveGroup->addButton(temp, indice++);
    }
    eliminerCarteChere();

    //Deuxième colonne
    monumentGroup = new QButtonGroup();
    monumentGroup->exclusive();
    indice = 0;
    vue_monument* temp1;
    auto monuments = p->getJeu()->getMonument();
    for(size_t count=0;count<p->getJeu()->getNbMonuments();count++){
        temp1 = new vue_monument(monuments[count]);
        vueMonuments.push_back(temp1);
        layoutMonument->addWidget(temp1,indice/2,indice%2);
        monumentGroup->addButton(temp1, indice++);
    }
    rafraichir_etats_monuments();

    bilan = new QTableWidget(p->getJeu()->getNbEtablissements(), 2);
    layoutJoueur->addWidget(bilan);
    int count = 0;
    for (auto k : p->getJoueurActif()->getPileRouge()){
        bilan->setItem(count++, 0, new QTableWidgetItem(QString::fromStdString((*k).getEtablissement()->getNom())));
    }
    for (auto k : p->getJoueurActif()->getPileBleu()){
        bilan->setItem(count++, 0, new QTableWidgetItem(QString::fromStdString((*k).getEtablissement()->getNom())));

    }
    for (auto k : p->getJoueurActif()->getPileVert()){
        bilan->setItem(count++, 0, new QTableWidgetItem(QString::fromStdString((*k).getEtablissement()->getNom())));
    }
    for (auto k : p->getJoueurActif()->getPileViolet()){
        bilan->setItem(count++, 0, new QTableWidgetItem(QString::fromStdString((*k).getEtablissement()->getNom())));
    }

    for (size_t i=0;i<p->getJeu()->getNbEtablissements();i++){
        bilan->setItem(i, 1, new QTableWidgetItem());
    }

    miseajourBilan();



    //Troisième colonne
    affichageIDJoueur = new QLabel();
    layoutButtons->addWidget(affichageIDJoueur);

    montantJoueur = new QLabel();
    montantJoueur->setNum(p->getJoueurActif()->getCompte());
    layoutButtons->addWidget(montantJoueur);

    displayCarte = new QLabel("Rien choisie");
    layoutButtons->addWidget(displayCarte);

    acheter = new QPushButton("Acheter");
    connect(acheter, SIGNAL(clicked()), this, SLOT(acheter_reserve()));
    layoutButtons->addWidget(acheter);

    construire = new QPushButton("Construire");
    connect(construire, SIGNAL(clicked()), this, SLOT(construire_monument()));
    layoutButtons->addWidget(construire);

    passerMonTour = new QPushButton("Terminer mon tour");
    connect(passerMonTour, SIGNAL(clicked()), this, SLOT(terminertour()));
    layoutButtons->addWidget(passerMonTour);

    quitter = new QPushButton("Quitter");
    connect(quitter,SIGNAL(clicked()), this, SLOT(fermer()));//Pour quitter
    layoutButtons->addWidget(quitter);






    setLayout(couche);

}






void Manche::fermer(){
    delete p;
    emit relancer_menu();
    this->close();
    delete this;
}


void Manche::acheter_reserve(){
    //vueCartesReserve[reserveGroup->checkedId()] pour accéder à la vuecarte choisie
    displayCarte->setText(QString::fromStdString(vueCartesReserve[reserveGroup->checkedId()]->getCarte()->getEtablissement()->getNom()));
    p->achat_carte(vueCartesReserve[reserveGroup->checkedId()]->getCarte());
    miseajour();
    update();

}

void Manche::construire_monument(){
    p->construire_monument(vueMonuments[monumentGroup->checkedId()]->get_monument());
    vueMonuments[monumentGroup->checkedId()]->setDisabled(true);//Si contruit, il devient non cliquable
    miseajour();
    update();
}

void Manche::miseajourCompte(){
    montantJoueur->setNum(p->getJoueurActif()->getCompte());
    update();
}

void Manche::miseajourBilan(){
    int count = 0;
    for (auto k : p->getJoueurActif()->getPileRouge()){
        bilan->item(count++, 1)->setText(QString::fromStdString(std::to_string(k->getEffectif())));
    }
    for (auto k : p->getJoueurActif()->getPileBleu()){
        bilan->item(count++, 1)->setText(QString::fromStdString(std::to_string(k->getEffectif())));
    }
    for (auto k : p->getJoueurActif()->getPileVert()){
        bilan->item(count++, 1)->setText(QString::fromStdString(std::to_string(k->getEffectif())));
    }
    for (auto k : p->getJoueurActif()->getPileViolet()){
        bilan->item(count++, 1)->setText(QString::fromStdString(std::to_string(k->getEffectif())));
    }
}

void Manche::rafraichir_etats_monuments(){//Mise à jour état construction des monuments
    auto monumentsJoueurEnCours = p->getJoueurActif()->getMonuments();
    int count = 0;
    int montantJoueur = p->getJoueurActif()->getCompte();
    for (auto k : monumentsJoueurEnCours){
        vueMonuments[count]->repaint(k);
        if (k->getMonument()->getPrix()>montantJoueur)//Si trop chère pour joueur
                vueMonuments[count]->setCheckable(false);
        else
            vueMonuments[count]->setCheckable(true);
        count++;
    }

    for (auto k : vueMonuments){//Autocheck le premier monument checkable (raison logique)
        if (k->isCheckable())
        {
            k->setChecked(true);
            break;
        }
    }
    update();
}

void Manche::eliminerCarteChere(){
    int montantJoueur = p->getJoueurActif()->getCompte();
    for (auto k : vueCartesReserve){
        if (k->getCarte()->getPrix()>montantJoueur)//Si trop chère pour joueur
                k->setCheckable(false);
        else
            k->setCheckable(true);
    }
    for (auto k : vueCartesReserve){//Autocheck la première carte checkable (raison logique)
        if (k->isCheckable())
        {
            k->setChecked(true);
            break;
        }
    }
    update();
}

void Manche::terminertour(){
    p->joueur_next(false);//False pour l'intant, faut modifier joueur_next
    affichageIDJoueur->setText(QString::fromStdString(p->getJoueurActif()->getPseudo()));
    eliminerCarteChere();
    rafraichir_etats_monuments();
    miseajour();
    update();
}
