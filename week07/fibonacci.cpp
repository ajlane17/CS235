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
#include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\list.h"
#include "list.h"        // for LIST
#include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\wholeNumber.h"
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
   // show the first serveral Fibonacci numbers
   int number;
   int numFib;
   list <wholeNumber> fibSequence;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;
   calcFibonacci(number, fibSequence);

   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   //calculates and displays the final/last number
   calcFinalFibonacci(number, fibSequence);
}

/************************************************
 * CALCFIBONACCI
 * Calculates the Fibonacci number(s)
 ***********************************************/
void calcFibonacci(int number, list <wholeNumber> & fibSequence)
{
   
    //wholeNumber fib1 = 0, fib2 = 1, fib3 = 1;
   
   for (int i = 0; i < number; i++)
   {
      if (i == 0 || i == 1)
      {
         //copmensates for first loop
         wholeNumber *numToAdd = new wholeNumber(1);
         fibSequence.push_front(*numToAdd);
         cout << "\t" << 1 << endl;;
      }
      else
      {
         list <wholeNumber> ::iterator it = fibSequence.begin();
         //do calculations
         wholeNumber *numToAdd = new wholeNumber(*it);
         it--;
         *numToAdd += *it;
         fibSequence.push_front(*numToAdd);
         //display number
         cout << "\t" << *numToAdd << endl;
      }
   }
}

/************************************************
 * CALCFIBONACCI
 * Calculates the final or last Fibonacci number
 ***********************************************/
void calcFinalFibonacci(int number, list <wholeNumber> & fibSequence)
{
   wholeNumber fib1 = 0, fib2 = 1, fib3 = 1;
   for (int i = 0; i < number; i++)
   {
      if (i == 0 || i == 1)
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


