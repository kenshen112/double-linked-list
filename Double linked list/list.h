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

		int size() { return numElements; }

		bool empty() { return pHead == nullptr; }

		void clear();
		void push_back(T item);
		void push_front(T item);
		
		T front();

		T back();


		~list()
		{

		}

	};
}