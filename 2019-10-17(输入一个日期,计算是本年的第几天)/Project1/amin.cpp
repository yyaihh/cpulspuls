#include<iostream>
using namespace std;
class Solution {
public:
	int fun(int year, int month, int day) {
		int Month1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
		int Month2[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int count = 0;
		if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
			if (year < 0 || month < 1 || day < 1 || month>12 || day<1 || day>Month1[month - 1]) { 
				return -1;
			}
			for (int i = 0; i < month - 1; ++i) {//ѭ����Ӹ��������·�֮ǰ�������·�����֮��
				count += Month1[i];
			}
		}
		else {
			if (year < 0 || month < 1 || day < 1 || month>12 || day<1 || day>Month2[month - 1]) { 
				return -1;
			}
			for (int i = 0; i < month - 1; ++i) {//ѭ����Ӹ��������·�֮ǰ�������·�����֮��
				count += Month2[i];
			}
		}
		count += day;//���ϻ�������һ�µ�����
		return count;
	}
};
int main() {
	int year, month, day;
	Solution p;
	while (cin >> year >> month >> day) {
		cout << p.fun(year, month, day) << endl;
	}
	system("pause");
	return 0;
}