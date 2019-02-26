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
#include "list.h"        // for LIST
#include "wholeNumber.h"
//#include <list> //std list
using namespace custom;
using std::cout;
using std::endl;
using std::cin;

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
                   *it + *ir;
                        
			if (*it >= 1000)
			{
                           *it - 1000;
                        
			if (*it >= 1000)
			{
				if (++it == NULL)
				{
                                   digits.push_back(1);
				}
				else
                                {
                                   *++it + 1; //make sure this would work with our list class. cuz it doesn't with the std::list class
                                }
			++it;
                        }
                        }
                }
        }
}
