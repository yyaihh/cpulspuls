#include<iostream>
using namespace std;
//��һ������ͨ��ָ�����ư�λ����ֱ�Ӹ���ԭ����
void sysReverse(int &num, int n) {
	int tmp = 0;
	while (num) { 
		tmp += num % n;
		tmp *= n;
		num /= n;
	}
	num = tmp;
}
void Print_2(int num) {
	if (num != 1) {
		Print_2(num / 2);
	}
	printf("%d", num % 2);
}
int main() {
	int num1, num2, num3, num4;
	num1 = num2 = num3 = num4 = 25;
	printf("2�������%dΪ:", num1);
	Print_2(num1);
	sysReverse(num1, 2);
	printf("\n2������%d��λ����Ϊ:", num1);
	Print_2(num1);
	cout << "\n\n";

	printf("8���������%dΪ:%o\n", num2, num2);
	sysReverse(num2, 8);
	printf("8�����°�λ����Ϊ:%o\n\n", num2);

	printf("10���������%dΪ:%d\n", num3, num3);
	sysReverse(num3, 10);
	printf("10�����°�λ����Ϊ:%d\n\n", num3);

	printf("16���������%dΪ:%X\n", num4, num4);
	sysReverse(num4, 16);
	printf("16�����°�λ����Ϊ:%X\n\n", num4);
	system("pause");
	return 0;
}