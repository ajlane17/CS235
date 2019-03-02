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

using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;

class HuffTree
{
  public:
   HuffTree() {}
   HuffTree(BNode <pair <string, float>> rhs);
   HuffTree(const HuffTree lhs, const HuffTree rhs);
   
   float getFrequency() { return root.data.second; }
   float setFrequency(float num) { root.data.second = num; }
      
   //private:
   BNode <pair <string, float>> root;
 
};

void huffman(const string & fileName);
vector <HuffTree> readFile(const string & fileName);

#endif // HUFFMAN_h
