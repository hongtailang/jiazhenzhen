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
		HashTable()//�޲ι���
			:_size(0)
		{}

		HashTable(size_t capacity)//���ι���
			:_size(0)
		{
			_table.resize(_GetNextPrime(capacity));
		}

		HashTable(const HashTable<K, V>& ht)//��������
					:_size(0)//һ��Ҫ��ʼ�������ܻ������ֵ
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
		HashTable<K,V>& operator=(const HashTable<K, V>& ht)//��ֵ���������
		{
			if (this != &ht)
			{
				HashTable<K, V> tmp(ht);
				_table.swap(tmp._table);//������������������ݺ��������
				swap(_size, tmp._size);
				return *this;
			}
			return NULL;
		}
		bool Insert(const K& key, const V& value)//ͷ��
		{
			_CheckCapacity();
			size_t index = _HashFunc(key, _table.size());
			//�����࣬�жϽڵ��ڹ�ϣ�����Ƿ��Ѿ�����
			Node* cur = _table[index];
			while (cur)
			{
				if (cur->_value == value)
				{
					return false;
				}
				cur = cur->_next;
			}
			//ͷ��
			Node* tmp = new Node(key, value);
			tmp->_next = _table[index];
			_table[index] = tmp;
			_size++;
			return false;
		}

		Node* Find(const K& key, const V& value)//�ҽڵ�
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
			//�ڵ��Ƿ����
			size_t index = _HashFunc(key, _table.size());
			Node* cur = _table[index];
			if (cur == NULL)
			{
				return false;
			}
			//ɾ��ͷ�ڵ�
			if (cur->_key == key)
			{
				_table[index] = cur->_next;
				delete cur;
				return true;
			}
			//ɾ���м�ڵ�
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

		void Print()//��ӡ��ϣ��
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
		size_t _HashFunc(const K& key, size_t capacity)//�����ϣ��ַ
		{
			return key%capacity;
		}

		void _CheckCapacity()//�������
		{
			if (_size == _table.size())//�������ӵ���1��ÿ��λ�ù���һ���ڵ�
			{
				size_t prime = _GetNextPrime(_size);
				vector<Node*> newTable;
				newTable.resize(prime);
				for (size_t i = 0; i < _size; i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						//ժ�ڵ�
						Node* tmp = cur;
						cur = cur->_next;
						//ͷ�壬Ҫ���¼���ڵ����±��е�λ��
						size_t index = _HashFunc(tmp->_key, newTable.size());
						tmp->_next = _table[index];
						_table[index] = tmp;
					}
					_table[i] = NULL;
				}
				_table.swap(newTable);
			}
		}

		size_t _GetNextPrime(size_t size)//ȡ������
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
		size_t _size;//һ����Ľڵ���
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