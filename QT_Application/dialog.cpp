#include "dialog.h"
#include "miniville.h"
#include <QButtonGroup>
#include <QRadioButton>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>

Dialog::Dialog(QWidget *parent):QWidget(parent)
{
    versions = new QButtonGroup();
    versions->exclusive();//Seulement un bouton à la fois
    jeu = new Jeu(Extensions[0]);

    layoutversions = new QHBoxLayout();
    form = new QFormLayout();
    layoutcontrols = new QVBoxLayout();
    formAndControls = new QHBoxLayout();
    couche = new QVBoxLayout();

    QRadioButton* temp;
    int idprovider = 0;

    for (auto extension: Extensions){//Création buttons pour sélectionner une version
        temp = new QRadioButton(QString::fromStdString(toString1(extension)));
        connect(temp,SIGNAL(clicked()), this, SLOT(setmaxjoueur()));
        versions->addButton(temp);
        versions->setId(temp,idprovider++);
        layoutversions->addWidget(temp);
    }

    versions->button(0)->setChecked(1);//Autocheck le premier bouton pour assurer que un bouton est toujours checked


    ajouterIA = new QPushButton("Ajouter IA");
    connect(ajouterIA,SIGNAL(clicked()), this, SLOT(addIA()));
    addplayer = new QPushButton("Ajouter Joueur");
    connect(addplayer,SIGNAL(clicked()), this, SLOT(addjoueur()));
    deleteplayer = new QPushButton("retirer Joueur");
    connect(deleteplayer,SIGNAL(clicked()), this, SLOT(deletejoueur()));//Pour quitter
    confirmer = new QPushButton("Valider");
    connect(confirmer,SIGNAL(clicked()), this, SLOT(demarrer()));
    quitter = new QPushButton("Quitter");
    connect(quitter,SIGNAL(clicked()), this, SLOT(close()));//Pour quitter


    for (size_t i=1;i<=2;i++){
        form->addRow(new QLineEdit("Player "+ QString::number(i)));
    }

    layoutcontrols->addWidget(ajouterIA);
    layoutcontrols->addWidget(addplayer);
    layoutcontrols->addWidget(deleteplayer);
    layoutcontrols->addWidget(confirmer);
    layoutcontrols->addWidget(quitter);

    formAndControls->addLayout(form);
    formAndControls->addLayout(layoutcontrols);

    couche->addLayout(layoutversions);
    couche->addLayout(formAndControls);
    setLayout(couche);
    this->show();
}

void Dialog::demarrer(){
    //this->hide();
    //tester->setText(QString::fromStdString(toString1(Extensions[versions->checkedId()])));
    manche = new Manche(nullptr, new Partie(jeu, form->rowCount()));

    int counter = 0;
    for(auto joueur : manche->getPartie()->getJoueurs()){
        joueur->setPseudo(dynamic_cast<QLineEdit*>(form->itemAt(counter++)->widget())->text().toStdString());
    }
    manche->affichageIDJoueur->setText(QString::fromStdString(manche->p->getJoueurActif()->getPseudo()));
    connect(manche, SIGNAL(relancer_menu()), this, SLOT(relancer()));
    this->hide();
    manche->showFullScreen();
    manche->show();
}

void Dialog::setmaxjoueur(){
    delete jeu;
    jeu = new Jeu(Extensions[versions->checkedId()]);
    size_t cap = IA?jeu->getNb_joueurs_MAX()-1:jeu->getNb_joueurs_MAX();
    while (static_cast<size_t>(form->rowCount())>cap)
        form->removeRow(form->rowCount()-1);

    this->update();
}

void Dialog::addIA(){
    if (ajouterIA->text() == "Ajouter IA"){
        ajouterIA->setText("Retirer IA");
        IA = true;
        while (static_cast<size_t>(form->rowCount()+1)>jeu->getNb_joueurs_MAX())
            form->removeRow(form->rowCount()-1);
    }
    else{
        ajouterIA->setText("Ajouter IA");
        IA = false;
    }
    this->update();
}

void Dialog::addjoueur(){
    size_t cap = IA?jeu->getNb_joueurs_MAX()-1:jeu->getNb_joueurs_MAX();
    if (static_cast<size_t>(form->rowCount())<cap)
        form->addRow(new QLineEdit("Player "+ QString::number(form->rowCount()+1)));
}
void Dialog::deletejoueur(){
    if (static_cast<size_t>(form->rowCount())>2)
        form->removeRow(form->rowCount()-1);
}


