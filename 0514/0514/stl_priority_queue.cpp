#include <iostream>
#include <queue> 
#include <string>
using namespace std;

void main() {
	priority_queue<string> q;
	q.push("what");
	q.push("is");
	q.push("life");

	//q.back(), q.front()는 없음

	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop(); //문자열 우선순위순서대로 빠짐
	}
}