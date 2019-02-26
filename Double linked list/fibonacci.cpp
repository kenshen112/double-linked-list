/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    <your names here>
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
//#include <list> //std list
using namespace custom;
using std::cout;
using std::endl;
using std::cin;

/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   // show the first serveral Fibonacci numbers
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   // your code to display the first <number> Fibonacci numbers
   int fib1 = 1;
   int fib2 = 1;
   int fib3 = 0;
   
   cout << fib1 << endl;
   cout << fib2 << endl;
   int counter = 0;

   while(counter < number)
   {
      fib3 = fib1 + fib2;
      cout <<  fib3 << endl;
      
      fib1 = fib2;
      fib2 = fib3;
      
      counter++;
   }

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;
   Number bigFib1 = 1;
   Number bigFib2 = 1;
   Number bigFibTotal = 0;
   
   // your code to display the <number>th Fibonacci number
   counter = 0;

   for(counter; counter <= number; counter++)
   {
      bigFibTotal += bigFib1;
	  Number numTemp = bigFib1;
      bigFib1 += bigFib2;
      bigFib2 = numTemp;
   }
   
}

/*******************************************
* Here follows methods for the Number class
********************************************/

/******************************************
* NUMBER DEFAULT CONSTRUCTOR
*******************************************/
Number::Number()
{
   //need to make sure the new List is made??
	//I don't think i actually need to put anything here???
}

/************************************************
* NUMBER NON-DEFAULT CASE ONE
*********************************************/
Number::Number(const Number &rhs)
{
	this->digits = rhs.digits; //relying on the list assignment operator here
}

/**************************************************
* NUMBER NON-DEFAULT CASE TWO
***************************************************/
Number::Number(int in)
{
	//i need to interpret the int into its seperate sets of three digits... and push them into the list...
	//   simple, i need to use modulus, in sets of 1000. :)
	//   three steps, one, is it equal to or bigger than 1K
	//                two, either way push that number to the back of digits.
	//			      three, divide by 1K to remove the three lowest digits from play.
	// actually, two should go first, then one, then three... or, we don't even need one!

	while (in != 0)
	{
		digits.push_back(in % 1000);
		in = (in / 1000);
	}

}

/************************************************
* NUMBER DESTRUCTOR
*************************************************/
Number::~Number()
{
	//Here we will make sure the memory for the list is freed// or rather don't, the list class should take care of itself???
}

/***********
* Operators
************/

/*******************************
* ADD ONTO OPERATOR
********************************/
Number Number::operator+=(Number &rhs)
{
   //add the sets of digits one at a time, watching for the case of carrying, use an       iterator?
   list<int>::iterator it = this->digits.begin();
//	std::list<int>::iterator ir = rhs.digits.begin();
	
   for (list<int>::iterator ir = rhs.digits.begin(); ir != rhs.digits.end(); ++ir)//as long as we earent out of things to add, keep going    
	{
           if (it == digits.end())
		{//if the numberwe are adding to is not big enoug, no big deal, just throw it on the end               
                   digits.push_back(*ir);
		}
		else
		{
<<<<<<< HEAD
                   *it + *ir;
                        
			if (*it >= 1000)
			{
                           *it - 1000;
=======
            *it += *ir;
                        
			if (*it >= 1000)
			{
                *it -= 1000;
>>>>>>> 6c78509dabf26532c9aea7d2a2c7add2aeddd7b6
				if (++it == NULL)
				{
                    digits.push_back(1);
				}
				else
<<<<<<< HEAD
                                   *++it + 1; //make sure this would work with our list class. cuz it doesn't with the std::list class
=======
                   *++it += 1; //make sure this would work with our list class. cuz it doesn't with the std::list class
>>>>>>> 6c78509dabf26532c9aea7d2a2c7add2aeddd7b6
			}
			++it;
		}
	}
}
