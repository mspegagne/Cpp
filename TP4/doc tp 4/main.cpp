//=======================================================================
// main.cpp
//=======================================================================

#include "ensemble.h"
#include <fstream>
#include <iostream>
#include <string>

//=======================================================================
// M�thode   : 	Ensemble<int> lire(char* fname)
// But       : 	Lecture d'un ensemble dans un fichier texte
// Param�tres: 	fname	:
// Retour    : 	Ensemble<int>
//=======================================================================
Ensemble<int> lire(const std::string& fname) {
	Ensemble<int> res;
	// Ouverture du fichier contenant l'ensemble
	std::ifstream input(fname.c_str(), std::ios::in);

	if (!input) {
		std::cerr  << "Erreur de lecture de " << fname << std::endl;
	}
	else {
		input >> res;
		std::cout << "Contenu du fichier \"" << fname << "\" = " << res << std::endl;
	}

	// Fermeture du fichier
	input.close();

	return res;
}

//=======================================================================
// M�thode   : 	void main()
// But       : 	Programme principal de test
// Param�tres: 	-
//=======================================================================
int main() {
	// Lecture des ensembles
	Ensemble<int> e1 = lire("test1.txt");
	Ensemble<int> e2 = lire("test2.txt");

	// Affichage des ensembles
	std::cout << "e1 = " << e1 << std::endl;
	std::cout << "e2 = " << e2 << std::endl;

	// Op�rations sur les ensembles
	std::cout << "Union        :: " << (e1 + e2) << std::endl;
	std::cout << "Intersection :: " << (e1 * e2)<< std::endl;
	std::cout << "Soustraction :: " << (e1 - e2)<< std::endl;
	std::cout << "Difference   :: "   << (e1 / e2)<< std::endl;
	return 0;
}
