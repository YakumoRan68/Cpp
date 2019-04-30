#include <iostream>
using namespace std;

void main() {
	int num[100] = { 0 , };
	int *pnum = new int[100];

	for (int i = 0; i < 100; i++) {
		num[i] = i + 5; //조사식에 num + 5, 10, i, num[4] 등
		pnum[i] = i + 10; //pnum도 배열형식이므로 값을 볼 수 있음.
		cout << "num[i] = " << num[i] << endl;
	}
}