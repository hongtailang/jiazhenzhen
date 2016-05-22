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
		char* pData = (char*)bigData._strData.c_str();//string�����ĳ�Ա����c_str()��string ����ת����c�е��ַ�����ʽ,c_str����ֵΪconst char*
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

BigData::BigData(char* pData)//��pData��ʼ��_strData
{
	assert(pData);
	char cSymbol = pData[0];
	//ȷ������λ
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
	//ȥ��pDataǰ���0
	while (*pData == '0')
	{
		pData++;
	}
	//ת��
	_strData.resize(strlen(pData) + 1);//���¿��ٿռ�
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
	char cStep = 0;//��Ž�λ
	string strRet;//��ż���������
	if (LSize < RSize)//�Ѿ���ֵ�����������left��
	{
		swap(left, right);
		swap(LSize, RSize);
	}
	strRet.resize(LSize + 1);//���·���ռ�

	//��λ���
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
	//������û�����
	if ((!IsINT64Overflow()) && (!bigData.IsINT64Overflow()))
	{
		if (_strData[0] != bigData._strData[0])//���
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
	//���������
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

