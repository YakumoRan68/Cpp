#include <iostream>
#include "Car.h"

void main() {
	Car c1("red", 100);  //stack ������ �ִ� CarŬ���� ����
	c1.Boost();
	c1.ViewStatus();

	Car *c2 = new Car("blue", 200); //heap ������ �ִ� CarŬ������ ����
	c2->ViewStatus();
	delete c2; //~Car �Ҹ��� ȣ��

	getchar();
}