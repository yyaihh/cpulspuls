#include<iostream>
using namespace std;
class Person {
public:
	virtual void BuyTicket() {
		cout << "全票\n";
	}
};
class Student :public Person {
public:
	virtual void BuyTicket() {
		cout << "学生半价\n";
	}
};
class Soldier :public Person {
public:
	virtual void BuyTicket() {
		cout << "军人优先购票\n";
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