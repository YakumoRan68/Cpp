#include <iostream>
using namespace std;

void sub() {
	cout << "���� �Լ�" << endl;
}

void sub(int num) {
	cout << "���� �Լ�" << endl;
}

void sub(double num) {
	cout << "�Ǽ� �Լ�" << endl;
}

void sub(int x, double y) {
	cout << "���� : " << x << ", �Ǽ� : " << y << endl;
}

void main() {
	sub();
	sub(10);
	sub(10.4);
	sub(10, 10.4);

	getchar();
}