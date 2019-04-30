#include <iostream>
using namespace std;

void main() {
	int num[100] = { 0 , };
	int *pnum = new int[100];

	for (int i = 0; i < 100; i++) {
		num[i] = i + 5; 
		pnum[i] = i + 10; //중단점 조건을 정할 수 있음(i가 50 보다 클 경우, num[5]가 변경된 경우)
		cout << "num[" << i << "] = " << num[i] << endl;
	}
}