#include <iostream>
using namespace std;

class RemoteControl {
	// ���������Լ�����
public:
	virtual void turnOn() = 0;	// ������ǰ���Ҵ�.
	virtual void turnOff() = 0;	// ������ǰ������.
};

class Television : public RemoteControl {
public:
	void turnOn()
	{
		cout << "TV On" << endl;
	}
	void turnOff()
	{
		cout << "TV Off" << endl;
	}
};

void main() {
	Television *pt = new Television();
	pt->turnOn();
	pt->turnOff();

	//RemoteControl *pr = new RemoteControl(); ����, �߻�Ŭ������ ��ü�� ���� �� ����
	RemoteControl *pr = new Television();
	pr->turnOn();
	pr->turnOff();

	delete pt;
	delete pr;

	getchar();
}
