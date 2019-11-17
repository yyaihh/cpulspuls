#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class LCA {
	void Swap(int& a, int&b) {
		int tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
public:
	int getLCA(int a, int b) {
		if (a < 1 || b < 1) {
			return 0;
		}
		int i;//a²ãÊý
		int j;//b²ãÊý
		int m, zu1, zu2;
		for (i = 0, m = 1; a < m || a >= 2 * m; ++i, m *= 2);
		for (j = 0, m = 1; b < m || b >= 2 * m; ++j, m *= 2);
		if (j < i) {
			Swap(i, j);
			Swap(a, b);
		}
		zu1 = a;
		zu2 = b;
		for (; j > i; --j) {
			if (zu2 % 2) {
				zu2 = (2 * zu2 - 1) / 4;
			}
			else {
				zu2 = (2 * zu2 + 1) / 4;
			}
			if (zu1 == zu2) {
				return zu1;
			}
		}
		while (zu1 != zu2) {
			if (zu1 % 2) {
				zu1 = (2 * zu1 - 1) / 4;
			}
			else {
				zu1 = (2 * zu1 + 1) / 4;
			}
			if (zu2 % 2) {
				zu2 = (2 * zu2 - 1) / 4;
			}
			else {
				zu2 = (2 * zu2 + 1) / 4;
			}
		}
		return zu1;
	}
};
int main() {
	LCA l;
	int a, b;
	while (cin >> a >> b) {
		cout << l.getLCA(a, b)<< endl;
	}
	system("pause");
	return 0;
}
