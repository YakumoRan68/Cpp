#include <iostream>
using namespace std;

class Car {
public :
	Car() {
		cout << "Car ������" << endl;
	}

	~Car() {
		cout << "Car �Ҹ���" << endl;
	}

	void view() {
		cout << "Car view" << endl;
	}
};

class Taxi : public Car {
public : 
	Taxi() {
		cout << "Taxi ������" << endl;
	}

	~Taxi() {
		cout << "Taxi �Ҹ���" << endl;
	}

	void view() {
		cout << "Taxi view"  << endl;
	}
};

void main() {
	Car *c1 = new Taxi(); //���� ����ȯ
	c1->view(); 
	((Taxi *)c1)->view(); // ���� ����ȯ
	delete c1;

	cout << endl;

	Taxi *t1 = new Taxi();
	t1->view();
	delete t1;

	cout << endl;


}