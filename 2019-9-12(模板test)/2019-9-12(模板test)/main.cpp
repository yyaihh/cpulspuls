#include<iostream>
#include<string>
using namespace std;
template<class T>
T Add(T a, T b) {
	cout << a << "+" << b << "����ģ�庯��\n";
	return a + b;
}
int main() {
	cout << Add(1, 2) << endl
		<< Add('1', 2) << endl;
	system("pause");
	return 0;
}
//#include<iostream>
//#include<string>
//using namespace std;
//template<typename T>
//void Swap(T& a, T& b) {
//	cout << "����" << a << "��" << b << "����ģ�庯��\n";
//	T temp = a;
//	a = b;
//	b = temp;
//}
//void Swap(int& a, int& b) {
//	cout << "����" << a << "��" << b << "���÷�ģ�庯��\n";
//	int temp = a;
//	a = b;
//	b = temp;
//}
//int main() {
//	int a = 1;
//	int b = -1;
//	double c = 1.23;
//	double d = -1.23;
//	Swap(a, b);
//	Swap<int>(a, b);
//	Swap(c, d);
//	cout << a << endl
//		<< b << endl
//		<< c << endl
//		<< d << endl;
//	system("pause");
//	return 0;
//}