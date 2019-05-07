#include <iostream>
using namespace std;

class Car {
public:
	Car() {
		cout << "Car 생성자" << endl;
	}

	~Car() {
		cout << "Car 소멸자" << endl;
	}

	virtual void view() { //자식이 있을경우 실행되지않고 자식으로 내려감
		cout << "Car view virtual" << endl;
	}
};

class Taxi : public Car {
public:
	Taxi() {
		cout << "Taxi 생성자" << endl;
	}

	~Taxi() {
		cout << "Taxi 소멸자" << endl;
	}

	void view() {
		cout << "Taxi view" << endl;
	}
};

void main() {
	Car *c1 = new Taxi();
	c1->view(); //자식이 있을경우 실행되지않고 자식으로 내려감
	((Taxi *)c1)->view();
	delete c1;

	cout << endl;

	Car *c2 = new Car();
	c1->view();

	cout << endl;

	Taxi *t1 = new Taxi();
	t1->view();
	delete t1;

	cout << endl;


}