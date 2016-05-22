#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
typedef long long INT64;
#define UN_INIT 0xCCCCCCCCCCCCCCCC//随机值
#define MAX_INT64 0x7FFFFFFFFFFFFFFF
#define MIN_INT64 0x8000000000000000
class BigData
{
	friend ostream& operator<<(ostream& os, const BigData& bigData);
public:
	BigData(INT64 value = UN_INIT);
	BigData(char* strData);
	BigData operator+(const BigData& bigData);
	BigData operator-(const BigData& bigData);
	BigData operator*(const BigData& bigData);
	BigData operator/(const BigData& bigData);

private:

	bool IsINT64Overflow()const;//const修饰的是this
	bool IsLeftBig(char* pLeft, int LSize, char* pRight, int RSize);
	int SubLoop(char* pLeft, int LSize, char* pRight, int RSize);
	string Add(string left, string right);
	string Sub(string left, string right);
	string Mul(string left, string right);
	string Div(string left, string right);
private:
	INT64 _value;
	string _strData;
};