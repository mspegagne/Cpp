#include "sequences.h"

using namespace std;

int main() {
	string s1, s2, s3;
	cout << "Entrez une sequence proteique: ";
	cin >> s1;
	cout << "Entrez son nom: ";
	cin >> s2;

	try {
		seqprot P1(s1, s2);
		cout << P1 << endl;
	}
	catch (std::invalid_argument e) {
		cout << "Proteine incorrecte, essaye encore : " << e.what() << endl;
		std::system("pause");
		return 1;
	}

	cout << "Entrez une sequence d'adn: ";
	cin >> s1;
	cout << "Entrez son nom: ";
	cin >> s2;

	try {
		seqadn A1(s1, s2);
		cout << A1 << endl;
	}
	catch (std::invalid_argument e) {
		cout << "ADN incorrecte, essaye encore : " << e.what() << endl;
		std::system("pause");
		return 1;
	}

	cout << "Entrez une sequence d'arn: ";
	cin >> s1;
	cout << "Entrez son nom: ";
	cin >> s2;

	try {
		seqarn R1(s1, s2);
		cout << R1 << endl;
	}
	catch (std::invalid_argument e) {
		cout << "ARN incorrecte, essaye encore : " << e.what() << endl;
		std::system("pause");
		return 1;
	}

	std::system("pause");
	return 0;
}