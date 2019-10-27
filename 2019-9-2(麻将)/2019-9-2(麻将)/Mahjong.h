#pragma once
#include<iostream>
using namespace std;
class Mahjong {
	int m_type;
	int m_point;
public:
	Mahjong();
	Mahjong(int a, int b);
	~Mahjong();
};
class PackCards {
	Mahjong m_src[136];
	int m_size;
public:
	PackCards() {
		m_size = 53;
	}
	void InitPoker();//��ʼ��һ����, ϴ��
	void allprint();
	Mahjong* fapai();//����
	void draw1(PackCards& A, Player& p1, Player& p2, Player& p3);
};
class Player {
private:
	Mahjong m_a[13];
	int m_size;
public:
	Player() {
		m_size = 0;
	}
	void Draw1_(PackCards& A);//�ֶ�����, һ��ȡһ������
	void Draw18(PackCards& A);//�Զ�����,һ��18��
	void print();//
	bool cmppoker(Mahjong a, Mahjong b);
	void InsertSort();//����
};

