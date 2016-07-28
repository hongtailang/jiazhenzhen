#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
class UnionFindSet
{
public:
	UnionFindSet(int N)
		:_sets(new int[N])
		, _N(N)
	{
		memset(_sets, -1, sizeof(int)*N);//memset初始化可能会存在问题，它是按字节初始化的。但初始化为-1,0,1不会有问题
	}
	int FindRoot(int x)
	{
		while (_sets[x] >= 0)
		{
			x = _sets[x];
		}
		return x;
	}
	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 != root2)
		{
			_sets[root1] -= 1;
			_sets[root2] = root1;
		}
	}
	int Count()
	{
		int k = 0;
		for (int i = 1; i < _N; i++)
		{
			if (_sets[i] < 0)
			{
				k++;
			}
		}
		return k;
	}
protected:
	int* _sets;
	int _N;
};
int Friend(int n, int m, int r[][2])//n个人，m对朋友
{
	assert(r);
	UnionFindSet ufs(n + 1);
	for (int i = 0; i < m; i++)
	{
		int r1 = r[i][0];
		int r2 = r[i][1];
		ufs.Union(r1, r2);
	}
	return ufs.Count();
}
void Test()
{
	int a[][2] = { 1, 2, 2, 3, 1, 3, 4, 5 };
	int n = 5;
	int m = 4;
	int ret = Friend(n, m, a);
	cout << "朋友圈个数：" << ret << endl;
}