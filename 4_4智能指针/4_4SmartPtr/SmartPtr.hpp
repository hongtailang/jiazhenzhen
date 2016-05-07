#define _CRT_SECURE_NO_WARNING
#include<iostream>
using namespace std;
//template<typename T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr)
//		:_ptr(ptr)
//		, _owner(true)
//	{}
//	AutoPtr(AutoPtr<T>& ap)
//		:_ptr(ap._ptr)
//		, _owner(true)
//	{
//		ap._owner = false;
//	}
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		if (this != &ap)
//		{
//			_ptr = ap._ptr;
//			ap._owner = false;
//			_owner = true;
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
//	~AutoPtr()
//	{
//		if (_owner)
//		{
//			delete _ptr;
//		}
//	}
//protected:
//	T* _ptr;
//	bool _owner;
//};
//
//void TestAutoPtr()
//{
//	AutoPtr<int> ap1(new int(10));
//	AutoPtr<int> ap2(ap1);
//	AutoPtr<int> ap3(new int(10));
//	ap3 = ap2;
//}

//template<typename T>
//class SharedPtr
//{
//public:
//
//protected:
//	T* _ptr;
//};


//#include<memory>
//struct Node
//{
//	Node* _next;
//	Node* _prev;
//	shared_ptr<Node> _next;
//	shared_ptr<Node> _prev;
//	weak_ptr<Node> _next;
//	weak_ptr<Node> _prev;
//
//	~Node()
//	{
//		cout << "delete" << this << endl;
//	}
//};
//void TestSharedPtr()
//{
//	shared_ptr<int> sp1(new int(1));
//	shared_ptr<int> sp2(sp1);
//	cout << "sp1:" << sp1.use_count() << endl;
//	cout << "sp2:" << sp2.use_count() << endl;
//
//	shared_ptr<Node> cur(new Node());
//	shared_ptr<Node> next(new Node());
//	cout << "cur:" << cur.use_count() << endl;
//	cout << "next:" << next.use_count() << endl;
//
//	cur->_next = next;
//	next->_prev = cur;
//
//	cout << "赋值后" << endl;
//	cout << "cur:" << cur.use_count() << endl;
//	cout << "next:" << next.use_count() << endl;
//}


//struct Free
//{
//	void operator()(void* ptr)
//	{
//		cout << "Free:" << ptr << endl;
//		free(ptr);
//	}
//};
//
//
//struct Fclose
//{
//	void operator()(void* ptr)
//	{
//		cout << "Fclose" << ptr << endl;
//		fclose((FILE*)ptr);
//	}
//};
//void TestSharedPtr()
//{
//	int *p1 = (int *)malloc(sizeof(int)* 10);
//	shared_ptr<int> sp1(p1,Free());//可能会发生内存泄漏
//	Fclose f;
//	FILE* p2 = fopen("test.cpp", "r");
//	shared_ptr<FILE> sp2(p2,Fclose());//出作用域释放文件，发生崩溃
//}

//仿函数 其实是一个类
//template<typename T>
//struct  Less
//{
//	bool operator()(const T& l, const T& r)
//	{
//		return l < r;
//	}
//};

//void TestLess()
//{
//	Less<int> less;
//	cout << less(1, 2) << endl;
//}
template<typename T>
struct DefaultDel
{
	void operator()(T* ptr)
	{
		delete ptr;
	}
};
template<typename T,typename D=DefaultDel<T>>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _pCount(new long(1))
	{}

	SharedPtr(T* ptr,D del)
		:_ptr(ptr)
		, _pCount(new long(1))
		, _del(del)
	{}
	SharedPtr(const SharedPtr<T,D>& sp)
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)
	{
		++(*_pCount);
	}
	~SharedPtr()
	{
		_Release();
	}
	SharedPtr<T,D>& operator=(const SharedPtr<T,D>& sp)
	{
		if (_ptr != sp._ptr)
		{
			_Release();
			_ptr = sp._ptr;
			_pCount = sp._pCount;
			++(*_pCount);
		}
		return *this;
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
public:
	void UseCount()
	{
		return *_pCount;
	}
	void GetPtr()
	{
		return _ptr;
	}
protected:
	void _Release()
	{
		if (--(*_pCount) == 0)
		{
			//delete _ptr;
			_del(_ptr);//_del是一个仿函数的对象
			delete _pCount;
		}
	}

protected:
	T* _ptr;
	long* _pCount;
	D _del;
};
//
//template<typename T>
//struct Free
//{
//	void operator()(T* ptr)
//	{
//		free(ptr);
//	}
//};
//void TestDeleter()
//{
//	SharedPtr<int, DefaultDel<int>> sp1(new int(1));
//	SharedPtr<int, Free<int>> sp2((int *)malloc(sizeof(int)));
//	SharedPtr<int> sp3(new int(1));
//	SharedPtr<int, Free<int>> sp4((int *)malloc(sizeof(int)));
//}


AutoPtr<int> ap1(new int(1));
if (某个条件)
{
	AutoPtr<int> ap2(ap1);
}