#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
template<class T>
class StackWithMin
{
public:
	//StackWithMin()
	//	:m_data()
	//	, m_min()
	//{}
	void Push(const T& x)
	{
		if (m_min.size() == 0 || x < m_min.top())
		{
			m_min.push(x);
		}
		else
		{
			m_min.push(m_min.top());
		}
		m_data.push(x);
	}
	void Pop()
	{
		assert(m_min.size() > 0 && m_data.size() > 0);
		m_min.pop();
		m_data.pop();
	}
	int Min()
	{
		assert(m_min.size() > 0 && m_data.size() > 0);
		return m_min.top();
	}
protected:
	stack<int> m_data;//数据栈
	stack<int> m_min;//辅助栈
};
void Test1()
{
	//栈里只有一个元素
	StackWithMin<int> Stack1;
	Stack1.Push(1);
	int ret1 = Stack1.Min();
	cout << "ret1:" << ret1 << endl;
	//栈里没有元素
	StackWithMin<int> Stack;
	int ret = Stack.Min();
	cout << "ret:" << ret << endl;
}
void Test2()//入栈元素大于之前的最小值
{
	StackWithMin<int> Stack;
	Stack.Push(1);
	Stack.Push(2);
	Stack.Push(3);
	Stack.Push(4);
	Stack.Push(5);
	int ret1 = Stack.Min();
	cout << "ret1:" << ret1 << endl;
	Stack.Pop();//弹出的数字不是最小元素
	int ret2 = Stack.Min();
	cout << "ret2:" << ret2 << endl;
}
void Test3()//入栈元素小于之前的最小值
{
	StackWithMin<int> Stack;
	Stack.Push(5);
	Stack.Push(4);
	Stack.Push(3);
	Stack.Push(2);
	Stack.Push(1);
	int ret1 = Stack.Min();
	cout << "ret1:" << ret1 << endl;
	Stack.Pop();//弹出的数字不是最小元素
	int ret2 = Stack.Min();
	cout << "ret2:" << ret2 << endl;
}
void Test4()
{
	StackWithMin<int> Stack;
	Stack.Push(5);
	Stack.Push(3);
	Stack.Push(4);
	Stack.Push(1);
	Stack.Push(2);
	int ret1 = Stack.Min();
	cout << "ret1:" << ret1 << endl;
	Stack.Pop();//弹出的数字不是最小元素
	int ret2 = Stack.Min();
	cout << "ret2:" << ret2 << endl;
	Stack.Pop();//弹出的数字是最小元素
	int ret3 = Stack.Min();
	cout << "ret3:" << ret3 << endl;
}
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	system("pause");
	return 0;
}