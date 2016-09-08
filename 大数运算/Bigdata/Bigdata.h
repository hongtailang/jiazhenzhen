#pragma once
#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define UN_INIT 0xcccccccccccccccc
#define MAX_NUM 0x7FFFFFFFFFFFFFFF
#define MIN_NUM 0x8000000000000000

typedef long long INT64;


class BigData
{
	friend ostream& operator<<(ostream& os, BigData& bigData);
public:
	BigData(INT64 value = UN_INIT)
		:_value(value)
	{
		INT64toString();
	}
	BigData(char* pData);
	BigData operator+(const BigData& bigData);
	BigData operator-(const BigData& bigData);
	BigData operator*(const BigData& bigData);
	BigData operator/(const BigData& bigData);
public:
	bool IsINT64Overflow() const;   //是否溢出
	void INT64toString();           //将数转化为字符串
	bool IsLeftBig(char* pLeft, int LSize, char* pRight, int RSize); //pLeft>pRight
	int SubLoop(char* &pLeft, int &LSize, char* pRight, int RSize); //商
	string ADD(string left, string right);
	string SUB(string left, string right);
	string MUL(string left, string right);
	string DIV(string left, string right);

private:
	INT64 _value;
	string _strData;
};