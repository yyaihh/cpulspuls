#include<iostream>
#include<stdlib.h>
#include<cmath>
using namespace std;
double sroot(int n) {
	return sqrt(n);
}
double sroot(long n) {
	return sqrt(n);
}
double sroot(double n) {
	return sqrt(n);
}
int main() {
	int a = 10;
	long b = 10000;
	double c = 13.14;
	cout << a << "�Ķ��η���Ϊ" << sroot(a) << endl;//��ʱ���õ��ǲ���Ϊint�͵�sroot
	cout << b << "�Ķ��η���Ϊ" << sroot(b) << endl;//��ʱ���õ��ǲ���Ϊlong�͵�sroot
	cout << c << "�Ķ��η���Ϊ" << sroot(c) << endl;//��ʱ���õ��ǲ���Ϊdouble�͵�sroot	
	system("pause");
	return 0;
}