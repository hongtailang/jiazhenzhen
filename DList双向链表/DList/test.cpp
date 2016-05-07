#define _CRT_SECURE_NO_WARNINGS
#include "DList.h"
void test1()
{
	DList l1;
	l1.PushBack(1);
	l1.PushBack(2);
	l1.PushBack(3);
	l1.PushBack(4);
	cout << l1 << endl;
	l1.PopBack();
	cout << l1 << endl;
	l1.PopBack();
	cout << l1 << endl;
	l1.PopBack();
	cout << l1 << endl;
	l1.PopBack();
	cout << l1 << endl;
	l1.PopBack();
	cout << l1 << endl;
}
void test2()
{
	DList l1;
	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	cout << l1 << endl;
	l1.PopFront();
	cout << l1 << endl;
	l1.PopFront();
	cout << l1 << endl;
	l1.PopFront();
	cout << l1 << endl;
	l1.PopFront();
	cout << l1 << endl;
	l1.PopFront();
	cout << l1 << endl;
}
void test3()
{
	DList l1;
	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	cout << l1 << endl;
	Node* pos = l1.Find(2);
	l1.Insert(pos, 5);
	cout << l1 << endl;
}
void test4()
{
	DList l1;
	l1.PushFront(1);
	l1.PushFront(3);
	l1.PushFront(4);
	l1.PushFront(2);
	cout << l1 << endl;
	l1.BubbleSort();
	cout << l1 << endl;
}
void test5()
{
	DList l1;
	l1.PushFront(1);
	l1.PushFront(3);
	l1.PushFront(4);
	l1.PushFront(2);
	cout << l1 << endl;
	l1.Reverse();
	cout << l1 << endl;
}
void test6()
{
	DList l1;
	l1.PushFront(1);
	l1.PushFront(3);
	l1.PushFront(4);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(1);
	l1.PushFront(3);
	cout << l1 << endl;
	l1.Remove(3);
	cout << l1 << endl;
}
void test7()
{
	DList l1;
	l1.PushFront(1);
	l1.PushFront(3);
	l1.PushFront(4);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(1);
	l1.PushFront(3);
	cout << l1 << endl;
	l1.RemoveAll(3);
	cout << l1 << endl;
}
void test8()
{
	DList l1;
	l1.PushFront(1);
	l1.PushFront(2);
	l1.PushFront(3);
	l1.PushFront(4);
	cout << l1 << endl;
	Node* pos = l1.Find(2);
	l1.Erase(pos);
	cout << l1 << endl;
}
int main()
{
	test8();
	system("pause");
	return 0;
}