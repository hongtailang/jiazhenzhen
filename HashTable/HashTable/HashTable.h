#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
using namespace std;
namespace First//œﬂ–‘ÃΩ≤‚
{
	enum State
	{
		EMPTY,
		DELETE,
		EXIST,
	}; 
	template<typename K>
	class HashTable
	{
	public:
		HashTable(size_t capacity=10)
			:_table(new K(capacity))
			, _states(new State[capacity])
			, _size(0)
			, _capacity(capacity)
		{
			for (size_t i = 0; i < _capacity; i++)
			{
				_states[i] = EMPTY;
			}
		}
		bool Insert(const K& key)
		{
			if (_size == _capacity)
			{
				return false;
			}
			size_t index=HashFunc(key);
			size_t start = index;
			while (_states[index] != EMPTY)
			{
				index++;
				if (index == _capacity)
				{
					index = 0;
				}
				if (index == start)
				{
					return false;
				}
			}
			_table[index] = key;
			_states[index] = EXIST;
			_size++;
			return true;
		}
		bool Find(const K& key)
		{
			size_t index = HashFunc(key);
			size_t start = index;
			while (_states[index] != EMPTY)
			{
				if (_states[index] == EXIST && _table[index] == key)
				{
						return true;
				}
				if (_states[index] == DELETE)
				{
					if (_table[index] == key)
					{
						return false;
					}
				}
				index++;
				if (index == _capacity)
				{
					index = 0;
				}
				if (start == index)
				{
					return false;
				}
			}
			return false;
		}
		size_t HashFunc(const K& key)
		{
			return key%_capacity;
		}
		bool Remove(const K& key)
		{
			size_t index = HashFunc(key);
			bool ret = Find(key);
			if (ret)
			{
				_states[index] = DELETE;
				_size--;
				return true;
			}
			return false;
		}
		void Print()
		{
			for (size_t i = 0; i < _capacity; i++)
			{
				printf("[%d:%d]--", _table[i], _states[i]);
			}
			cout << endl;
		}
	protected:
		void _CheckCapacity()
		{
			if (_size * 10 / _capacity >= 7)
			{
				HashTable<K> tmp;
				tmp._capacity = _capacity * 2;
				Swap(tmp);
			}
		}
		void Swap(HashTable<K>& ht)
		{
			swap(_table, ht._table);
			swap(_states, ht._states);
			swap(_size, ht._size);
			swap(_capacity, ht._capacity);
		}
	protected:
		K* _table;
		State* _states;
		size_t _size;
		size_t _capacity;
	};
	void TestHashTable()
	{
		HashTable<int> ht;
		ht.Insert(58);
		ht.Insert(39);
		ht.Insert(53);
		ht.Insert(9);
		ht.Insert(12);
		ht.Insert(6);
		ht.Insert(33);
		ht.Insert(56);
		ht.Print();
		ht.Find(39);
		ht.Remove(53);
		ht.Print();
		ht.Remove(53);
		ht.Print();
	}
}
namespace Second
{
	enum State
	{
		EMPTY,
		DELETE,
		EXIST,
	};
	template<typename K,typename V>
	struct HashTableNode
	{
		K _key;
		V _value;
	};
	template<typename K>
	struct __HashFunc
	{
		size_t operator()(const K& key)
		{
			return key;
		}
	};
	template<typename K, typename V, typename  HashFunc = __HashFunc<K>>
	class HashTable
	{
		typename HashTableNode<K, V> Node;
	public:
		HashTable(size_t capacity = 10)
			:_table(new K(capacity))
			, _states(new State[capacity])
			, _size(0)
			, _capacity(capacity)
		{
			for (size_t i = 0; i < _capacity; i++)
			{
				_states[i] = EMPTY;
			}
		}
		bool Insert(const K& key,const V& value)
		{
			_CheckCapacity();
			//if (_size == _capacity)
			//{
			//	return false;
			//}
			size_t index = HashFunc(key);
			//size_t start = index;
			while (_states[index] != EMPTY)
			{
				index++;
				if (index == _capacity)
				{
					index = 0;
				}
				//if (index == start)
				//{
				//	return false;
				//}
			}
			_table[index] = key;
			_states[index] = EXIST;
			_size++;
			return true;
		}
		Node* Find(const K& key)
		{
			size_t index = HashFunc(key);
			size_t start = index;
			while (_states[index] != EMPTY)
			{
				if (_states[index] == EXIST && _table[index] == key)
				{
					return true;
				}
				if (_states[index] == DELETE)
				{
					if (_table[index] == key)
					{
						return false;
					}
				}
				index++;
				if (index == _capacity)
				{
					index = 0;
				}
				if (start == index)
				{
					return false;
				}
			}
			return false;
		}
		size_t HashFunc(const K& key)
		{
			return key%_capacity;
		}
		bool Remove(const K& key)
		{
			size_t index = HashFunc(key);
			bool ret = Find(key);
			if (ret)
			{
				_states[index] = DELETE;
				_size--;
				return true;
			}
			return false;
		}
		void Print()
		{
			for (size_t i = 0; i < _capacity; i++)
			{
				printf("[%d:%d]--", _table[i], _states[i]);
			}
			cout << endl;
		}
	protected:
		void _CheckCapacity()
		{
			if (_size * 10 / _capacity >= 7)
			{
				HashTable<K> tmp;
				tmp._capacity = _capacity * 2;
				Swap(tmp);
			}
		}
		void Swap(HashTable<K>& ht)
		{
			swap(_table, ht._table);
			swap(_states, ht._states);
			swap(_size, ht._size);
			swap(_capacity, ht._capacity);
		}
	protected:
		Node* _table;
		State* _states;
		size_t _size;
		size_t _capacity;
	};
}
