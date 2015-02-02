#ifndef ENSEMBLE_H
#define ENSEMBLE_H

#include <iostream>
#include "list.h"


// Pr�d�claration de Ensemble pour pouvoir pr�-d�clarer des op�rateurs
template <class T> class Ensemble;

// Pr�-d�claration pouvoir d�clarer ces op�rateurs amis de Ensemble
template <class T> std::ostream& operator<<(std::ostream& out, const Ensemble<T>& lref);
template <class T> std::istream& operator>>(std::istream& in, Ensemble<T>& lref);


// =====================================================================
// Classe: d�finition de la classe Ensemble<T> d�crivant un ensemble
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
	// But: op�rateur d'affichage d'une liste dans un flux
	// =====================================================================
	friend std::ostream& operator<< <T>(std::ostream& out, const Element<T>& lref);

	// =====================================================================
	// But: op�rateur de lecture d'une liste dans un flux
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