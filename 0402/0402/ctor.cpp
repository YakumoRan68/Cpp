#include <iostream>
using namespace std;

class Car{
	//const string & alias; &�ڷ����� ���·� �Ȱ� �ݵ�� �ʱ�ȭ �ؾ���. ��ü ����(������)�� null�� �ƴϿ���(��ȿ�ؾ�) �Ѵ�.
	int *speed;

public:
	//Car(string &s) : alias(s) {	}
	Car(int *s) {
		speed = s;
	}

	void view() {
		cout << speed << endl;
	}

	void swap() {
		*speed = 300;
		cout << &speed << endl;
	}
};

int main() {
	int arg = 10;
	Car c1(&arg);
	c1.view();

	getchar();
}