#include <iostream>
using namespace std;

class RemoteControl {
	// 순수가상함수정의
public:
	virtual void turnOn() = 0;	// 가전제품을켠다.
	virtual void turnOff() = 0;	// 가전제품을끈다.
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

	//RemoteControl *pr = new RemoteControl(); 에러, 추상클래스는 개체를 가질 수 없음
	RemoteControl *pr = new Television();
	pr->turnOn();
	pr->turnOff();

	delete pt;
	delete pr;

	getchar();
}
