#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define N 10
struct student {
	char name[32];
	int age;
	int Class;
	bool sex;
};
void Print(student* src, int size) {
	cout << "����" << "\t" << "����" << "\t" << "�༶" << "\t" << "�Ա�" << endl;
	for (int i = 0; i < size;++i) {
		cout << src[i].name << "\t" << src[i].age << "\t" << src[i].Class << "\t" << src[i].sex << endl;
	}
}
int count(student* src, int size, const char* name) {
	int count = 0;
	for (int i = 0; i < N; ++i) {
		strcmp(name,src[i].name) ? count : ++count;
	}
	return count;
}
int count(student* src, int size, bool n) {
	int count = 0;
	for (int i = 0; i < N; ++i) {
		n == src[i].sex ? ++count : count;
	}
	return count;
}
int count(student* src, int size, int n, int flag = 0) { 
	int count = 0;
	if (flag == 0) {
		for (int i = 0; i < N; ++i) {
			n == src[i].age ? ++count : count;
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			n == src[i].Class ? ++count : count;
		}
	}
	return count;
}
int main() {
	student src[N];
	char name[32];
	int Class;
	int Age;
	bool Sex;
	for (auto& i : src) {
		cout << "������ѧ������Ϣ\n����������\n";
		scanf("%s", i.name);
		cout << "����������\n";
		cin >> i.age;
		cout << "������༶\n";
		cin >> i.Class;
		cout << "�������Ա�,��������1,Ů������0\n";
		cin >> i.sex;
		system("cls");
	}
	system("cls");
	Print(src, N);
	cout << "����������Ҫͳ�Ƶ�����\n";
	scanf("%s", name);
	cout << "����������Ҫͳ�Ƶ�����\n";
	cin >> Age;
	cout << "����������Ҫͳ�Ƶİ༶\n";
	cin >> Class;
	cout << "����������Ҫͳ�Ƶ��Ա�, ����1,Ů��0\n";
	cin >> Sex;
	cout << "������������" <<count(src, N, name)<< "��" <<endl;
	cout << Class << "���ѧ����" << count(src, N, Class, 100) << "��" << endl;
	cout << Age << "�����ѧ����" << count(src, N, Age) << "��" << endl;
	Sex ? cout << "��" : cout << "Ů";
	cout << "�Ե���ѧ����" << count(src, N, Sex) << "��" << endl;
	system("pause");
	return 0;
}