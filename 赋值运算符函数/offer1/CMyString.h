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
	//�����쳣��ȫ���д�Ĵ��룬��ֹ�ͷ�ʵ��m_pData֮���ڴ治�㣬�޷����ٵķ���
	CMyString& operator=(const CMyString& str)
	{
		if (this != &str)
		{
			CMyString strTmp(str);//��������
			char* pTmp = strTmp.m_pData;
			m_pData = pTmp;
		}
		return *this;
	}
protected:
	char* m_pData;
};