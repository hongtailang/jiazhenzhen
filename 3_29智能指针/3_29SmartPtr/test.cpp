#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"SmartPtr.hpp"
using namespace std;
//int main()
//{
//	int *p = new int(1);
//	AutoPtr<int> ap1(p);
//	AutoPtr<int> ap2(p);
//	AutoPtr<int> ap3(p);
//	ap1 = ap2;
//
//	system("pause");
//	return 0;
//}
//template<typename T>
//class ScopedPtr
//{
//public:
//	ScopedPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	~ScopedPtr()
//	{
//		if (_ptr)
//		{
//			cout << "delete:" << _ptr << endl;
//			delete _ptr;
//		}
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//protected:
//	ScopedPtr(ScopedPtr<T>& sp);
//	ScopedPtr<T>& operator=(ScopedPtr<T>& sp);
//protected:
//	T* _ptr;
//};
//template<typename T>
//class SharedPtr
//{
//public:
//	SharedPtr(T* ptr)
//		:_ptr(ptr)
//	{}
//	SharedPtr(const SharedPtr<T>& sp)
//		:_ptr(sp._ptr)
//		, _pCount(sp._ptr)
//	{
//		++(*_pCount);
//	}
//	~SharedPtr()
//	{
//		_Release();
//	}
//	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
//	{
//		if (_ptr != sp._ptr)
//		{
//			_Release();
//			_ptr = sp._ptr;
//			_pCount = sp._pCount;
//			++(*_pCount);
//		}
//		return *this;
//	}
//	T& operator*()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//protected:
//	void _Release()
//	{
//		if (--(*pCount) == 0)
//		{
//			delete _ptr;
//			delete _pCount;
//		}
//	}
//protected:
//	T* _ptr;
//	long* _pCount;
//};
//template<typename T>
//class ScopedArray
//{
//public:
//	ScopedArray();
//	~ScopedArray();
//	ScopedArray<T>& operator[]();
//protected:
//
//
//};
//template<typename T>
//class SharedArray
//{
//public:
//	SharedArray();
//	~SharedArray();
//	SharedArray<T>& operator[]();
//protected:
//	T* _ptr;
//
//};
//void Test1()
//{
//	int* p = new int(1);
//	AutoPtr<int> ap(p);
//	if (1)
//	{
//		return;
//	}
//}
//void DoSomething()
//{
//	if (1)
//	{
//		throw 1;
//	}
//}
//void Test2()
//{
//	int* p = new int(1);
//	AutoPtr<int> ap(p);
//	DoSomething();
//	/*try
//	{
//		DoSomething();
//	}
//	catch (...)
//	{
//		delete p;
//		throw;
//	}
//	delete p;*/
//}
//int main()
//{
//	try
//	{
//		Test1();
//		Test2();
//	}
//	catch (...)
//	{
//		cout << "δ֪�쳣" << endl;
//	}
//	system("pause");
//	return 0;
//}
//struct A
//{
//	int _a;
//};
//int main()
//{
//	AutoPtr<int> ap1(new int(1));
//	
//	AutoPtr<int> ap2(ap1);
//	AutoPtr<int> ap3(new int(3));
//	ap3 = ap1;
//	//A* p4 = new A;
//	//p4->_a = 10;
//	AutoPtr<A> ap4(new A);
//	ap4->_a = 10;
//	system("pause");
//	return 0;
//
//}
int main()
{
	//TestScopedArray();
	TestSharedArray();
	//TestScopedPtr();
	system("pause");
	return 0;
}