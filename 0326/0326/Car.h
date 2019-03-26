#pragma once
#include <iostream>
#define VNAME(x) #x
using namespace std;

class Car {
private: // ���������� ���� �⺻������ ������ ����.(�Լ��� �����ϰ� �ؾ� ��)
	const int SpeedLimit = 300;
	string color;
	int speed;

	void SetSpeed(int x) {
		speed = x > SpeedLimit ? SpeedLimit : x;
	}

public: // �⺻�� private

	Car();//�μ��� �ƹ��͵� ���� ������(��������)�� �������־ ������. ��, �ٸ� �����ڰ� ������� �������ڴ� ������.
	~Car();

	Car(int _speed) : speed(_speed) {
		speed = 200;
		color = "OVERRIDEN";
	}

	Car(int _speed, int limit);
	Car(char* _color = "Normal", int speed = 150);

	void ViewStatus(); // �Լ� �ܺ�����
	void Boost();
	void Boost(int num);
};

Car::Car() {}

Car::~Car() {
	cout << "�Ҹ��� ȣ��" << endl;
}

Car::Car(char* _color, int speed) {
	color = _color;
	this->speed = speed;
}

Car::Car(int _speed, int limit) : SpeedLimit(limit) {
	speed = _speed;
}

void Car::ViewStatus() {
	cout << "���� : " << color.c_str() << endl;
	cout << "�ӵ� : " << speed << endl;
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