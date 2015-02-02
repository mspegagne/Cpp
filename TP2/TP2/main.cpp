/**
* \brief Main du TP2.
*
*/

#include "Chaine.h"
#include <iostream>

using namespace std;

int main()
{
	/*Construction chaines*/

	char value1[81];
	cout << "valeur 1 ?" << endl;
	cin >> value1;
	Chaine * chaine1 = new Chaine(value1);

	char value2[81];
	cout << "valeur 2 ?" << endl;
	cin >> value2;
	Chaine * chaine2 = new Chaine(value2);

	/*Affichage chaine*/
	chaine1->afficher();
	chaine2->afficher();

	/*Getter*/
	//==
	int rang = 0;
	cout << "Rang du caractere de la valeur 1 a renvoyer ?" << endl;
	cin >> rang;
	char val = chaine1->getChar(rang-1);
	cout << "Le second caractere de valeur 1 est :" << val << endl;

	/*Operators*/
	//==
	if (*chaine1 == *chaine2)
	{
		cout << "chaine1 == chaine2" << endl;
	}
	else
	{
		cout << "!(chaine1 == chaine2)" << endl;
	}

	//>
	if (*chaine1 > *chaine2)
	{
		cout << "chaine1 > chaine2" << endl;
	}
	else
	{
		cout << "!(chaine1 > chaine2)" << endl;
	}

	//<
	if (*chaine1 < *chaine2)
	{
		cout << "chaine1 < chaine2" << endl;
	}
	else
	{
		cout << "!(chaine1 < chaine2)" << endl;
	}

	//>=
	if (*chaine1 >= *chaine2)
	{
		cout << "chaine1 >= chaine2" << endl;
	}
	else
	{
		cout << "!(chaine1 >= chaine2)" << endl;
	}

	//<=
	if (*chaine1 <= *chaine2)
	{
		cout << "chaine1 <= chaine2" << endl;
	}
	else
	{
		cout << "!(chaine1 <= chaine2)" << endl;
	}

	//+
	Chaine * resultat = new Chaine(*chaine1 + *chaine2);
	resultat->afficher();
	
	/*Destuction chaine*/
	delete chaine1;
	delete chaine2;
	delete resultat;

	system("pause");
	return EXIT_SUCCESS;



}