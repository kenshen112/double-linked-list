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
//#include "list.h"        // for LIST
using namespace std;


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
   
   cout << fib1 << ", " << fib2 << ", ";
   int counter = 0;

   while(counter < number)
   {
      fib3 = fib1 + fib2;
      cout <<  fib3 << ", ";
      
      fib1 = fib2;
      fib2 = fib3;
      
      counter++;
   }

   cout << endl;
   
   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;
   int fib1 = 1;
   int fib2 = 1;
   int fib3 = 0;

   cout << fib1 << ", " << fib2 << ", ";
   
   // your code to display the <number>th Fibonacci number
   while(fib3 <= number)
   {
      fib3 = fib1 + fib2;
      cout << fib3 << ", ";

      fib1 = fib2;
      fib2 = fib3;

   }
   
   cout << endl;
}

/*******************************************
* Here follows methods for the Number class
********************************************/

/******************************************
* NUMBER DEFAULT CONSTRUCTOR
*******************************************/
Number::Number()
{
	//I don't think i actually need to put anything here???
}

/************************************************
* NUMBER NON-DEFAULT CASE ONE
*********************************************/
Number::Number(Number rhs)
{
	this->digits = rhs.digits; //relying on the list assignment operator here
}

/**************************************************
* NUMBER NON-DEFAULT CASE TWO
***************************************************/
Number::Number(int in)
{
	//i need to interpret the int into its seperate sets of three digits... and push them into the list...
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
* ASSIGNMENT OPERATOR
********************************/
Number::operator += (Number rhs)
{
	//add the sets of digits one at a time, watching for the case of carrying, use an iterator?
	list<int> iterator it = this->digits.begin();
	list<int> iterator ir = rhs->digits.begin();
	
	for (ir; ir != nullptr; ir++)//as long as we earent out of things to add, keep going
	{
		if (it == nullptr)
		{//if the number we are adding to is not big enoug, no big deal, just throw it on the end
			digits.push_back(ir->data);
		}
		else
		{
			it->data += ir->data;

			if (it->data >= 1000)
			{
				it->data -= 1000;
				if (it->pNext == nullptr)
				{
					digits.push_back(1);
				}
				else
					it->pNext->data += 1;
			}
			it++;
		}
	}
}

/****************************
*NUMBER ASSIGNMENT OPERATOR
*****************************/


