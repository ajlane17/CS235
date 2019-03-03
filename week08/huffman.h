/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>        // for CIN and COUT
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "bnode.h"         // for BINARY_NODE class definition
#include "vector.h"        // for VECTOR container
#include "pair.h"          // for PAIR container
#include "deque.h"

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;

// Our Huffman Tree class
class HuffTree
{
  public:
   HuffTree() {}
   HuffTree(BNode <pair <string, float>> * rhs);
   HuffTree(const HuffTree first, const HuffTree second);
   
   float getFreq() const { return root->data.second; }
   float setFreq(float num) { root->data.second = num; }
      
   //private:
   BNode <pair <string, float>> * root;
 
};

// function prototypes
void huffman(const string & fileName);
vector <pair <string, float>> readFile(const string & fileName);
vector <HuffTree> convertToHuff(const vector <pair <string, float>> data);
vector <HuffTree> combineTwo(vector <HuffTree> & data);
void findLeafCode(const BNode <pair <string, float>> * root,
                  string code, vector <pair <string, string>> & matches);
   
#endif // HUFFMAN_h
