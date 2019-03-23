/***********************************************************************
 * Module:
 *    Week 11, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"
#include <cassert>
#include <iostream>

using namespace custom;

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
   BST <T> bst;

   for (int i = 0; i <= num - 1; i++)
   {
      bst.insert(array[i]);
   }

   int i = 0;
   typename BST <T> :: iterator it;
   for (it = bst.begin(); it != bst.end(); it++)
   {
      array[i++] = *it;
   }
}


#endif // SORT_BINARY_H
