#pragma once
#include<iostream>
using namespace std;
typedef struct node {
	int a;
	int b;
	int c;
	int d;
}node;
int cmp(const node &first, const node &second);
void mysort(node* src, int size, int n = 0);
void InsertSort(int* src, int size);//����
void BubbleSort(int* src, int size);//ð��
void SelectionSort(int* src, int size);//ѡ��
void ShellSort(int* src, int size);//ϣ��
void PrintArray(int* src, int size);//��ӡ
