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

class QFormLayout;
class QSpinBox;
class QLineEdit;
class Dialog : public QWidget
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
private:
    Jeu* jeu;
    Manche* manche;
    bool IA = false;

    QButtonGroup* versions;//Toutes les extensions
    QHBoxLayout* layoutversions;

    QPushButton* ajouterIA;
    QPushButton* addplayer;
    QPushButton* deleteplayer;
    QPushButton* confirmer;
    QPushButton* quitter;
    QVBoxLayout* layoutcontrols;
    QFormLayout* form;
    QHBoxLayout* formAndControls;
    QVBoxLayout* couche;



    //QSpinBox* nbPersonne;

    void paintPlayerform();

signals:
    void creationpartie(Partie*);
public slots:
    void relancer(){showNormal();delete manche;this->show();}
private slots:
    void demarrer();
    void setmaxjoueur();//Une fonction utilisée pour changer le nombre maximum de joueur selon la version
    void addIA();
    void addjoueur();
    void deletejoueur();

};

#endif // DIALOG_H
