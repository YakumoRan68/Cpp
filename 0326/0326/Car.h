#pragma once
#include <iostream>
#define VNAME(x) #x
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

	Car();//인수가 아무것도 없는 생성자(공생성자)는 지워져있어도 존재함. 단, 다른 생성자가 있을경우 공생성자는 없어짐.
	~Car();

	Car(int _speed) : speed(_speed) {
		speed = 200;
		color = "OVERRIDEN";
	}

	Car(int _speed, int limit);
	Car(char* _color = "Normal", int speed = 150);

	void ViewStatus(); // 함수 외부정의
	void Boost();
	void Boost(int num);
};

Car::Car() {}

Car::~Car() {
	cout << "소멸자 호출" << endl;
}

Car::Car(char* _color, int speed) {
	color = _color;
	this->speed = speed;
}

Car::Car(int _speed, int limit) : SpeedLimit(limit) {
	speed = _speed;
}

void Car::ViewStatus() {
	cout << "색깔 : " << color.c_str() << endl;
	cout << "속도 : " << speed << endl;
}

void Car::Boost() {
	speed = speed + 10 > SpeedLimit ? SpeedLimit : speed + 10;
}

void Car::Boost(int num) {
	speed = speed + num > SpeedLimit ? SpeedLimit : speed + num;
}

void Empty() {
	cout << endl;
}