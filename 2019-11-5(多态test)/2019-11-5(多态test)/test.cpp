#include<iostream>
using namespace std;
class Person {
public:
	virtual void BuyTicket() {
		cout << "ȫƱ\n";
	}
};
class Student :public Person {
public:
	virtual void BuyTicket() {
		cout << "ѧ�����\n";
	}
};
class Soldier :public Person {
public:
	virtual void BuyTicket() {
		cout << "�������ȹ�Ʊ\n";
	}
};
void Buy(Person& people) {
	people.BuyTicket();
}
int main_() {
	Person p;
	Student st;
	Soldier so;
	Buy(p);
	Buy(st);
	Buy(so);
	system("pause");
	return 0;
}