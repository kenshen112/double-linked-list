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
			this = rhs; //pointers are fun kids
		}

		class list <T> ::iterator
		{

		private:
			Node<T> *p;

		public:
			iterator()
			{
				p = nullptr;
			}

			iterator(Node <T> *pNew)
			{
				p = pNew
			}

			iterator(const iterator &rhs)
			{
				this = rhs; // agian with the refractoring
			}

			iterator operator=(const iterator &rhs)
			{
				this = rhs; // this will be refractored 
			}

			iterator operator++()
			{
				if (p->pNext)
				{
					p = p->pNext;
				}
			}

			iterator operator--()
			{
				if (p->pPrev)
				{
					p = p->pPrev;
				}
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
		void erase();
		void push_back(T item);
		void push_front(T item);
		void pop_back();
		void pop_front();

		list<T> ::iterator begin();
		list <T> ::iterator end();
		T front();
		T back();

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

		~list()
		{
			clear();
		}

	};


	template <class T>
	list<T>::iterator list<T>::begin()
	{
		return list<T>::iterator(p->pHead);
	}

	template <class T>
	list<T>::iterator list<T>::end()
	{
		return list<T>::iterator(nullptr);
	}


	template <class T>
	T list<T>::front()
	{
		if (empty())
		{
			throw("ERROR: unable to access data from an empty list");
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
			throw("ERROR: unable to access data from an empty list");
		}

		else
		{
			return (pHead->data + numElements);
		}
	}

	template <class T>
	void list<T>::clear()
	{
		numElements = 0;

		// To Clear the data out of the pointers
		pHead = nullptr;
		pTail = nullptr;

		// To explicitly free the malloc or rather newly allocated memory

		delete pHead;
		delete pTail;
	}

	template <class T>
	void list<T>::erase()
	{

	}


	// These seem flawed...

	template <class T>
	void list<T>::push_back(T item)
	{
		Node <T> *itemNode = new Node<T>(item); //making a new node
		


		if (pTail == nullptr)
		{
			pTail = itemNode;
		}

		else 
		{
			Node <T> *tempPrev = pTail;

			while (tempPrev->pPrev != nullptr)
			{
				tempPrev = tempPrev->pPrev;
			}

			tempPrev = itemNode;
		}

	}

	template <class T>
	void list<T>::push_front(T item)
	{
		Node <T> *itemNode = new Node<T>(item); //making a new node

		if (pHead == nullptr)
		{
			pHead = itemNode
		}

		else
		{
			Node<T> *tempFront = pHead;

			while (tempFront->pNext != nullptr)
			{
				tempFront = tempFront->pNext;
			}
			pHead = tempFront;
		}

	}

	template <class T>
	void list<T>::pop_front()
	{

	}

	template<class T>
	void list<T>::pop_back()
	{

	}

}