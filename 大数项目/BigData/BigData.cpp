#define _CRT_SECURE_NO_WARNINGS
#include"BigData.h"
ostream& operator<<(ostream& os, const BigData& bigData)
{
	if (!bigData.IsINT64Overflow())
	{
		os << bigData._value;
	}
	else
	{
		char* pData = (char*)bigData._strData.c_str();//string类对象的成员函数c_str()把string 对象转换成c中的字符串样式,c_str返回值为const char*
		if (bigData._strData[0] == '+')
		{
			pData++;
		}
		os << pData;
	}
	return os;
}

BigData::BigData(INT64 value)
						:_value(value)
{}

BigData::BigData(char* pData)//用pData初始化_strData
{
	assert(pData);
	char cSymbol = pData[0];
	//确定符号位
	if ((cSymbol >= '0') && (cSymbol <= '9'))
	{
		cSymbol = '+';
	}
	else if ((cSymbol == '+') || (cSymbol == '-'))
	{
		pData++;
	}
	else
	{
		_value = UN_INIT;
		return;
	}
	//去除pData前面的0
	while (*pData == '0')
	{
		pData++;
	}
	//转化
	_strData.resize(strlen(pData) + 1);//重新开辟空间
	_strData[0] = cSymbol;
	_value = 0;
	int iCount = 1;
	while ((*pData >= '0') && (*pData <= '9'))
	{
		_strData[iCount++] = *pData;
		_value = _value * 10 + *pData - '0';
		pData++;
	}
	if (cSymbol == '-')
	{
		_value = 0 - _value;
	}
	_strData.resize(iCount);
}
bool BigData::IsINT64Overflow()const
{
	string temp("+9223372036854775807");
	if (_strData[0] == '-')
	{
		temp = "-9223372036854775808";
	}
	if (_strData.size() < temp.size())
	{
		return false;
	}
	else if ((_strData.size() == temp.size()) && (_strData <= temp))
	{
		return false;
	}
	return true;
}
bool BigData::IsLeftBig(char* pLeft, int LSize, char* pRight, int RSize)
{

}
int BigData::SubLoop(char* pLeft, int LSize, char* pRight, int RSize)
{

}
string BigData::Add(string left, string right)
{
	int LSize = left.size();
	int RSize = right.size();
	char cStep = 0;//存放进位
	string strRet;//存放加完后的数据
	if (LSize < RSize)//把绝对值大的数保存在left中
	{
		swap(left, right);
		swap(LSize, RSize);
	}
	strRet.resize(LSize + 1);//重新分配空间

	//逐位相加
	for (int i = 1; i < LSize; i++)
	{
		char cRet = left[LSize - i] + cStep - '0';
		if (i < RSize)
		{
			cRet += right[RSize - i] - '0';
		}
		strRet[LSize + 1 - i] = cRet % 10 + '0';
		cStep = cRet / 10;
	}
	strRet[1] = cStep + '0';
	strRet[0] = left[0];
	return strRet;
}

string BigData::Sub(string left, string right)
{
	return NULL;
}

string BigData::Mul(string left, string right)
{

}
string BigData::Div(string left, string right)
{

}
BigData BigData::operator+(const BigData& bigData)
{
	//操作数没有溢出
	if ((!IsINT64Overflow()) && (!bigData.IsINT64Overflow()))
	{
		if (_strData[0] != bigData._strData[0])//异号
		{
			return BigData(_value + bigData._value);
		}
		else
		{
			if (((_strData[0] == '+')&&(MAX_INT64 - _value >= bigData._value)) || ((_strData[0] == '-')&&(MIN_INT64 - _value <= bigData._value)))
			{
				return BigData(_value + bigData._value);
			}
		}
	}
	//操作数溢出
	if (_strData[0] == bigData._strData[0])
	{
		return BigData((char*)Add(_strData, bigData._strData).c_str());
	}
	return BigData((char*)Sub(_strData, bigData._strData).c_str());
}
BigData BigData::operator-(const BigData& bigData)
{

}
BigData BigData::operator*(const BigData& bigData)
{

}
BigData BigData::operator/(const BigData& bigData)
{

}

