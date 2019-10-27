#include<iostream>
#include<string>
#include <typeinfo>
using namespace std;
void test() {
	//string��8�����캯��(���ع�ϵ)
	string s;//string()
	string s1("abcdef");//string(const char* s)
	string s2(4, 'a');	//string(size_t n, char c)
	string s3(s1);		//string(const string& s)
	string s4(s1, 3);	//string(const string& s, size_t n)
	string s5(s1, 1, 5);
	string s6("abcdefe", 3);
	string s7("scscssr", 2, 6);
	cout << typeid(s1.begin()).name() << endl;
	cout << typeid(*s1.begin()).name() << endl;
	string::iterator begin = s1.begin();
	string::iterator end = s1.end();

	string s8(begin, end);
	cout << "s: " << endl
	    << "s1:" << s1 << endl
		<< "s2:" << s2 << endl
		<< "s3:" << s3 << endl
		<< "s4:" << s4 << endl
		<< "s5:" << s5 << endl
		<< "s6:" << s6 << endl
		<< "s7:" << s7 << endl
		<< "s8:" << s8 << endl;
	for (int i = 0; begin + i < end; ++i) {
		cout << *(begin + i);
	}
	cout << endl;
	system("pause");
	system("cls");
}
void test1() {
	string s1("abcdef");//string(const char* s)
	string s2(4, 'a');	//string(size_t n, char c)
	string s3(s1);		//string(const string& s)
	cout << "sting�����������\n";
	cout << "s1��Ч������:" << s1.size() << endl;
	//size_t size() const �����ַ�����Ч�ַ�����
	cout << "s1��Ч������:" << s1.length() << endl;
	//size_t length() const �����ַ�����Ч�ַ�����
	cout << "s2��Ч������:" << s2.size() << endl;
	cout << "s2��Ч������:" << s2.length() << endl;
	cout << "s1��������:" << s1.capacity() << endl;
	//size_t capacity() const ���ؿռ��ܴ�С
	cout << "s2��������:" << s2.capacity() << endl;
	s1.reserve(20);
	//void reserve(size_t res_arg = 0) Ϊ�ַ���Ԥ���ռ�
	cout << "s1��Ч������:" << s1.size() << endl;
	cout << "s1��������:" << s1.capacity() << endl;
	s2.resize(25);
	//void resize(size_t n) ����Ч�ַ��ĸ����ĳ�n��������Ŀռ���0���
	cout << "s2��Ч������:" << s2.size() << endl;
	cout << "s2��������:" << s2.capacity() << endl;
	s2 += "�ַ�������";
	cout << "s2:" << s2 << endl;
	s3.resize(20, 'z');
	//void resize(size_t n, char c) ����Ч�ַ��ĸ����ó�n��������Ŀռ����ַ�c���
	cout << "s3��Ч������:" << s3.size() << endl;
	cout << "s3��������:" << s3.capacity() << endl;
	cout << "s3:" << s3 << endl;
	s1.empty() ? cout << "s1Ϊ��\n" : cout << "s1��Ϊ��!\n";
	//bool empty() const ����ַ����ͷ�Ϊ�մ����Ƿ���true�����򷵻�false
	cout << "���s2\n";
	s2.clear();
	s2.empty() ? cout << "s2Ϊ��\n" : cout << "s2��Ϊ��!\n";
	system("pause");
	system("cls");
}
void test2() {
	//string�����ķ��ʲ���
	string s1("abcdef");
	const string s2("xyz");
	cout << "s1:" << s1 << endl;
	for (size_t i = 0; i < s1.size(); ++i) {
		cout << s1[i] << " ";
		//char& operator[] ( size_t pos ) ����posλ�õ��ַ�����const string��������
	}
	cout << endl;
	cout << "s2:" << s2 << endl;
	for (size_t i = 0; i < s2.size(); ++i) {
		cout << s2[i] << " ";
		//char& operator[] ( size_t pos ) ����posλ�õ��ַ���const string��������
	}
	cout << endl;
	system("pause");
	system("cls");
}
void test3() {
	string s("abcdef");
	string s1("higk");
	string s2("qrst");
	cout << "s:" << s << endl;
	s.push_back('g');//void push_back(char c) ���ַ�����β���ַ�c
	cout << "s:" << s << endl;
	s.append(s1);//string& append (const char* s); ���ַ�����׷��һ���ַ���
	s.append("dsscs");
	s.append(8, 'a');
	cout << "s:" << s << endl;
	s += "lmnop";//string& operator+=(const char* s) ���ַ�����׷��һ���ַ���
	cout << "s:" << s << endl;
	s += s2;//string& operator+=(const string& str)���ַ�����׷��sting���ַ���str
	cout << "s:" << s << endl;
	s += 'u';//string& operator+=(char c) ���ַ�����׷���ַ�c
	cout << "s:" << s << endl;
	s.pop_back();//void pop_back() ɾ���ַ������һ���ַ�
	cout << "s:" << s << endl;
	const char* c_s = s1.c_str();//const char* c_str( )const ����C��ʽ�ַ���
	cout << "c_s:" << c_s << endl;
	char c = 'd';
	size_t pos = 0;
	size_t n = s.find(c, pos);//pos<s.size();����ᷢ������Խ��
	//size_t find (char c, size_t pos =0)const //pos��ȱʡ����, �������Ǵ�0��ʼ
	//���ַ���posλ�ÿ�ʼ�������ַ�c���ҵ��ַ������ַ����е��±�,�Ҳ�������-1, ��Ϊ����ֵ��size_t������4294967295
	n != (size_t)-1 ? cout << c << "���ַ���s���±�Ϊ" << n << "��λ��\n" :
		cout << c << "���ڴ��±�" << pos << "λ�ÿ�ʼ������ַ�����\n";

	n = s.find(s1/*ȱʡ����Ĭ��0*/);//pos<s.size();����ᷢ������Խ��
	//size_t find (string c, size_t pos =0)const //pos��ȱʡ����, �������Ǵ�0��ʼ
	//���ַ���posλ�ÿ�ʼ�������ִ�c���ҵ��ַ���c
	//����c�ڱ����ַ����е��±�,�Ҳ�������-1, ��Ϊ����ֵ��size_t������4294967295
	n != (size_t)-1 ? cout << s1 << "���ַ���s���±�Ϊ" << n << "��λ��\n" :
		cout << s1 << "���ڴ��±�" << pos << "λ�ÿ�ʼ������ַ�����\n";

	n = s.rfind(c_s, s.size() - 1);//pos<s.size();����ᷢ������Խ��
	//size_t find (char* c, size_t pos =0)const //pos��ȱʡ����, �������Ǵ�0��ʼ
	//���ַ���posλ�ÿ�ʼ�������ִ�c���ҵ��ַ���c
	//����c�ڱ����ַ����е��±�,�Ҳ�������-1, ��Ϊ����ֵ��size_t������4294967295
	n != (size_t)-1 ? cout << c_s << "���ַ���s���±�Ϊ" << n << "��λ��\n" :
		cout << c_s << "���ڴ��±�" << pos << "λ�ÿ�ʼ������ַ���s��\n";

	size_t npos = 10;
	n = s.rfind(c, npos);//npos<s.size();����ᷢ������Խ��
	//size_t rfind (char c, size_t pos =0)const//pos��ȱʡ����, Ĭ��Ϊ0
	//���ַ���posλ�ÿ�ʼ��ǰ���ַ�c
	//�ҵ��ַ������ַ����е��±�,�Ҳ�������-1, ��Ϊ����ֵ����size_t������4294967295
	n != (size_t)-1 ? cout << c << "���ַ���s���±�Ϊ" << n << "��λ��\n" :
		cout << c << "���ڴ��±�" << npos << "λ�ÿ�ʼ��ǰ���ַ�����\n";
	string s3 = s.substr(pos, npos);//npos<s.size(), pos>=0, npos-pos>=0;
	//posΪȱʡ����
	//string substr(size_t pos = 0, size_t n= npos)const
	//��str�д�posλ�ÿ�ʼ����ȡn���ַ���Ȼ���䷵��
	cout << "s3:" << s3 << endl;
	system("pause");
	system("cls");
}
void test4() {
	string s1;
	string s2;
	getline(cin, s1);
	getline(cin, s2, 'c');
	cout << s1 << endl;
	cout << s2 << endl;
	system("pause");
	system("cls");
}
int main() {
	test();
	test1();
	test2();
	test3();
	test4();
	return 0;
 }