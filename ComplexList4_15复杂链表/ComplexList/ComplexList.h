#define _CRT_SECURE_NO_WARNING
#include<iostream>
using namespace std;
typedef int DataType;
struct ComplexNode
{
	DataType _data; //�ڵ�����
	struct ComplexNode* _next; //ָ����һ���ڵ��ָ��
	struct ComplexNode* _random; //ָ��ڵ��������ָ��
	ComplexNode(int x) //Ҫ���Ծ�Ҫд���캯��
		:_data(x)
		, _next(NULL)
		, _random(NULL)
	{}
};
ComplexNode* CopyList(ComplexNode* list)
{
	//���ö��ԣ�ֻ���ڲ���Ϊ�յ�����²Ŷ���
	ComplexNode* cur = list;
	while (cur)
	{
		ComplexNode* tmp = new ComplexNode(cur->_data);
		tmp->_next = cur->_next;
		cur->_next = tmp;
		cur = tmp->_next;
	}
	//��random
	cur = list;
	while (cur)
	{
		ComplexNode* next = cur->_next;
		if (cur->_random)
		{
			next->_random = cur->_random->_next;
		}
		cur = next->_next;
	}
	//��ż����
	cur = list;
	ComplexNode* newHead = NULL;
	ComplexNode* newTail = NULL;
	if (cur)
	{
		newHead = newTail = cur->_next;
		cur->_next = newHead->_next;
		cur = cur->_next;
	}
	while (cur)
	{
		newTail->_next = cur->_next;
		newTail = newTail->_next;
		cur->_next = newTail->_next;
		cur = cur->_next;
	}
	return newHead;
}
ComplexNode* CreateCopmlexList()
{
	ComplexNode* head1 = new ComplexNode(1);
	ComplexNode* head2 = new ComplexNode(2);
	ComplexNode* head3 = new ComplexNode(3);
	ComplexNode* head4 = new ComplexNode(4);
	head1->_next = head2;
	head2->_next = head3;
	head3->_next = head4;
	head1->_random = head4;
	head2->_random = head1;
	head4->_random = head2;
	return head1;
}
void PrintComplexList(ComplexNode* list)
{
	while (list)
	{
		cout << list->_data << ":";
		if (list->_random)
		{
			cout << list->_random->_data << endl;
		}
		else
		{
			cout << "NULL" << endl;
		}
		list = list->_next;
	}
}
void Test()
{
	ComplexNode* list1 = CreateCopmlexList();
	ComplexNode* list2 = CopyList(list1);
	PrintComplexList(list1);
	PrintComplexList(list2);
}