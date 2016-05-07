#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;
#define N 10
struct Pos
{
	Pos(size_t row, size_t col)
		:_row(row)
		, _col(col)
	{}
	int _row;
	int _col;
};
void GetMaze(int *a,int n)
{
	FILE* fout = fopen("MazeMap.txt", "r");
	assert(fout);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;)
		{
			char ch = fgetc(fout);
			if ('0' == ch || '1' == ch)
			{
				a[i*n + j] = ch - '0';
				j++;
			}
			else
			{
				continue;
			}
		}
	}
	fclose(fout);
}
void PrintMaze(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i*n + j]<<" ";
		}
		cout << endl;
	}
}
bool CheckIsAccess(int* a, int n, Pos next)
{
	assert(a);
	if ((next._row >= 0) && (next._row < n) && (next._col >= 0) && (next._col < n)&&(a[next._row*n+next._col]==0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool MazePath(int* a, int n, const Pos& entry, stack<Pos>& path)
{
	Pos cur = entry;
	path.push(cur);
	while (!path.empty())
	{
		//是否已经到出口
		if (cur._row == n - 1)
		{
			a[cur._row*n + cur._col] = 2;
			return true;
		}
		a[cur._row*n + cur._col] = 2;

		//*****************************************上
		Pos next = cur;
		next._row--;
		if (CheckIsAccess(a, n, next))
		{
			cur = next;
			path.push(cur);
			continue;
		}

		//*****************************************下
		next = cur;
		next._row++;
		if (CheckIsAccess(a, n, next))
		{
			cur = next;
			path.push(cur);
			continue;
		}

		//*****************************************左
		next = cur;//左
		next._col--;
		if (CheckIsAccess(a, n, next))
		{
			cur = next;
			path.push(cur);
			continue;
		}

		//*****************************************右
		next = cur;
		next._col++;
		if (CheckIsAccess(a, n, next))
		{
			cur = next;
			path.push(cur);
			continue;
		}
		cur = path.top();
		path.pop();
	}
	return false;
}
void TestMaze()
{
	int a[N][N] = {};
	GetMaze((int *)a,N);
	PrintMaze((int *)a, N);
	stack<Pos> path;
	Pos entry = { 2, 0 };
	bool ret = MazePath((int *)a, N, entry, path);
	cout << "是否有通路？" << ret << endl;
	PrintMaze((int *)a, N);
}