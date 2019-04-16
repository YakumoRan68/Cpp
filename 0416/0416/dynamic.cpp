#include <iostream>
using namespace std;

void main() {
	int* num = NULL;
	int* a = new int;
	a = num;

	cout << *a << endl;

	a = NULL;

	delete a;
	getchar();
}