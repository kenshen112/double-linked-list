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


