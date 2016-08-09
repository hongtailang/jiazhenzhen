#pragma once
#include<iostream>
using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int value)
		:m_nValue(value)
		, m_pLeft(NULL)
		, m_pRight(NULL)
	{}
};
void MirrorRecursively(BinaryTreeNode* pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	if (pNode->m_pLeft == NULL&&pNode->m_pRight == NULL)
	{
		return;
	}
	BinaryTreeNode* tmp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = tmp;
	if (pNode->m_pLeft)
	{
		MirrorRecursively(pNode->m_pLeft);
	}
	if (pNode->m_pRight)
	{
		MirrorRecursively(pNode->m_pRight);
	}
}
void Test()
{
	BinaryTreeNode* _root1 = NULL;
	BinaryTreeNode* _root2(NULL);
	MirrorRecursively(_root1);
	MirrorRecursively(_root2);
}