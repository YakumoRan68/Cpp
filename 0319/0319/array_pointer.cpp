#include <iostream>

using namespace std;

void print(int *p) {
	cout << *(p + 1) << endl;
	cout << p[3] << endl;
	cout << p << endl;
	cout << p + 1 << endl;
}

void main() {
	int num[5] = { 1, 2, 3, 4, 5 }, *p;
	p = num;
	print(num);
}