#include <iostream>
using namespace std;

class Car {
public:
	int a = 300;
	Car() {
		cout << a << endl;
	}
	void view() {
		cout << "Car view" << endl;
	}
};

class Taxi : public Car {
public:
	int a = 100;
	Taxi() {
		cout << a << endl;
	}
	void view() {
		cout << "Taxi view" << endl;
	}
};

void main() {
	Taxi t1;
	
	t1.view();	
	t1.Car::view();
	getchar();
}