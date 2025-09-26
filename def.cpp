#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "header.h"

using namespace std;



void notdefterinotolu�tur::notolu�tur() {
	cout << "Ba�l�k:";
	cin.ignore();
	getline(cin, Notbasligi);
	cout << "��erik:";
	getline(cin, Noticerigi);
	cout << "Notunuz:";
	getline(cin, nott);
	notlar.push_back(" Ba�l�k: " + Notbasligi + " \n " + "  Konu: " + Noticerigi + "\n\n- " + nott);
	cout << "Notunuz Ba�ar�yla Eklenmi�tir! \n";
};

void notdefterinotolu�tur::notgoster() {

	if (notlar.empty()) {

		cout << "Herhangi bir not bulunmamaktad�r.\n";
		return;
	}

	cout << "\nNotlar�n�z\n\n";
	for (int i = 0; i < notlar.size(); i++) {
		cout << "-- Not " << i + 1 << " --\n" << notlar[i] << endl << endl;

	}
};


void notdefterinotsil::notsil() {
	if (notlar.empty()) {

		cout << "Herhangi bir not bulunmamaktad�r.\n";
		return;
	}


	cout << "Notlar�n�z: \n ";
	for (int i = 0; i < notlar.size(); i++) {

		cout << "-- " << i + 1 << ". Not --\n " << notlar[i] << endl << endl;

	}


	int index;
	cout << "Silmek �stedi�iniz notu se�iniz\n";
	cin >> index;


	if (index < 1 || index > static_cast<int>(notlar.size())) {

		cout << "Silmek istedi�iniz notunuz, var olan notunuzla uyu�mamaktad�r.\n";
	}
	else {

		notlar.erase(notlar.begin() + (index - 1));
		cout << "Notunuz ba�ar�yla silinmi�tir.\n";

	}
};

void notdefterimen�::anamen�() {
	cout << " Not defterine ho� geldiniz"
		<< endl <<
		" Ne yapaca��n�z� Numara belirterek se�iniz"
		<< endl
		;

	int se�enek;

	while (true)
	{
		cout << " 1- Not olu�tur"
			<< endl <<
			" 2- Notlar�m� g�r"
			<< endl <<
			" 3- Notlar�m� Sil"
			<< endl <<
			" 4- Not defterinden ��k"
			<< endl << ":"
			;
		cin >> se�enek;

		if (se�enek == 1) {

			notolu�tur();
			continue;

		}
		else if (se�enek == 2) {

			notgoster();
			continue;
		}
		else if (se�enek == 3) {

			notsil();
			continue;
		}
		else if (se�enek == 4) {
			cout << "Not defterinden ��k�l�yor...";
			break;
		};

	}
};

void notdefterimen�::dosyadanOku() {
	ifstream dosya("nnotlar.txt");
	if (dosya.is_open()) {

		string satir, nott;
		while (getline(dosya, satir)) {
			if (satir == "---") {
				if (!nott.empty()) {
					notlar.push_back(nott);
					nott.clear();
				}
			}
			else {

				nott += satir + "\n";

			}
		};
		if (!notlar.empty()) {

			notlar.push_back(nott);

		}

		dosya.close();
	}
};

void notdefterimen�::dosyayaYaz() {
	ofstream dosya("nnotlar.txt");
	if (dosya.is_open()) {
		for (const string& nott : notlar) {
			dosya << nott << "\n---\n";
		};

		dosya.close();

	}
	else {
		cout << "\nDosyan�z bir hatadan dolay� a��lamad� ve kaydedilmedi!\n";

	}
};


	