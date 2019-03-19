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

	Car(int _speed) {
		color = "";
		speed = _speed;
	}

	Car(char* _color, int speed) {
		color = _color;
		this->speed = speed;
	  //self.speed = speed
	}

	void ViewStatus() {
		cout << "���� : " << color.c_str() << endl;
		cout << "�ӵ� : " << speed << endl;
	}
	
	void Boost() {
		speed = speed > SpeedLimit ? SpeedLimit : speed + 10;
	}
	//void speed ��� �̸��� �Ȱ��� �� �� ����.
};

void main() {
	Car c1("red", 100);  //stack ������ �ִ� CarŬ���� ����
	Car *c2 = new Car("blue", 200); //heap ������ �ִ� CarŬ������ ����

	c1.Boost();
	c1.ViewStatus();

	c2->ViewStatus();
	delete c2;
}