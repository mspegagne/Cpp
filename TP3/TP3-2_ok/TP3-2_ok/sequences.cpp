#include "sequences.h"

using namespace std;

ostream & operator<<(ostream & os, const seqmac & s) {
	s.writeseq(os);
	return os;
}

seqmac::seqmac(const string & seq, const string & name, const string & alphabet) : _alph(alphabet), _name(name) {
	string s = "";
	for (string::const_iterator c = seq.begin(); c != seq.end(); c++) {
		if (_alph.is_in_alpha(*c)) {
			s += *c;
		}
		else {
			throw std::invalid_argument("La lettre n'appartient pas a l'alphabet autorise");
		}
	}
	_seq = s;
}

seqadn::seqadn(const string & seq, const string & name) : seqmac(seq, name, "CGAT") {
	if (_seq.size() % 3 != 0) {
		throw std::invalid_argument("La sequence doit avoir une taille multiple de 3");
	}

	bool start = false;
	bool stop = false;
	for (int i = 0; i < _seq.size(); i += 3) {
		string sub = _seq.substr(i, 3);
		if (!start) {
			start = (sub == "ATG");
		}

		if (sub == "TAA" || sub == "TAG" || sub == "TGA") {
			if (!start) {
				throw std::invalid_argument("Le codon START doit etre avant le codon STOP");
			}
			else {
				stop = true;
			}
		}
	}

	if (!start) {
		throw std::invalid_argument("Le codon START est manquant");
	}
	if (!stop) {
		throw std::invalid_argument("Le codon STOP est manquant");
	}
}

seqarn::seqarn(const string & seq, const string & name) : seqmac(seq, name, "ACGU") {
	if (_seq.size() % 3 != 0) {
		throw std::invalid_argument("La sequence doit avoir une taille multiple de 3");
	}

	bool start = false;
	bool stop = false;
	for (int i = 0; i<_seq.size(); i += 3) {
		string sub = _seq.substr(i, 3);
		if (!start) {
			start = sub == "AUG";
		}

		if (sub == "UAA" || sub == "UAG" || sub == "UGA") {
			if (!start) {
				throw std::invalid_argument("Le codon START doit etre avant le codon STOP");
			}
			else {
				stop = true;
			}
		}
	}

	if (!start) {
		throw std::invalid_argument("Le codon START est manquant");
	}
	if (!stop) {
		throw std::invalid_argument("Le codon STOP est manquant");
	}
}