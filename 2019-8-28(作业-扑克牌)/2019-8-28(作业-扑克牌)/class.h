#pragma once
#include<iostream>
using namespace std;
enum {
	SPADES,//����
	HEARTS,//����
	CLUBS,//÷��
	DIAMONDS,//��Ƭ
	JOKER  //��С��
};
class ALL;
class  Player;
class Poker {
private:	
	int type;
	int point;
public:
	void input(int T, int P);
	void output();
	char Type() { return type; }
	int Point() { return point; }
};

class ALL {
private:
	Poker src[54];
	int size;
public:
	ALL() {
		size = 53;
	}
	void InitPoker();//��ʼ��һ����, ϴ��
	void allprint();
	Poker* fapai();//����
	void draw1(ALL& A, Player& p1, Player& p2, Player& p3);
};

class Player {
private:
	Poker a[18];
	int size;
public:
	Player() {
		size = 0;
	}
	void Draw1_(ALL& A);//�ֶ�����, һ��ȡһ������
	void Draw18(ALL& A);//�Զ�����,һ��18��
	void print();//
	bool cmppoker(Poker a, Poker b);
	void InsertSort();//����
};
