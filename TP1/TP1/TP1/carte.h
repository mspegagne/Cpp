/*!
* @file Carte.h
* @author Spegagne Mathieu - Millet Delphine G1.1
* @date 11/09/2013
*/
#ifndef CARTE_H
#define CARTE_H
#include <iostream>

/**
*	Players enum
*/
enum Joueur{
	nord = 1,
	sud
};

/**
*	Colors enum
*/
enum Couleur{
	pique = 1,
	trefle,
	coeur,
	carreau
};

/**
*	Values enum
*/
enum Valeur{
	as = 1,
	deux,
	trois,
	quatre,
	cinq,
	six,
	sept,
	huit,
	neuf,
	dix,
	valet,
	dame,
	roi
};

/**
* Carte is used to represents a deck of 52 cards.
*/
class Carte{
private:
	/**
	*	The player
	*/
	Joueur _joueur;
	/**
	*	The card's value
	*/
	Valeur _valeur;
	/**
	*	The card's color
	*/
	Couleur _couleur;
	/**
	*	The next card
	*/
	Carte * _succ;

	static Carte * teteN;
	static Carte * teteS;
	static Carte * queueN;
	static Carte * queueS;

public:

	/**
	* Constructor.
	* Set the color, the value, the player, and put it on the top of the deck
	* @param color
	* @param value
	* @param player
	*/
	Carte(Couleur c, Valeur v, Joueur j);
	/**
	* @return true if the 2 cards's values are equals
	* @param the card to compare with
	*/
	bool egale(Carte carte) const;
	/**
	* @return true if the card's value is superior to the value of the card in param
	* @param the card to compare with
	*/
	bool supAbs(Carte carte) const;
	/**
	* change the player
	*/
	void changerProp();
	/**
	* put the card on the bottom of the deck
	*/
	void passerDerriere();
	/**
	* display the card
	*/
	void afficher() const;
	/**
	* display the deck of the North player
	*/
	static void afficherN();
	/**
	* display the deck of the South player
	*/
	static void afficherS();

	/**
	*	Getters
	*/
	inline int joueur() const;
	inline int valeur() const;
	inline int couleur() const;
	inline Carte * suc() const;

	static Carte * getNTete() { return teteN; }
	static Carte * getSTete() { return teteS; }
};

/**
*	Getters
*/
inline int Carte::joueur() const { return _joueur; }
inline int Carte::valeur() const { return _valeur; }
inline int Carte::couleur() const { return _couleur; }
inline Carte * Carte::suc() const { return _succ; }

#endif