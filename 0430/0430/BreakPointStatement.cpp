#include <iostream>
using namespace std;

void main() {
	int num[100] = { 0 , };
	int *pnum = new int[100];

	for (int i = 0; i < 100; i++) {
		num[i] = i + 5; 
		pnum[i] = i + 10; //�ߴ��� ������ ���� �� ����(i�� 50 ���� Ŭ ���, num[5]�� ����� ���)
		cout << "num[" << i << "] = " << num[i] << endl;
	}
}