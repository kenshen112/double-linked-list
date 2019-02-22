#pragma once
#include "node.h"

namespace custom
{
	template <class T>
	class list
	{

	private:
		Node <T> *pHead;
		Node <T> *pTail;
		int numElements;

	public:
		list()
		{
			pHead = nullptr;
			pTail = nullptr;
			numElements = 0;
		}

		list(list rhs)
		{

		}

		list operator=(list rhs)
		{

		}

		class list <T> ::iterator
		{

		private:
			Node<T> *p;

		public: 
			iterator()
			{

			}

			iterator(Node <T> *p)
			{

			}

			iterator(const iterator &rhs)
			{

			}

			iterator operator=(const iterator &rhs)
			{

			}

			iterator operator++()
			{

			}

			iterator operator--()
			{

			}

			bool operator==(iterator it)
			{
				return this == rhs;
			}

			bool operator!=(iterator it)
			{
				return this != rhs;
			}

			T operator*()
			{

			}

		}

		int size() { return numElements; }

		bool empty() { return pHead == nullptr; }

		void clear();
		void push_back(T item);
		void push_front(T item);
		
		friend iterator list <T> ::insert(iterator & it, const T & data)
		{
			Node <T> *pNew = new Node(data);

			if (it != NULL)
			{
				pNew->pNext = it;
				pNew->pPrev = it.pPrev;
				it.pPrev = pNew;

				if (pNew->pPrev != nullptr)
				{
					pNew->pPrev->pNext = pNew;
				}
			}

			return pNew;
		}

		T front();

		T back();


		~list()
		{

		}

	};

	template <class T>
	T list<T>::front()
	{
		if (empty())
		{
			throw("empty list");
		}

		else
		{
			return pHead->data;
		}
	}

	template <class T>
	T list<T>::back()
	{
		if (empty())
		{
			throw("empty list");
		}

		else
		{
			return (pHead->data + numElements);
		}
	}

	template <class T>
	void list<T>::clear()
	{

	}

	template <class T>
	void list<T>::push_back(T item)
	{

	}

	template <class T>
	void list<T>::push_front(T item)
	{

	}



}