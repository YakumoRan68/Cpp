#include <iostream>
using namespace std;

#define MAXCHANNEL 99

class TV {
protected:
	int ch = 9;
	int vol = 10;
	int input = 3;
	string power = "OFF";
	string seh = "KBS2";

public:
	void TogglePower(){
		power = power == "ON" ? "OFF" : "ON";
	}

	void chUp() {
		ch = ch >= MAXCHANNEL ? 0 : ++ch;
	}

	void chDown() {
		ch = ch <= 0 ? MAXCHANNEL : ++ch;
	}

	void SetChnnel(int x) {
		ch = x;
	}

	void Search(string ch) {
		seh = ch;
	}

	void Status() {
		cout << "power = " << power.c_str() << endl;
		cout << "ch = " << ch << endl;
		cout << "vol = " << vol << endl;
		cout << "input = " << input << endl;
		cout << "seh = " << seh.c_str() << endl;
	}
};

class RemoteController : public TV {
	string LED;
public :
	void onLED() {
		LED = power;
	}
};

void main() {
	TV TV;

	TV.TogglePower();
	TV.Status();

	getchar();
}