/***********************************************************************
 * Module:
 *    Week 11, Sort Heap
 *    Brother Helfrich, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the Heap Sort
 ************************************************************************/

#ifndef SORT_HEAP_H
#define SORT_HEAP_H
#include <algorithm>
/*****************************************************
 * HEAP CLASS
 * A class to store the funtions and data of a heap.
 ****************************************************/
template <class T>
class Heap
{
  public:
   Heap(T *inputArray, int inputNum);
   void sort();
         
  private:
   T * array;
   int num;

   void percolateDown(int index);
   void swap(int i1, int i2)
   { std::swap((array[i1]), (array[i2])); }
   
};

/*****************************************************
 * NON-DEFAULT CONSTRUCTOR
 * Coppies the num and array into the class and then
 * convert the array into a heap.
 ****************************************************/
template <class T>
Heap <T> :: Heap(T *inputArray, int inputNum)
{
   array = inputArray;
   num = inputNum;
   // heapify the array as soon as it is passed into the class
   for(int i = (num / 2); i >= 0; i--)
      percolateDown(i);
}

/*****************************************************
 * PERCOLATE DOWN
 * Takes the array and sorts it into a heap.
 ****************************************************/
template <class T>
void Heap <T> :: percolateDown(int index)
{
   int indexLeft = index * 2;
   int indexRight = indexLeft + 1;

   // make the right the head if it is bigger
   if (indexRight <= num
       && array[indexRight] > array[indexLeft]
       && array[indexRight] > array[index])
   {
      swap(index, indexRight);
      // then check to see if we need to change things
      //   further back down because of the swap.
      percolateDown(indexRight);
   }
   // make the left the head if bigger.
   else if (indexLeft <= num
            && array[indexLeft] > array[index])
   {
      swap(index, indexLeft);
      percolateDown(indexLeft);
   }
}

/*****************************************************
 * SORT
 * Sorts the heap within the class
 ****************************************************/
template <class T>
void Heap <T> :: sort()
{
   // set num to the last slot
   num--;
   // sort from biggest to smallest starting at the end
   while (num > 0)
   {
      // swap the counter item with the hepified head
      swap(0, num);
      num--;
      percolateDown(0);
   }
   return;
}

/*****************************************************
 * SORT HEAP
 * Perform the heap sort
 ****************************************************/
template <class T>
void sortHeap(T array[], int num)
{
   // create object and sort
   Heap<T> h(array, num);
   h.sort();
}

#endif // SORT_HEAP_H
