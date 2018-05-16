#include "Ranking.h"

#define NUM_MVP 5

static PlayInfo MVP[NUM_MVP];
static int nMVP = NUM_MVP;

static void initRanking() {
	PlayInfo noname = { "C++���ƿ�", 1000, 1000.0 };
	for (int i = 0; i < nMVP; i++) {
		MVP[i] = noname;
	}
}

void loadRanking(char* fname) {
	//	FILE* fp = fopen(fname, "r");		C���
	ifstream fin;
	fin.open(fname);
	//	if (fp == NULL) {			C���
	if (fin.good() == false) {
		initRanking();
	}
	else {
		for (int i = 0; i < nMVP; i++) {
			//			fscanf(fp, "%d%s%lf", &MVP[i].nMove,			C���
			//				MVP[i].name, &MVP[i].tElapsed);			C���
			fin >> MVP[i].nMove >> MVP[i].name >> MVP[i].tElapsed;
		}
		//		fclose(fp);			C���
		fin.close();
	}
}

void storeRanking(char* fname) {
	//	FILE* fp = fopen(fname, "w");
	ofstream fout;
	fout.open(fname);
	//	if (fp == NULL) return;
	if (fout.good() == false) return;
	for (int i = 0; i < nMVP; i++) {
		//		fprintf(fp, " %4d %-16s &-5.1f\n", MVP[i].nMove,
		//			MVP[i].name, MVP[i].tElapsed);
		fout << "  " << left << setw(4) << MVP[i].nMove << "  " << setw(16) << MVP[i].name << setw(5) << MVP[i].tElapsed << endl;
		//	left = �·� ����
	}
	//	fclose(fp);
	fout.close();
}

void printRanking() {
	for (int i = 0; i < nMVP; i++) {
		printf("[%2d��] %4d %-16s %5.1f\n", i + 1, MVP[i].nMove,
			MVP[i].name, MVP[i].tElapsed);
	}
}

int addRanking(int nMove, double tElap) {
	if (nMove < MVP[nMVP - 1].nMove) {
		int pos = nMVP - 1;
		for (; pos > 0; pos--) {
			if (nMove >= MVP[pos - 1].nMove) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;
		MVP[pos].tElapsed = tElap;
		printf("%d���Դϴ�. �̸��� �Է��ϼ���: ", pos + 1);
		scanf("%s", MVP[pos].name);

		return pos + 1;
	}

	return 0;
}