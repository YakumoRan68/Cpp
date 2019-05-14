#include <iostream>
#include <list>
using namespace std;

void main() {
	list<int> L(5);
	list<int>::iterator it;
	
	for (it = L.begin(); it != L.end(); it++) {
		cout << *it << endl;
	}
}