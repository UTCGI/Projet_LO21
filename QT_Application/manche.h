#ifndef MANCHE_H
#define MANCHE_H

#include <QWidget>
#include "partie.h"


class QPushButton;
class QVBoxLayout;
class Manche : public QWidget
{
    Q_OBJECT
public:
    explicit Manche(QWidget *parent = nullptr, Partie* p = nullptr);

private:
    Partie* p;
    QPushButton* quitter;
    QVBoxLayout* couche;
signals:
    void relancer_menu();
public slots:

private slots:
    void fermer();
};

#endif // MANCHE_H
