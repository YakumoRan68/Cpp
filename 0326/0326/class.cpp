#include <iostream>
#include "Car.h"

void main() {
	Car c1("red", 100);  //stack 영역에 있는 Car클래스 생성
	c1.Boost();
	c1.ViewStatus();

	Car *c2 = new Car("blue", 200); //heap 영역에 있는 Car클래스에 생성
	c2->ViewStatus();
	delete c2; //~Car 소멸자 호출

	getchar();
}