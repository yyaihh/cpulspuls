#include<iostream>
using namespace std;
template<class T1,class T2>
class Test {
public:
	void func() {
		cout << "<T1, T2>" << endl;
	}
};
template<class T1>//ƫ�ػ�
class Test<T1,double> {
public:
	void func() {
		cout << "<T1, double>" << endl;
	}
};
int main3() {
	Test<int, char> a;
	Test<float, double> b;
	a.func();
	b.func();
	system("pause");
	return 0;
}