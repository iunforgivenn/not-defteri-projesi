#include <iostream>
#include <clocale>
#include "header.h"

int main() {

	setlocale(LC_CTYPE, "Turkish");

	notdefterimenü Notdefterimenü;
	Notdefterimenü.dosyadanOku();
	Notdefterimenü.anamenü();
	Notdefterimenü.dosyayaYaz();

}
