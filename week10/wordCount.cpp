/***********************************************************************
 * Module:
 *    Week 10, WORD COUNT
 *    Brother Helfrich, CS 235
 * Author:
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 * Summary:
 *    This program will implement the wordCount() function
 ************************************************************************/

#include "map.h"       // for MAP
#include "wordCount.h" // for wordCount() prototype
#include <iostream>
#include <fstream>
using std::string;
using std::ifstream;
using namespace custom;
void readFile(map <string, Count> & counts, const string & fileName);

/*****************************************************
 * WORD COUNT
 * Prompt the user for a file to read, then prompt the
 * user for words to get the count from
 *****************************************************/
void wordCount()
{
   string fileName;
   string input = " ";
   map <string, Count> wordMap;

   // Get the file name and read it into memory
   std::cout << "What is the filename to be counted? ";
   std::cin  >> fileName;

   readFile(wordMap, fileName);

   // Prompt for a word to get the count for
   std::cout << "What word whose frequency is to be found. Type ! when done" << std::endl;

   // The loop happens after the prompt
   while (input != "!")
   {
      std::cout << "> ";
      std::cin  >> input;
      if (input != "!")
         std::cout << "\t" << input << " : " << wordMap[input].getCount() << std::endl;
   }
}

/*****************************************************
 * READ FILE
 * Read the file into a map object
 *****************************************************/
void readFile(map <string, Count> & counts, const string & fileName)
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      std::cout << "Can't read file: " << fileName << std::endl;
      return;
   }

   while (fin)
   {
      string word;
      fin >> word;
      (counts[word]).setCount((counts[word]).getCount() + 1);
   }
}
