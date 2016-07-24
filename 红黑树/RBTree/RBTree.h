#pragma once
#include<iostream>
using namespace std;
enum Colour
{
	RED,
	BLACK
};
template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	K _key;
	V _value;
	Colour _col;
	RBTreeNode(const K& key, const V& value)
		:_left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _key(key)
		, _value(value)
		, _col(RED)
	{}
};
template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}
	bool Insert(const K& key,const V& value)
	{
		//����ڵ�
		if (_root == NULL)
		{
			_root = new Node(key, value);
			_root->_col = BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key, value);
		if (parent->_key>key)
		{
			parent->_left = cur;
			cur->_parent = parent;//һ��Ҫע�⽫cur�ĸ���ָ��parent
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		//������ɫ
		while (cur != _root && parent->_col == RED)//�����㱣֤grandfather�Ĵ���
		{
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				//��һ�����������ڵ������Ϊ��ɫ
				if (uncle&&uncle->_col == RED)
				{
					grandfather->_col = RED;
					parent->_col = BLACK;
					uncle->_col = BLACK;
					cur = grandfather;
					parent = cur->_parent;
				}
				//�ڶ����������������ڵ㲻���ڻ��ߴ���Ϊ��ɫ
				else
				{
					if (parent->_right == cur)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					parent->_col = BLACK;
					grandfather->_col = RED;
					RotateR(grandfather);
				}
			}
			//�������游����
			else
			{
				Node* uncle = grandfather->_left;
				//��һ�����������ڵ������Ϊ��ɫ
				if (uncle&&uncle->_col == RED)
				{
					grandfather->_col = RED;
					parent->_col = BLACK;
					uncle->_col = BLACK;
					cur = grandfather;
					parent = cur->_parent;
				}
				//�ڶ����������������ڵ㲻���ڻ��ߴ���Ϊ��ɫ
				else
				{
					if (parent->_left == cur)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					parent->_col = BLACK;
					grandfather->_col = RED;
					RotateL(grandfather);
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}
	bool CheckRBTree()
	{
		if (_root == NULL&&_root->_col == RED)//����1
		{
			return false;
		}
		int nodeNum = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				nodeNum++;
			}
			cur = cur->_left;
		}
		int count = 0;
		return _CheckRBTree(_root, nodeNum, count);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
protected:
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}
		subR->_left = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subR;
		if (ppNode==NULL)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subR;
			}
			else
			{
				ppNode->_right = subR;
			}
			subR->_parent = ppNode;
		}
	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}
		subL->_right = parent;
		Node* ppNode = parent->_parent;
		parent->_parent = subL;
		if (ppNode == NULL)
		{
			_root = subL;
			subL->_parent = NULL;
		}
		else
		{
			if (ppNode->_left == parent)
			{
				ppNode->_left = subL;
			}
			else
			{
				ppNode->_right = subL;
			}
			subL->_parent = ppNode;
		}
	}
	bool _CheckRBTree(Node* root, const int nodeNum, int count)
	{
		//count���ô�ֵ�Ͳ���Ӱ����һ��
		if (root == NULL)
		{
			return true;
		}
		//������3
		Node* parent = root->_parent;
		if (root->_col == RED&&parent&&parent->_col == RED)
		{
			cout << "�������ĺ�ڵ�" << root->_key << endl;
			return false;
		}
		//������4
		if (root->_col == BLACK)
		{
			count++;
		}
		if (root->_left == NULL&&root->_right == NULL&&nodeNum != count)
		{
			cout << "��ɫ�ڵ���������" << root->_key << endl;
			return false;
		}
		return _CheckRBTree(root->_left, nodeNum, count) && _CheckRBTree(root->_right, nodeNum, count);
	}
	void _InOrder(Node*root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << "->";
		_InOrder(root->_right);
	}

protected:
	Node* _root;
};
void TestRBTree()
{
	RBTree<int, int> tree;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		tree.Insert(arr[i], i);
	}
	tree.InOrder();
	bool ret=tree.CheckRBTree();
	cout << "�Ƿ�ƽ�⣿" << " " << ret << endl;
}
