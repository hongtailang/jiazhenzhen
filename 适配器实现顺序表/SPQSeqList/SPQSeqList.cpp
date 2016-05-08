#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<typename T>
class SeqList
{
public:
	SeqList()
		:_data(NULL)
		, _size(0)
		, _capacity(0)
	{
		CheckCapacity();
	}
	~SeqList()
	{
		if (_data != NULL)
		{
			delete[] _data;
		}
	}
public:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			T* tmp = new T[2 * _capacity + 3];
			memcpy(tmp, _data, _size*sizeof(T));
			delete _data;
			_data = tmp;
			_capacity = 2 * _capacity + 3;
		}
	}
	void Print();
	void PushBack(const T& d);
	void PopBack();
	void PushFront(const T& d);
	void PopFront();
	int Find(const T& d);
	void Insert(int pos, const T& d);
	void Sort();
private:
	T* _data;
	int _size;
	int _capacity;
};
template<typename T>
void SeqList<T>::Print()
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		cout << _data[i] << " ";
	}
	cout << endl;
}
template<typename T>
void SeqList<T>::PushBack(const T& d)
{
	CheckCapacity();
	_data[_size] = d;
	_size++;
}
template<typename T>
void SeqList<T>::PopBack()
{
	if (_data != NULL)
	{
		_data[_size] = NULL;
		_size--;
	}
}
template<typename T>
void SeqList<T>::PushFront(const T& d)
{
	CheckCapacity();
	int i = 0;
	if (_data == NULL)
	{
		_data[0] = d;
		_size++;
	}
	else
	{
		for (i = _size - 1; i >= 0; i--)
		{
			_data[i + 1] = _data[i];
		}
		_data[0] = d;
		_size++;
	}
}
template<typename T>
void SeqList<T>::PopFront()
{
	if (_data != NULL)
	{
		int i = 0;
		for (i = 0; i <= _size - 1; i++)
		{
			_data[i] = _data[i + 1];
		}
		_size--;
	}
}
template<typename T>
int SeqList<T>::Find(const T& d)
{
	if (_data != NULL)
	{
		int i = 0;
		for (i = 0; i <= _size - 1; i++)
		{
			if (_data[i] == d)
			{
				return i;
			}
		}
	}
	return NULL;
}
template<typename T>
void SeqList<T>::Insert(int pos, const T& d)
{
	CheckCapacity();
	int i = 0;
	for (i = _size - 1; i >= pos; i--)
	{
		_data[i + 1] = _data[i];
	}
	_data[pos] = d;
	_size++;
}
template<typename T>
void SeqList<T>::Sort()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < _size - 1; i++)
	{
		for (j = 0; j < _size - 1 - i; j++)
		{
			if (_data[j] > _data[j + 1])
			{
				T tmp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = tmp;
			}
		}
	}
}
template< typename T,typename Container=SeqList<T> >
class Stack
{
public:
	void Push(const T& d)
	{
		con.PushBack(d);
	}
	void Pop()
	{
		con.PopBack();
	}
	void _Print()
	{
		con.Print();
	}
private:
	Container con;
};
int main()
{
	Stack<int> stack1;
	stack1.Push(1);
	stack1.Push(2);
	stack1.Push(3);
	stack1.Push(4);
	stack1._Print();
	stack1.Pop();
	stack1._Print();
	stack1.Pop();
	stack1._Print();
	system("pause");
	return 0;
}