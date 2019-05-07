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

	virtual void view() = 0;//추상클래스로 만듬.
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
	c1->view(); //동적바인딩(런타임에 실행 위치가 결정됨)
	((Taxi *)c1)->view(); //정적 바인딩(컴파일될 때 실행 위치가 결정됨)
	delete c1;

	cout << endl;

	Taxi *t1 = new Taxi();
	t1->view();
	delete t1;

	cout << endl;
}