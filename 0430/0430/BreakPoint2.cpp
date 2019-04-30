#include <iostream>
using namespace std;

int methodA(int a) {
	return a + 100;
}

int methodB() {
	return -200;
}

int methodC(int a, int b) {
	return a < 0 ? a * -1 : a * 1000;
}

void main() {
	int num1 = 7;
	int num2 = methodA(num1);
	int num3 = methodB(); //F9, F10, F11
	int num4 = methodC(num2, num3);
	int num5 = methodC(num3, num2);

	cout << "num4 :" << num3 << endl;
}