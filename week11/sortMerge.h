/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

#include <iostream>

/*****************************************************
 * MERGE
 * Merge two sub-arrays into the destination array
 ****************************************************/
template <class T>
void merge(T * destination, T * source1, int size1, T * source2, int size2)
{
   int i1 = 0;
   int i2 = 0;

   for (int iDestination = 0; iDestination < (size1 + size2); iDestination++)
   {
      if (i1 < size1 && (i2 == size2 || source1[i1] < source2[i2]))
         destination[iDestination] = source1[i1++];
      else
         destination[iDestination] = source2[i2++];
   }
}

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void sortMerge(T array[], int num)
{
   int iBegin1;
   int iEnd1;
   int iBegin2;
   int iEnd2;
   int numIterations;

   T * source = array;
   T * destination = new T[num];

   do
   {
      // The pseudocode makes no mention of how to set iBegin1 anywhere, it took
      // much trial and error to figure out it had to be at the beginning of the 
      // outer loop.
      iBegin1 = 0;
      numIterations = 0;
      while (iBegin1 < num)
      {
         numIterations++;
         // I couldn't get it to work based on the pseudocode originally because the 
         // arrays were always grabing the end + 1, which was preventing the sort 
         // from working as it skipped a bunch of numbers, and the operator in the 
         // condition kept me in an infinite loop until I reversed it and removed the
         // negation check.
         for (iEnd1 = iBegin1; iEnd1 < num && source[iEnd1 + 1] >= source[iEnd1]; iEnd1++) {}

         iBegin2 = iEnd1 + 1;

         for (iEnd2 = iBegin2; iEnd2 < num && source[iEnd2 + 1] >= source[iEnd2]; iEnd2++) {}

         if (iBegin2 < num)
         {
            // The pseudocode also made no mention that the destination pointer also
            // needed to be offset. 
            merge(destination + iBegin1,
                  source + iBegin1, iEnd1 - iBegin1 + 1,
                  source + iBegin2, iEnd2 - iBegin2 + 1);
         }

         iBegin1 = iEnd2 + 1;
      }

      // Swap using a temporary pointer
      T * tmp = source;
      source = destination;
      destination = tmp;
   } 
   // This was also tricky, I thought I was supposed to track some new variable that counted
   // merge calls separately based on the pseudocode. I wish there was errata for the book.
   while (numIterations > 1);

   if (array != source)
      for (int i = 0; i < num; i++)
         array[i] = source[i];
}


#endif // SORT_MERGE_H
