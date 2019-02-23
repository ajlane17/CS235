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
// #include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\list.h"
#include "list.h"        // for LIST
// #include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\wholeNumber.h"
#include "wholeNumber.h"
using namespace std;

//TODO: Need to use wholeNumber class to display
/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   //Prompt
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   //calcualtes the fibonocci sequence
   calcFibonacci(number);

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   //calculates and displays the final/last number
   calcFinalFibonacci(number);
}

/************************************************
 * CALCFIBONACCI
 * Calculates and displays the Fibonacci number(s)
 ***********************************************/
void calcFibonacci(int number)
{
    wholeNumber fib1(0);
    wholeNumber fib2(1);
    wholeNumber fib3;
   if (number > 0)
   {
      cout << "\t" << fib2 << endl;
      
      for (int i = 0; i < number + 1; i++)
      {
         if (i > 1)
         {
            fib3 = fib2;
            fib2 += fib1;
            fib1 = fib3;
            cout << "\t" << fib2 << endl;
         }
      }
   }
}

/************************************************
 * CALCFIBONACCI
 * Calculates and displays the final or last 
 * Fibonacci number
 ***********************************************/
void calcFinalFibonacci(int number)
{
    wholeNumber fib1(0);
    wholeNumber fib2(1);
    wholeNumber fib3;
   if (number > 0)
   {
      for (int i = 0; i < number + 1; i++)
      {
         if (i > 1)
         {
            fib3 = fib2;
            fib2 += fib1;
            fib1 = fib3;
         }
      }
      cout << "\t" << fib2 << endl;
   }
}


