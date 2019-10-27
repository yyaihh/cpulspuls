#include"fun.h"
void InsertSort(int* src, int size) { //ֱ�Ӳ�������
	int tmp, j;
	for (int i = 1; i < size; ++i) {
		tmp = src[i];
		for (j = i; j > 0 && src[j - 1] > tmp; --j) {
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}
void ShellSort(int* src, int size) {
	int gap, j;
	int tmp;
	gap = size / 3;//n/3������
	for (int k = 0; gap; ++k) {
		if (k >= gap) {
			gap /= 2;
			k = -1;
			continue;
		}
		for (int i = gap + k; i < size; i += gap) {
			tmp = src[i];
			for (j = i; j >= gap && src[j - gap] > tmp; j -= gap) {
				src[j] = src[j - gap];
			}
			src[j] = tmp;
		}
	}
}
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int* src, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (src[j] > src[j + 1]) {
				Swap(src + j, src + j + 1);
			}
		}
	}
}
void SelectionSort(int* src, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (src[i] > src[j]) {
				Swap(src + i, src + j);
			}
		}
	}
}
void PrintArray(node* src, int size) {
	for (int i = 0; i < size; ++i) {
		cout << src[i].a << src[i].b << src[i].c << src[i].d << endl;
	}
}
int cmp(const node &first, const node &second) { //������Ҫ�������� 
	if (first.a == second.a) {
		return first.b > second.b;
	}
	else {
		first.a > second.a;
	}
}

void mysort(node* src, int size, int n) {
	if (n == 0) {
		cout << "ð��\n";
		BubbleSort(src, size);
	}
	else if (n == 1) {
		cout << "����\n";
		InsertSort(src, size);
	}
	else if (n == 2) {
		cout << "ѡ��\n";
		SelectionSort(src, size);
	}
	else {
		cout << "ϣ��\n";
		ShellSort(src, size);
	}
}
