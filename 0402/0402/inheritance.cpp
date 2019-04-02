#include <iostream>
using namespace std;

#define MAXSPEED 300

class Car {
	int speed = 100;
	string color; // �� Ŭ���� ���ǰ� ������ ���� �Ұ���
protected:
	int gear = 3; // ��ӵ� ���������� ���� ����(�ܺο��� x)
public:
	string name;

	void status() {
		cout << "���� ���� : " << endl;
	}

	void view() {
		cout << speed << endl;
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
		//color = "red" private������ �� Ŭ������ ���ǵ� ���������� ���� ����
		status();
	}
};

class KakaoTaxi : public Taxi {
	  
};

void main() {
	KakaoTaxi t1;

	t1.name = "KaKao";
	t1.view();

	getchar();
}