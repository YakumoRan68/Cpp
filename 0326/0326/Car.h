#pragma once
#include <iostream>
using namespace std;

class Car {
private: // 정보은닉을 위해 기본적으로 접근을 못함.(함수로 가능하게 해야 함)
	const int SpeedLimit = 300;
	string color;
	int speed;

	void SetSpeed(int x) {
		speed = x > SpeedLimit ? SpeedLimit : x;
	}

public: // 기본은 private

	Car() {
		color = "";
	} //인수가 아무것도 없는 생성자(공생성자)는 지워져있어도 존재함. 단, 다른 생성자가 있을경우 공생성자는 없어짐.

	~Car() {
		cout << "끝" << endl;
	}

	Car(int _speed) {
		color = "";
		speed = _speed;
	}

	Car(char* _color, int speed) {
		color = _color;
		this->speed = speed;
		//self.speed = speed
	}

	void ViewStatus(); // 함수 외부정의
	void Boost();
};

void Car::ViewStatus() { // 함수 외부정의
	cout << "색깔 : " << color.c_str() << endl;
	cout << "속도 : " << speed << endl;
}

void Car::Boost() {
	speed = speed > SpeedLimit ? SpeedLimit : speed + 10;
}