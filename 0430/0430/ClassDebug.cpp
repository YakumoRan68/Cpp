#include <iostream>
using namespace std;

class Car{
	int speed, gear = 3;
protected :
	int x = 10;
public:
	Car() {
		cout << "������ ����" << endl;
		speed = 100;
	}

	void View() {
		cout << "speed = " << speed << endl << "gear = " << gear << endl;
	}
};

void main() {
	Car c; //F10���� �ߴ��� ���� ����� ���� ����
	c.View();
}