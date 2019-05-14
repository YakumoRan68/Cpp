#include <iostream>
#include <set> //집합
using namespace std;

void main() { 
	set<int> s;
	set<int>::iterator it; //set은 반복자가 필수임
	s.insert(1);
	s.insert(99);
	s.insert(99); //중복 x
	s.insert(50);
	s.erase(50); //인덱스가 필요없음
	
	it = s.find(99);
	cout << *it << endl;

	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
}