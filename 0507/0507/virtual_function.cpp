#include <iostream>
using namespace std;

class Car {
public:
	Car() {
		cout << "Car ������" << endl;
	}

	~Car() {
		cout << "Car �Ҹ���" << endl;
	}

	virtual void view() { //�ڽ��� ������� ��������ʰ� �ڽ����� ������
		cout << "Car view virtual" << endl;
	}
};

class Taxi : public Car {
public:
	Taxi() {
		cout << "Taxi ������" << endl;
	}

	~Taxi() {
		cout << "Taxi �Ҹ���" << endl;
	}

	void view() {
		cout << "Taxi view" << endl;
	}
};

void main() {
	Car *c1 = new Taxi();
	c1->view(); //�ڽ��� ������� ��������ʰ� �ڽ����� ������
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