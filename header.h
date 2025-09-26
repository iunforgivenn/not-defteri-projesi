#pragma once

#include <vector>
#include <string>
using namespace std;

class notdefteriveri {

protected:

	vector<string> notlar;

};

class notdefterinotoluþtur : virtual notdefteriveri {

public:

	string Notbasligi = "";
	string Noticerigi = "";
	string nott;

	void notgoster();

	void notoluþtur();

};

class notdefterinotsil : virtual notdefteriveri {

public:

	void notsil();

};

class notdefterimenü : public notdefterinotoluþtur, public notdefterinotsil, virtual notdefteriveri {

public:

	void anamenü();
	void dosyayaYaz();
	void dosyadanOku();
};



	

