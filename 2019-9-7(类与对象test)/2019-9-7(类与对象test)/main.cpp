//#include"Person.h"
#include<iostream>
using namespace std;
class Date {
	int m_year;
	size_t m_month;
	size_t m_day;
public:
	Date() {

	}
	Date* operator& () {
		cout << "Date* operator& ()������\n";
		return this;
	}
	const Date* operator& () const {
		cout << "const Date* operator& () const ������\n";
		return this;
	}
};

int main() {
	Date a;
	&a;
	const Date b;
	&b;
	system("pause");
	return 0;
}
////Date(Date& d) {
////	m_year = d.m_year;
////	m_month = d.m_month;
////	m_day = d.m_day;
////}
// ȫ�ֵ�operator==
//#include<iostream>
//using namespace std;
//class Date {
//	int m_year;
//	int m_month;
//	int m_day;
//public:
//	Date(int year = 2019, int month = 10, int day = 1) {
//		cout << "����Date()\n";
//		m_year = year;
//		m_month = month;
//		m_day = day;
//	}
//	Date(const Date& d) {
//		cout << "���ÿ���Date()\n";
//		m_year = d.m_year;
//		m_month = d.m_month;
//		m_day = d.m_day;
//	}
//	Date& operator=(const Date& d) {
//		cout << "����operator=()\n";
//		if (this != &d) {
//			m_year = d.m_year;
//			m_month = d.m_month;
//			m_day = d.m_day;
//		}
//		return *this;
//	}
//};
//void Test(){
//	Date d1(2019, 9, 27);
//	Date d2 = d1;
//	Date d3;
//	d3 = d1;
//}
//int main() {
//	Test();
//	system("pause");
//	return 0;
//}