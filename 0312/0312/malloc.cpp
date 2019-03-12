#include <iostream>
using namespace std;

void main() {
	int *pi; //동적 메모리를 가리키는 포인터(stack 영역)
	pi = new int[100]; // 동적 메모리 할당(heap 영역)

	for (int i = 0; i < 100; i++) {
		*(pi + i) = i; // 동적 메모리 사용
		cout << (pi + i) << " : " << *(pi + i) << endl; //cout은 자기가 원하는 형태로 출력함.
		printf("%d\n", (pi + i));
	}
	
	delete[] pi; //동적 메모리 반납
}