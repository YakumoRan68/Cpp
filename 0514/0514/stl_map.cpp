#include <iostream>
#include <map> 
#include <string>
using namespace std;

void main() {
	map<string, string> dic;
	dic["boy"] = "소년";
	dic["school"] = "학교";
	dic["home"] = "집";

	cout << dic["home"] << endl;
	cout << dic["none"] << endl;//맵에 인덱싱 하는 것으로도 값이 생성됨
	cout << dic["HOME"] << endl;//키는 대소문자를 구분함

	for (auto it = dic.begin(); it != dic.end(); it++) {
		cout << "key : " << it->first << "\n" << "value : " << it->second << '\n' << endl;
	}
}