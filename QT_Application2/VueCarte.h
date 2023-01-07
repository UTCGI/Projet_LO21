#ifndef VUECARTE_H
#define VUECARTE_H

#include <QWidget>
#include <QPushButton>
#include "pile_etablissement.h"

class VueCarte : public QPushButton
{
    Q_OBJECT
public:
    VueCarte(Pile_Etablissement* p, QWidget *parent = nullptr);
    explicit VueCarte(QWidget *parent = nullptr);
    // affecter une nouvelle carte à la vue
    void setCarte(Pile_Etablissement* p) { setCheckable(true); setChecked(false); pile=p; update(); }
    Pile_Etablissement* getCarte() const { return pile; }
private:
    Pile_Etablissement* pile = nullptr;
signals:
    // quand la vude de carte est cliquée, elle émet un signal en transmettant son adresse
    void carteClicked(VueCarte*);
public slots:
private slots:
    void clickedEvent() { emit carteClicked(this); }
};

#endif // VUECARTE_H

