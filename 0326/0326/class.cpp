#include <iostream>
#include "Car.h"

void main() {
	Car c1(100);  //stack ������ �ִ� CarŬ���� ����
	c1.Boost();
	c1.ViewStatus();

	Empty();
	Car *c2 = new Car("blue", 200); //heap ������ �ִ� CarŬ������ ����
	c2->ViewStatus();
	delete c2; //~Car �Ҹ��� ȣ��

	Empty();
	Car c3(100, 150);
	c3.Boost(100);
	c3.ViewStatus();

	getchar();
}