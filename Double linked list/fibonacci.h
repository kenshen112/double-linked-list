/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "list.h"
using namespace custom;

// the interactive fibonacci program
void fibonacci();

// the class definition for really big numbers
class Number
{
public:
	//constructor, copy constructor, destructor, nondefault construrctor
	Number();
	Number(Number *rhs);
	Number(int in);
	~Number();

	//Operators i need add, assignment, insertion(for displaying)
	Number operator += (Number & rhs);
	Number operator= (const Number & rhs)
	{
		digits = rhs.digits;

	}
	Number operator<<(Number rhs)
	{
		list<int> iterator rit = rhs.digits.rbegin();

		for (rit; rit != nullptr; rit.decrement())
		{
			cout << rit->data;
			if (rit->pPrev != nullptr)
			{
				cout << ',';
			}
		}
	}

private:
	list<int> digits;
};



#endif // FIBONACCI_H

