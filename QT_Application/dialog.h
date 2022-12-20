#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include "jeu.h"
#include "partie.h"
#include "manche.h"

class QButtonGroup;
class QHBoxLayout;
class QPushButton;

class QVBoxLayout;
class QLabel;

class QSpinBox;
class Dialog : public QWidget
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
private:
    Jeu* jeu;
    Manche* manche;
    QButtonGroup* versions;//Toutes les extensions
    QHBoxLayout* layoutversions;

    QPushButton* confirmer;
    QPushButton* quitter;
    QHBoxLayout* layoutcontrols;
    QVBoxLayout* couche;

    QSpinBox* nbPersonne;
    QLabel* tester;//Affichage pour tester la sélection

signals:
    void creationpartie(Partie*);
public slots:
    void relancer(){this->show();}
private slots:
    void demarrer();
    void setmaxjoueur();//Une fonction utilisée pour changer le nombre maximum de joueur selon la version

};

#endif // DIALOG_H
