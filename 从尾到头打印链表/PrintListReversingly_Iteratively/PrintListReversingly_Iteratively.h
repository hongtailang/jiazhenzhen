#pragma once
#include<iostream>
#include<stack>
using namespace std;
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};
void PrintListRevesingly_Iteratively(ListNode* pHead)
{
	stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty())
	{
		pNode = nodes.top();
		cout << "从尾到头打印链表：" << pNode->m_nKey << "->";
		nodes.pop();
	}
	cout << endl;
}
void PrintListRevesingly_Recursively(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
		{
			PrintListRevesingly_Recursively(pHead->m_pNext);
		}
		cout << "从尾到头打印链表：" << pHead->m_nKey << "->";
	}
	cout << endl;
}
void TestList()
{
	ListNode* pHead = new ListNode();
	PrintListRevesingly_Iteratively(pHead);
	PrintListRevesingly_Recursively(pHead);
}
