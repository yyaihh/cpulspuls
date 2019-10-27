#include<iostream>
using namespace std;
class Test {
	size_t m_size;
	int* m_arr;
public:
	Test(size_t size = 0) {
		m_size = size;
		m_arr = (int*)malloc(sizeof(int)*size);
	}
	~Test() {
		if (m_arr) {
			free(m_arr);
		}
	}
	Test& operator=(const Test& t);
	void SetTest();
	void PrintTest()const;
};
Test& Test::operator=(const Test& t) {
	m_size = t.m_size;
	m_arr = (int*)malloc(sizeof(int)*m_size);
	for (int i = 0; i < (int)m_size; ++i) {
		m_arr[i] = t.m_arr[i];
	}
	return *this;
}
void Test::SetTest() {
	for (int i = 0; i < (int)m_size; ++i) {
		cout << "�������" << i + 1 << "��Ԫ�ص�ֵ\n";
		cin >> m_arr[i];
	}
}
void Test::PrintTest() const { 
	for (int i = 0; i < (int)m_size; ++i) {
		cout << m_arr[i] << "  ";
	}
	cout << endl;
}
void test() {
	Test a(3);
	Test b;
	cout << "������a��������\n";
	a.SetTest();
	cout << "��ӡ����a:\n";
	a.PrintTest();
	b = a;
	cout << "��ӡ����b:\n";
	b.PrintTest();
	cout << "������b��������\n";
	b.SetTest();
	cout << "��ӡ����b:\n";
	b.PrintTest();
	cout << "��ӡ����a:\n";
	a.PrintTest();
}
int main_() {
	test();
	system("pause");
	return 0;
}