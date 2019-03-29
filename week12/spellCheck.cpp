/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "spellCheck.h"
#include "hash.h"
using namespace std;

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
   prompt();
}

void prompt()
{
   string fileName;
   

   cout << "What file do you want to check?\n";
   cin >> fileName;
   SHash data(100);
   readFile(data, fileName);
}

/*****************************************************
 * READ FILE
 * Read the file into a map object
 *****************************************************/
void readFile(SHash & data, string & fileName)
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      std::cout << "Can't read file: " << fileName << std::endl;
      return;
   }

   while (!fin.eof())
   {
      string word;
      fin >> word;
      data.insert(word);
   }
}
