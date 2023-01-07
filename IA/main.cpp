#include <clocale>
#include <iostream>
#include "partie_with_bot.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "fr_FR.UTF-8");
    PartieWithBot* p = new PartieWithBot;
    p->initialisation(); 
    p->menu();
    delete p;
    //testPioche();
    return 0;
}
