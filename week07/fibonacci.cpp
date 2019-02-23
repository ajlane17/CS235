/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
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
   int numFib;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> numFib;
   calcFibonacci(numFib);
   // your code to display the first <number> Fibonacci numbers

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   // your code to display the <number>th Fibonacci number
}

void calcFibonacci(int numFib)
{
   int fib1 = 0, fib2 = 1, fib3 = 1;
   for(int i = 0; i < numFib; i++)
   {
      fib3 = fib1 + fib2;
      fib1 = fib2;
      fib2 = fib3;
      cout << fib3 << endl;
   }
}


