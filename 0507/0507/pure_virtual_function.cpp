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

	virtual void view() = 0;//�߻�Ŭ������ ����.
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
	c1->view(); //�������ε�(��Ÿ�ӿ� ���� ��ġ�� ������)
	((Taxi *)c1)->view(); //���� ���ε�(�����ϵ� �� ���� ��ġ�� ������)
	delete c1;

	cout << endl;

	Taxi *t1 = new Taxi();
	t1->view();
	delete t1;

	cout << endl;
}