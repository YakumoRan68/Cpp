#include <iostream>
using namespace std;

void main() {
	int num[100] = { 0 , };
	int *pnum = new int[100];

	for (int i = 0; i < 100; i++) {
		num[i] = i + 5; //����Ŀ� num + 5, 10, i, num[4] ��
		pnum[i] = i + 10; //pnum�� �迭�����̹Ƿ� ���� �� �� ����.
		cout << "num[i] = " << num[i] << endl;
	}
}