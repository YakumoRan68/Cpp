#include <iostream>
using namespace std;

class A {
public:
	void view() {
		cout << "A view" << endl;
	}
};

class B {
public:
	void view() {
		cout << "B view" << endl;
	}
};

class AB : public A, public B {
public:
	void view() {
		cout << "AB view" << endl;
	}
};

void main() {
	AB a;
	a.A::view();
	a.B::view();
	a.view();

	getchar();
}