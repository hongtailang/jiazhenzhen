#pragma once
#include<iostream>
using namespace std;
template<class T>
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode<T>* m_pLeft;
	BinaryTreeNode<T>* m_pRight;
	BinaryTreeNode(const T& value)
		:m_nValue(value)
		, m_pLeft(NULL)
		, m_pRight(NULL)
	{}
};
template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	Node* _root;
public:
	BinaryTree()
		:_root(NULL)
	{}
	BinaryTree(const T* a, size_t size, const T& invalid)
	{
		size_t index = 0;
		_root = _CreateTree(a, size, index, invalid);
	}
	//在树A中查找与树B根节点值相同的节点R
	//判断树A中以R为根节点的子树是不是包含和数B一样的结构
	bool HasSubTree(Node* pRoot1, Node* pRoot2)
	{
		bool result = false;
		if (pRoot1 != NULL&&pRoot2 != NULL)
		{
			if (pRoot1->m_nValue == pRoot2->m_nValue)
			{
				result = DoesTree1HaveTree2(pRoot1, pRoot2);
			}
			if (!result)
			{
				result = HasSubTree(pRoot1->m_pLeft, pRoot2);
			}
			if (!result)
			{
				result = HasSubTree(pRoot1->m_pRight, pRoot2);
			}
		}
		return result;
	}
protected:
	Node* _CreateTree(const T* a, size_t size, size_t& index, const T& invalid)
	{
		Node* root = NULL;
		if(index<size && a[index]!=invalid)
		{
			root = new Node(a[index]);
			root->m_pLeft = _CreateTree(a, size, ++index, invalid);
			root->m_pRight = _CreateTree(a, size, ++index, invalid);
		}
		return root;
	}
	bool DoesTree1HaveTree2(Node* pRoot1, Node* pRoot2)
	{
		if (pRoot2 == NULL)
		{
			return true;
		}
		if (pRoot1 == NULL)
		{
			return false;
		}
		if (pRoot1->m_nValue != pRoot2->m_nValue)
		{
			return false;
		}
		return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
	}
};
void Test()
{
	int array1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	//int array2[15] = { 1, 2, '#', 3, '#', '#', 4, 5, '#', 6, '#', 7, '#', '#', 8 };
	int array2[6] = { 1, 2, 3, '#', '#', 4 };
	BinaryTree<int> tree1(array1,10,'#');
	BinaryTree<int> tree2(array2,15,'#');
	bool ret = tree2.HasSubTree(tree1._root, tree2._root);
	cout << "ret:" << ret << endl;
}