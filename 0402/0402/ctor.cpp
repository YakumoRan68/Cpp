#include <iostream>
using namespace std;

class Car{
	//const string & alias; &자료형의 형태로 된건 반드시 초기화 해야함. 객체 참조(포인터)는 null이 아니여야(유효해야) 한다.
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