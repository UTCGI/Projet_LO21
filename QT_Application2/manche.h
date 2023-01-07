#ifndef MANCHE_H
#define MANCHE_H

#include <QWidget>
#include "partie.h"
#include "VueCarte.h"
#include "vue_monument.h"

class QPushButton;
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QLCDNumber;
class QLabel;
class QSpinBox;
class QTableWidget;
class Manche : public QWidget
{
    Q_OBJECT
public:
    explicit Manche(QWidget *parent = nullptr, Partie* p = nullptr);


private:
    Partie* p;
    int deObtenu;

    //Partie layout
    QHBoxLayout* couche;

    QVBoxLayout* layoutReserve;
    QGridLayout* layoutCartes; // grille des cartes réserve

    QVBoxLayout* layoutJoueur; // grille des cartes joueur (y compris monuments)
    QGridLayout* layoutMonument;
    QGridLayout* layoutCartesJoueur;

    QVBoxLayout* layoutButtons;

    //Partie réserve
    QLabel* affichageEffet;
    std::vector<VueCarte*> vueCartesReserve;
    QButtonGroup* reserveGroup;


    //Partie joueur
    std::vector<vue_monument*> vueMonuments;
    QButtonGroup* monumentGroup;
    QTableWidget* bilan;


    //Partie Bouton
    QLabel* affichageIDJoueur;
    QLabel* montantJoueur;
    QLabel* displayDes;
    QPushButton* acheter;
    QPushButton* construire;
    QPushButton* passerMonTour;
    QPushButton* quitter;

    void rafraichir_quantite_reserve();
    void rafraichir_etats_monuments();
    void miseajour(){miseajourCompte(); miseajourBilan();}
    void miseajourCompte();
    void miseajourBilan();
    Partie* getPartie(){return p;}
    friend class Dialog;


    //Dialogs
    int deschoisirdialog(QWidget* parent);
    bool effet_tour_radio_dialog(QWidget* parent, int lastvalue);
    void gagner_dialog(QWidget* parent);


signals:
    void relancer_menu();
public slots:

private slots:
    void fermer();
    void afficher_effet();
    void acheter_reserve();
    void construire_monument();
    void eliminerCarteChere();
    void terminertour();
};

#endif // MANCHE_H
