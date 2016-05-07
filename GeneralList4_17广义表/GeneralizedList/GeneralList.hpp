#define _CRT_SECURE_NO_WARNING
#pragma once
#include<assert.h>
enum NodeType
{
	HEAD, //ͷ���
	VALUE, //ֵ���
	SUB //�ӱ��㣬�����������
};
struct GeneralListNode
{
	GeneralListNode(NodeType type=HEAD,char value='\0')
		:_type(type)
		, _next(NULL)
	{
		if (type == VALUE)
		{
			_value = value;
		}
		else if (type==SUB)
		{
			_subLink = NULL;
		}
	}
	NodeType _type; //�������
	GeneralListNode* _next;
	union //�Ż���ʡ�ռ䣨��㲻����ͬʱΪֵ�����ӱ��㣩
	{
		char _value; //�����ֵ
		GeneralListNode* _subLink;
	};
};
class GeneralList
{
public:
	GeneralList()//�޲ι���
		:_head(new GeneralListNode(HEAD))
	{}
	GeneralList(const char* str)//�вι���
		:_head(NULL)
	{
		_head=_CreateGeneralList(str);
	}
	GeneralList(const GeneralList& g)//��������
	{
		_head = _Copy(g._head);
	}
	//GeneralList& operator=(const GeneralList& g)//�ȿ��ռ�ʧ�ܱٿռ��ٸ�ֵ����ֹ�˿���
	//{
	//	if (this != &g)
	//	{
	//		GeneralListNode* tmp = _Copy(g._head);
	//		_Destory(_head);
	//		_head = tmp;
	//	}
	//	return *this;
	//}
	GeneralList& operator=(GeneralList& g)//�ִ�д��
	{
		swap(_head, g._head);
		return *this;
	}
	~GeneralList()
	{
		_Destory(_head);
	}
	size_t Size()
	{
		return _Size(_head);
	}
	size_t Depth()
	{
		return _Depth(_head);
	}
	size_t Length()
	{
		return _Length(_head);
	}
	void PrintGeneralList()
	{
		_Print(_head);
		cout << endl;
	}
protected:
	bool _IsValue(char ch)
	{
		if ((ch >= '0') && (ch <= '9') || ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z')))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	size_t _Size(GeneralListNode* head)
	{
		GeneralListNode* cur = head;
		size_t size = 0;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				size++;
			}
			else if (cur->_type == SUB)
			{
				size += _Size(cur->_subLink);
			}
			cur = cur->_next;
		}
		return size;
	}
	size_t _Depth(GeneralListNode* head)
	{
		size_t depth = 1;
		GeneralListNode* cur = head;
		while (cur)
		{
			if (cur->_type == SUB)
			{
				size_t subDepth = _Depth(cur->_subLink);
				if ((subDepth + 1) > depth)
				{
					depth = subDepth + 1;
				}
			}
			cur = cur->_next;
		}
		return depth;
	}
	size_t _Length(GeneralListNode* head)//�ӱ���Ϊ1����㳤�� Ϊ1
	{
		GeneralListNode* cur = head;
		size_t len = 0;
		if (head == NULL)
			return 0;
		while (cur)
		{
			if (cur->_type == VALUE)
			{
				len++;
			}
			else if (cur->_type == SUB)
			{
				len++;
			}
			cur = cur->_next;
		}
		return len;
	}
protected:
	GeneralListNode* _CreateGeneralList(const char*& str)
	{
		assert(str&&*str == '(');//Ϊʲô���Ͼͻ����
		str++;
		GeneralListNode* head = new GeneralListNode(HEAD);
		GeneralListNode* cur = head;
		while (*str)
		{
			if (_IsValue(*str))
			{
				cur->_next = new  GeneralListNode(VALUE, *str);
				cur = cur->_next;
				str++;
			}
			else if (*str == '(')
			{
				cur->_next = new  GeneralListNode(SUB);
				cur = cur->_next;
				cur->_subLink = _CreateGeneralList(str);
			}
			else if (*str == ')')//�ݹ���ֹ����
			{
				str++;
				return head;
			}
			else
			{
				str++;
			}
		}
	    assert(false);//ǿ���ж�
		return head;
	}
	GeneralListNode* _Copy(GeneralListNode* head)
	{
		GeneralListNode* cur = head->_next;
		GeneralListNode* newHead = new GeneralListNode(HEAD);
		while (cur)
		{
			if (cur->_type == VALUE)//��Ϊֵ���������±�ͷ�ĺ��
			{
				GeneralListNode* newCur = newHead;
				newCur->_next = new GeneralListNode(VALUE, cur->_value);
				newCur = newCur->_next;
			}
			else if (cur->_type == SUB)//��Ϊ�ӱ�
			{
				GeneralListNode* newCur = newHead;
				newCur->_next = new GeneralListNode(SUB);
				newCur = newCur->_next;
				newCur->_subLink = _Copy(cur->_subLink);//�ݹ�
			}
			cur = cur->_next;
		}
		return newHead;
	}
	void _Destory(GeneralListNode* head)
	{
		GeneralListNode* cur = head;
		while (cur)
		{
			GeneralListNode* del = cur;
			cur = cur->_next;
			if (del->_type == SUB)
			{
				_Destory(del->_subLink);
			}
			else
			{
				delete del;
			}
		}
	}
	void _Print(GeneralListNode* head)
	{
		GeneralListNode* cur = head;
		while (cur)
		{
			if (cur->_type == HEAD)
			{
				cout << "(";
			}
			else if (cur->_type == VALUE)
			{
				cout << cur->_value;
				if (cur->_next)
				{
					cout << ",";
				}
			}
			else if (cur->_type == SUB)
			{
				_Print(cur->_subLink);
				if (cur->_next)
				{
					cout << ",";
				}
			}
			cur = cur->_next;;
		}
		cout << ")";
	}
protected:
	GeneralListNode* _head;
};
void Test1()
{
	const char* str1 = "()";
	GeneralList gl1(str1);
	gl1.PrintGeneralList();
	int ret1=gl1.Size();
	cout << ret1 << endl;
	const char* str2 = "(a,b)";
	GeneralList gl2(str2);
	gl2.PrintGeneralList();
	int ret2 = gl2.Size();
	cout << ret2 << endl;
	const char* str3 = "(a,b,(c,d))";
	GeneralList gl3(str3);
	gl3.PrintGeneralList();
	int ret3 = gl3.Depth();
	int ret4 = gl3.Size();
	int ret5 = gl3.Length();
	cout << ret3 << endl;
	cout << ret4 << endl;
	cout << ret5 << endl;
}