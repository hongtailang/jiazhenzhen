#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
using namespace std;
enum PointerTag
{
	THREAD,
	LINK
};
template<typename T>
struct BinaryTreeNodeThd
{
	T _data;										//数据
	BinaryTreeNodeThd<T>* _left;		//左孩子
	BinaryTreeNodeThd<T>* _right;	//右孩子
	PointerTag _leftTag;						//左孩子线索标志
	PointerTag _rightTag;					//右孩子线索标志
	BinaryTreeNodeThd(const T& x)
		:_data(x)
		, _left(NULL)
		, _right(NULL)
		, _leftTag(LINK)
		, _rightTag(LINK)
	{}
};
template<typename T>
class BinaryTreeThd
{
	typedef BinaryTreeNodeThd<T> Node;
public:
	BinaryTreeThd()//无参构造
		:_root(NULL)
	{}
	BinaryTreeThd(const T* a,size_t size,const T& invalid)//带参构造
	{
		size_t index = 0;
		_root = _CreateTree(a, size, index, invalid);
	}
	void PrevOrderThreading()//前序线索化
	{
		Node* prev = NULL;
		_PrevOrderThreading(_root,prev);
	}
	void InOrderThreading()//中序线索化
	{
		Node* prev = NULL;
		_InOrderThreading(_root,prev);
	}
	void PrevOrderThd()
	{
		cout << "前序线索化遍历:";
		_PrevOrderThd(_root);
	}
	void InOrderThd()
	{
		cout << "中序线索化遍历:";
		_InOrderThd(_root);
	}
protected:
	Node* _CreateTree(const T* a, size_t size, size_t& index, const T& invalid)
	{
		Node* root = NULL;
		if ((index<size)&&(a[index] != invalid))
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, size, ++index, invalid);
			root->_right = _CreateTree(a, size, ++index, invalid);
		}
		return root;
	}
	void _PrevOrderThreading(Node* cur,Node*& prev)
	{
		if (cur == NULL)
		{
			return;
		}
		if (cur->_left == NULL)
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if (prev&&prev->_right == NULL)
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		if (cur->_leftTag == LINK)
		{
			_PrevOrderThreading(cur->_left, prev);
		}
		if (cur->_rightTag == LINK)
		{
			_PrevOrderThreading(cur->_right, prev);
		}
	}
	void _InOrderThreading(Node* cur,Node*& prev)
	{
		if (cur == NULL)
		{
			return;
		}
		_InOrderThreading(cur->_left, prev);
		if (cur->_left == NULL)//最里层
		{
			cur->_leftTag = THREAD;
			cur->_left = prev;
		}
		if ((prev)&&(prev->_right==NULL))
		{
			prev->_rightTag = THREAD;
			prev->_right = cur;
		}
		prev = cur;
		_InOrderThreading(cur->_right,prev);
	}
	void _PrevOrderThd(Node* root)
	{
		Node* cur = root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cout << cur->_data << " ";
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			cur = cur->_right;
		}
		cout << endl;
	}
	void _InOrderThd(Node* root)
	{
		Node* cur = root;
		while (cur)
		{
			while (cur->_leftTag == LINK)
			{
				cur = cur->_left;
			}
			cout << cur->_data << " ";
			while (cur->_rightTag == THREAD)
			{
				cur = cur->_right;
				cout << cur->_data << " ";
			}
			cur = cur->_right;
		}
		cout << endl;
	}
protected:
	Node* _root;
};

void Test()
{
	int array1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int array2[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	BinaryTreeThd<int> bt1(array1, 10, '#');
	bt1.InOrderThreading();
	bt1.InOrderThd();
	BinaryTreeThd<int> bt2(array2, 15, '#');
	bt2.InOrderThreading();
	bt2.InOrderThd();
	BinaryTreeThd<int> bt3(array1, 10, '#');
	bt3.PrevOrderThreading();
	bt3.PrevOrderThd();
	BinaryTreeThd<int> bt4(array2, 15, '#');
	bt4.PrevOrderThreading();
	bt4.PrevOrderThd();
}