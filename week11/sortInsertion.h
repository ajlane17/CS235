/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>

/*****************************************************
 * BINARY SEARCH
 * Returns insert location for item into sorted array
 ****************************************************/
template <class T>
int binarySearch(T array[], T search, int iBegin, int iEnd)
{
   int iMiddle = (iBegin + iEnd) / 2;
   if (iBegin > iEnd)
   {
      return iBegin;
   }

   if (array[iMiddle] == search)
   {
      return iMiddle;
   }

   if (search > array [iMiddle])
   {
      return binarySearch(array, search, iMiddle + 1, iEnd);
   }

   if (search < array[iMiddle])
   {
      return binarySearch(array, search, iBegin, iMiddle - 1);
   }
}

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   int iPivot;
   int iInsert;
   int iShift;
   T valuePivot;

   for (iPivot = num -2; iPivot >= 0; iPivot--)
   {
      valuePivot = array[iPivot];
      
      iInsert = binarySearch(array, valuePivot, iPivot + 1, num - 1);
      
      iInsert--;
      
      for (iShift = iPivot; iShift < iInsert; iShift++)
      {
         array[iShift] = array[iShift + 1];
      }

   array[iShift] = valuePivot;
   }
}


#endif // SORT_INSERTION_H
