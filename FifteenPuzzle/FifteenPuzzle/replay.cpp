#include "replay.h"
#include "Ranking.h"
#include <conio.h>

#define NUM_RP 5

static int nRP = NUM_RP;

void showRanking() {
	system("cls");
	printRanking();
	printf("���÷��̸� �� ������ �������ּ���(1~5) : ");
	getche();
}

void loadReplay(char* fname) {
	ifstream fin;
	fin.open(fname);
	if (!fin.good()) {
		cout << "���÷��� �����Ͱ� �����ϴ�.";
		return;
	}
	else {
		for (int i = 0; i < nRP; i++) {
			//fin >> MVP[i].nMove >> MVP[i].name >> MVP[i].tElapsed;
		}
		fin.close();
	}
}

