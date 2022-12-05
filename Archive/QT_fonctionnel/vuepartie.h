#ifndef VUEPARTIE_H
#define VUEPARTIE_H

#include <QWidget>
#include <vector>
#include <set>
#include "partie.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;
class VueCarte;

class VuePartie : public QWidget
{
    Q_OBJECT
public:
    explicit VuePartie(QWidget *parent = nullptr);
private:
    Partie controleur; // controleur de la partie
    QHBoxLayout* layoutInformations;
    QGridLayout* layoutCartes; // grille des cartes
    QVBoxLayout* couche;
    vector<VueCarte*> vuecartes; // adresses des objets VueCarte
    int scoreValue=0; // score courant (nb de sets trouvés)
private slots:
    // slots qui gère les clics sur les cartes
    //void carteClique(VueCarte* vc);
};
#endif // VUEPARTIE_H
