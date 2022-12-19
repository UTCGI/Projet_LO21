#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include "jeu.h"

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
    QButtonGroup* versions;//Toutes les extensions
    QHBoxLayout* layoutversions;

    QPushButton* confirmer;
    QPushButton* quitter;
    QHBoxLayout* layoutcontrols;
    QVBoxLayout* couche;

    QSpinBox* nbPersonne;
    QLabel* tester;//Affichage pour tester la sélection
private slots:
    void demarrer();
    void setmaxjoueur();//Une fonction utilisée pour changer le nombre maximum de joueur selon la version

};

#endif // DIALOG_H
