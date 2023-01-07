#include "VueCarte.h"
#include <QPainter>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QStaticText>
#include <string>
#include <QGuiApplication>
#include <QScreen>

#define x_scale 0.14
#define y_scale 0.16

VueCarte::VueCarte(Pile_Etablissement* p, QWidget *parent) : QPushButton(parent),pile (p)
{
    //setBackgroundRole(QPalette::Base);
    QPalette pal = this->palette();
    switch (p->getEtablissement()->getCouleur()) {
    case Couleur::bleu:
        pal.setColor(QPalette::Button, QColor(61,115,173));
        break;
    case Couleur::rouge:
        pal.setColor(QPalette::Button, QColor(145,46,58));
        break;
    case Couleur::vert:
        pal.setColor(QPalette::Button, QColor(87,126,66));
        break;
    case Couleur::violet:
        pal.setColor(QPalette::Button, QColor(114,61,140));
        break;
    default:
        break;
    }

    //carteNom->setText(QString::fromStdString(p->getEtablissement()->getNom()+"\n\n"+p->getEtablissement()->getEffet()+"\n\n"+"Prix : "+std::to_string(p->getEtablissement()->getPrix())));
    QLabel * carteNom = new QLabel(this);
    carteNom->setText(QString::fromStdString(p->getEtablissement()->getNom()));
    carteNom->setAlignment(Qt::AlignCenter);
    carteNom->setMouseTracking(false);
    carteNom->setWordWrap(true);
    carteNom->setTextInteractionFlags(Qt::NoTextInteraction);
    QLabel * carteEffet = new QLabel(this);
    carteEffet->setText(QString::fromStdString(p->getEtablissement()->getEffet()));
    carteEffet->setAlignment(Qt::AlignCenter);
    carteEffet->setStyleSheet("font-size: 10px;");
    carteEffet->setMouseTracking(false);
    carteEffet->setWordWrap(true);
    carteEffet->setTextInteractionFlags(Qt::NoTextInteraction);
    carteQuantite = new QLabel(this);
    carteQuantite->setText(QString::fromStdString("Quantité : "+std::to_string(p->getEffectif())));
    carteQuantite->setAlignment(Qt::AlignCenter);
    carteQuantite->setMouseTracking(false);
    carteQuantite->setWordWrap(true);
    carteQuantite->setTextInteractionFlags(Qt::NoTextInteraction);
    QLabel * cartePrix = new QLabel(this);
    cartePrix->setText(QString::fromStdString("Prix : "+std::to_string(p->getEtablissement()->getPrix())));
    cartePrix->setAlignment(Qt::AlignCenter);
    cartePrix->setMouseTracking(false);
    cartePrix->setWordWrap(true);
    cartePrix->setTextInteractionFlags(Qt::NoTextInteraction);
    this->setLayout(new QVBoxLayout(this));
    this->layout()->addWidget(carteNom);
    this->layout()->addWidget(carteEffet);
    this->layout()->addWidget(cartePrix);
    this->layout()->addWidget(carteQuantite);


    setAutoFillBackground(true);
    setPalette(pal);
    //setFixedSize(300*x_scale,220*y_scale);
    //setFixedHeight(220*y_scale);
    //setMinimumHeight(250*y_scale);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    setFixedHeight(screenGeometry.height()*y_scale);
    setFixedWidth(screenGeometry.width()*x_scale);

    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(260*x_scale,200*y_scale);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}


void VueCarte::setQuantite(){carteQuantite->setText(QString::fromStdString("Quantité : "+std::to_string(pile->getEffectif())));};
