#include "dialog.h"
#include "miniville.h"
#include <QButtonGroup>
#include <QRadioButton>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
Dialog::Dialog(QWidget *parent):QWidget(parent)
{
    versions = new QButtonGroup();
    versions->exclusive();//Seulement un bouton à la fois
    tester = new QLabel(QString::fromStdString(toString1(Extensions[0])));//utiliser pour tester, essayer de cliquer sur valider
    jeu = new Jeu(Extensions[0]);

    layoutversions = new QHBoxLayout();
    layoutcontrols = new QHBoxLayout();
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


    confirmer = new QPushButton("Valider");
    connect(confirmer,SIGNAL(clicked()), this, SLOT(demarrer()));
    quitter = new QPushButton("Quitter");
    connect(quitter,SIGNAL(clicked()), this, SLOT(close()));//Pour quitter

    nbPersonne = new QSpinBox();
    nbPersonne->setMinimum(2);
    nbPersonne->setMaximum(jeu->getNb_joueurs_MAX());
    layoutversions->addWidget(nbPersonne);

    layoutcontrols->addWidget(tester);
    layoutcontrols->addWidget(confirmer);
    layoutcontrols->addWidget(quitter);
    couche->addLayout(layoutversions);
    couche->addLayout(layoutcontrols);
    setLayout(couche);
    this->show();
}

void Dialog::demarrer(){
    //this->hide();
    //tester->setText(QString::fromStdString(toString1(Extensions[versions->checkedId()])));
    manche = new Manche(nullptr, new Partie(jeu, nbPersonne->value()));
    connect(manche, SIGNAL(relancer_menu()), this, SLOT(relancer()));
    this->hide();
    manche->show();
}

void Dialog::setmaxjoueur(){
    tester->setText(QString::fromStdString(toString1(Extensions[versions->checkedId()])));
    delete jeu;
    jeu = new Jeu(Extensions[versions->checkedId()]);
    nbPersonne->setMaximum(jeu->getNb_joueurs_MAX());
    this->update();
}
