#include "manche.h"

#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>

#include <QVBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QVBoxLayout>

Manche::Manche(QWidget *parent,Partie* p)
    : QWidget{parent}, p(p)
{
    couche = new QHBoxLayout();
    layoutCartes = new QGridLayout();
    layoutButtons = new QVBoxLayout();
    couche->addLayout(layoutCartes);
    couche->addLayout(layoutButtons);

    reserveGroup = new QButtonGroup();
    reserveGroup->exclusive();// Seul un bouton checked à un instant donné
    int indice = 0;//Pour donner chaque VueCarte un id, aussi pour la mise en forme
    VueCarte* temp;//Stocker vuecarte reserve temporairement
    for(auto reserve = p->getReserve()->get_Iterator();reserve.contiditon();reserve.next()){
        temp = new VueCarte(*reserve);
        vueCartesReserve.push_back(temp);
        layoutCartes->addWidget(temp,indice/5,indice%5);
        reserveGroup->addButton(temp, indice++);
        connect(temp,SIGNAL(carteClicked(VueCarte*)),this, SLOT(setcartechoisie(VueCarte*)));
    }
    eliminerCarteChere();

    affichageIDJoueur = new QLabel();
    affichageIDJoueur->setNum(p->getJoueurActif()->getId());
    layoutButtons->addWidget(affichageIDJoueur);

    displayCarte = new QLabel("Rien choisie");
    layoutButtons->addWidget(displayCarte);

    acheter = new QPushButton("Acheter");
    connect(acheter, SIGNAL(clicked()), this, SLOT(choisirCarte()));
    layoutButtons->addWidget(acheter);

    passerMonTour = new QPushButton("Passer mon tour");
    connect(passerMonTour, SIGNAL(clicked()), this, SLOT(passertour()));
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
}

void Manche::setcartechoisie(VueCarte* vs){
    cartechoisie = vs;
}

void Manche::choisirCarte(){
    if (cartechoisie){
        displayCarte->setText(QString::fromStdString(cartechoisie->getCarte()->getEtablissement()->getNom()));
        update();
    }
}

void Manche::eliminerCarteChere(){
    int montantJoueur = p->getJoueurActif()->getCompte();
    for (auto k : vueCartesReserve){
        if (k->getCarte()->getPrix()>montantJoueur)//Si trop chère pour joueur
                k->setCheckable(false);
        else
            k->setCheckable(true);
    }
    update();
}

void Manche::passertour(){
    p->joueur_next(false);//False pour l'intant, faut modifier joueur_next
    affichageIDJoueur->setNum(p->getJoueurActif()->getId());
    update();
}
