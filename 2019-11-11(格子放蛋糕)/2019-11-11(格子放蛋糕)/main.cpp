#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
	int size1;
	int size2;
	int count;
	bool f(vector<vector<int>>& v,int i,int j) {
		if (i + 2 < size1&&v[i + 2][j] != 0) { 
			return false;
		}
		if (i - 2 >= 0 && v[i - 2][j] != 0) { 
			return false;
		}
		if (j + 2 < size2&&v[i][j + 2] != 0) {
			return false;
		}
		if (j - 2 >= 0&&v[i][j - 2] != 0) {
			return false;
		}
		return true;
	}
public:
	int fun(vector<vector<int>>& v) {
		count = 0;
		size1 = v.size();
		size2 = v[0].size();
		for (int i = 0; i < size1; ++i) {
			for (int j = 0; j < size2; ++j) {
				if (f(v, i, j)) {
					v[i][j] = 1;
					++count;
				}
			}
		}
		return count;
	}
};
int main() {
	vector<vector<int>> v;
	int W, H;
	cin >> W >> H;
	v.resize(W);
	for (int i = 0; i < W; ++i) {
		v[i].resize(H, 0);
	}
	Solution f;
	cout << f.fun(v);
	system("pause");
	return 0;
}
