#ifndef VUE_MONUMENT_H
#define VUE_MONUMENT_H

#include <QWidget>
#include <QPushButton>
#include "Carte_Monument.h"

class vue_monument : public QPushButton
{
    Q_OBJECT
public:
    vue_monument(const Monument* p, QWidget *parent = nullptr);
    // affecter une nouvelle carte à la vue
    void repaint(Carte_Monument* c);
    const Monument* get_monument(){return monument;}
private:
    const Monument* monument = nullptr;
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(vue_monument*);
public slots:
private slots:
    void clickedEvent() { emit carteClicked(this); }
};

#endif // VUE_MONUMENT_H

