#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main() {
	vector<int> scores(5); //�����޸𸮿� ���� �ʱ�ȭ
	vector<int>::iterator i; //�ݺ���(name.begin() ���� �ݺ��� ���� ������ ���� ���갡��)

	for (int i = 0; i < 5; i++) {
		scores[i] = i + 1;
		cout << scores[i] << endl;
	}
	
	scores.push_back(20);

	cout << endl;

	std::for_each(scores.begin(), scores.end(), [](int &n) {cout << n << endl; n++; }); //���ٽ��� �̿��� ��� (algorithm.h �ʿ�)

	cout << endl;

	scores.pop_back();
	for (int n : scores) {
		cout << n << endl;
	}	

	cout << endl;

	for (i = scores.begin(); i < scores.end(); i++) {
		cout << *i << endl;
	}

	cout << endl;

	vector<string> name(0);
	name.push_back("X");
	name.insert(name.begin() + 1, "Y"); //name.begin�ܿ� ����� ���� �� ����
	name.erase(name.begin() + 1);
	
	for (auto n : name) {
		cout << n.c_str() << endl;
	}
}