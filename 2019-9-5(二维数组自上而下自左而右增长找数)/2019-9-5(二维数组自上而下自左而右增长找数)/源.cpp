#include<iostream>
using namespace std;
#define N 4
#define M 4
int main() {
	int a[N][M] = {
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	int num;
	int i = 0;
	int j = M - 1;
	cout << "��������Ҫ���ҵ���\n";
	cin >> num;
	while (i < N && j >= 0) {
		for (; j >= 0 && a[i][j] > num; --j);
		for (; i < N && a[i][j] < num; ++i);
		if (num == a[i][j]) {
			break;
		}
	}
	if (i < N && j >= 0 && a[i][j]==num) {
		cout << "�ҵ���!������" << i << "  " << j << endl;
	}
	else {
		cout << "û�ҵ�!\n";
	}
	system("pause");
	return 0;
}