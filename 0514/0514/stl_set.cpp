#include <iostream>
#include <set> //����
using namespace std;

void main() { 
	set<int> s;
	set<int>::iterator it; //set�� �ݺ��ڰ� �ʼ���
	s.insert(1);
	s.insert(99);
	s.insert(99); //�ߺ� x
	s.insert(50);
	s.erase(50); //�ε����� �ʿ����
	
	it = s.find(99);
	cout << *it << endl;

	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << endl;
	}
}