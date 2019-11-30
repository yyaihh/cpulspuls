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
	TreeNode<T>* m_parent;
	int m_bf;
public:
	TreeNode(const T& data = T())
		:m_data(data), m_left(nullptr), m_bf(0),
		m_right(nullptr), m_parent(nullptr)
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
		TreeNode<T>* parent = pre->m_parent;
		TreeNode<T>* cur = pre->m_right;
		cur->m_parent = parent;//��ת�ڵ�ĸ��ڵ��Ϊ���ϸ��ڵ�
		//cur��ǣ��
		if (parent) {//parent�������������ڵ�
			//parent��ǣ��
			if (parent->m_left == pre) {//pre��parent������
				/*		1  parent�������������
					2 pre
						3 cur
							4*/
				parent->m_left = cur;
			}
			else {
				/*1parent����������
					 2 pre
						 3 cur
							 4*/
				parent->m_right = cur;
			}
		}
		else {//parent�����������ڵ�
			m_root = cur;
		}
		pre->m_right = cur->m_left;//pre��ǣ��
		if (cur->m_left) {
			/*1 parent                 
	      0.5	2 pre
	   0.25	  1.5  3 cur       --->    
		       cur->l	4
							5 newp*/
			cur->m_left->m_parent = pre;
		}
		cur->m_left = pre;//cur��ǣ��
		pre->m_parent = cur;//pre��ǣ��
		cur->m_bf = pre->m_bf = 0;//��ʱcur��preƽ�����ӱ�Ϊ0
	}
	void rRound(TreeNode<T>* pre) {
		TreeNode<T>* parent = pre->m_parent;
		TreeNode<T>* cur = pre->m_left;
		cur->m_parent = parent;//��ת�ڵ�ĸ��ڵ��Ϊ���ϸ��ڵ�
		//cur��ǣ��
		if (parent) {//parent�������������ڵ�
			//parent��ǣ��
			if (parent->m_right == pre) {//pre��parent���Һ���
				/*		1  parent�������������
					        4 pre
						3 cur
					2*/
				parent->m_right = cur;
			}
			else {
				/*          4parent����������
					    3 pre
					2 cur
				1*/
				parent->m_left = cur;
			}
		}
		else {//parent�����������ڵ�
			m_root = cur;
		}
		pre->m_left = cur->m_right;//pre��ǣ��
		if (cur->m_right) {
			/*   6 parent
		    pre2	2
		 cur3  2.5     7
	     4   3.5            
      5 newp    */
			cur->m_right->m_parent = pre;
		}
		cur->m_right = pre;//cur��ǣ��
		pre->m_parent = cur;//pre��ǣ��
		cur->m_bf = pre->m_bf = 0;//��ʱcur��preƽ�����ӱ�Ϊ0
	}
	void rlRound(TreeNode<T>* pre) {
		TreeNode<T> * right = pre->m_right;
		TreeNode<T> * newroot = right->m_left;
		int flag = newroot->m_bf;
		rRound(pre->m_right);
		lRound(pre);
		if (flag == -1) {
			right->m_bf = 1;
		}
		else {
			pre->m_bf = -1;
		}
	}
	void lrRound(TreeNode<T>* pre) {
		TreeNode<T> * left = pre->m_left;
		TreeNode<T> * newroot = left->m_right;
		int flag = newroot->m_bf;
		lRound(pre->m_left);
		rRound(pre);
		if (flag == -1) {
			pre->m_bf = 1;
		}
		else {
			left->m_bf = -1;
		}
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
		}//ѭ������, ��û���ظ��ڵ�, ����Բ���, pre������Ҫ����λ�õĵĸ��ڵ�
		//�Ȳ���, �ٿ���ƽ������
		if (pre->m_data < val) {
			pre->m_right = newp;
		}
		else {
			pre->m_left = newp;
		}
		newp->m_parent = pre;//��ǰҲ����
		TreeNode<T>* cur = newp;
		while (pre) {
			if (pre->m_left == newp) {//�½ڵ���������
				pre->m_bf--;
			}
			else {//�������������
				pre->m_bf++;
			}
			if (pre->m_bf == 0) {//����֮��ǳ�ƽ��, ֱ������
				break;
			}
			else { //m_bf����ֵֻ��С��2
				if (pre->m_buf == -1 || pre->m_buf == 1) {
					//��ƽ��������������, ���������ж�
					cur = pre;
					pre = pre->m_parent;
				}//else��ƽ����, ����Ҫbreak
				else if (pre->m_bf == 2) { 
					if (cur->m_bf == 1) {//������
						lRound(pre);
					}
					else {//������
						rlRound(pre);
					}
					break;
				}
				else {//m_bf==-2
					if (cur->m_bf == -1) {//������
						rRound(pre);
					}
					else {//������
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
		if (cur->m_left == nullptr) {//���Һ��Ӷ�Ϊ�ջ�������Ϊ���������
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
		else if (cur->m_right == nullptr) {//�Һ���Ϊ��
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
		else {//���Һ��Ӷ���Ϊ��
			if (cur->m_right) {
				for (; cur2->m_right; pre2 = cur2, cur2 = cur2->m_right);
				pre2->m_right = cur2->m_left;//���Լ��������и�������, �ø��װ�����Ϊ�Һ���
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