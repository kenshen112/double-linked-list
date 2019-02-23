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
#include <iostream> // Always rember kids iostream is important ;) Tim

#include <list>
//using namespace custom;

// the interactive fibonacci program
void fibonacci();

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

	}
	Number operator<<(Number rhs)
	{
		std::list<int>::reverse_iterator rit = rhs.digits.rbegin();

		for (rit; rit != nullptr; rit--)
		{
			std::cout << rit->data; // were not using std nor should we, this is the proper C++ way to call anything from std or custom for that instance, Tim.
			if (rit->pPrev != nullptr)
			{
				std::cout << ',';
			}
		}
	}

private:
	list<int> digits;
};



#endif // FIBONACCI_H

