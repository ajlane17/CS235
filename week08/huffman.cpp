/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "bnode.h"         // for BINARY_NODE class definition
#include "vector.h"        // for VECTOR container
#include "pair.h"          // for PAIR container
#include "huffman.h"       // for HUFFMAN() prototype

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const string & fileName)
{
   vector <HuffTree> data = readFile(fileName);

   //for error checking
   for (int i = 0; i < data.size(); i++)
      cout << data[i].getFreq() << endl;
   

   
      
   return;
}

/*******************************************
 * READ FILE
 * Reads the file data into a vector of HuffTrees
 *******************************************/
vector <HuffTree> readFile(const string & fileName)
{
   vector <pair <string, float>> data;
   vector <HuffTree> trees;
   
   ifstream fin(fileName);
   if (fin.fail())
      return trees;

   while (fin)
   {
      pair <string, float> temp;
      fin >> temp;
      if (temp.second != 0)
      {
          data.push_back(temp);
      }
   }

   for (int i = 0; i < data.size(); i++)
      trees.push_back(HuffTree(data[i]));
   
   return trees;
}

/*************************************************
 * HUFF TREE
 * NON-DEFAULT CONSTRUCTOR
 * INPUT: BNODE
 * Copies a BNode into the root of the HuffTree
 *************************************************/
HuffTree :: HuffTree (BNode <pair <string, float>> rhs)
{
   root = rhs;
}

/*************************************************
 * HUFF TREE
 * NON-DEFAULT CONSTRUCTOR
 * INPUT: TWO HUFFTREE OBJECTS
 * Copies two HuffTrees into a single one and adds
 * their values together to make a root BNode.
 *************************************************/
HuffTree :: HuffTree (const HuffTree first, const HuffTree second)
{
   pair <string, float> newPair;
   newPair.second = first.getFreq() + second.getFreq();
   root = BNode <pair <string, float>>(newPair);
   
   
}
