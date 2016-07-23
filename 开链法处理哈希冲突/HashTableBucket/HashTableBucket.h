#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
#include<vector>
using namespace std;
namespace First
{
	template<typename K,typename V>
	struct HashTableNode
	{
		HashTableNode(const K& key, const V& value)
							:_key(key)
							, _value(value)
							, _next(NULL)
		{}
		K _key;
		V _value;
		HashTableNode<K, V>* _next;
	};
	template<typename K,typename V>
	class HashTable
	{
		typedef HashTableNode<K, V> Node;
	public:
		HashTable()//无参构造
			:_size(0)
		{}

		HashTable(size_t capacity)//带参构造
			:_size(0)
		{
			_table.resize(_GetNextPrime(capacity));
		}

		HashTable(const HashTable<K, V>& ht)//拷贝构造
					:_size(0)//一定要初始化，可能会是随机值
		{
			_table.resize(ht._table.size());
			for (size_t i = 0; i < ht._table.size(); i++)
			{
				Node* cur = ht._table[i];
				while (cur)
				{
					this->Insert(cur->_key, cur->_value);
					cur = cur->_next;
				}
			}
		}
		HashTable<K,V>& operator=(const HashTable<K, V>& ht)//赋值运算符重载
		{
			if (this != &ht)
			{
				HashTable<K, V> tmp(ht);
				_table.swap(tmp._table);//交换两个表里面的内容和相关数据
				swap(_size, tmp._size);
				return *this;
			}
			return NULL;
		}
		bool Insert(const K& key, const V& value)//头插
		{
			_CheckCapacity();
			size_t index = _HashFunc(key, _table.size());
			//防冗余，判断节点在哈希表中是否已经存在
			Node* cur = _table[index];
			while (cur)
			{
				if (cur->_value == value)
				{
					return false;
				}
				cur = cur->_next;
			}
			//头插
			Node* tmp = new Node(key, value);
			tmp->_next = _table[index];
			_table[index] = tmp;
			_size++;
			return false;
		}

		Node* Find(const K& key, const V& value)//找节点
		{
			size_t index = _HashFunc(key, _table.size());
			Node* cur = _table[index];
			while (cur)
			{
				if (cur->_value == value)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return NULL;
		}

		bool Remove(const K& key)
		{
			//节点是否存在
			size_t index = _HashFunc(key, _table.size());
			Node* cur = _table[index];
			if (cur == NULL)
			{
				return false;
			}
			//删除头节点
			if (cur->_key == key)
			{
				_table[index] = cur->_next;
				delete cur;
				return true;
			}
			//删除中间节点
			Node* prev = cur;
			cur = cur->_next;
			while (cur)
			{
				if (cur->_key==key)
				{
					prev->_next = cur->_next;
					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			delete prev;
			prev = NULL;
			return true;
		}

		void Print()//打印哈希表
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				printf("Table[%d]->", i);
				while (cur)
				{
					cout << "[" << cur->_key << "," << cur->_value << "]" << "->";
					cur = cur->_next;
				}
				cout <<"end"<< endl;
			}
			cout << endl;
		}

	protected:
		size_t _HashFunc(const K& key, size_t capacity)//计算哈希地址
		{
			return key%capacity;
		}

		void _CheckCapacity()//检测容量
		{
			if (_size == _table.size())//负载因子等于1，每个位置挂了一个节点
			{
				size_t prime = _GetNextPrime(_size);
				vector<Node*> newTable;
				newTable.resize(prime);
				for (size_t i = 0; i < _size; i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						//摘节点
						Node* tmp = cur;
						cur = cur->_next;
						//头插，要重新计算节点在新表中的位置
						size_t index = _HashFunc(tmp->_key, newTable.size());
						tmp->_next = _table[index];
						_table[index] = tmp;
					}
					_table[i] = NULL;
				}
				_table.swap(newTable);
			}
		}

		size_t _GetNextPrime(size_t size)//取得素数
		{
			const int _PrimeSize = 28;
			static const unsigned long _PrimeList[_PrimeSize] =
			{
				53ul, 97ul, 193ul, 389ul, 769ul,1543ul, 3079ul, 6151ul,12289ul, 
				24593ul,49157ul, 98317ul, 196613ul, 393241ul,786433ul,
				1572869ul, 3145739ul, 6291469ul, 12582917ul,25165843ul,
				50331653ul, 100663319ul, 201326611ul, 402653189ul,
				805306457ul,1610612741ul, 3221225473ul, 4294967291ul
			};
			for (int i = 0; i < _PrimeSize; i++)
			{
				if (size < _PrimeList[i])
				{
					return _PrimeList[i];
				}
			}
			return _PrimeList[_PrimeSize - 1];
		}

	protected:
		vector<Node*> _table;
		size_t _size;//一共存的节点数
		//Node* _table[];
		//size_t _size;
		//size_t _capacity;
	};

	void TestInsert()
	{
		HashTable<int, int> ht;
		ht.Insert(1, 11);
		ht.Insert(0, 10);
		ht.Insert(3, 13);
		ht.Insert(4, 14);
		ht.Insert(5, 15);
		ht.Insert(5, 13);
		ht.Insert(1, 12);
		ht.Insert(53,9);
		ht.Print();
		HashTable<int, int> ht1(ht);
		ht1.Print();
		cout << endl;
		HashTableNode<int,int>* ret=ht.Find(106, 9);
		if (ret)
		{
			cout << "[key" << ret->_key << ",value" << ret->_value <<"]"<< endl;
		}
		cout << endl;
		ht.Remove(1);
		ht.Print();
	}
	void TestCapacity()
	{
		HashTable<int, int> ht;
		for (size_t i = 0; i < 54; i++)
		{
			ht.Insert(i, i);
		}
		ht.Insert(54, 54);
		ht.Print();
	}
}