//#include<iostream>
//using namespace std;
//class Person {
//public:
//	virtual void BuyTicket() {
//		cout << "ȫƱ\n";
//	}
//};
//class Student :public Person {
//public:
//	virtual void BuyTicket() {
//		cout << "ѧ�����\n";
//	}
//};
//class Soldier :public Person {
//public:
//	virtual void BuyTicket() {
//		cout << "�������ȹ�Ʊ\n";
//	}
//};
//void Buy(Person& people) {
//	people.BuyTicket();
//}
//void Buy1(Person people) {
//	people.BuyTicket();
//}
//void Buy2(Person* people) {
//	people->BuyTicket();
//}
//int main() {
//	Person p;
//	Student st;
//	Soldier so;  
//	Buy(p);
//	Buy(st);
//	Buy(so);
//	Buy1(p);
//	Buy1(st);
//	Buy1(so);
//	Buy2(&p);
//	Buy2(&st);
//	Buy2(&so);
//	cout << sizeof(long) << endl;
//	system("pause");
//	return 0;
//}