#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define DEFAULT_CAPACITY 7
#define DEFAULT_INC 9
typedef int DataType;//如果后期要改类型，只用改这里，比较简单
class SeqList
{
public:
	friend ostream& operator<<(ostream& os, const SeqList& s);
	SeqList(int capacity = DEFAULT_CAPACITY)
		:_capacity(capacity)
		, _size(0)
		, _pdata(0)
	{
		_pdata = new DataType[_capacity];
	}
	SeqList(const SeqList& s)
		:_size(s._size)
		, _capacity(s._capacity)
	{
		_pdata = new DataType[_capacity];
		memcpy(_pdata, s._pdata, _size*sizeof(DataType));
	}
	~SeqList()
	{
		if (_pdata != NULL)
		{
			delete[] _pdata;
		}
	}
	SeqList& operator=(const SeqList& s)
	{
		if (this != &s)
		{
			delete[] _pdata;
			_pdata = new DataType[s._capacity];
			memcpy(_pdata, s._pdata, s._size*sizeof(DataType));
			_size = s._size;
			_capacity = s._capacity;
		}
		return *this;
	}
	SeqList& operator[](const SeqList& s);
public:
	void PushBack(const DataType& d)
	{
		_CheckCapacity();
		_pdata[_size++] = d;
	}
	void PushFront(const DataType& d)//对数字的引用是常引用，所以必须加上const
	{
		_CheckCapacity();
		int start = _size - 1;
		while (start >= 0)
		{
			_pdata[start + 1] = _pdata[start];
			start--;
		}
		_pdata[0] = d;
		_size++;
	}
	void PopBack()
	{
		if (_pdata != NULL)
		{
			_size--;
		}
	}
	void PopFront()//const DataType& d
	{
		if (_pdata != NULL)
		{
			int i = 0;
			for (i = 0; i < _size - 1; i++)
			{
				_pdata[i] = _pdata[i + 1];
			}
			_size--;
		}
	}
	int Find(const DataType& d)
	{
		int i = 0;
		for (i = 0; i < _size; i++)
		{
			if (_pdata[i] == d)
			{
				return i;
			}
		}
		return - 1;
	}
	void Remove(const DataType& d)
	{
		int pos = Find(d);
		if (pos != -1)
		{
			int i = 0;
			for (i = pos; i < _size; i++)
			{
				_pdata[i] = _pdata[i + 1];
			}
			_size--;
		}
	}
	void Reverse()
	{
		int start = 0;
		int end = _size - 1;
		while (start < end)
		{
			DataType tmp = _pdata[start];
			_pdata[start] = _pdata[end];
			_pdata[end] = tmp;
			start++; 
			end--;
		}
	}
	void Insert(int pos, const DataType& d)
	{
		if ((pos<_size) && (pos>0))
		{
			_CheckCapacity();
			int i = 0;
			for (i = _size; i >pos; i--)
			{
				_pdata[i] = _pdata[i-1];
			}
			_pdata[pos] = d;
		    _size++;
		}
	}
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			DataType* tmp = new DataType[_capacity + DEFAULT_INC];
			memcpy(tmp, _pdata, _size*sizeof(DataType));//最后一个参数是拷贝字节数
			delete[] _pdata;
		    _pdata=tmp;
			_capacity = _capacity + DEFAULT_INC;
		}
	}
private:
	DataType* _pdata;
	int _size;//当前有多少数据
	int _capacity;//当前容量
};
ostream& operator<<(ostream& os, const SeqList& s)
{
	int i = 0;
	for (i = 0; i < s._size; i++)
	{
		os << s._pdata[i]<<" ";
	}
	os << endl;
	return os;
}

int main()
{
	SeqList seqlist1;
	seqlist1.PushBack(1);
	seqlist1.PushBack(2);
	seqlist1.PushBack(3);
	seqlist1.PushBack(4);
	seqlist1.PushFront(5);
	seqlist1.PushFront(6);
	seqlist1.PushFront(7);
	seqlist1.Reverse();
	seqlist1.Insert(2, 0);
	seqlist1.Remove(2);
	seqlist1.PushFront(8);
	seqlist1.PopFront();
	seqlist1.PopBack();
	cout << seqlist1;
	SeqList seqlist2(seqlist1);
	SeqList seqlist3;
	seqlist3 = seqlist1;
	cout << seqlist2;
	cout << seqlist3;
	system("pause");
	return 0;
}