/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain the declaration or prototypes for fibonacci() 
 *    as well as other supporting functions
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 **********************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H
#include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\list.h"
#include "list.h"        // for LIST

 /************************************************
  * FIBONACCI
  * The interactive function allowing the user to
  * display Fibonacci numbers
  ***********************************************/
void fibonacci();

/************************************************
 * CALCFIBONACCI
 * Calculates the Fibonacci number(s)
 ***********************************************/
void calcFibonacci(int numFib, list <wholeNumber> & fibSequence);

/************************************************
 * CALCFIBONACCI
 * Calculates the final or last Fibonacci number
 ***********************************************/
void calcFinalFibonacci(int number, list <wholeNumber> & fibSequence);

#endif // FIBONACCI_H

