#include <iostream>
using namespace std;

class Car {
public :
	Car() {
		cout << "Car Ctor" << endl;
	}
	~Car() {
		cout << "Car Dtor" << endl;
	}

	Car(int x) {
		cout << "Car parameter : " << x << endl;
	}
};

class Taxi : public Car {
public :
	Taxi() {
		cout << "Taxi Ctor" << endl;
	}
	~Taxi() {
		cout << "Taxi Dtor" << endl;
	}

	Taxi(int a, int b) : Car(a) {
		cout << "Taxi parameter : " << a << ", " << b << endl;
	}
};

class KakaoTaxi : public Taxi {
public :
	KakaoTaxi() {
		cout << "Kakao Ctor" << endl;
	}
	~KakaoTaxi() {
		cout << "Kakao Dtor" << endl;
	}

	KakaoTaxi(int a, int b, int c) : Taxi(a, b) {
		cout << "Kakao parameter : " << a << ", " << b << ", " << c << endl;
	}
};

int main() {
	KakaoTaxi *t1 = new KakaoTaxi(1, 2, 3); 
	//생성자의 parameter들이 어떤 순서로 만들어지 확인(스택)
	delete t1;
	getchar();
}