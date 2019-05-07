#include <iostream>
using namespace std;

void main() {
	int pizza_slices = 0;
	int people = -1;
	int slices_per_person = 0;
	try {
		cout << "피자조각 수를 입력하시오: ";
		cin >> pizza_slices;
		cout << "사람수를 입력하시오: ";
		cin >> people;
		if (people == 0) throw "DVZ"; // 0으로 나누는 행위는 c++가 해결할 수 없는 범위의 오류이므로 예외를 발생하지 않음. 무조건 따라서 예외로 throw 해야 함.
		if (people == -1) throw "Negative";
		slices_per_person = pizza_slices / people;
		cout << "한사람당 피자는" << slices_per_person << "입니다." << endl;
	} catch(const char *e) {
		if (e == "DVZ") cout << "0으로 나눌 수 없습니다." << endl;
		if (e == "Negative") cout << "음수로 나눌 수 없습니다." << endl;
	} catch (const int e) { // 예외 인수의 데이터 타입이 맞으면(int형이면) 실행
		cout << "int형 예외 처리" << endl;
	} catch (const double e) {
		cout << "double형 예외 처리" << endl;
	} catch (const exception e) {
		cout << "기타 c++ exception 예외" << endl;
	} catch (...) { //c++의 모든 오류를 캐치(swtich case의 default처럼 블럭의 흐름을 확인해야함)
		cout << "예기치 않은 오류가 발생했습니다." << endl;
	}
}
