#include "buildfonctions.h"
#include "create_database.h"
#include <cstring>
#include <vector>

//***********************************
// dehors du QT

#include <filesystem>

//***********************************

// Dans QT
#include <QDir>
#include <QFile>
// #include <QString>

void lancerdatabase(sqlite3** db)
{
    //*********************************************************************************************
    // Dans QT
    string cheminfinal = QDir::currentPath().toStdString()+"/projet.db";
    cout<<cheminfinal<<endl;
    if (!QFile::exists(QString::fromStdString(cheminfinal))) {
        //cout << "Database doesn't exist, creating\n";
        database(cheminfinal);
    }else{
        //cout << "Success\n";

    }
    sqlite3_open(cheminfinal.data(), db);

    // dehors du QT


    //*********************************************************************************************
}

void buildcaracteristics1(Jeu* j, Extension e)
{
    cout << toString1(j->getExtension()) << endl;

    sqlite3* db;
    sqlite3_stmt* stmt;
    int rc;
    int row = 0;
    string sql;

    // Variable objets
    // Extension extension;// = Extension::Aucune;
    size_t cdv;
    size_t nbj;
    size_t nbpr;
    size_t nblr;
    size_t nbcr;
    size_t nbed;
    size_t nbe;
    size_t nbm;
    size_t nbc;

    lancerdatabase(&db);
    sql = "select * from Jeu where nom='" + toString1(e) + "';";
    // cout << sql;
    sqlite3_prepare(db, sql.data(), sql.length() * sizeof(char), &stmt, NULL);
    bool done = false;
    while (!done) {
        // printf("In select while\n");
        switch (sqlite3_step(stmt)) {
        case SQLITE_ROW:
            j->condition_de_victoire = sqlite3_column_int(stmt, 1);
            j->nb_joueurs_MAX = sqlite3_column_int(stmt, 2);
            j->nb_pile_reserve_MAX = sqlite3_column_int(stmt, 3);
            j->nb_lignes_reserve_MAX = sqlite3_column_int(stmt, 4);
            j->nb_colonnes_reserve_MAX = sqlite3_column_int(stmt, 5); //(const size_t)
            j->nbEtablissements_Depart = sqlite3_column_int(stmt, 6);
            j->nbEtablissements = sqlite3_column_int(stmt, 7);
            j->nbMonuments = sqlite3_column_int(stmt, 8);
            j->nbCartes = sqlite3_column_int(stmt, 9);
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

    j->liste_etablissements = new const Etablissement*[j->getNbEtablissements()];
    j->liste_monuments = new const Monument*[j->getNbMonuments()];

    j->liste_etablissements_depart = new const Etablissement*[j->getNbEtablissements_Depart()];
}

void buildmonument(const Monument** liste_monuments, Extension e)
{
    // Variable Sqlite3
    sqlite3* db;
    sqlite3_stmt* stmt;
    int row = 0;
    string sql;

    // Variable objets
    string nom;
    string effet;
    unsigned int prix;

    lancerdatabase(&db);

    sql = "SELECT * from " + toString1(e) + "Monument;"; // monument";
    sqlite3_prepare(db, sql.data(), sql.length() * sizeof(char), &stmt, NULL);
    bool done = false;
    while (!done) {
        // printf("In select while\n");
        switch (sqlite3_step(stmt)) {
        case SQLITE_ROW:
            nom = (const char*)sqlite3_column_text(stmt, 0);
            effet = (const char*)sqlite3_column_text(stmt, 1);
            prix = sqlite3_column_int(stmt, 2);
            liste_monuments[row] = new Monument(nom, effet, prix);
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

void buildetablissement(const Etablissement** liste_etablissements, const Etablissement** liste_etablissements_depart /* , const Etablissement **liste_etablissements_speiciaux */, Extension e)
{
    // Variable Sqlite3
    sqlite3* db;
    sqlite3_stmt* stmt;
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
    bool payeur; // nouveau
    int identificateur;
    unsigned int nb_exemplaires;
    const Etablissement* temp = nullptr;

    int nombreCarteDepart;
    int nombreCarteNormale;
    int nombreCarteSpeciale;

    if (e == Extension::Deluxe) {
        nombreCarteDepart = 5;
        nombreCarteNormale = 5;
        nombreCarteSpeciale = 2;
    } else {
        nombreCarteDepart = 4;
        nombreCarteNormale = 6;
        nombreCarteSpeciale = 4;
    }

    lancerdatabase(&db);

    sql = "SELECT nom, effet, couleur, prix, cast(de.atom as integer), type1, montant_effet, type_effet, payeur, identificateur from " + toString1(e) + ", json_each(" + toString1(e) + ".num_de) de";

    sqlite3_prepare(db, sql.data(), sql.length() * sizeof(char), &stmt, NULL);
    bool done = false;
    while (!done) {
        // printf("In select while\n");
        switch (sqlite3_step(stmt)) {
        case SQLITE_ROW:
            if (strcmp(nom.data(), (const char*)sqlite3_column_text(stmt, 0)) == 0 && identificateur == sqlite3_column_int(stmt, 9)) {
                num_de.push_back(sqlite3_column_int(stmt, 4));
            } else {
                if (row != 0) {
                    if (identificateur == 0)
                        if (couleur == Couleur::vert && type_effet != Type::aucun)
                            *(liste_etablissements_depart++) = new Etablissement_VertTE(nom, effet, couleur, prix, num_de, type, montant_effet, false, nombreCarteDepart, type_effet);
                        else
                            *(liste_etablissements_depart++) = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, false, nombreCarteDepart);
                    else if (identificateur <= 1) {
                        // temp = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur);
                        if (couleur == Couleur::vert && type_effet != Type::aucun)
                            *(liste_etablissements++) = new Etablissement_VertTE(nom, effet, couleur, prix, num_de, type, montant_effet, false, nombreCarteNormale, type_effet);
                        else
                            *(liste_etablissements++) = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, false, nombreCarteNormale);

                    } else
                        // Partie carte spéciale
                        //  *(liste_etablissements++) = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur);
                        *(liste_etablissements++) = new Etablissement_Violet(nom, effet, couleur, prix, num_de, type, montant_effet, true, nombreCarteSpeciale, payeur);
                    //*(liste_etablissements_speiciaux++) = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur);
                }
                row++;
                num_de.clear();
                nom = (const char*)sqlite3_column_text(stmt, 0);
                effet = (const char*)sqlite3_column_text(stmt, 1);
                couleur = toCouleur((const char*)sqlite3_column_text(stmt, 2));
                prix = sqlite3_column_int(stmt, 3);
                num_de.push_back(sqlite3_column_int(stmt, 4));
                type = toType((const char*)sqlite3_column_text(stmt, 5));
                montant_effet = sqlite3_column_int(stmt, 6);
                type_effet = toType((const char*)sqlite3_column_text(stmt, 7));
                payeur = sqlite3_column_int(stmt, 8);
                identificateur = sqlite3_column_int(stmt, 9);
                // cout<<endl;
            }
            break;

        case SQLITE_DONE:
            if (row != 0) {
                if (identificateur == 0)
                    if (couleur == Couleur::vert && type_effet != Type::aucun)
                        *(liste_etablissements_depart++) = new Etablissement_VertTE(nom, effet, couleur, prix, num_de, type, montant_effet, false, nombreCarteDepart, type_effet);
                    else
                        *(liste_etablissements_depart++) = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, false, nombreCarteDepart);
                else if (identificateur <= 1) {
                    // temp = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur);
                    if (couleur == Couleur::vert && type_effet != Type::aucun)
                        *(liste_etablissements++) = new Etablissement_VertTE(nom, effet, couleur, prix, num_de, type, montant_effet, false, nombreCarteNormale, type_effet);
                    else
                        *(liste_etablissements++) = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, false, nombreCarteNormale);

                } else
                    // Partie carte spéciale
                    //  *(liste_etablissements++) = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur);
                    *(liste_etablissements++) = new Etablissement_Violet(nom, effet, couleur, prix, num_de, type, montant_effet, true, nombreCarteSpeciale, payeur);
                //*(liste_etablissements_speiciaux++) = new Etablissement(nom, effet, couleur, prix, num_de, type, montant_effet, type_effet, payeur);
            }
            done = true;
            break;

        default:

            cout << "Failed.\n";
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
