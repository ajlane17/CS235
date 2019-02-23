/***********************************************************************
 * Implementation:
 *    WHOLENUMBER
 * Summary:
 *    This will contain the implementation for wholeNumber class.
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 **********************************************************************/

#include <iostream>
#include "wholeNumber.h"   // for wholeNumber prototypes
//#include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\list.h" //for Kenyon remove before submition
#include "list.h"
using namespace std;

/**************************************************
 * Default Constructor
 *************************************************/
wholeNumber::wholeNumber()
{
   
}

/**************************************************
 * Non-Default Constructor
 *************************************************/
wholeNumber::wholeNumber(unsigned int num)
{
   this->num.push_front(num);
}

/**************************************************
 * Copy Constructor
 *************************************************/
wholeNumber::wholeNumber(const wholeNumber & rhs)
{
   *this = rhs;
}

/**************************************************
 * Desctructor
 *************************************************/
wholeNumber::~wholeNumber()
{

}

/**************************************************
 * insertion operator
 *************************************************/
ostream & operator<<(ostream & out, const wholeNumber & rhs)
{  
   list <unsigned int> ::reverse_iterator it;    
   for (it = rhs.num.rbegin(); it != rhs.num.rend(); ++it)
   {
      if (it != rhs.num.rbegin())
      {
         if (*it < 10)
            out << ",00";
         else if (*it < 100)
            out << ",0";
         else
            out << ',';
      }
      out << *it;
   }

   return out;
}

/**************************************************
 * assignment operator
 *************************************************/
wholeNumber & wholeNumber :: operator = (const wholeNumber & rhs)
{
   this->num = rhs.num;
}

/**************************************************
 * add-onto operator
 *************************************************/
wholeNumber & wholeNumber :: operator+=(const wholeNumber & rhs)
{
   list <unsigned int> :: iterator itLHS = this->num.begin();
   list <unsigned int> :: iterator itRHS = rhs.num.begin();

   unsigned int remainder = 0;
   unsigned int sum;

   while (itLHS != NULL)
   {
      if  (itRHS != NULL)
         sum = *itLHS + *itRHS + remainder;
      else
         sum = *itLHS + remainder;

      if (sum > 999)
      {
         remainder = sum / 1000;
         sum = sum % 1000;
      }
      else 
      {
         remainder = 0;
      }
      *itLHS = sum;
      itLHS++;
      if (itRHS != NULL)
         itRHS++;
   }
   if (remainder > 0)
      this->num.push_back(remainder);

   return *this;
}


