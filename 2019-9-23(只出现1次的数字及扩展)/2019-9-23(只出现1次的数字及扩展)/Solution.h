#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Solution {
	void swapArga(int* a, int* b) {
		int tmp;
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
	int HoareWay(int* src, int start, int end) {
		int a = start + 1;
		int b = end - 2;
		int mid = (start + end) / 2;
		if (src[start] > src[mid]) {
			swapArga(src + start, src + mid);
		}
		if (src[mid] > src[end]) {
			swapArga(src + mid, src + end);
		}
		if (src[start] > src[mid]) {
			swapArga(src + start, src + mid);
		}
		if (end - start <= 2) {
			return mid;
		}
		swapArga(src + mid, src + end - 1);
		while (a <= b) {
			while (a < end - 1 && src[a] <= src[end - 1]) {
				++a;
			}
			while (b > 1 && src[b] >= src[end - 1]) {
				--b;
			}
			if (a == b && (a == 1 || a == end - 1)) {
				break;
			}
			if (a < b) {
				swapArga(src + a, src + b);
			}
		}
		swapArga(src + a, src + end - 1);
		return a;
	}
	void dealQuickSort(int* src, int start, int end) {
		int mid;
		if (start < end) {
			mid = HoareWay(src, start, end);
			dealQuickSort(src, start, mid - 1);
			dealQuickSort(src, mid + 1, end);
		}
	}
	void QuickSort(int* src, int size) {
		dealQuickSort(src, 0, size - 1);
	}
public:
	//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
	int singleNumber_1(const vector<int>& v);
	//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
	int singleNumber_2(const vector<int>& v);
	//����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
	vector<int> singleNumber_3(const vector<int>& v);

};