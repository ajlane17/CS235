/***********************************************************************
 * Module:
 *    Week 11, Sort Quick
 *    Brother Helfrich, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the Quick Sort
 ************************************************************************/

#ifndef SORT_QUICK_H
#define SORT_QUICK_H

/*****************************************************
 * SORT QUICK
 * Perform the quick sort
 ****************************************************/
template <class T>
void sortQuick(T array[], int num)
{
   if (num <= 1)
   {
      return;
   }
   int iDown = num - 1;
   int iEnd = num - 1;
   int iUp = 0;

   T pivotValue = array[iEnd / 2];

   while (iUp <= iDown)
   {
      while (iUp <= iEnd && pivotValue > array[iUp])
      {
         iUp++;
      }
      while (iDown >= 0 && array[iDown] > pivotValue)
      {
         iDown--;
      }

      //Swap elements
      if (iUp <= iDown)
      {
         std::swap(array[iUp++], array[iDown--]);
      }
   }
   sortQuick(array, iUp);
   sortQuick(array + iUp, iEnd - iUp + 1);
}


#endif // SORT_QUICK_H
