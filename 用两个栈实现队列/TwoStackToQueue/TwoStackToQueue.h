#pragma once
#include<iostream>
#include<stack>
using namespace std;
template<typename T>
class CQueue
{
public:
	//CQueue();
	//~CQueue();
	void appendTail(const T& node)
	{
		stack1.push(node);
	}
	T deleteHead()
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				T& data = stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}
		if (stack2.size() == 0)
		{
			throw new exception("queue is empty");
		}
		T head = stack2.top();
		stack2.pop();
		return head;
	}
private:
	stack<T> stack1;
	stack<T> stack2;
};
void Test()
{
	CQueue<int> queue1;
	queue1.appendTail(1);
	queue1.appendTail(2);
	queue1.appendTail(3);
	queue1.appendTail(4);
	queue1.deleteHead();
	queue1.deleteHead();
	queue1.deleteHead();
	queue1.deleteHead();
	//queue1.deleteHead();
}