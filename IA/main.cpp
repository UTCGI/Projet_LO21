#include <clocale>
#include <iostream>
#include "partie.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "fr_FR.UTF-8");
    Partie p;
    p.menu();
    return 0;
}
