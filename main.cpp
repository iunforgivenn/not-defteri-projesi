#include <iostream>
#include <clocale>
#include "header.h"

int main() {

	setlocale(LC_CTYPE, "Turkish");

	notdefterimen� Notdefterimen�;
	Notdefterimen�.dosyadanOku();
	Notdefterimen�.anamen�();
	Notdefterimen�.dosyayaYaz();

}
