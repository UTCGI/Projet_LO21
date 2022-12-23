#include "vue_monument.h"
#include <QPainter>
#include <QString>
#include <QStaticText>

#define x_scale 0.6
#define y_scale 0.6

vue_monument::vue_monument(const Monument* p, QWidget *parent) : QPushButton(parent), monument(p)
{
    setText(QString::fromStdString(p->getNom()));
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(120*x_scale,120*y_scale);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(true);
}

void vue_monument::repaint(Carte_Monument* c){
    if (c){
        if (c->estConstruit()){
            //setBackgroundRole(QPalette::Base);
        }else{
            //setBackgroundRole(QPalette::Shadow);
        }
    }
    update();
}
