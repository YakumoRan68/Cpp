#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main() {
	vector<int> scores(5); //동적메모리에 벡터 초기화

	for (int i = 0; i < 5; i++) {
		scores[i] = i + 1;
		cout << scores[i] << endl;
	}
	
	scores.push_back(20);

	cout << endl;

	std::for_each(scores.begin(), scores.end(), [](int &n) {cout << n << endl; n++; }); //람다식을 이용한 출력

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