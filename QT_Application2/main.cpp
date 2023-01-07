
#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    //QApplication::setAttribute(Qt::AA_Use96Dpi);
    //QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication a(argc, argv);
    Dialog menu;
    menu.show();
    return a.exec();
}
