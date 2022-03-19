#include "header.h"
#include "bibliotekos.h"


void generavimas_skaiciai() {
	std::ofstream fr("studentai.txt");
	std::stringstream buffer;

	mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	int_distribution dist(1, 10);
	int n, k;
	cout << "Kiek bus studentu: "; cin >> n;
	cout << "Po kiek jie tures pazymiu: "; cin >> k;
	buffer << setw(11) << left << "Vardas" << setw(11) << "Pavarde";
	for (int i = 0; i < k; i++) {
		string s = std::to_string(i+1);
		buffer << "ND" << setw(6) << s;
	}
	buffer << "Egz.\n";

	for (int i = 0; i < n; i++) {
		string s = std::to_string(i + 1);
		buffer << "Var" << setw(8) << s << "Pav" << setw(8) <<s;
		for (int j = 0; j < k; j++) {
			buffer << setw(8) << dist(mt);
		}
		buffer << dist(mt) << "\n";
	}

	fr << buffer.str();
	fr.close();
}

