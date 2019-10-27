#include "Date.h"
int Date::m_s_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int Date::getMonthDay(int y, size_t n) {
	return m_s_month[n - 1] + (n == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100)));
}
bool Date::LeapYear(int y)const {
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}
ostream& operator<<(ostream& os, Date& a) {
	os << a.m_year << "��" << a.m_month << "��" << a.m_day << "��";
	return os;
}
istream& operator>>(istream& os, Date& t) {
	printf("���������\n");
	while (1) {
		os >> t.m_year;
		if (t.m_year >= 0) {
			break;
		}
		cout << "��ݱ���Ǹ�,�������������\n";
	}
	cout << "�������·�\n";
	while (1) {
		os >> t.m_month;
		if (t.m_month < 1) {
			cout << "�·ݱ������0, ����������\n";
			continue;
		}
		if (t.m_month > 12) {
			cout << "�·ݱ���С�ڵ���12, ����������\n";
			continue;
		}
		break;
	}
	cout << "��������\n";
	while (1) {
		os >> t.m_day;
		if (t.m_day < 1) {
			cout << "���������0������\n";
			continue;
		}
		if (t.m_day > Date::getMonthDay(t.m_year, t.m_month)) {
			cout << "������ĺ������ڱ�������" << Date::getMonthDay(t.m_year, t.m_month) << "����������\n";
			continue;
		}
		break;
	}
	return os;
}
int Date::countLeapYear(int year)const {
	if (m_year == year) {
		return LeapYear(year);
	}
	int begin = m_year;
	int end = year - 1;
	if (m_year > year) {
		begin = year;
		end = m_year - 1;
	}
	while (!(LeapYear(begin))) {
		++begin;
	}
	while (!(LeapYear(end))) {
		--end;
	}
	int tmp = begin;
	int count = 0;
	if (begin <= end) {
		while (tmp <= end && tmp % 100) {
			++tmp;;
		}
		for (; tmp <= end; !LeapYear(tmp) ? ++count : count, tmp += 100);
		return (end - begin) / 4 + 1 - count;
	}
	return 0;
}
Date Date::operator+(size_t n)const {
	Date tmp = *this;
	size_t count = 0;
	for (int i = 1; i < (int)tmp.m_month; ++i) {
		count += getMonthDay(tmp.m_year, i);
	}
	count += tmp.m_day;
	if (n >= (365 + LeapYear(tmp.m_year) - count)) {
		n -= (365 + LeapYear(tmp.m_year) - count);
		tmp.m_month = 12;
		tmp.m_day = 31;
		while ((int)n >= (365 + LeapYear(tmp.m_year + 1))) {
			n -= (365 + LeapYear(++tmp.m_year));
		}
	}
	for (; n > 0; --n) {
		if (tmp.m_day == getMonthDay(tmp.m_year, tmp.m_month)) {
			tmp.m_day = 1;
			tmp.m_month == 12 ? tmp.m_month = 1, ++tmp.m_year : ++tmp.m_month;
		}
		else {
			++tmp.m_day;
		}
	}
	return tmp;
}
