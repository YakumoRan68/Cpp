#include <iostream>
#include <queue> 
#include <string>
using namespace std;

void main() {
	queue<string> q; 
	q.push("what");
	q.push("is");
	q.push("life");

	cout << q.back() << endl << endl;

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}