#include "manche.h"
#include <QPushButton>
#include <QVBoxLayout>
Manche::Manche(QWidget *parent,Partie* p)
    : QWidget{parent}, p(p)
{
    couche = new QVBoxLayout();
    quitter = new QPushButton("Quitter");
    connect(quitter,SIGNAL(clicked()), this, SLOT(fermer()));//Pour quitter

    couche->addWidget(quitter);
    setLayout(couche);

}




void Manche::fermer(){
    delete p;
    emit(relancer_menu());
    this->close();
}
