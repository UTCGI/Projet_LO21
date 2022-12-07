#pragma once
#include <iostream>
#include "sqlite3.h"
#include "cstring"

using namespace std;

/*static*/ int createDB(const char* s);
/*static*/ int createTable(const char* s);
/*static*/ int insertData(const char* s);
/*static*/ int selectData(const char* s, const string& extension = "Aucune");
/*static*/ int collectEtablissement(void* NotUsed, int nbselectedlines, char** value, char** columnname);
/*static*/ int collectCaracteristique(void* NotUsed, int nbselectedlines, char** value, char** columnname);