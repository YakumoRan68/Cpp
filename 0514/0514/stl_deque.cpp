#include <iostream>
#include <deque>
using namespace std;

void main() {
	deque<int> dq;
	dq.push_back(90);
	dq.push_back(50);
	dq.push_front(10);
	dq.push_front(30);
	dq.push_back(50);

	dq.insert(dq.begin(), 100);
	for (int x : dq) {
		cout << x << endl;
	}
}