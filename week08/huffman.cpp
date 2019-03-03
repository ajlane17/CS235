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
   vector <pair <string, float>> data = readFile(fileName);
   vector <HuffTree> trees = convertToHuff(data);

   // combine the trees until there is only one left in the array
   while (trees.size() > 1)
   {
      trees = combineTwo(trees);
   }

   //create objects to store the codes for each value
   string code;
   vector <pair <string, string>> matches;
   findLeafCode(trees[0].root, code, matches);

   // loop through the original data and matches to display
   //    in order.
   for (int i = 0; i < data.size(); i++)
   {
      string temp = data[i].first;
      for (int x = 0; x < matches.size(); x++)
      {
         string matchString = matches[x].first;
         if (temp == matchString)
         {
            cout << matchString << " = "
                 << matches[x].second << endl;
         }
      }
   }
      
   return;
}

/*******************************************
 * READ FILE
 * Reads the file data into a vector of pairs
 *******************************************/
vector <pair <string, float>> readFile(const string & fileName)
{
   vector <pair <string, float>> data;
   
   ifstream fin(fileName);
   if (fin.fail())
      return data;

   while (fin)
   {
      pair <string, float> temp;
      fin >> temp;
      if (temp.second != 0)
      {
          data.push_back(temp);
      }
   }

   return data;
}

/*******************************************
 * CONVERT TO HUFF
 * Converts data from pair vector to HuffTree vector
 *******************************************/
vector <HuffTree> convertToHuff(const vector <pair <string, float>> data)
{
   vector <HuffTree> trees;
   
   for (int i = 0; i < data.size(); i++)
   {
      BNode <pair <string, float>> * newRoot = new BNode <pair <string, float>>;
      newRoot->data = data[i];
      trees.push_back(HuffTree(newRoot));
   }
   
   return trees;
}

/*************************************************
 * COMBINE TWO
 * Takes the vector and combines the two lowest
 * frequencies and returns a new updated vector.
 *************************************************/
vector <HuffTree> combineTwo(vector <HuffTree> & data)
{
   // find the largest frequency in the vector
   int iMax = 0;
   for (int i = 1; i < data.size(); i++)
   {
      if (data[i].getFreq() > data[iMax].getFreq())
      {
         iMax = i;
      }
   }

   // start with the two smallest set to the highest frequency to compair
   int iS = iMax;  // smallest slot
   int iNS = iMax; // next smallest slot

   // traverse the vector to update the two smallest frequncies
   for (int i = 0; i < data.size(); i++)
   {
      if (data[i].getFreq() < data[iS].getFreq())
      {
         iNS = iS;
         iS = i;
      }
      else if (data[i].getFreq() < data[iNS].getFreq())
      {
         iNS = i;
      }
   }

   // combine the two trees and return a new vector
   vector <HuffTree> newData;
   HuffTree newTree(data[iS], data[iNS]);
   
   bool firstSlot = true;
   for (int i = 0; i < data.size() - 1; i++)
   {
      // fill in the first slot with the new tree
      if ((i == iS || i == iNS) && firstSlot)
      {
         newData.push_back(newTree);
         firstSlot = false;
      }
      // fill in the second slot with the last tree in the vector
      else if((i == iS || i == iNS) && !firstSlot)
      {
         newData.push_back(data[data.size() - 1]);
      }
      // just copy over the other trees to the new vector
      else
      {
         newData.push_back(data[i]);
      }
   }

   return newData;
}

/*************************************************
 * FIND LEAF CODE
 * Takes the root node and finds the codes for each
 * of the values, then stores them in a vector to
 * access later.
 *************************************************/
void findLeafCode(const BNode <pair <string, float>> * root,
                  string code, vector <pair <string, string>> & matches)
{

   if (root == NULL)
      return;

   // if it is a leaf then it stores the code in the vector
   if (!root->pLeft && !root->pRight)
   {
      pair <string, string> match;
      match.first = root->data.first;
      match.second = code;
      matches.push_back(match);
      return;
   }

   // adds the path to the code as each node is traversed.
   findLeafCode(root->pLeft, code + "0", matches);
   findLeafCode(root->pRight, code + "1", matches);
   
}

/*************************************************
 * HUFF TREE
 * NON-DEFAULT CONSTRUCTOR
 * INPUT: BNODE
 * Copies a BNode into the root of the HuffTree
 *************************************************/
HuffTree :: HuffTree (BNode <pair <string, float>> * rhs)
{
   root = copyBTree(rhs);
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
   newPair.first = "---";
   newPair.second = first.getFreq() + second.getFreq();
   BNode <pair <string, float>> * newRoot = new BNode <pair <string, float>>;
   newRoot->data = newPair;
   root = newRoot;

   // sets order based on size (left to right)
   if (second.getFreq() < first.getFreq())
   {
      addLeft(root, second.root);
      addRight(root, first.root);
   }
   else
   {
      addLeft(root, first.root);
      addRight(root, second.root);
   }
}
