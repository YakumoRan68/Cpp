#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

#define MAXITEMS 5
const string ITEMNAME[MAXITEMS] = { "커피", "에너지드링크", "생수", "사이다", "콜라" };
const int PRICE[MAXITEMS] = { 800, 1000, 500, 1000, 1200 };
const int MONEY[4] = { 100, 500, 1000, 5000 };

class Machine {
private:
	int Money = 0;
	int Selected[MAXITEMS] = { 0, };
	string StatusMessage = "";

public:
	Machine() {
		Print();
	}

	~Machine() {
		return;
	}

	void GetInput() {
		cout << "값을 입력하세요(종료 : 0)" ;
		char input = _getch();

		if (input == '0') {
			this->~Machine();
		} else {
			Change(input);
			Print();
		}
	}

	void Change(int x) {
		if (x - '0' >= 1 && x - '0' <= MAXITEMS) {
			int i = x - '0' - 1;
			if (PRICE[i] <= Money) {
				Selected[i]++;
				Money -= PRICE[i];
				StatusMessage = ITEMNAME[i] + "가 추가되었습니다.";
			} else {
				StatusMessage = "잔액이 부족합니다.";
			}
		} else if (x >= 97 && x <= 100) {
			int amount = MONEY[x - 97];
			Money += amount;
			StatusMessage = to_string(amount) + " 만큼 추가되었습니다.";
		} else {
			StatusMessage = "잘못된 입력입니다.";
		}
	}

	void Print() {
		system("cls");
		for (int i = 0; i < MAXITEMS; i++) {
			cout << i + 1 << " : " << ITEMNAME[i] << " (" << PRICE[i] << "원)" << endl;
		}

		for (int i = 0; i < 4; i++) {
			printf("\n%c : %d원 넣기", 97 + i, MONEY[i]);
		}
		cout << "\n잔액 : " << Money << endl << endl;
		for (int i = 0; i < MAXITEMS; i++) {
			if (Selected[i]) cout << ITEMNAME[i] << " : " << Selected[i] << "개" << endl;
		}
		cout << endl << StatusMessage << endl;
		GetInput();
	}
};

int main() {
	Machine main;
}