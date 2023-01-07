#pragma once
#include "Carte_Monument.h"
#include "jeu.h"
#include "miniville.h"
#include "pile_etablissement.h"
#include <string>
#include <cstdlib>

class Joueur {
protected:
    static int nombre_actuel; // Compteur du nombre actuel de joueur
    int id;
    string pseudo = "J";
    int de = 1;
    unsigned int compte = 3;
    std::vector<Carte_Monument*> monuments;
    std::vector<Pile_Etablissement*> pileRouge;
    std::vector<Pile_Etablissement*> pileBleu;
    std::vector<Pile_Etablissement*> pileVert;
    std::vector<Pile_Etablissement*> pileViolet;

    bool effet_parc_attaction = false;
    bool effet_tour_radio = false;
    bool effet_port = false;
    bool effet_aeroport = false;

public:
    Joueur(const Jeu& jeu);
    virtual ~Joueur();


    //Section effet
    bool getEffet_parc_attaction()const{return effet_parc_attaction;}
    void setEffet_parc_attaction(){ effet_parc_attaction = true;}

    bool getEffet_tour_radio()const{return effet_tour_radio;}
    void setEffet_tour_radio(){ effet_tour_radio = true;}

    bool getEffet_port()const{return effet_port;}
    void setEffet_port(){ effet_port = true;}

    bool getEffet_aeroport()const{return effet_aeroport;}
    void setEffet_aeroport(){ effet_aeroport = true;}

    // Getter
    int getId() const { return id; }

    string getPseudo() const { return pseudo; }

    int getNbDes() const;

    unsigned int getCompte() const;

    int getNombreMonumentsConstruits() const;

    const vector<Carte_Monument*>& getMonuments() const { return monuments; }
    const Carte_Monument* getMonument(unsigned int i) const { return monuments[i]; }

    const vector<Pile_Etablissement*>& getPileRouge() const { return pileRouge; }

    const vector<Pile_Etablissement*>& getPileBleu() const { return pileBleu; }

    const vector<Pile_Etablissement*>& getPileVert() const { return pileVert; }

    const vector<Pile_Etablissement*>& getPileViolet() const { return pileViolet; }

    

    // Setter

    void setPseudo(string pseudo) { this->pseudo = pseudo; };

    void setNbDes();

    void setCompte(int montant);

    void initialisation_etablissement_depart(const Etablissement* e);

    void ajouter_etablissement(const Etablissement* e);

    bool retirer_etablissement(const Etablissement* e);

    void ajouterMontant(int montant);

    bool victoire() const;

    int lancerDes() const;

    bool estPresqueVide(const vector<Pile_Etablissement*>& pile);

    void printJoueur(ostream& f = std::cout) const;

    void printJoueurConcise(ostream& f = cout) const; // Affichage plus concis
};

int nombreDePileActive(const vector<Pile_Etablissement*>& pile);

ostream& operator<<(ostream& f, const Joueur& j);
