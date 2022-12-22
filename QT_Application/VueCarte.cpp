#include "VueCarte.h"
#include <QPainter>
#include <QString>
#include <QStaticText>

#define x_scale 0.6
#define y_scale 0.6

VueCarte::VueCarte(const Pile_Etablissement* p, QWidget *parent) : QPushButton(parent),pile (p)
{
    setText(QString::fromStdString(p->getEtablissement()->getNom()));
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120*x_scale,200*y_scale);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

VueCarte::VueCarte(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120*x_scale,200*y_scale);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}
