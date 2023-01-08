#include <clocale>
#include <iostream>
#include "partie_with_bot.h"
#include "MKrandom.h"

using namespace std;
//int getRand(int min, int max);
int main(){
    setlocale(LC_ALL, "fr_FR.UTF-8");
    PartieWithBot* p = new PartieWithBot;
    p->initialisation(); 
    p->menu();
    delete p;
}


int getRand(int min, int max)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    return distr(gen);
}