#include"Orders.h"

int main() {
	int n;
	cout << "�������Ʒ������\n";
	cin >> n;
	Orders::input(n);//����ԭ��, �������ԭ�����µ���
	Orders a;
	double m = a.count(n);
	cout << "�����۸�Ϊ:" << m << endl;
	//����ԭ��, ��Ʒ��, ����
	cout << "�����������Ʒ������\n";
	cin >> n;
	Orders::input(n);
	m = a.count(n);
	cout << "�����۸�Ϊ:" << m << endl;

	Orders::Free();
	system("pause");
	return 0;
}