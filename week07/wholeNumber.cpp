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
wholeNumber wholeNumber::operator<<(const wholeNumber & rhs)
{
   return *this;
}

/**************************************************
 * add-onto operator
 *************************************************/
wholeNumber wholeNumber::operator+=(const wholeNumber & rhs)
{
   return *this;
}

