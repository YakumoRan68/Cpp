#include <iostream>
using namespace std;

void main() {
	int *pi; //���� �޸𸮸� ����Ű�� ������(stack ����)
	pi = new int[100]; // ���� �޸� �Ҵ�(heap ����)

	for (int i = 0; i < 100; i++) {
		*(pi + i) = i; // ���� �޸� ���
		cout << (pi + i) << " : " << *(pi + i) << endl; //cout�� �ڱⰡ ���ϴ� ���·� �����.
		printf("%d\n", (pi + i));
	}
	
	delete[] pi; //���� �޸� �ݳ�
}