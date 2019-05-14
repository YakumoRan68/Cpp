#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void main() {
	vector<int> scores(5); //동적메모리에 벡터 초기화
	vector<int>::iterator i; //반복자(name.begin() 같은 반복자 전용 포인터 값만 연산가능)

	for (int i = 0; i < 5; i++) {
		scores[i] = i + 1;
		cout << scores[i] << endl;
	}
	
	scores.push_back(20);

	cout << endl;

	std::for_each(scores.begin(), scores.end(), [](int &n) {cout << n << endl; n++; }); //람다식을 이용한 출력 (algorithm.h 필요)

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
	name.insert(name.begin() + 1, "Y"); //name.begin외에 상수는 넣을 수 없음
	name.erase(name.begin() + 1);
	
	for (auto n : name) {
		cout << n.c_str() << endl;
	}
}