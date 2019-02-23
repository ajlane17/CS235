/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the declaration or prototypes for fibonacci() 
 *    as well as other supporting functions
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
using namespace std;

//TODO: Need to use wholeNumber class to display
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
   cin  >> number;
   calcFibonacci(number);

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   //calculates and displays the final/last number
   calcFinalFibonacci(number);
}

/************************************************
 * CALCFIBONACCI
 * Calculates the Fibonacci number(s)
 ***********************************************/
void calcFibonacci(int number)
{
   
   int fib1 = 0, fib2 = 1, fib3 = 1;
   for (int i = 0; i < number; i++)
   {
      if (i == 0)
      {
         //copmensates for first loop
         cout << "\t" << 1 << endl;;
      }
      else
      {
         //do calculations
         fib3 = fib1 + fib2;
         fib1 = fib2;
         fib2 = fib3;
         //display number
         cout << "\t" << fib3 << endl;
      }
   }
}

/************************************************
 * CALCFIBONACCI
 * Calculates the final or last Fibonacci number
 ***********************************************/
void calcFinalFibonacci(int number)
{
   int fib1 = 0, fib2 = 1, fib3 = 1;
   for (int i = 0; i < number; i++)
   {
      if (i == 0)
      {
         //do nothing
      }
      else
      {
         //do calculations
         fib3 = fib1 + fib2;
         fib1 = fib2;
         fib2 = fib3;
      }
   }

   //display the final number
   cout << "\t" << fib3 << endl;
}


