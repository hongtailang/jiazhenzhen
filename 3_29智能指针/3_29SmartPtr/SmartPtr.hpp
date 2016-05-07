#define _CRT_SECURE_NO_WARNINGS
#pragma once
template <typename T>
class AutoPtr
{
public:
	AutoPtr(T* ptr)
		:_ptr(ptr)
	{}
	AutoPtr(AutoPtr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = NULL;
	}
	AutoPtr<T>& operator=(AutoPtr<T>& ap)
	{
		if (this != &ap)
		{
			delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = NULL;
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
	~AutoPtr()
	{
		if (_ptr)
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}
	}
protected:
	T* _ptr;
};
void TestAutoPtr()
{
	AutoPtr<int> ap1(new int(1));	
	AutoPtr<int> ap2(ap1);
	AutoPtr<int> ap3(new int(3));
	ap3 = ap1;
	A* p4 = new A;
	p4->_a = 10;
	AutoPtr<A> ap4(new A);
	ap4->_a = 10;
}


template<typename T>
class ScopedPtr
{
public:
	ScopedPtr(T* ptr)
		:_ptr(ptr)
	{}
	~ScopedPtr()
	{
		if (_ptr)
		{
			cout << "delete:" << _ptr << endl;
			delete _ptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
protected:
	ScopedPtr(ScopedPtr<T>& sp);
	ScopedPtr<T>& operator=(ScopedPtr<T>& sp);
protected:
	T* _ptr;
};
void TestScopedPtr()
{
	ScopedPtr<int> sp1(new int(1));
	ScopedPtr<int> sp2(sp1);
}


template<typename T>
class SharedPtr
{
public:
	SharedPtr(T* ptr)
		:_ptr(ptr)
		, _pCount(new long(1))
	{}
	SharedPtr(const SharedPtr<T>& sp)
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)
	{
		++(*_pCount);
	}
	~SharedPtr()
	{
		_Release();
	}
	SharedPtr<T>& operator=(const SharedPtr<T>& sp)
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
			delete _ptr;
			delete _pCount;
		}
	}

protected:
	T* _ptr;
	long* _pCount;
};
void TestSharedPtr()
{
	SharedPtr<int> sp1(new int(1));
	SharedPtr<int> sp2(sp1);
	SharedPtr<int> sp3(sp2);
	cout << "sp1:" << sp1.UseCount() << endl;
	cout << "sp2:" << sp1.UseCount() << endl;
	cout << "sp3:" << sp1.UseCount() << endl<<endl;


	sp1 = sp1;
	sp1 = sp2;

	cout << "sp1:" << sp1.UseCount() << endl;
	cout << "sp2:" << sp1.UseCount() << endl;
	cout << "sp3:" << sp1.UseCount() << endl << endl;

	SharedPtr<int> sp4(new int(2));
	sp1 = sp3;
	cout << "sp1:" << sp1.UseCount() << endl;
	cout << "sp2:" << sp1.UseCount() << endl;
	cout << "sp3:" << sp1.UseCount() << endl;
	cout << "sp4:" << sp1.UseCount() << endl << endl;
}

template<typename T>
class ScopedArray
{
public:
	ScopedArray(T* ptr)
		:_ptr(ptr)
	{}
	~ScopedArray()
	{
		if (_ptr)
		{
			delete[] _ptr;
		}
	}
	T& operator[](size_t index)
	{
		return _ptr[index];
	}
protected:
	ScopedArray(const ScopedArray<T>& sp);
	ScopedArray<T>& operator=(const ScopedArray<T>& sp);
protected:
	T* _ptr;
};
struct A
{
	int _a;
};
void TestScopedArray()
{
	ScopedArray<A> sa(new A[10]);
}

template<typename T>
class SharedArray
{
public:
	SharedArray(T* ptr)
		:_ptr(ptr)
		, _pCount(new long(1))
	{}
	~SharedArray()
	{
		if (_ptr)
		{
			delete[] _ptr;
		}
	}
	SharedArray(const SharedArray<T>& sp)
		               :_ptr(sp._ptr)
		               , _pCount(sp._pCount)
	{
			++(*_pCount);
	}
	SharedArray<T>& operator=(const SharedArray<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			_Release();
			_ptr = sp._ptr;
			//memcpy(_ptr, sp._ptr, sizeof());
			_pCount = sp._pCount;
			++(*_pCount);
		}
		return *this;
	}
	T& operator[](size_t index)
	{
		return _ptr[index];
	}
protected:
	void _Release()
	{
		if (--(*_pCount) == 0)
		{
			delete _ptr;
			delete _pCount;
		}
	}
protected:
	T* _ptr;
	long* _pCount;
};
void TestSharedArray()
{
	SharedArray<int> sa1(new int(10));
	SharedArray<int> sa2(sa1);
	SharedArray<int> sa3(new int(10));
	SharedArray<int> sa4(new int(10));
	sa4 = sa3;

}