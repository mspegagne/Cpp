#ifndef CARTE_C
#define CARTE_C
#include "Carte.h"

Carte * Carte::teteN = nullptr;
Carte * Carte::teteS = nullptr;
Carte * Carte::queueN = nullptr;
Carte * Carte::queueS = nullptr;

Carte::Carte(Couleur c, Valeur v, Joueur j) : _couleur(c), _valeur(v), _joueur(j)
{
	if (_joueur == nord){
		_succ = teteN;
		teteN = this;
		if (teteN == 0){
			queueN = this;
		}
	}
	else {
		_succ = teteN;
		teteS = this;
		if (teteS == 0){
			queueS = this;
		}
	}
}

bool Carte::egale(Carte carte) const {
	return _valeur == carte.valeur();
}

bool Carte::supAbs(Carte carte) const {
	return _valeur > carte.valeur();
}

void Carte::changerProp(){
	if (_joueur == nord){
		_joueur = sud;
		teteN = this->_succ;
		this->_succ = 0;
		queueS->_succ = this;
		queueS = this;
	}
	else {
		_joueur = nord;
		teteS = this->_succ;
		this->_succ = 0;
		queueN->_succ = this;
		queueN = this;
	}
}

void Carte::passerDerriere() {
	if (_joueur == nord){
		teteN = this->_succ;
		this->_succ = 0;
		queueN->_succ = this;
		queueN = this;
	}
	else {
		teteS = this->_succ;
		this->_succ = 0;
		queueS->_succ = this;
		queueS = this;
	}
}

void Carte::afficher() const {
	std::cout << "Couleur : " << _couleur << ", Valeur : " << _valeur << ", Joueur : " << _joueur << std::endl;
}
void Carte::afficherN() {
	Carte* c = teteN;
	do{
		c->afficher();
		c = c->suc();
	} while (c->suc() != 0);
}
void Carte::afficherS() {
	Carte* c = teteS;
	do{
		c->afficher();
		c = c->suc();
	} while (c->suc() != 0);
}
#endif