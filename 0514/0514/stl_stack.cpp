#include <iostream>
#include <stack> 
#include <string>
using namespace std;

void main() {
	stack<string> st; //������ push�� pop���θ� �����Ϳ� ������ �� �ְ�, �ݺ��ڰ� ����.
					  //���Ϳ� �ٸ��� �����̳��� ������ ���ϰ� �ϴ� ���� ����������.
	st.push("what");
	st.push("is");
	st.push("life");

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
}