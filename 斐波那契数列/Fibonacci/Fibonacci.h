#pragma once
#include<iostream>
using namespace std;
//递归实现
//long long Fibonacci(unsigned int n)
//{
//	if (n <= 0)
//	{
//		return 0;
//	}
//	if (n == 1)
//	{
//		return 1;
//	}
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
long long Fibonacci(unsigned int n)//非递归效率更高O(n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
	{
		return result[n];
	}
	long long FibNMinusOne = 0;
	long long FibNMinusTwo = 1;
	long long FibN = 0;
	for (int i = 2; i <= n; i++)
	{
		FibN = FibNMinusOne + FibNMinusTwo;
		FibNMinusOne = FibNMinusTwo;
		FibNMinusTwo = FibN;
	}
	return FibN;
}
void Test()
{
	unsigned int n1 = 0;
	long long ret1 = Fibonacci(n1);
	cout << "ret1=" << ret1 << endl;
	unsigned int n2 = 1;
	long long ret2 = Fibonacci(n2);
	cout << "ret2=" << ret2 << endl;	
	unsigned int n3 = 2;
	long long ret3 = Fibonacci(n3);
	cout << "ret3=" << ret3 << endl;
	unsigned int n4 = 100;
	long long ret4 = Fibonacci(n4);
	cout << "ret4=" << ret4 << endl;
}

