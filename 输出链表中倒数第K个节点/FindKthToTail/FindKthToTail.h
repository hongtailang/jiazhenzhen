#pragma once
#include<iostream>
using namespace std;
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)//因为节点数从1开始算，所以0是非法输入
	{
		return NULL;
	}
	ListNode* pAhead = pListHead;
	ListNode* pBehind = NULL;
	for (unsigned int i = 0; i < k - 1; i++)
	{
		if (pAhead->m_pNext != NULL)//防止以pListHead为头节点的链表的节点数小于k个
		{
			pAhead = pAhead->m_pNext;
		}
		else
		{
			return NULL;
		}
	}
	pBehind = pListHead;
	while (pAhead->m_pNext != NULL)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}
	return pBehind;
}
void Test()
{
	//第k个节点在链表中间
	//第k个节点是头节点
	//第k个节点是是尾节点
	//链表头节点为NULL
	ListNode* ret1 = FindKthToTail(NULL, 2);
	//链表的总节点数小于k
	//k=0
	ListNode* ret2 = FindKthToTail(NULL, 0);
	//cout << ret2->m_nValue << endl;
}