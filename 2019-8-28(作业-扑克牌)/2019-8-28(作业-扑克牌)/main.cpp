#include"class.h"

int main() {
	ALL a;
	cout << "ϴ�ƺ�������\n";
	a.InitPoker();
	a.allprint();//���ϴ�����
	Player p[3];
#if 0
	//һ��һ��˳���ȡ
	a.draw1(a, p[0], p[1], p[2]);
	
#else
	//����������������18����
	for (int i = 0; i < 3; ++i) {
		p[i].Draw18(a);
	}
#endif
	for (int i = 0; i < 3; ++i) {
		cout << "���" << i + 1 << "��ȡ����\n";
		p[i].print();
	}
	for (int i = 0; i < 3; ++i) {
		p[i].InsertSort();//����
	}
	for (int i = 0; i < 3; ++i) {
		cout << "���ƺ����" << i + 1 << "��ȡ����\n";
		p[i].print();
	}
	system("pause");
}