#include "monument.h"
#include "sqlite3.h"
/*#include <filesystem>
namespace fs = std::filesystem;*/


void buildmonument(const Monument** liste_monuments){
     //Variable Sqlite3
   sqlite3 *db;
   sqlite3_stmt *stmt;
   char *zErrMsg = 0;
   int rc;
   int row = 0;
   char* sql;

   //Variable objets
   string nom;
   string effet;

   //Il faut mettre à jour l'adresse absolue de la base de donnée avant de tester
   //rc = sqlite3_open("%s/projet.db", &db),fs::current_path();
   rc = sqlite3_open("../projet.db", &db);
   if (rc)
   {
      cout << "Can't open database: %s\n", sqlite3_errmsg(db);
      exit(0);
   }
   else
   {
      cout << "Opened database successfully" << endl;
   }

   sql = "SELECT * from monument";


   sqlite3_prepare(db, sql, strlen(sql)*sizeof(char), &stmt, NULL);
   bool done = false;
   while (!done)
   {
      printf("In select while\n");
      switch (sqlite3_step(stmt))
      {
      case SQLITE_ROW:
         nom = (const char*)sqlite3_column_text(stmt, 0);
         effet = (const char*)sqlite3_column_text(stmt, 1);
        liste_monuments[row] = new Monument(nom, effet);
         row++;
         break;

      case SQLITE_DONE:
         done = true;
         break;

      default:
         cout<<"Failed.\n";
        
      }
   }

   sqlite3_finalize(stmt);
   sqlite3_close(db); 

}

int main(){

    const Monument** liste_monuments = new const Monument * [4];
    buildmonument(liste_monuments);
    cout<<liste_monuments[0]->getNom()<<" "<<liste_monuments[0]->getEffet()<<liste_monuments[0]->getExemplaire()<<endl;
    return 0;
}