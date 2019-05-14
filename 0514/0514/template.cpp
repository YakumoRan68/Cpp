#include <iostream>
using namespace std;

class Car {
public:
	template<typename T>
	void c(T x) {
		cout << x << endl;
	}
};

//template<typename X> 이경우 타입 종류가 2개이상일 수 없음. (X a, X b) 일 경우에 a와 b 의 타입은 같아야함.
template<typename T, typename U> 
T calc(T x, U y) {
	x = x + y;
	cout << x << endl;
	return x; //타입이 함수에 들어올때 결정됨.
}

void calc(int x, int y) {
	int sum = x + y;
	cout << sum << endl;
}

void main() {
	float num = 50.0, num2 = 50.3;
	int intnum = 50;

	calc(num, intnum);

	Car a;
	a.c(10);
}