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

// the interactive fibonacci program
void fibonacci();

// the class definition for really big numbers
class Number
{
public:
	//constructor, copy constructor, destructor, nondefault construrctor
	Number();
	Number(Number rhs);
	Number(int in);
	~Number();

	//Operators i need add, assignment, insertion(for displaying)
	Number operator += (Number & rhs);
	Number & operator = (const Number & rhs);
	Number Operator << (Number rhs);

private:
	list<int> digits;
};

Number & Number::Operator = (const Number & rhs)

#endif // FIBONACCI_H

