/***********************************************************************
 * Header:
 *    WHOLENUMBER
 * Summary:
 *    This will contain the prototype for wholeNumber class.
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 ************************************************************************/

#ifndef WHOLENUMBER_H
#define WHOLENUMBER_H
#include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\list.h" //for Kenyon remove before submition
#include "list.h"
using std::ostream;
using std::ios;

// wholeNumber class
class wholeNumber
{
private:

public:
/**************************************************
 * Constructors and Destructors
 *************************************************/
   wholeNumber();
   wholeNumber(int num);
   wholeNumber(const wholeNumber & rhs);
   ~wholeNumber();


   list <int> x;
   //represents number in groups of 3 digits.
   wholeNumber operator << (const wholeNumber & rhs);
   wholeNumber operator += (const wholeNumber & rhs);
   
};

#endif // WHOLENUMBER_H


