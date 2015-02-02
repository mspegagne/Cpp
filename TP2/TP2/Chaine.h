/*!
* @file Chaine.h
* @author Spegagne Mathieu - Millet Delphine G1.2
* @date 17/09/2013
*/
#ifndef CHAINE_H
#define CHAINE_H

#include <algorithm>
#include <iostream>

class Chaine {
	//attributs
	int _taille;
	char * _chaine;

public :

	/* Constructors */
	Chaine();
	Chaine(const char * c);
	Chaine(const Chaine & c);
	
	/* Destuctors */
	~Chaine();

	/* Printers */
	void afficher();

	/*Fonctions de comparaison*/
	bool operator== (const Chaine & c) const;
	bool operator> (const Chaine & c) const;
	bool operator< (const Chaine & c) const;
	bool operator<= (const Chaine & c) const;
	bool operator>= (const Chaine & c) const;

	/*Fonctions de concatenation*/
	Chaine operator+ (const Chaine & c) const;

	/* Getter */
	inline char getChar(const int n) const;
	inline int length() const;
};

/* Getter */
inline char Chaine::getChar(const int n) const { return this->_chaine[n]; }
inline int Chaine::length() const { return _taille; }

#endif