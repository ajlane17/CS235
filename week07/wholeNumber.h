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
#include <list>
using std::ostream;
using std::ios;

// wholeNumber class
class wholeNumber
{
public:
/**************************************************
 * Constructors, Destructors
 *************************************************/
   wholeNumber();
   
   ~wholeNumber();

private:
   class list;
   //list & numGroup;

   //represents number in groups of 3 digits.
   int numGroup;

   /*ostream & operator << (ostream & out, wholeNumber & rhs)
   {

   }*/
   
};

#endif // WHOLENUMBER_H

