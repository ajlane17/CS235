/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Kirby, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "spellCheck.h"
#include "hash.h"
#include "vector.h"
using namespace std;

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
   string spellCheckfileName;
   string dictionaryFileName = "/home/cs235/week12/dictionary.txt";
   // string dictionaryFileName = "dictionary.txt";
   // We are creating a hash table with 3845 buckets because the 
   // general rule of thumb from the book is to create 1.5 times 
   // the number of buckets than the number of elements to be 
   // stored to avoid collisions while avoiding wasting space. 
   // The only item stored in the hash is the dictionary, which
   // contains 2323 items, of which 1.5 times that is 3485 rounded.
   SHash dictionary(3485);
   custom::vector <string> spellCheckList;
   custom::vector <string> misspelledWords;
   
   // Put the dictionary into a hash
   readFileIntoHash(dictionary, dictionaryFileName);

   // Put the file to spell check into a vector
   getFileName(spellCheckfileName);
   readFileIntoVector(spellCheckList, spellCheckfileName);

   // Spell check the file
   for (int i = 0; i < spellCheckList.size(); i++)
   {
      // for word comparisons, ensure word to check is all lowercase
      string tmp = spellCheckList[i];
      transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
      if (!dictionary.find(tmp))
         misspelledWords.push_back(spellCheckList[i]);
   }

   // Display spell check results
   if (misspelledWords.empty())
   {
      cout << "File contains no spelling errors\n";
   }
   else
   {
      cout << "Misspelled: ";

      for (int i = 0; i < misspelledWords.size(); i++)
      {
         // If it's the last word in the list, endline, else, comma separate
         cout << misspelledWords[i];
         if (i == misspelledWords.size() - 1)
            cout << endl;
         else
            cout << ", ";
      }
   }
}

/*****************************************************
 * GET FILE NAME
 * Prompt the user for a file name
 *****************************************************/
void getFileName(string & fileName)
{
   cout << "What file do you want to check? ";
   cin >> fileName;
}

/*****************************************************
 * READ FILE INTO HASH
 * Read the text file into a map object
 *****************************************************/
void readFileIntoHash(SHash & data, string & fileName)
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Can't read file: " << fileName << endl;
      return;
   }

   while (!fin.eof())
   {
      string word;
      fin >> word;
      data.insert(word);
   }

   fin.close();
}

/*****************************************************
 * READ FILE INTO VECTOR
 * Read the text file into a vector
 *****************************************************/
void readFileIntoVector(custom::vector <string> & wordList, string & fileName)
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Can't read file: " << fileName << endl;
      return;
   }

   while (!fin.eof())
   {
      string word;
      fin >> word;
      // Check for empty new lines
      if (!word.empty())
         wordList.push_back(word);
   }

   fin.close();
}
