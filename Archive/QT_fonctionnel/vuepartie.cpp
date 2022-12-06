#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLCDNumber>
#include <QString>
#include <QMessageBox>

#include "VueCarte.h"
#include "vuepartie.h"


VuePartie::VuePartie(QWidget *parent) : QWidget(parent),vuecartes(20,nullptr)
{
    setWindowTitle("Set !"); // modifier le titre de la fenêtre
    controleur.initialisation();



    layoutCartes=new QGridLayout;

    size_t k=0;
    // création des vue des cartes
    for(auto i:controleur.getReserve()->getCarteBase())
            vuecartes[k++]=new VueCarte(i);
    for(size_t i=0; i<15; i++) {
        layoutCartes->addWidget(vuecartes[i],i/5,i%5); // ajout à la grid de cartes
        // connection su slot qui gère les clicks de carte
        //connect(vuecartes[i],SIGNAL(carteClicked(VueCarte*)),this,SLOT(carteClique(VueCarte*)));

    }

    setLayout(layoutCartes);
}

