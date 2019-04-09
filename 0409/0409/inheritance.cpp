#include <iostream>
using namespace std;

#define MAXSPEED 300

class Car {
	int speed = 100;
	string color; // �� Ŭ���� ���ǰ� ������ ���� �Ұ���
protected:
	int gear = 3; // ��ӵ� ������ �����ڱ����� ���� ����(�ܺο��� x)
public:
	string name;

	void status() {
		cout << "���� ���� : " << endl;
	}

	void view() {
		cout << speed << endl;
		cout << name.c_str() << endl;
		cout << gear << endl;
	}

	void SetSpeed(int num) {
		speed = speed + num < MAXSPEED ? speed + num : MAXSPEED;
	}
};

class Taxi : public Car {
	int meter = 13000;
public:
	Taxi() {
		name = "Taxi";
		gear = 2; //��ӵ� ������ �����ڱ����� ���� ����
		//color = "red" private������ �� Ŭ������ ���ǵ� ���������� ���� ����
		status();
	}
};

class KakaoTaxi : public Taxi {
public:
	KakaoTaxi() {
		Taxi();
		gear = 3;
	}
};

void main() {
	KakaoTaxi t1;

	//t1.name = "KaKao";
	t1.view();

	getchar();
}