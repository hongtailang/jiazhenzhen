#pragma once
#include<iostream>
using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};
BinaryTreeNode* Construct(int* preorder,int* Inorder,int length)
{
	BinaryTreeNode* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInorder, int* endInorder);
	if (preorder == NULL || Inorder == NULL || length <= 0)
	{
		return NULL;
	}
	return ConstructCore(preorder, preorder + length - 1, Inorder, Inorder + length - 1);
}
BinaryTreeNode* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInorder, int* endInorder)
{
	int rootValue = startPreOrder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;
	if (startPreOrder == endPreOrder)
	{
		if (startInorder==endInorder&&*startPreOrder==*startInorder)
		{
			return NULL;
		}
		else
		{
			throw exception("Invalid input.");
		}
	}
	//在中序遍历中查找根节点的值
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&&*rootInorder != rootValue)
	{
		rootInorder++;
	}
	if (rootInorder == endInorder&&*rootInorder != rootValue)
	{
		throw exception("Invalid input");
	}
	int leftLength = rootInorder - startInorder;//左子树的节点数
	int* leftPreorderEnd = startPreOrder + leftLength;//左子树末尾指针
	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreOrder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreOrder - startPreOrder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreOrder, rootInorder + 1, endInorder);
	}
	return root;
}
void TestTree()
{
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int ord[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int size = sizeof(pre) / sizeof(pre[0]);
	BinaryTreeNode* ret = Construct(pre, ord, size);
	while (ret)
	{
		cout << ret->m_nValue << "->";
		ret = ret->m_pLeft;
	}
	cout << endl;
}