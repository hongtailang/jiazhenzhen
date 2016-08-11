#include<iostream>
#include<stack>
using namespace std;
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	bool bPossible = false;
	if (pPush != NULL&&pPop != NULL&&nLength > 0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;
		stack<int> stackData;
		while (pNextPop - pPop < nLength)
		{
			while (stackData.empty() || stackData.top() != *pNextPop)
			{
				if (pNextPush - pPush == nLength)
				{
					break;
				}
				stackData.push(*pNextPush);
				pNextPush++;
			}
			if (stackData.top() != *pNextPop)
			{
				break;
			}
			stackData.pop();
			pNextPop++;
		}
		if (stackData.empty()&&pNextPop - pPop == nLength)
		{
			bPossible = true;
		}
	}
	return bPossible;
}
void Test1()//功能测试
{
	int arr1[] = { 1 };
	int arr2[] = { 1 };
	int arr[] = { 2 };
	int arr3[] = { 1, 2, 3, 4, 5 };
	int arr4[] = { 4, 5, 3, 2, 1 };
	int arr5[] = { 4, 3, 5, 1, 2 };
	bool ret = IsPopOrder(arr1, arr, 1);
	bool ret1 = IsPopOrder(arr1, arr2, 1);//1
	bool ret2 = IsPopOrder(arr3, arr4, 5);//1
	bool ret3 = IsPopOrder(arr3, arr5, 5);//0
	cout << "ret=" << ret << endl;
	cout << "ret1=" << ret1 << endl;
	cout << "ret2=" << ret2 << endl;
	cout << "ret3=" << ret3 << endl;
}
void Test2()//特殊输入测试
{
	int* arr1 = NULL;
	int* arr2 = NULL;
	int ret = IsPopOrder(arr1, arr2, 0);
	cout << "ret=" << ret << endl;
}
int main()
{
	Test1();
	Test2();
	system("pause");
	return 0;
}