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
	if (pListHead == NULL || k == 0)//��Ϊ�ڵ�����1��ʼ�㣬����0�ǷǷ�����
	{
		return NULL;
	}
	ListNode* pAhead = pListHead;
	ListNode* pBehind = NULL;
	for (unsigned int i = 0; i < k - 1; i++)
	{
		if (pAhead->m_pNext != NULL)//��ֹ��pListHeadΪͷ�ڵ������Ľڵ���С��k��
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
	//��k���ڵ��������м�
	//��k���ڵ���ͷ�ڵ�
	//��k���ڵ�����β�ڵ�
	//����ͷ�ڵ�ΪNULL
	ListNode* ret1 = FindKthToTail(NULL, 2);
	//������ܽڵ���С��k
	//k=0
	ListNode* ret2 = FindKthToTail(NULL, 0);
	//cout << ret2->m_nValue << endl;
}