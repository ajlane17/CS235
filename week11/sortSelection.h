/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
   for (int iPivot = num - 1; iPivot >= 1; iPivot--)
   {
      int iLargest = 0;
      for (int iCheck = 1; iCheck <= iPivot - 1; iCheck++)
      {
         if (array[iLargest] <= array[iCheck])
         {
            iLargest = iCheck;
         }

      }

      //swap elements
      if (array[iLargest] > array[iPivot])
      {
         std::swap(array[iLargest], array[iPivot]);
         // T tmp = array[iLargest];
         // array[iLargest] = array[iPivot];
         // array[iPivot] = tmp;
      }
   }
}
#endif // SORT_SELECTION_H
