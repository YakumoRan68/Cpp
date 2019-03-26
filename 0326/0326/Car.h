#pragma once
#include <iostream>
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

	Car() {
		color = "";
	} //�μ��� �ƹ��͵� ���� ������(��������)�� �������־ ������. ��, �ٸ� �����ڰ� ������� �������ڴ� ������.

	~Car() {
		cout << "��" << endl;
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

	void ViewStatus(); // �Լ� �ܺ�����
	void Boost();
};

void Car::ViewStatus() { // �Լ� �ܺ�����
	cout << "���� : " << color.c_str() << endl;
	cout << "�ӵ� : " << speed << endl;
}

void Car::Boost() {
	speed = speed > SpeedLimit ? SpeedLimit : speed + 10;
}