#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "header.h"

using namespace std;



void notdefterinotoluþtur::notoluþtur() {
	cout << "Baþlýk:";
	cin.ignore();
	getline(cin, Notbasligi);
	cout << "Ýçerik:";
	getline(cin, Noticerigi);
	cout << "Notunuz:";
	getline(cin, nott);
	notlar.push_back(" Baþlýk: " + Notbasligi + " \n " + "  Konu: " + Noticerigi + "\n\n- " + nott);
	cout << "Notunuz Baþarýyla Eklenmiþtir! \n";
};

void notdefterinotoluþtur::notgoster() {

	if (notlar.empty()) {

		cout << "Herhangi bir not bulunmamaktadýr.\n";
		return;
	}

	cout << "\nNotlarýnýz\n\n";
	for (int i = 0; i < notlar.size(); i++) {
		cout << "-- Not " << i + 1 << " --\n" << notlar[i] << endl << endl;

	}
};


void notdefterinotsil::notsil() {
	if (notlar.empty()) {

		cout << "Herhangi bir not bulunmamaktadýr.\n";
		return;
	}


	cout << "Notlarýnýz: \n ";
	for (int i = 0; i < notlar.size(); i++) {

		cout << "-- " << i + 1 << ". Not --\n " << notlar[i] << endl << endl;

	}


	int index;
	cout << "Silmek Ýstediðiniz notu seçiniz\n";
	cin >> index;


	if (index < 1 || index > static_cast<int>(notlar.size())) {

		cout << "Silmek istediðiniz notunuz, var olan notunuzla uyuþmamaktadýr.\n";
	}
	else {

		notlar.erase(notlar.begin() + (index - 1));
		cout << "Notunuz baþarýyla silinmiþtir.\n";

	}
};

void notdefterimenü::anamenü() {
	cout << " Not defterine hoþ geldiniz"
		<< endl <<
		" Ne yapacaðýnýzý Numara belirterek seçiniz"
		<< endl
		;

	int seçenek;

	while (true)
	{
		cout << " 1- Not oluþtur"
			<< endl <<
			" 2- Notlarýmý gör"
			<< endl <<
			" 3- Notlarýmý Sil"
			<< endl <<
			" 4- Not defterinden çýk"
			<< endl << ":"
			;
		cin >> seçenek;

		if (seçenek == 1) {

			notoluþtur();
			continue;

		}
		else if (seçenek == 2) {

			notgoster();
			continue;
		}
		else if (seçenek == 3) {

			notsil();
			continue;
		}
		else if (seçenek == 4) {
			cout << "Not defterinden çýkýlýyor...";
			break;
		};

	}
};

void notdefterimenü::dosyadanOku() {
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

void notdefterimenü::dosyayaYaz() {
	ofstream dosya("nnotlar.txt");
	if (dosya.is_open()) {
		for (const string& nott : notlar) {
			dosya << nott << "\n---\n";
		};

		dosya.close();

	}
	else {
		cout << "\nDosyanýz bir hatadan dolayý açýlamadý ve kaydedilmedi!\n";

	}
};


	