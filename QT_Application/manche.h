#ifndef MANCHE_H
#define MANCHE_H

#include <QWidget>
#include "partie.h"
#include "VueCarte.h"


class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLCDNumber;
class QLabel;
class Manche : public QWidget
{
    Q_OBJECT
public:
    explicit Manche(QWidget *parent = nullptr, Partie* p = nullptr);

private:
    Partie* p;

    //Partie layout
    QHBoxLayout* couche;
    QGridLayout* layoutCartes; // grille des cartes
    QVBoxLayout* layoutButtons;

    //Partie réserve
    std::vector<VueCarte*> vueCartesReserve;
    QButtonGroup* reserveGroup;
    VueCarte* cartechoisie = nullptr;

    //Partie joueur
    QLabel* affichageIDJoueur;
    QLabel* displayCarte;
    QPushButton* acheter;
    QPushButton* passerMonTour;
    QPushButton* quitter;




signals:
    void relancer_menu();
public slots:

private slots:
    void fermer();
    void setcartechoisie(VueCarte* vs);
    void choisirCarte();
    void eliminerCarteChere();
    void passertour();
};

#endif // MANCHE_H
