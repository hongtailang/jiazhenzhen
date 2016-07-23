#pragma once
#include<iostream>
using namespace std;
void ReplaceBlank(char string[], int length)
{
	if (string == NULL || length <= 0)
	{
		return;
	}
	int originaLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		originaLength++;
		if (string[i] == ' ')
		{
			numberOfBlank++;
		}
		i++;
	}
	int newLength = originaLength + 2 * numberOfBlank;
	if (newLength > length)//length为字符数组总容量
	{
		return;
	}
	int indexOfOriginal = originaLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew >= indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--]=string[indexOfOriginal];
		}
		indexOfOriginal--;
	}
	cout << string << endl;
}
void TestReplaceBlank()
{
	char str[20] = "we are happy.";//50为字符数组的容量，13为字符串的长度
	int length = sizeof(str)/sizeof(str[0]);
	//int length = strlen(str);//strlen求的是字符串的长度（不包含'\0'），sizeof求的是数组长度。
	ReplaceBlank(str, length);
	//cout <<  << endl;
}








