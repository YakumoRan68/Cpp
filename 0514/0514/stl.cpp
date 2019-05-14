#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main() {
	vector<int> scores(5); //�����޸𸮿� ���� �ʱ�ȭ

	for (int i = 0; i < 5; i++) {
		scores[i] = i + 1;
		cout << scores[i] << endl;
	}
	
	scores.push_back(20);

	cout << endl;

	std::for_each(scores.begin(), scores.end(), [](int &n) {cout << n << endl; n++; }); //���ٽ��� �̿��� ���

	cout << endl;

	scores.pop_back();
	for (int n : scores) {
		cout << n << endl;
	}	

	cout << endl;

	vector<int>::iterator i;
	for (i = scores.begin(); i < scores.end(); i++) {
		cout << *i << endl;
	}

}