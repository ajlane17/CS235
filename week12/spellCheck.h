/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Kirby, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#ifndef SPELL_CHECK_H
#define SPELL_CHECK_H
#include "hash.h"
#include "vector.h"
#include <iostream>      // for CIN and COUT
#include <string>        // for STRING
#include <fstream>
#include <algorithm>
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using std::transform;
 /****************************************
  * S HASH
  * A simple hash of strings
  ****************************************/
class SHash : public Hash <string>
{
   public:
      SHash(int numBuckets) 
         throw (const char *) : Hash <string> (numBuckets) {}
      SHash(const SHash & rhs) 
         throw (const char *) : Hash <string> (rhs)        {}

      // Hash function for words - As was pointed out in the 
      // book, using the remainder from taking the ASCII values 
      // divided by capacity was a common approach for generating
      // an evenly distributed and fairly unique set of index 
      // values to populate a hash table with. The performance 
      // will depend on the size of the table compared to the 
      // number of unique values in the data set, as the modulo
      // will be a range of 0...capacity - 1.
      int hash(const string & word) const
      {
         int asciiSum = 0;
         int asciiValue = 0;
         int hashValue = 0;

         // Get the sum of all ASCII values in the word
         for (int i = 0; i < word.length(); i++)
         {
            asciiValue = int(word[i]);
            asciiSum += asciiValue;
         }

         //The hash is the remainder of the sum / capacity
         hashValue = asciiSum % capacity();
         return hashValue;
      }
};
void spellCheck();

void getFileName(string & fileName);

void readFileIntoHash(SHash & data, string & fileName);

void readFileIntoVector(custom::vector <string> & wordList, string & fileName);

#endif // SPELL_CHECK_H
