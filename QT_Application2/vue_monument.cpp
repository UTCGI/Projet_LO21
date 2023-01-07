#include "vue_monument.h"
#include <QPainter>
#include <QString>
#include <QStaticText>

#define x_scale 0.6
#define y_scale 0.6

vue_monument::vue_monument(const Monument* p, QWidget *parent) : QPushButton(parent), monument(p)
{
    setText(QString::fromStdString(p->getNom()+"\n\n\n"+std::to_string(p->getPrix())));

    setAutoFillBackground(true);

    setFixedSize(220*x_scale,150*y_scale);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

void vue_monument::repaint(Carte_Monument* c){
    if (c){
        if (c->estConstruit()){

            setDisabled(true);
        }else{

            setDisabled(false);
        }
    }
    update();
}
