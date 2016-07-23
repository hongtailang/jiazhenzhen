#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<iostream>
#include<string>
using namespace std;
class CMyString
{
public:
	CMyString(char* pData)
		:m_pData(pData)
	{}
	//CMyString(const CMyString& str);
	~CMyString();
	//CMyString& operator=(const CMyString& str)
	//{
	//	if (this == &str)
	//	{ 
	//		return *this;
	//	}
	//	delete[] m_pData;
	//	m_pData = NULL;
	//	m_pData = new char[strlen(str.m_pData) + 1];
	//	strcpy(m_pData, str.m_pData);
	//	return *this;
	//}
	//考虑异常安全后编写的代码，防止释放实例m_pData之后内存不足，无法开辟的风险
	CMyString& operator=(const CMyString& str)
	{
		if (this != &str)
		{
			CMyString strTmp(str);//拷贝构造
			char* pTmp = strTmp.m_pData;
			m_pData = pTmp;
		}
		return *this;
	}
protected:
	char* m_pData;
};