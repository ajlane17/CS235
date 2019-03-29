/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#ifndef SPELL_CHECK_H
#define SPELL_CHECK_H
#include "hash.h"
#include <iostream>      // for CIN and COUT
#include <string>        // for STRING
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
 /****************************************
  * S HASH
  * A simple hash of strings
  ****************************************/
class SHash : public Hash <string>
{
public:
   SHash(int numBuckets) throw (const char *) : Hash <string> (numBuckets) {}
};
void spellCheck();

void prompt();

void readFile(SHash & data, string & fileName);

#endif // SPELL_CHECK_H
