#include <iostream>
#include <stack> 
#include <string>
using namespace std;

void main() {
	stack<string> st; //오로지 push와 pop으로만 데이터에 접근할 수 있고, 반복자가 없음.
					  //벡터와 다르게 컨테이너의 접근을 못하게 하는 것이 존재의의임.
	st.push("what");
	st.push("is");
	st.push("life");

	while (!st.empty()) {
		cout << st.top() << endl;
		st.pop();
	}
}