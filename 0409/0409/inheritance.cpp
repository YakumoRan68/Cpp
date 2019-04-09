#include <iostream>
using namespace std;

#define MAXSPEED 300

class Car {
	int speed = 100;
	string color; // 이 클래스 정의가 끝나면 접근 불가능
protected:
	int gear = 3; // 상속된 범위의 생성자까지만 접근 가능(외부에선 x)
public:
	string name;

	void status() {
		cout << "현재 상태 : " << endl;
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
		gear = 2; //상속된 범위의 생성자까지만 접근 가능
		//color = "red" private변수는 그 클래스의 정의된 범위까지만 접근 가능
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