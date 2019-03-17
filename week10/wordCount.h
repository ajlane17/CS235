/***********************************************************************
* Header:
*    WORD COUNT
* Summary:
*    This will contain just the prototype for the wordCount()
*    function
* Author
*    Adrian Lane, Ethan Holden, Kenyon Bunker
************************************************************************/

#ifndef WORD_COUNT_H
#define WORD_COUNT_H
#include <string>

class Count
{
   public:
      Count() : count(0)                                         {}
      Count & operator = (Count & rhs)  { this->count =rhs.count; }
      int getCount() const                        { return count; }
      void setCount(int count)             { this->count = count; }
   private:
      int count;

};

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount();

#endif // WORD_COUNT_H

