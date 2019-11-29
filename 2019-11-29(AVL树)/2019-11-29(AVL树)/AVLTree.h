#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
template <class T>
class TreeNode {
	T m_data;
	TreeNode<T>* m_left;
	TreeNode<T>* m_right;
	TreeNode<T>* m_pre;
	int m_bf;
public:
	TreeNode(const T& data = T())
		:m_data(data), m_left(nullptr), m_bf(0),
		m_right(nullptr), m_pre(nullptr)
	{}
	template <class T>
	friend class AVLTtree;
};
template <class T>
class AVLTtree {
	TreeNode<T>* m_root;
	void destroy(TreeNode<T>* root) {
		if (root) {
			destroy(root->m_left);
			destroy(root->m_right);
			delete root;
		}
	}
	void lRound(TreeNode<T>* pre) {

	}
	void rlRound(TreeNode<T>* pre) {

	}
	void lRound(TreeNode<T>* pre) {

	}
	void lrRound(TreeNode<T>* pre) {

	}
public:
	AVLTtree()
		:m_root(nullptr)
	{}
	~AVLTtree() {
		destroy(m_root);
	}
	bool insert(const T& val) {
		TreeNode<T>* newp = new TreeNode<T>;
		newp->m_data = val;
		if (m_root == nullptr) {
			m_root = newp;
			return true;
		}
		TreeNode<T>* cur = m_root;
		TreeNode<T>* pre = m_root;
		while (cur) {
			pre = cur;
			if (val > cur->m_data) {
				cur = cur->m_right;
			}
			else if (val < cur->m_data) {
				cur = cur->m_left;
			}
			else {
				delete newp;
				return false;
			}
		}//循环结束, 若没有重复节点, 则可以插入, pre就是需要插入位置的的父节点
		//先插上, 再考虑平衡问题
		if (pre->m_data < val) {
			pre->m_right = newp;
		}
		else {
			pre->m_left = newp;
		}
		newp->m_pre = pre;//往前也接上
		TreeNode<T>* cur = newp;
		while (pre) {
			if (pre->m_left == newp) {//新节点是左子树
				pre->m_bf--;
			}
			else {//否则就是右子树
				pre->m_bf++;
			}
			if (pre->m_bf == 0) {//加上之后非常平衡, 直接跳出
				break;
			}
			else { //m_bf绝对值只能小于2
				if (pre->m_buf == -1 || pre->m_buf == 1) {
					//若平衡因子满足条件, 继续向上判断
					cur = pre;
					pre = pre->m_pre;
				}//else不平衡了, 所以要break
				else if (pre->m_bf == 2) { 
					if (cur->m_bf == 1) {//根右右
						lRound(pre);
					}
					else {//根左右
						rlRound(pre);
					}
					break;
				}
				else {//m_bf==-2
					if (cur->m_bf == -1) {//根左左

					}
					else {//根右左
						rRound(pre);
					}
					break;
				}
			}
		}
		return true;
	}
	bool erase(const T& val) {
		TreeNode<T>* pre = m_root;
		TreeNode<T>* cur = m_root;
		while (cur) {
			if (val > cur->m_data) {
				pre = cur;
				cur = cur->m_right;
			}
			else if (val < cur->m_data) {
				pre = cur;
				cur = cur->m_left;
			}
			else {
				break;
			}
		}
		if (cur == nullptr) {
			return false;
		}
		TreeNode<T>* cur2 = cur->m_left;
		TreeNode<T>* pre2 = cur2;
		if (cur->m_left == nullptr) {//左右孩子都为空或者左孩子为空两种情况
			if (pre == m_root) {
				m_root = cur->m_right;
			}
			else {
				if (cur->m_data < pre->m_data) {
					pre->m_left = cur->m_right;
				}
				else {
					pre->m_right = cur->m_right;
				}
			}
		}
		else if (cur->m_right == nullptr) {//右孩子为空
			if (pre == m_root) {
				m_root = cur->m_left;
			}
			else {
				if (cur->m_data > pre->m_data) {
					pre->m_right = cur->m_left;
				}
				else {
					pre->m_left = cur->m_left;
				}
			}
		}
		else {//左右孩子都不为空
			if (cur->m_right) {
				for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
				pre2->m_right = cur2->m_left;//将自己的左孩子托付给父亲, 让父亲把他作为右孩子
				cur2->m_left = cur->m_left;
			}
			cur2->m_right = cur->m_right;
			if (cur->m_data < pre->m_data) {
				if (pre == m_root) {
					m_root = cur2;
				}
				else {
					pre->m_left = cur2;
				}
			}
			else {
				if (pre == m_root) {
					m_root = cur2;
				}
				else {
					pre->m_right = cur2;
				}
			}

		}
		delete cur;
		return true;
	}
	void InorderPrint() {
		stack<TreeNode<T>*> s;
		vector<T> res;
		TreeNode<T>* cur = m_root;
		while (cur) {
			for (; cur; cur = cur->m_left) {
				s.push(cur);
			}
			do {
				cur = s.top();
				res.push_back(cur->m_data);
				s.pop();
			} while (cur->m_right == nullptr && !s.empty());
			cur = cur->m_right;
		}
		for (auto& i : res) {
			cout << i << ' ';
		}
		cout << endl;
	}
};