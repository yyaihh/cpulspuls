#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
//����ѹ��ջ���������־�����ȡ���������1, 2, 3, 4, 5��ĳջ��ѹ��˳��
//����4, 5, 3, 2, 1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4, 3, 5, 1, 2�Ͳ������Ǹ�ѹջ���еĵ������С�
//��ע�⣺���������еĳ�������ȵģ�
class Solution {
public:
	bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
		stack<int> s;
		auto i = pushV.begin();
		auto j = popV.begin();
		for (; i != pushV.end(); ++i) { 
			if (*i != *j) {
				s.push(*i);
			}
			else {
				++j;
			}
		}
		for (; j != popV.end(); ++j) {
			if (s.top() != *j) {
				return false;
			}
			s.pop();
		}
		return true;
	}
};
int main() {
	int a[] = { 1,2,3,4,5 };
	//int b[] = { 4,5,3,2,1 };
	int b[] = { 4,3,5,1,2 };
	vector<int> v1(a, a + 5);
	vector<int> v2(b, b + 5);
	Solution p;
	cout << p.IsPopOrder(v1, v2) << endl;
	system("pause");
	return 0;
}