#pragma once
#include<iostream>
using namespace std;
class Date{
	int m_year;
	int m_month;
	int m_day;
	static int m_s_months[12];
public:
	Date(int y = 2019, int m = 10, int d = 1) :
		m_year(y),
		m_month(m),
		m_day(d) 
	{
	}
	Date& operator=(const Date& t);
	friend ostream& operator<<(ostream& os, const Date& t);
	friend istream& operator>>(istream& os, Date& t);
	bool operator<(const Date& t)const;
	bool operator>(const Date& t)const;
	bool operator==(const Date& t)const;
	bool operator!=(const Date& t)const;
	bool operator<=(const Date& t)const;
	bool operator>=(const Date& t)const;
	Date& operator+=(size_t n);//���㵱ǰ����+n�������ֵ, �ٽ����ֵ���Լ�
	Date operator+(size_t n)const;//n��֮�������
	Date operator-(size_t n)const;//n��֮ǰ������
	Date& operator-=(size_t n);//���㵱ǰ����-n�������ֵ, �ٽ����ֵ���Լ�
	int operator-(const Date& t)const;//��������֮����
	Date& operator++();
	Date& operator--();
	Date operator++(int);
	Date operator--(int);

	static int getMonthDay(int y, size_t n);//����y��n�µ�����
	bool LeapYear(int year)const;
	int countLeapYear(int year)const;
};