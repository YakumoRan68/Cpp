#include <iostream>
#include <map> 
#include <string>
using namespace std;

void main() {
	map<string, string> dic;
	dic["boy"] = "�ҳ�";
	dic["school"] = "�б�";
	dic["home"] = "��";

	cout << dic["home"] << endl;
	cout << dic["none"] << endl;//�ʿ� �ε��� �ϴ� �����ε� ���� ������
	cout << dic["HOME"] << endl;//Ű�� ��ҹ��ڸ� ������

	for (auto it = dic.begin(); it != dic.end(); it++) {
		cout << "key : " << it->first << "\n" << "value : " << it->second << '\n' << endl;
	}
}