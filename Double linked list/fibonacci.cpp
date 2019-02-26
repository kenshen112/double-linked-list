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
#include "wholeNumber.h"

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

