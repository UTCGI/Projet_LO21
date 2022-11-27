
#include "buildfonctions.h"
#include "create_database.h"
#include <vector>
#include <cstring>

//***********************************
// dehors du QT

#include <filesystem>

//***********************************

// Dans QT
/* #include <QDir>
#include <QString>
#include <QFile> */


void lancerdatabase(sqlite3 **db){
    //*********************************************************************************************
    // Dans QT
    /* cout<<"here"<<endl;
    string cheminfinal = QDir::currentPath().toStdString()+"/projet.db";
    cout<<cheminfinal<<endl;
    if (!QFile::exists(QString::fromStdString(cheminfinal))) {
        //cout << "Database doesn't exist, creating\n";
        database(cheminfinal);
    }else{
        //cout << "Success\n";

    }
    sqlite3_open(cheminfinal.data(), db); */

    // dehors du QT
    
    if (!filesystem::exists("./projet.db"))
    {
        // cout << "Database doesn't exist, creating\n";
        database("./projet.db");
    }
    else
    {
        // cout << "Success\n";
    }
    sqlite3_open("./projet.db", db);
   




    //*********************************************************************************************
}

void buildmonument(vector<const Monument *> &liste_monuments)
{
    // Variable Sqlite3
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int row = 0;
    string sql;

    // Variable objets
    string nom;
    string effet;
    unsigned int prix;

    lancerdatabase(&db);



    sql = "SELECT * from monument";
    sqlite3_prepare(db, sql.data(), sql.length() * sizeof(char), &stmt, NULL);
    bool done = false;
    while (!done)
    {
        // printf("In select while\n");
        switch (sqlite3_step(stmt))
        {
        case SQLITE_ROW:
            nom = (const char *)sqlite3_column_text(stmt, 0);
            effet = (const char *)sqlite3_column_text(stmt, 1);
            prix = sqlite3_column_int(stmt, 2);
            liste_monuments.push_back(new Monument(nom, effet, prix));
            row++;
            break;

        case SQLITE_DONE:
            done = true;
            break;

        default:
            cout << "Failed.\n";
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void buildetablissement(vector<const Etablissement *> &liste_etablissements, Extension e)
{
    // Variable Sqlite3
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int row = 0;
    string sql;

    // Variable objets
    string nom = "-1";
    string effet;
    Couleur couleur;
    unsigned int prix;
    // unsigned int num_de; // from_1_to_12
    vector<unsigned int> num_de;
    Type type;
    unsigned int montant_effet;
    Type type_effet; // nouveau
    bool payeur;     // nouveau
    unsigned int nb_exemplaires;

    lancerdatabase(&db);

    sql = "SELECT nom, effet, couleur, prix, cast(de.atom as integer), type1, montant_effet, type_effet, payeur from " + toString1(e) + ", json_each(" + toString1(e) + ".num_de) de";

    sqlite3_prepare(db, sql.data(), sql.length() * sizeof(char), &stmt, NULL);
    bool done = false;
    while (!done)
    {
        // printf("In select while\n");
        switch (sqlite3_step(stmt))
        {
        case SQLITE_ROW:
            if (strcmp(nom.data(), (const char *)sqlite3_column_text(stmt, 0)) != 0)
            {
                if (row != 0)
                    liste_etablissements.push_back(new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur));
                row++;
                num_de.clear();
                nom = (const char *)sqlite3_column_text(stmt, 0);
                effet = (const char *)sqlite3_column_text(stmt, 1);
                couleur = toCouleur((const char *)sqlite3_column_text(stmt, 2));
                prix = sqlite3_column_int(stmt, 3);
                num_de.push_back(sqlite3_column_int(stmt, 4));
                type = toType((const char *)sqlite3_column_text(stmt, 5));
                montant_effet = sqlite3_column_int(stmt, 6);
                type_effet = toType((const char *)sqlite3_column_text(stmt, 7));
                payeur = sqlite3_column_int(stmt, 8);
                // cout<<endl;
            }
            else
            {
                num_de.push_back(sqlite3_column_int(stmt, 4));
            }
            break;

        case SQLITE_DONE:
            liste_etablissements.push_back(new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur));
            done = true;
            break;

        default:

            cout << "Failed.\n";
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void buildetablissementSpecial(vector<const Etablissement *> &liste_etablissements, Extension e)
{
    // Variable Sqlite3
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int row = 0;
    string sql;

    // Variable objets
    string nom = "-1";
    string effet;
    Couleur couleur;
    unsigned int prix;
    // unsigned int num_de; // from_1_to_12
    vector<unsigned int> num_de;
    Type type;
    unsigned int montant_effet;
    Type type_effet; // nouveau
    bool payeur;     // nouveau
    unsigned int nb_exemplaires;

    lancerdatabase(&db);

    // sql = "SELECT nom, effet, couleur, prix, cast(de.atom as integer), type1, montant_effet, type_effet, payeur from etablissement, json_each(etablissement.num_de) de";
    sql = "SELECT nom, effet, couleur, prix, cast(de.atom as integer), type1, montant_effet, type_effet, payeur from " + toString1(e) + "SP, json_each(" + toString1(e) + "SP.num_de) de";

    sqlite3_prepare(db, sql.data(), sql.length() * sizeof(char), &stmt, NULL);
    bool done = false;
    while (!done)
    {
        // printf("In select while\n");
        switch (sqlite3_step(stmt))
        {
        case SQLITE_ROW:
            if (strcmp(nom.data(), (const char *)sqlite3_column_text(stmt, 0)) != 0)
            {
                if (row != 0)
                    liste_etablissements.push_back(new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur));
                row++;
                num_de.clear();
                nom = (const char *)sqlite3_column_text(stmt, 0);
                effet = (const char *)sqlite3_column_text(stmt, 1);
                couleur = toCouleur((const char *)sqlite3_column_text(stmt, 2));
                prix = sqlite3_column_int(stmt, 3);
                num_de.push_back(sqlite3_column_int(stmt, 4));
                type = toType((const char *)sqlite3_column_text(stmt, 5));
                montant_effet = sqlite3_column_int(stmt, 6);
                type_effet = toType((const char *)sqlite3_column_text(stmt, 7));
                payeur = sqlite3_column_int(stmt, 8);
                // cout<<endl;
            }
            else
            {
                num_de.push_back(sqlite3_column_int(stmt, 4));
            }
            break;

        case SQLITE_DONE:
            liste_etablissements.push_back(new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur));
            done = true;
            break;

        default:

            cout << "Failed.\n";
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void builddepart(vector<const Etablissement *> &liste_etablissements_depart)
{
    // Variable Sqlite3
    sqlite3 *db;
    sqlite3_stmt *stmt;
    int row = 0;
    string sql;

    // Variable objets
    string nom = "-1";
    string effet;
    Couleur couleur;
    unsigned int prix;
    // unsigned int num_de; // from_1_to_12
    vector<unsigned int> num_de;
    Type type;
    unsigned int montant_effet;
    Type type_effet; // nouveau
    bool payeur;     // nouveau
    unsigned int nb_exemplaires;

    lancerdatabase(&db);

    sql = "SELECT nom, effet, couleur, prix, cast(de.atom as integer), type1, montant_effet, type_effet, payeur from Depart, json_each(Depart.num_de) de";

    sqlite3_prepare(db, sql.data(), sql.length() * sizeof(char), &stmt, NULL);
    bool done = false;
    while (!done)
    {
        // printf("In select while\n");
        switch (sqlite3_step(stmt))
        {
        case SQLITE_ROW:
            if (strcmp(nom.data(), (const char *)sqlite3_column_text(stmt, 0)) != 0)
            {
                if (row != 0)
                    liste_etablissements_depart.push_back(new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur));

                row++;
                num_de.clear();
                nom = (const char *)sqlite3_column_text(stmt, 0);
                effet = (const char *)sqlite3_column_text(stmt, 1);
                couleur = toCouleur((const char *)sqlite3_column_text(stmt, 2));
                prix = sqlite3_column_int(stmt, 3);
                num_de.push_back(sqlite3_column_int(stmt, 4));
                type = toType((const char *)sqlite3_column_text(stmt, 5));
                montant_effet = sqlite3_column_int(stmt, 6);
                type_effet = toType((const char *)sqlite3_column_text(stmt, 7));
                payeur = sqlite3_column_int(stmt, 8);
                // cout << endl;
            }
            else
            {
                num_de.push_back(sqlite3_column_int(stmt, 4));
            }
            break;

        case SQLITE_DONE:
            liste_etablissements_depart.push_back(new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur));
            done = true;
            break;

        default:

            cout << "Failed.\n";
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
