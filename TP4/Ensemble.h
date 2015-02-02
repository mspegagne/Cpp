#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include <iostream>
#include "list.h"


// Prédéclaration de Ensemble pour pouvoir pré-déclarer des opérateurs
template <class T> class Ensemble;

// Pré-déclaration pouvoir déclarer ces opérateurs amis de Ensemble
template <class T> std::ostream& operator<<(std::ostream& out, const Ensemble<T>& lref);
template <class T> std::istream& operator>>(std::istream& in, Ensemble<T>& lref);


// =====================================================================
// Classe: définition de la classe Ensemble<T> décrivant un ensemble
// =====================================================================
template <class T> class Ensemble  {

private:
	List<T> _ens;

public:
	Ensemble(){
		_ens = List<T>();
	}

	
	Ensemble(const List<T> & l){
		// constructeur par recopie
		_ens = List(l);
	}



	// union de deux ensembles
	Ensemble<T> operator+ (const Ensemble<T> & e1) const;
	// soustraction de deux ensembles
	Ensemble<T> operator- (const Ensemble<T> & e1) const;
	// intersection de deux ensembles
	Ensemble<T> operator* (const Ensemble<T> & e1) const;
	// difference de deux ensembles
	Ensemble<T> operator/ (const Ensemble<T> & e1) const;

	// getter
	// Cardinal de l'ensemble
	int card_Ens() const {
		return _ens.card();
	}


	// =====================================================================
	// But: opérateur d'affichage d'une liste dans un flux
	// =====================================================================
	friend std::ostream& operator<< <T>(std::ostream& out, const Element<T>& lref);

	// =====================================================================
	// But: opérateur de lecture d'une liste dans un flux
	// =====================================================================
	friend std::istream& operator>> <T>(std::istream& in, Element<T>& lref);


};




template <class T>
std::ostream& operator<<(std::ostream& out, const Ensemble<T>& lref) {
	out << lref.card() << "    ";
	return out;
}

template <class T>
std::istream& operator>>(std::istream& in, Ensemble<T>& lref) {
	
	in >> lref;
	return in;
}

#endif