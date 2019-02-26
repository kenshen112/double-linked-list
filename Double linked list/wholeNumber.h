/***********************************************************************
 * Header:
 *    WHOLE NUMBERS
 * Summary:
 *    This will contain the whole Number class. You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef WHOLENUMBER_H
#define WHOLENUMBER_H
#include <iostream> // Always rember kids iostream is important ;) Tim
#include "list.h"


using namespace custom;


// the class definition for really big numbers
class Number
{
public:
	//constructor, copy constructor, destructor, nondefault construrctor
	Number();
	Number(const Number &rhs);
	Number(int in);
	~Number();

	//Operators i need add, assignment, insertion(for displaying)
	Number operator += (Number & rhs);

	Number operator= (const Number & rhs)
	{
		digits = rhs.digits;
		return *this;
	}
	Number operator<<(Number rhs)
	{
           //std::list<int>::reverse_iterator rit = rhs.digits.rbegin(); // rBegin belongs to reverse_iterator no valid conversion to iterator.

		for ( list<int>::reverse_iterator rit = rhs.digits.rbegin(); rit != rhs.digits.rend(); ++rit)
		{
			std::cout << *rit; // were not using std nor should we, this is the proper C++ way to call anything from std or custom for that instance, Tim.
			if (rit != rhs.digits.rend())
			{
				std::cout << ',';
			}
		}
	}

private:
	list<int> digits;
};



#endif // WHOLENUMBER_H

