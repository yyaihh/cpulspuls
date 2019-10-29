#include<iostream>
using namespace std;
int g_num1 = 1;
static int s_g_num2 = 2;
class T {
	int m_a;
public:
	T() {
		cout << "调用构造函数\n";
	}
	~T() {
		cout << "调用析构函数\n";
	}
};
void test() {
	T* p1 = new T;
	T* p2 = (T*)operator new(sizeof(T));
	delete p1;
	operator delete(p2);

}
int main() {
	static int num3 = 3;
	int num4 = 4;
	int arr[] = { 1,2,3,4 };
	char str1[] = "abcde";
	const char* pstr = "abcde";
	int* ptr1 = (int*)malloc(num4 * sizeof(int));
	int* ptr2 = (int*)calloc(num4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr1, num4 * sizeof(int));
	int* ptr4 = new int(10);
	int* ptr5 = new int[*ptr4];
	delete ptr4;
	delete[] ptr5;
	//free(ptr1);//不需要
	free(ptr2);
	free(ptr3);
	test();
	system("pause");
	return 0;
}