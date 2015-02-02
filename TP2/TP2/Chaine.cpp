#ifndef CHAINE_C
#define CHAINE_C

#include "Chaine.h"

using namespace std;

Chaine::Chaine(){
	_chaine = new char[0];
	_taille = 0;
	cout << "construction de la chaine vide" << endl;
}

Chaine::Chaine(const char * c){
	_taille = 0;
	for (int i = 0; c[i] != '\0'; i++){
		_taille++;
	}
	_chaine = new char[_taille];
	for (int i = 0; c[i] != '\0'; i++){
		_chaine[i] = c[i];
	}
	cout << "construction de la chaine de taille " << _taille << endl;
}

Chaine::Chaine(const Chaine & c){
	_chaine = new char[c._taille];
	for (int i = 0; i < c._taille ; i++){
		_chaine[i] = c._chaine[i];
	}
	_taille = c._taille;
	cout << "Recopie de la chaine de taille " << _taille << endl;
}

void Chaine::afficher(){
	cout << "Chaine de taille " << _taille << " de contenu ";
	for (int i = 0; i < _taille; i++){
		cout << _chaine[i];
	}
	cout << endl;
}

Chaine::~Chaine(){
	cout << "Destruction d'une chaine de taille " << _taille << endl;
	_taille = 0;
	delete [] _chaine;	
}

bool Chaine::operator== (const Chaine & c) const {
	if (this->_taille != c.length()) {
		return false;
	}
	for (int i = 0; i < this->_taille; i++) {
		if (this->_chaine[i] != c.getChar(i)) {
			return false;
		}
	}
	return true;
}

bool Chaine::operator> (const Chaine & c) const {
	int taille = max(this->_taille, c.length());
	for (int i = 0; i < taille; i++) {
		if (this->_chaine[i] != c.getChar(i)) {
			return this->_chaine[i] > c.getChar(i);
		}
	}
	return this->_taille > c.length();
}

bool Chaine::operator< (const Chaine & c) const {
	int taille = max(this->_taille, c.length());
	for (int i = 0; i < taille; i++) {
		if (this->_chaine[i] != c.getChar(i)) {
			return this->_chaine[i] < c.getChar(i);
		}
	}
	return this->_taille < c.length();
}

bool Chaine::operator>= (const Chaine & c) const {
	return !(*this < c);
}

bool Chaine::operator<= (const Chaine & c) const {
	return !(*this > c);
}

Chaine Chaine::operator+ (const Chaine & c) const {
	int taille1 = this->_taille;
	int taille2 = c.length();
	int total = taille1 + taille2;
	char value[81];
	for (int i = 0; i < taille1; i++) {
		value[i] = this->_chaine[i];
	}
	int j = 0;
	for (int i = taille1; i < total; i++) {
		value[i] = c.getChar(j);
		j++;
	}
	Chaine resultat(value);
	return resultat;
}

#endif