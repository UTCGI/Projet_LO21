#include "miniville.h"
#include "etablissement.h"

	initializer_list<Couleur> Couleurs = { Couleur::bleu, Couleur::rouge, Couleur::violet, Couleur::vert };
	initializer_list<Type> Types = { Type::aucun, Type::agriculture, Type::elevage, Type::ressources, Type::maritime,
		Type::commerce, Type::industrie, Type::maraichage, Type::entreprise, Type::restauration, Type::special };
	initializer_list<Extension> Extensions = { Extension::Aucune, Extension::Marina, Extension::GreenValley, Extension::Deluxe };

	string toString(Couleur c) {
		switch (c) {
		case Couleur::bleu:
			return "bleu";
		case Couleur::rouge:
			return "rouge";
		case Couleur::violet:
			return "violet";
		case Couleur::vert:
			return "vert";
		default:
			throw SetException("Couleur inconnue");
		}
	}

	string toString(Type t) {
		switch (t) {
		case Type::aucun:
			return "";
		case Type::agriculture:
			return "agriculture";
		case Type::elevage:
			return "elevage";
		case Type::ressources:
			return "ressources";
		case Type::maritime:
			return "maritime";
		case Type::commerce:
			return "commerce";
		case Type::industrie:
			return "industrie";
		case Type::maraichage:
			return "maraichage";
		case Type::entreprise:
			return "entreprise";
		case Type::restauration:
			return "restauration";
		case Type::special:
			return "special";
		default:
			throw SetException("Type inconnu");
		}
	}

	string toString(Extension e) {
		switch (e) {
		case Extension::Aucune:
			return "Minivilles sans extension";
		case Extension::Marina:
			return "Minivilles Marina";
		case Extension::GreenValley:
			return "Minivilles GreenValley";
		case Extension::Deluxe:
			return "Minivilles Deluxe";
		default:
			throw SetException("Extension inconnue");
		}
	}

	std::ostream& operator<<(std::ostream& f, Couleur c) { f << toString(c); return f; }
	std::ostream& operator<<(std::ostream& f, Type t) { f << toString(t); return f; }
	std::ostream& operator<<(std::ostream& f, Extension e) { f << toString(e); return f; }

	void printCouleurs(std::ostream& f) {
		for (auto c : Couleurs) f << c << " ";
		f << "\n";
	}

	void printTypes(std::ostream& f) {
		for (auto t : Types) f << t << " ";
		f << "\n";
	}

	void printExtensions(std::ostream& f) {
		size_t i = 0;
		for (auto e : Extensions) f << "[" << ++i << "] " << e << "\n";
		f << "\n\n";
	}
