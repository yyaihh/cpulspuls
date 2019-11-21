#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int fun(int n, int* arr) {
		sort(arr, arr + n);
		int onenums = 0;
		for (int i = 0; arr[i] == 1; ++onenums, ++i);
		if (onenums == 0)  return 0;//û��1�Ļ����β������˴���
		vector<int> prod = { 1 }; //��¼���еĳ˻�
		vector<int> sum = { 0 };  //��¼���еĺ�
		for (int i = onenums, size, k, presize = 0; i < n; ++i) {
			//�����һ��1����һ��λ�ÿ�ʼ, ��Ϊ֮ǰ��1û��Ҫ�ظ��Ƚ�
			//���Ѿ���¼Ϊonenumbs, ��1��Ӱ��˻�
			size = sum.size();//prod.size(),һ����
			arr[i] == arr[i - 1] ? k = presize : k = 0;
			//�����ǰһ��һ����û��Ҫ�ظ���ӵ�ǰ��Ĵ���
			for (; k < size; ++k) {
				//�����i���򵽴��Ӻ��Ƿ�������, �ǵĻ�����˻�����
				if (sum[k] + arr[i] + onenums > prod[k] * arr[i]) {
					prod.push_back(prod[k] * arr[i]);
					sum.push_back(sum[k] + arr[i]);
				}
			}
			presize = size;
		}
		int count = 0;
		if (onenums > 2) {
			count = onenums - 1;
		}
		for (int k = 1; k < (int)sum.size(); ++k) {//ͨ�����벻ͬ������1��ʹ����������
			count += onenums + sum[k] - prod[k];
			//(onenums + sum[k]) - prod[k]����n, ��˵������1��, 2����,....n������������
		}
		return count;
	}
};
int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	Solution p;
	cout << p.fun(n, arr) << endl;
	delete[] arr;
	system("pause");
	return 0;
}
