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
	int fun1(int W, int H) {
		int i, j;
		if (W >= 4) {
			i = W % 4;
		}
		else {
			i = 0;
		}
		if (H >= 4) {
			j = H % 4;
		}
		else {

		}
		int _W = W + i;
		int _H = H + j;
		int count;
		if (_W > _H) {
			count = _H * _H;
		}
		else if(_W < _H){
			count = _W * _W;
		}
		else {
			count = _H * _W;
		}
		if (i != 0 || j != 0) { 
			count -= (i * W / 2 + j * H / 2); 
		}
		else {
			
		}
		if (i - j == 2 || j - i == 2) {//1,3
			count += 2;
		}
		else if (i == 2 && j == j) {//2,2
			count += 4;
		}
		else if (i == 1 && j == j) {//1,1
			count += 1;
		}
		else if(i - j == 1 || j - i == 1) {//1,2
			count += 2;
		}
		else {
			count += 5;
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
	cout << f.fun1(W, H) << endl;
	cout << f.fun(v);
	system("pause");
	return 0;
}
