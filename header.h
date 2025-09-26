#pragma once

#include <vector>
#include <string>
using namespace std;

class notdefteriveri {

protected:

	vector<string> notlar;

};

class notdefterinotolu�tur : virtual notdefteriveri {

public:

	string Notbasligi = "";
	string Noticerigi = "";
	string nott;

	void notgoster();

	void notolu�tur();

};

class notdefterinotsil : virtual notdefteriveri {

public:

	void notsil();

};

class notdefterimen� : public notdefterinotolu�tur, public notdefterinotsil, virtual notdefteriveri {

public:

	void anamen�();
	void dosyayaYaz();
	void dosyadanOku();
};



	

