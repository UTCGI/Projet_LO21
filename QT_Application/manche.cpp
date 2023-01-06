#include "manche.h"

#include <QPushButton>
#include <QButtonGroup>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>

#include <QVBoxLayout>
#include <QGridLayout>
#include <QVBoxLayout>


Manche::Manche(QWidget *parent,Partie* p)
    : QWidget{parent}, p(p)
{

    couche = new QHBoxLayout();
    //Première colonne

    affichageEffet = new QLabel();//AffichageEffet
    layoutReserve = new QVBoxLayout();
    layoutCartes = new QGridLayout();
    layoutReserve->addWidget(affichageEffet);
    layoutReserve->addLayout(layoutCartes);
    layoutReserve->setStretch(0, 0);
    layoutReserve->setStretch(1, 1);
    layoutReserve->addStretch();
    layoutCartes->setVerticalSpacing(10);
    couche->addLayout(layoutReserve, 8);

    //Deuxième colonne
    layoutJoueur = new QVBoxLayout();
    layoutMonument = new QGridLayout();
    layoutCartesJoueur = new QGridLayout();


    layoutJoueur->addLayout(layoutMonument);
    layoutJoueur->addLayout(layoutCartesJoueur);
    couche->addLayout(layoutJoueur, 1);

    //Troisième colonne
    layoutButtons = new QVBoxLayout();
    couche->addLayout(layoutButtons, 1);

    //Première colonne
    reserveGroup = new QButtonGroup();
    reserveGroup->exclusive();// Seul un bouton checked à un instant donné


    int indice = 0;//Pour donner chaque VueCarte un id, aussi pour la mise en forme
    VueCarte* temp;//Stocker vuecarte reserve temporairement
    for(auto reserve = p->getReserve()->get_Iterator();reserve.contiditon();reserve.next()){

        temp = new VueCarte(*reserve);
        connect(temp,SIGNAL(carteClicked(VueCarte*)),this, SLOT(afficher_effet()));
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
    deObtenu = p->getJoueurActif()->lancerDes();
    p->find_carte_des(deObtenu);

    affichageIDJoueur = new QLabel();
    layoutButtons->addWidget(affichageIDJoueur);

    montantJoueur = new QLabel();
    montantJoueur->setText("Montant restant : "+QString::number(p->getJoueurActif()->getCompte()));
    layoutButtons->addWidget(montantJoueur);

    displayDes= new QLabel();
    displayDes->setText("Des obtenu : "+QString::number(deObtenu));
    layoutButtons->addWidget(displayDes);

    layoutButtons->addStretch();

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



    affichageEffet->setText(reserveGroup->checkedId()<0?"Veuillez choisir":QString::fromStdString(vueCartesReserve[reserveGroup->checkedId()]->getCarte()->getEtablissement()->getEffet()));
    this->setMinimumSize(1400, 600);


    setLayout(couche);

}






void Manche::fermer(){
    delete p;
    this->close();
    emit relancer_menu();
}


void Manche::acheter_reserve(){
    //vueCartesReserve[reserveGroup->checkedId()] pour accéder à la vuecarte choisie
    montantJoueur->setText("Montant restant : "+QString::number(p->getJoueurActif()->getCompte()));
    p->achat_carte(vueCartesReserve[reserveGroup->checkedId()]->getCarte());
    eliminerCarteChere();
    miseajour();
    update();

}

void Manche::construire_monument(){
    auto k = vueMonuments[monumentGroup->checkedId()];
    p->construire_monument(k->get_monument());
    k->repaint(p->getJoueurActif()->getMonuments()[monumentGroup->checkedId()]);
    miseajour();
    update();
}

void Manche::afficher_effet(){
    affichageEffet->setText(reserveGroup->checkedId()<0?"Veuillez choisir":QString::fromStdString(vueCartesReserve[reserveGroup->checkedId()]->getCarte()->getEtablissement()->getEffet()));
}

void Manche::miseajourCompte(){
    montantJoueur->setText("Montant restant : "+QString::number(p->getJoueurActif()->getCompte()));
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
            afficher_effet();
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
    deObtenu = p->getJoueurActif()->lancerDes();
    affichageIDJoueur->setText(QString::fromStdString(p->getJoueurActif()->getPseudo()));
    displayDes->setText("Des obtenu : "+QString::number(deObtenu));
    p->find_carte_des(deObtenu);
    eliminerCarteChere();
    rafraichir_etats_monuments();
    miseajour();
    update();
}
