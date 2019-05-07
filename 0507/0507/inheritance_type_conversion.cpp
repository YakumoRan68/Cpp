#include <iostream>
using namespace std;

class Car {
public :
	Car() {
		cout << "Car 생성자" << endl;
	}

	~Car() {
		cout << "Car 소멸자" << endl;
	}

	void view() {
		cout << "Car view" << endl;
	}
};

class Taxi : public Car {
public : 
	Taxi() {
		cout << "Taxi 생성자" << endl;
	}

	~Taxi() {
		cout << "Taxi 소멸자" << endl;
	}

	void view() {
		cout << "Taxi view"  << endl;
	}
};

void main() {
	Car *c1 = new Taxi(); //상향 형변환
	c1->view(); 
	((Taxi *)c1)->view(); // 하향 형변환
	delete c1;

	cout << endl;

	Taxi *t1 = new Taxi();
	t1->view();
	delete t1;

	cout << endl;


}