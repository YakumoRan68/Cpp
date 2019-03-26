#include <iostream>
using namespace std;

void sub() {
	cout << "서브 함수" << endl;
}

void sub(int num) {
	cout << "정수 함수" << endl;
}

void sub(double num) {
	cout << "실수 함수" << endl;
}

void sub(int x, double y) {
	cout << "정수 : " << x << ", 실수 : " << y << endl;
}

void main() {
	sub();
	sub(10);
	sub(10.4);
	sub(10, 10.4);

	getchar();
}