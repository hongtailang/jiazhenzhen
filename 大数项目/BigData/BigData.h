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
	string Add(string left, string right);
	string Sub(string left, string right);
private:
	bool IsINT64Overflow()const;//const修饰的是this
private:
	INT64 _value;
	string _strData;
};