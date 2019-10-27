#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//��һ���ַ���ת��Ϊ���֣�����ֵ����У��ת���Ƿ�ɹ�
bool strtoi(const char* str, int &num) {
	if (!str) {
		return false;
	}
	int flag = 1;//������ǩ
	if (*str == '-') {
		flag = -1;
		++str;
	}
	if (*str > '9' || *str < '0') {
		return false;
	}
	long long tmp = 0;
	double max = pow(2, 31) - 1;
	double min = -pow(2, 31);
	for (; *str <= '9' && *str >= '0'&& *str; ++str) { 
		tmp = (int)*str - 48 + tmp * 10;
	}
	tmp = flag * tmp;
	if (tmp < min) {
		return false;
	}
	if (tmp > max) {
		return false;
	}
	num = (int)tmp;
	return true;
}
int main() {
	int num = 0;
	char str[20];
	cout << "������һ���ַ���\n";
	scanf("%s", &str);
	if (strtoi(str, num)) {
		cout << "ת���ɹ�\nת��������Ϊ:" << num << endl;
	}
	else {
		cout << "ת��ʧ��!\n";
	}
	system("pause");
	return 0;
}