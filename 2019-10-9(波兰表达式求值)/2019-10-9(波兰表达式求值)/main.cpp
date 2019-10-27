#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<string>
#include<cassert>
using namespace std;
//(a + b)*c - (a + b) / e�ĺ�׺���ʽΪ��
//(a + b)*c - (a + b) / e
//��((a + b)*c)((a + b) / e) -
//��((a + b)c*)((a + b)e / ) -
//��(ab + c * )(ab + e / ) -
//��ab + c * ab + e / -
class Solution {
	stack<int> num;
public:
	int evalRPN(vector<string>& tokens) {
		//���������������Ĺ���
		//����ֱ����vector��, �ҵ��������, ǰ����������Ҫ�����ֵ, Ȼ��������λ�û��ɼ����ֵ
		int leftnum;
		int rightnum;
		for (auto str : tokens) {
			if (str.size() > 1 || str[0] >= '0'&&str[0] <= '9') {
				num.push(atoi(str.c_str()));
			}
			else {
				rightnum = num.top();
				num.pop();
				leftnum = num.top();
				switch (str[0]) {
				case '+':
					num.top() = leftnum + rightnum;
					break;
				case '-':
					num.top() = leftnum - rightnum;
					break;
				case '*':
					num.top() = leftnum * rightnum;
					break;
				case '/':
					num.top() = leftnum / rightnum;
					break;
				}
			}
		}
		return num.top();
	}
};

int main() {
	vector<string> tokens;
	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
	Solution p;
	cout << p.evalRPN(tokens) << endl;
	system("pause");
	return 0;
}