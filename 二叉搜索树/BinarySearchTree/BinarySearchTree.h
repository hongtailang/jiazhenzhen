#pragma once
#include<iostream>
using namespace std;
template <class K,class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _right;
	BSTreeNode<K, V>* _left;
	K _key;
	V _value;
	BSTreeNode(const K& key,const V& value)
		:_left(NULL)
		, _right(NULL)
		, _key(key)
		, _value(value)
	{}
};
template <class K,class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
		:_root(NULL)
	{}
	BSTree(Node* root)
		:_root(root)
	{}
	~BSTree()
	{
		_Destory(_root);
		_root = NULL;
	}
	bool Insert(const K& key,const V& value)
	{
		if (_root == NULL)
		{
			_root = new Node(key, value);
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
		}//cur指向NULL，parent为要插入节点的父节点
		if (parent->_key>key)
		{
			parent->_left = new Node(key, value);
		}
		else
		{
			parent->_right = new Node(key, value);
		}
		return true;
	}
	Node* Find(const K& key)
	{
		if (_root == NULL)
			return NULL;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key == key)
			{
				return cur;
			}
			else if (cur->_key > key)
			{
				cur = cur->_left;
			}
			else
			{
				cur = cur->_right;
			}
		}
		return NULL;
	}
	bool Remove(const K& key)
	{
		//没有节点
		//删除叶子节点
		Node* parent = NULL;
		Node* cur = _root;
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
				break;
			}
		}//while循环结束后，有三种可能性：1，_root为空    2，没有找到key    3，找到key，break退出
		if (cur == NULL)//如果cur==NULL表示为前两中情况
		{
			return false;
		}
		Node* del;
		if (cur->_left == NULL)
		{
			del = cur;
			if (parent == NULL)//删除的是根节点
			{
				_root = cur->_right;
			}
			else
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_right;
				}
				else
				{
					parent->_right = cur->_right;
				}
			}
		}
		else if (cur->_right == NULL)
		{
			del = cur;
			if (parent == NULL)
			{
				_root = cur->_left;
			}
			else
			{
				if (parent->_left == cur)
				{
					parent->_left = cur->_left;
				}
				else
				{
					parent->_right = cur->_left;
				}
			}
		}
		else//cur的左右都不为空
		{
			parent = cur;
			Node* firstleft = cur->_right;
			while (firstleft->_left)//寻找cur右边的最左节点来代替cur节点
			{
				parent = firstleft;
				firstleft = firstleft->_left;
			}
			del = firstleft;
			cur->_key = firstleft->_key;
			cur->_value = firstleft->_value;
			if (parent->_left == firstleft)
			{
				parent->_left = firstleft->_right;
			}
			else
			{
				parent->_right = firstleft->_right;
			}
			delete del;
			return true;
		}
	}
	bool InsertR(const K& key, const V& value)
	{
		return _InsertR(_root, key, value);
	}
	Node* FindR(const K& key)
	{
		return _FindR(_root, key);
	}
	bool RemoveR(const K& key)
	{
		return _RemoveR(_root, key);
	}
	void InOrder()
	{
		_InOrder(_root);
	}
protected:
	void _InOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << "---";
		_InOrder(root->_right);
	}
	void _Destory(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		_Destory(root->_left);
		_Destory(root->_right);
		delete root;
	}
	bool _InsertR(Node*& root, const K& key, const V& value)
	{
		if (root == NULL)
		{
			root = new Node(key, value);
			return true;
		}
		if (root->_key > key)
		{
			return _InsertR(root->_left, key, value);
		}
		else if (root->_key < key)
		{
			return _InsertR(root->_right, key, value);

		}
		else
		{
			return false;
		}

	}
	Node* _FindR(Node* root, const K& key)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_key > key)
		{
			return _FindR(root->_left, key);
		}
		if (root->_key < key)
		{
			return _FindR(root->_right, key);
		}
		else
		{
			return root;
		}
	}
	bool _RemoveR(Node*& root, const K& key)
	{
		if (root == NULL)
		{
			return false;
		}
		if (root->_key > key)
		{
			return _RemoveR(root->_left, key);
		}
		else if (root->_key < key)
		{
			return _RemoveR(root->_right, key);
		}
		else
		{
			Node* del = root;
			if (root->_left == NULL)
			{
				root = root->_right;
			}
			else if (root->_right == NULL)
			{
				root = root->_left;
			}
			else
			{
				Node* firstleft = root->_right;
				while (firstleft->_left)
				{
					firstleft = firstleft->_left;
				}
				swap(root->_key, firstleft->_key);
				swap(root->_value, firstleft->_value);
				return _RemoveR(root->_right, key);
			}
			delete del;
		}
		return true;
	}
protected:
	Node* _root;
};
void TestBSTree1()
{
	BSTree<int,int> Tree1;
	Tree1.Insert(5, 0);
	Tree1.Insert(3, 1);
	Tree1.Insert(4, 2);
	Tree1.Insert(1, 3);
	Tree1.Insert(7, 4);
	Tree1.Insert(8, 5);
	Tree1.Insert(2, 6);
	Tree1.Insert(6, 7);
	Tree1.Insert(0, 8);
	Tree1.Insert(9, 9);
	Tree1.InOrder();
	Tree1.Find(8);
	cout << "\n";

	Tree1.Remove(8);
	Tree1.InOrder();
	cout << "\n";
	Tree1.Remove(9);
	Tree1.InOrder();
	cout << "\n";

	Tree1.Remove(5);
	Tree1.InOrder();
	cout << "\n";

	Tree1.Remove(7);
	Tree1.InOrder();
	cout << "\n";

	Tree1.Remove(0);
	Tree1.Remove(1);
	Tree1.Remove(2);
	Tree1.Remove(3);
	Tree1.Remove(4);
	Tree1.Remove(6);
	Tree1.InOrder();
}
void TestBSTree2()
{
	BSTree<int, int> Tree2;
	Tree2.InsertR(5, 0);
	Tree2.InsertR(3, 1);
	Tree2.InsertR(4, 2);
	Tree2.InsertR(1, 3);
	Tree2.InsertR(7, 4);
	Tree2.InsertR(8, 5);
	Tree2.InsertR(2, 6);
	Tree2.InsertR(6, 7);
	Tree2.InsertR(0, 8);
	Tree2.InsertR(9, 9);
	Tree2.InOrder();
	Tree2.FindR(8);
	cout << "\n";

	Tree2.RemoveR(8);
	Tree2.InOrder();
	cout << "\n";
	Tree2.RemoveR(9);
	Tree2.InOrder();
	cout << "\n";

	Tree2.RemoveR(5);
	Tree2.InOrder();
	cout << "\n";

	Tree2.RemoveR(7);
	Tree2.InOrder();
	cout << "\n";

	Tree2.RemoveR(0);
	Tree2.RemoveR(1);
	Tree2.RemoveR(2);
	Tree2.RemoveR(3);
	Tree2.RemoveR(4);
	Tree2.RemoveR(6);
	Tree2.InOrder();
}
