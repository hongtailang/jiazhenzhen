#define _CRT_SECURE_NO_WARNINGS
#include"BigData.h"
void Test1()
{
	BigData bigData1("11111111111111111111");
	BigData bigData2("99999999999999999999999999");
	cout << bigData1 + bigData2 << endl;
}
void Test2()
{

}
int main()
{
	Test1();
	//Test2();
	system("pause");
	return 0;
}