#include <iostream>
#include <queue> 
#include <string>
using namespace std;

void main() {
	priority_queue<string> q;
	q.push("what");
	q.push("is");
	q.push("life");

	//q.back(), q.front()�� ����

	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop(); //���ڿ� �켱����������� ����
	}
}