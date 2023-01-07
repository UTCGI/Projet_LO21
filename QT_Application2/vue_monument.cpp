#include "vue_monument.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include<QGuiApplication>
#include<QScreen>

#define x_scale 0.1
#define y_scale 0.1

vue_monument::vue_monument(const Monument* p, QWidget *parent) : QPushButton(parent), monument(p)
{
    setText(QString::fromStdString(p->getNom()+"\n\n\n"+std::to_string(p->getPrix())));

    setAutoFillBackground(true);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    setFixedHeight(screenGeometry.height()*y_scale);
    setFixedWidth(screenGeometry.width()*x_scale);
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
