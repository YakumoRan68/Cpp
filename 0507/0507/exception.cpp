#include <iostream>
using namespace std;

void main() {
	int pizza_slices = 0;
	int people = -1;
	int slices_per_person = 0;
	try {
		cout << "�������� ���� �Է��Ͻÿ�: ";
		cin >> pizza_slices;
		cout << "������� �Է��Ͻÿ�: ";
		cin >> people;
		if (people == 0) throw "DVZ"; // 0���� ������ ������ c++�� �ذ��� �� ���� ������ �����̹Ƿ� ���ܸ� �߻����� ����. ������ ���� ���ܷ� throw �ؾ� ��.
		if (people == -1) throw "Negative";
		slices_per_person = pizza_slices / people;
		cout << "�ѻ���� ���ڴ�" << slices_per_person << "�Դϴ�." << endl;
	} catch(const char *e) {
		if (e == "DVZ") cout << "0���� ���� �� �����ϴ�." << endl;
		if (e == "Negative") cout << "������ ���� �� �����ϴ�." << endl;
	} catch (const int e) { // ���� �μ��� ������ Ÿ���� ������(int���̸�) ����
		cout << "int�� ���� ó��" << endl;
	} catch (const double e) {
		cout << "double�� ���� ó��" << endl;
	} catch (const exception e) {
		cout << "��Ÿ c++ exception ����" << endl;
	} catch (...) { //c++�� ��� ������ ĳġ(swtich case�� defaultó�� ���� �帧�� Ȯ���ؾ���)
		cout << "����ġ ���� ������ �߻��߽��ϴ�." << endl;
	}
}
