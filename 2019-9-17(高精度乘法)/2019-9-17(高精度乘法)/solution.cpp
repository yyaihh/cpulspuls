#include "solution.h"

string solution::multiply(const string& num1, const string& num2) {
	string stmp, res;
	char n = 0;
	int left1 = 0;
	int left2 = 0;
	int right1 = num1.size() - 1;
	int right2 = num2.size() - 1;
	stmp.resize(num1.size() + 2 + num2.size(), '0');
	if (right1 >= 0 && right2 >= 0) {
		num1[0] == '-' ? left1 = 1, stmp[0] = '-' : left1;
		num2[0] == '-' ? left2 = 1, stmp[0] = '-' : left2;
		(num1[0] == '-') && (num2[0] == '-') ? stmp[0] = '0' : left1;
		num1[0] == '+' ? left1 = 1 : left1;
		num2[0] == '+' ? left2 = 1 : left2;
	}
	else {
		stmp.clear();
		stmp = "0";
		return stmp;
	}
	int t;
	for (int j = (int)stmp.size() - 1; right2 >= left2; --right2, --j) {
		for (int i = right1, tmp = j; i >= left1; --i, --tmp) {
			n = (num1[i] - '0')*(num2[right2] - '0');//��˽��
			t = stmp[tmp] + n % 10 - '0';//��ӽ��
			stmp[tmp] = t % 10 + '0';//��λ
			stmp[tmp - 1] += (t / 10 + n / 10);//��λ

		}
	}
	if (stmp[0] == '-') {
		res.push_back('-');
	}
	int i = 1, j = stmp.size();
	for (; (i < j) && (stmp[i] == '0'); ++i);
	if (i >= j) {
		res = "0";
		return res;
	}
	for (; i < j; ++i) {
		res.push_back(stmp[i]);
	}
	return res;
}
void solution::delinput(string& s) {
	char ch = 0;;
	while (ch != '\n') {
		ch = getchar();
		if (ch > '9' || ch < '0') {
			continue;
		}
		s.push_back(ch);

	}
	if (s.size() == 0) {
		cout << "û��������Ч��ֵ, Ĭ��Ϊ0\n";
		s.push_back('0');
		return;
	}
	if ((s[0] == '-' || s[0] == '+') && s.size() == 1) {//�൱��û������
		cout << "û��������Ч��ֵ, Ĭ��Ϊ0\n";
		s[0] = '0';
	}
}
void solution::input(string& s) {
	char ch;
	ch = getchar();
	if (ch == '-' || ch == '+' || ch <= '9' && ch >= '0') {
		s.push_back(ch);
	}
	else if (ch == '\n') {
		s.push_back('0');
		cout << "��������ֵĬ��Ϊ0\n";
		return;
	}
	delinput(s);
}
