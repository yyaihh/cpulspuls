#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define N 50 //���ִ���
class num {
private:
	double x1 = -10;
	double x2 = 10;
public:
	double fun();
};
int main() {
	num A;
	if (A.fun() != 0) {
		printf("����2x^3 - 4x^2 + 3x - 6 = 0�������ڵĸ�Ϊ:%f\n",A.fun());
	}
	else {
		printf("����2x^3 - 4x^2 + 3x - 6 = 0���������޸�\n");
	}
	system("pause");
	return 0;
}
double num::fun() {
	int count = 0;
	double f1, f2, fm, mid;
	while (1) {
		f1 = 2 * pow(x1, 3) - 4 * pow(x1, 2) + 3 * x1 - 6;
		f2 = 2 * pow(x2, 3) - 4 * pow(x2, 2) + 3 * x2 - 6;
		if (f1 * f2 > 0) {
			return 0;
		}
		++count;
		mid = (x1 + x2) / 2;
		fm = 2 * pow(mid, 3) - 4 * pow(mid, 2) + 3 * mid - 6;
		if (fm * f1 == 0 || fm * f2 == 0 || count == N) {//ѭ����ֹ����,(�ҳ�����׼ȷֵ�����Ѵ���ִ���)
			break;
		}
		if (fm * f1 < 0) {
			x2 = mid;
		}
		else if (fm * f2 < 0) {
			x1 = mid;
		}
	}
	return mid;
}