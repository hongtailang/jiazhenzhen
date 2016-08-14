#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
struct BinaryTreeNode
{
public:
	BinaryTreeNode(const T& data)
			: _data(data)
			, _left(NULL)
			, _right(NULL)
	{}
	T _data;
	BinaryTreeNode<T>* _left;
	BinaryTreeNode<T>* _right;
};
template<typename T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()//无参构造函数
		:_root(NULL)
	{}
	BinaryTree(const T* a, size_t size, const T& invalid)//带参构造函数
	{
		size_t index = 0;
		_root = _CreateTree(a, size, index, invalid);
	}
	BinaryTree(const BinaryTree<T>& t)//拷贝构造
	{
		_root = _Copy(t._root);
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)
	{
		if (this != &t)
		{
			Node* tmp = _Copy(t._root);
			_Destory(_root);
			_root = tmp;
		}
		return *this;
	}
	~BinaryTree()
	{
		_Destory(_root);
		_root = NULL;
	}
	void PrevOrder()//先序遍历
	{
		cout << "先序遍历:";
		_PrevOrder(_root);
		cout << endl;
	}
	void InOrder()//中序遍历
	{
		cout << "中序遍历:";
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()//后序遍历
	{
		cout << "后序遍历:";
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()//层序遍历
	{
		cout << "层序遍历:";
		_LevelOrder();
	}
	void PrevOrder_NonR()
	{
		cout << "非递归先序遍历:";
		Node* cur = _root;
		stack<Node*> s;
		if (cur != NULL)
		{
			s.push(cur);
			cout << cur->_data << " ";
			s.pop();
		}
		while (cur || !s.empty())
		{
			if (cur->_right != NULL)
			{
				s.push(cur->_right);
			}
			if (cur->_left != NULL)
			{
				s.push(cur->_left);
			}
			if (!s.empty())
			{
				cout << s.top()->_data << " ";
				cur = s.top();
				s.pop();
			}
			else
			{
				cur = NULL;
			}
		}
		cout << endl;
	}
	void InOrder_NonR()
	{
		cout << "非递归中序遍历:";
		Node* cur = _root;
		stack<Node*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}//循环结束时所有左孩子均进栈了
			Node* top = s.top();
			cout<< top->_data << " ";
			s.pop();
			cur = cur->_right;
		}
		cout << endl;
	}
	void PostOrder_NonR()
	{
		cout << "非递归后序遍历:";
		Node* prev = NULL;
		Node* cur = _root;
		stack<Node*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			Node* top = s.top(); 
			if (top->_right == NULL || top->_right == prev)
			{
				cout<< top->_data << " ";
				s.pop();
				prev = top;
			}
			else
			{
				cur = top->_right;
			}
		}
		cout << endl;
	}
	Node* Find(const T& x)//在二叉树里查找一个结点
	{
		return _Find(_root, x);
	}
	//size_t GetKLevel(size_t k)//第K层结点个数
	//{
	//	return _GetKLevel(_root, k);
	//}
	size_t GetKLevel(size_t k)//第K层结点个数
	{
		size_t size = 0;
		size_t level = 1;
		_GetKLevel(_root, level, k, size);
		return size;
	}
	size_t Size()
	{
		return _Size(_root);
	}
	size_t Depth()
	{
		return _Depth(_root);
	}
	size_t LeafSize()
	{
		return _LeafSize(_root);
	}
	void PrintFromTopToBottom()
	{
		cout << "层序遍历：";
		_PrintFromTopToBottom(_root);
		cout << endl;
	}
protected:
	void _PrevOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			cout << root->_data << " ";
			_PrevOrder(root->_left);
			_PrevOrder(root->_right);
		}
	}
	void _InOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			_InOrder(root->_left);
			cout << root->_data<<" ";
			_InOrder(root->_right);
		}
	}
	void _PostOrder(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout << root->_data << " ";
		}
	}
	void _LevelOrder()//层序遍历
	{
		queue<Node*> q;
		if (_root)
		{
			q.push(_root);
		}
		while (!q.empty())
		{
			Node* front = q.front();
			cout << q.front()->_data << " ";
			if (front->_left)
			{
				q.push(front->_left);
			}
			if (front->_right)
			{
				q.push(front->_right);
			}
			q.pop();
		}
		cout << endl;
	}
	Node* _Find(Node* root, const T& x)
	{
		if (root == NULL)
		{
			return NULL;
		}
		if (root->_data == x)
		{
			return root;
		}
		Node* ret = _Find(root->_left, x);
		if (ret)
		{
			return ret;
		}
		else
		{
			return _Find(root->_right, x);
		}
	}
	//size_t _GetKLevel(Node* root, size_t k)
	//{
	//	if (root == NULL)
	//	{
	//		return 0;
	//	}
	//	if (k == 1)
	//	{
	//		return 1;
	//	}
	//	return _GetKLevel(root->_left, k - 1) + _GetKLevel(root->_right, k - 1);
	//}
	void _GetKLevel(Node* root, size_t level, size_t k, size_t& size)
	{
		if (root == NULL)
		{
			return;
		}
		if (k == level)
		{
			size++;
			return;
		}
		_GetKLevel(root->_left, level + 1, k, size);//不能改变level的值，所以必须是加1，而不是++
		_GetKLevel(root->_right, level + 1, k, size);
	}
	size_t _Size(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return  _Size(root->_left) + _Size(root->_right)+1;
	}
	size_t _Depth(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		size_t left = _Depth(root->_left)+1;
		size_t right = _Depth(root->_right)+1;
		return (left > right) ? left : right;
	}
	size_t _LeafSize(Node* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		if ((root->_left == NULL) && (root->_right == NULL))
		{
			return 1;
		}
		return _LeafSize(root->_left) + _LeafSize(root->_right);
	}
	void _PrintFromTopToBottom(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		queue<Node *> queueTreeNode;
		queueTreeNode.push(root);
		while (!queueTreeNode.empty())
		{
			Node* pNode = queueTreeNode.front();
			if (pNode->_left)
			{
				queueTreeNode.push(pNode->_left);
			}
			if (pNode->_right)
			{
				queueTreeNode.push(pNode->_right);
			}
			cout << pNode->_data << " ";
			queueTreeNode.pop();
		}
	}
protected:
	Node* _CreateTree(const T* a, size_t size, size_t& index, const T& invalid)
	{
		Node* root = NULL;
		if ((index < size) && (a[index] != invalid))
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, size, ++index, invalid);
			root->_right = _CreateTree(a, size, ++index, invalid);
		}
		return root;
	}
	void _Destory(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		{
			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
		}
	}
	Node* _Copy(Node* root)
	{
		Node* newRoot = NULL;
		if (root != NULL)
		{
			newRoot = new Node*(root->_data);
			newRoot->_left = _Copy(root->_left);
			newRoot->_right = _Copy(root->_right);
		}
		return newRoot;
	}
protected:
	Node* _root;
};

void Test()
{
	int array1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int array2[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	BinaryTree<int> bt1(array1, 10, '#');
	bt1.PostOrder_NonR();
	bt1.PrevOrder_NonR();
	size_t ret1=bt1.Depth();
	bt1.PrintFromTopToBottom();
	cout << "ret1:" << ret1 << endl;
	size_t ret2 = bt1.Size();
	cout << "ret2:" << ret2 << endl;
	int leaf1=bt1.LeafSize();
	cout << "leaf1:" << leaf1 << endl;
	bt1.Find(3);
	size_t num=bt1.GetKLevel(2);
	cout << "num:" << num << endl;
	bt1.PrevOrder();
	//bt1.InOrder();
	//bt1.PostOrder();
	bt1.LevelOrder();
	BinaryTree<int> bt2(array2, 15, '#');
	bt2.PostOrder_NonR();
	bt2.PrevOrder_NonR();
	size_t ret3 = bt2.Depth();
	cout << "ret3:" << ret3 << endl;
	size_t ret4 = bt2.Size();
	cout << "ret4:" << ret4 << endl;
	int leaf2 = bt2.LeafSize();
	cout << "leaf2:" << leaf2 << endl;
	//bt2.PrevOrder();
	//bt2.InOrder();
	//bt2.PostOrder();
	//bt2.LevelOrder();

}