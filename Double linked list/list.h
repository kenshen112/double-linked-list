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

		class iterator
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
				p = pNew;
			}

			iterator(const iterator &rhs);
			//{
				//this = rhs; // again with the refractoring
			//}

			iterator operator=(const iterator &rhs);
			//{
				//this = rhs; // this will be refractored 
			//}

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
				return *this == it;
			}

			bool operator!=(iterator it)
			{
				return *this != it;
			}

			T operator*()
			{
				return pHead->data;
			}

		};

		class reverse_iterator
		{

		private:
			Node<T> *p;

		public:
			reverse_iterator()
			{
				p = nullptr;
			}

			reverse_iterator(Node <T> *pNew)
			{
				p = pNew;
			}

			reverse_iterator(const reverse_iterator &rhs);
			//{
				//this = rhs; // again with the refractoring
			//}

			reverse_iterator operator=(const reverse_iterator &rhs);
			//{
				//this = rhs; // this will be refractored 
			//}

			reverse_iterator operator++()
			{
				if (p->pNext)
				{
					p = p->pNext;
				}
			}

			reverse_iterator operator--()
			{
				if (p->pPrev)
				{
					p = p->pPrev;
				}
			}

			bool operator==(reverse_iterator it)
			{
				return *this == it;
			}

			bool operator!=(reverse_iterator it)
			{
				return *this != it;
			}

			T operator*()
			{
				return this->data;
			}

		};

		list()
		{
			pHead = nullptr;
			pTail = nullptr;
			numElements = 0;
		}

		list(const list <T> &rhs);
		//{
			//this = rhs;
		//}
		//the copy constructor and the assignment operator should be basically the same
		// making a new version of the list that is passed to it. new, and seperate.
		list operator=(list rhs);
		//{
			//this = rhs; //pointers are fun kids //I don't think that how it should work - Ken
		//}

		//class iterator;
		//class reverse_iterator;


		int size() { return numElements; }

		bool empty() { return pHead == nullptr; }

		void clear();
		void push_back(T item);
		void push_front(T item);
		void pop_back();
		void pop_front();

		
		T front();
		T back();

		
		list<T> ::iterator insert(iterator & it, const T & data)
		{
			Node <T> *pNew;
			try
			{
				pNew = new Node<T>(data);
			}
			catch (std::bad_alloc)
			{
				throw "unable to allocate a new node for a list";
			}

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



		
		list <T> ::iterator find(const T & t);
		list <T> ::iterator erase(list <T> ::iterator it);
		list <T> ::iterator end();
		list <T> ::iterator begin();


		list <T> ::reverse_iterator rend();
		list <T> ::reverse_iterator rbegin();


		~list()
		{
			clear();
		}


	};


	template <class T>
	typename list<T>::iterator list<T>::begin()
	{
		return list<T>::iterator(p->pHead);
	}

	template<class T>
	 typename list<T>::reverse_iterator list<T>::rend()
	{
		return list<T>::reverse_iterator(p->pHead);
	}

	 template<class T>
	 typename list<T>::reverse_iterator list<T>::rbegin()
	 {
		 return list<T>::reverse_iterator(nullptr);
	 }

	template <class T>
	typename list<T>::iterator list<T>::end()
	{
		return list<T>::iterator(nullptr);
	}

	template<class T>
	typename list<T>::iterator list<T>::find(const T & t)
	{
		return list<T>::iterator();
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
			return pTail->data;
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
	typename list<T>::iterator list<T>::erase(list <T> ::iterator it)
	{

	}


	// These seem flawed...


	template <class T>
	void list<T>::push_back(T item)
	{
		Node <T> *itemNode;
		try
		{	
			itemNode = new Node<T>(item); //making a new node
		}
		catch (std::bad_alloc)
		{
			throw "ERROR: unable to allocate a new node for a list";
		}

		if (pTail == nullptr)
		{
			pTail = itemNode;
			pHead = itemNode;
		}

		else 
		{
			
			itemNode->pPrev = pTail;

			pTail = itemNode;
			numElements++;
		}

	}

	template <class T>
	void list<T>::push_front(T item)
	{
		Node <T> *itemNode;
		try
		{
			itemNode = new Node<T>(item); //making a new node
		}
		catch (std::bad_alloc)
		{
			throw "ERROR: unable to allocate a new node for a list";
		}

		if (pHead == nullptr)
		{
			pHead = itemNode;
			pTail = itemNode;
		}

		else
		{
			itemNode->pNext = pHead;
			pHead = itemNode;

			numElements++;
		}

	}

	template <class T>
	void list<T>::pop_front()
	{
		if (empty())
			return;
		pHead = pHead->pNext;
		delete pHead->pPrev;
		pHead->pPrev = nullptr;

	}

	template<class T>
	void list<T>::pop_back()
	{
		if (empty())
			return;
		pTail = pTail->pPrev;
		delete pTail->pNext;
		pTail->pNext = nullptr;

	}



	/*template <class T>
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
			p = pNew;
		}

		iterator(const iterator &rhs)
		{
			this = rhs; // again with the refractoring
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
			return this->data;
		}

	};

	template <class T>
	class list <T> ::reverse_iterator
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
			p = pNew;
		}

		iterator(const iterator &rhs)
		{
			this = rhs; // again with the refractoring
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
			return this->data;
		}

	};*/




}