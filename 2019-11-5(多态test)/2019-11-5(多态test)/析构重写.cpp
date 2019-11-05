#include<iostream>
using namespace std;
class A {
public:
	virtual ~A() {
		cout << "~A()" << endl;
	}
};
class B :public A {
public:
	virtual ~B() {
		cout << "~B()" << endl;
	}
};

int main() {
	B* pb = new B;
	A* pa = pb;
	delete pa;
	system("pause");
	return 0;
}