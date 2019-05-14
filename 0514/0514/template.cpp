#include <iostream>
using namespace std;

class Car {
public:
	template<typename T>
	void c(T x) {
		cout << x << endl;
	}
};

//template<typename X> �̰�� Ÿ�� ������ 2���̻��� �� ����. (X a, X b) �� ��쿡 a�� b �� Ÿ���� ���ƾ���.
template<typename T, typename U> 
T calc(T x, U y) {
	x = x + y;
	cout << x << endl;
	return x; //Ÿ���� �Լ��� ���ö� ������.
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