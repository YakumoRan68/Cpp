#include <iostream>
using namespace std;

class Car{
	int speed, gear = 3;
protected :
	int x = 10;
public:
	Car() {
		cout << "생성자 시작" << endl;
		speed = 100;
	}

	void View() {
		cout << "speed = " << speed << endl << "gear = " << gear << endl;
	}
};

void main() {
	Car c; //F10으로 중단점 없이 디버깅 시작 가능
	c.View();
}