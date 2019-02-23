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
#include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week07\list.h" //for Kenyon remove before submition
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
wholeNumber::wholeNumber(int num)
{

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
   list <int> ::reverse_iterator it;    
   for (it = rhs.num.rbegin(); it != rhs.num.rend(); ++it)
   {
      if (it != rhs.num.rbegin())
      {
         out << ',';
      }
      out << *it;
   }

   return out;
}

/**************************************************
 * add-onto operator
 *************************************************/
wholeNumber wholeNumber::operator+=(const wholeNumber & rhs)
{
   int sum;
   int carry;
   list <int> ::iterator itLHS = this->num.begin();
   list <int> ::iterator itRHS = rhs.num.begin();

   //this->num.begin + rhs.num.begin;

   while (itLHS != NULL && itRHS != NULL)
   {
      std::cout << *itLHS << " + " << *itRHS << std::endl;
      sum = *itLHS + *itRHS;
      std::cout << sum << std::endl;
      itLHS++, itRHS++;
   };

   //*this = *this + rhs;
   return *this;
}

/**************************************************
 * add operator
 *************************************************/
wholeNumber wholeNumber::operator+(const wholeNumber & rhs)
{
   

   return *this;
}


