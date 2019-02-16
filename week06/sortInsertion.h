/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
   // Check for an empty array
   if (num == 0)
      return;

   // Create a new linked-list and a variable to track a new head
   Node <T> * nodeList = new Node <T> (array[0]);
   Node <T> * newHead;

   // Read the array into the linked-list one at a time
   for (int i = 1; i < num; i++)
   {
      // Inserts the array element and checks for a new head
      newHead = sortedInsert(array[i], nodeList);
      if (newHead != NULL)
      {
         nodeList = newHead;
      }
   }

   // Copy the sorted linked-list back into the array
   Node <T> * p = nodeList;
   for (int i = 0; i < num; i++)
   {
      array[i] = p->data;
      p = p->pNext;
   }

   // Delete the linked list
   freeData(nodeList);
}

/***********************************************
 * SORTED INSERT
 * Inserts an element into a linked-list in a sorted position
 * Returns the new head pointer if it inserts at the beginning
 * otherwise returns nothing
 **********************************************/
template <class T>
Node <T> * sortedInsert(const T & t, Node <T> * & nodeList)
{
   Node <T> * p = new Node <T>;

   // Check for an exact match first
   if (find(nodeList, t) != NULL)
   {
      insert(p, t);
      if (p->pPrev->pPrev == NULL)
      {
         return p->pPrev;
      }
      else
      {
         return NULL;
      }
   }

   // Loop through the node list looking for a match
   for (p = nodeList; p; p = p->pNext)
   {
      if (t <= p->data)
      {
         insert(p, t);
         if (p->pPrev->pPrev == NULL)
         {
            return p->pPrev;
         }
         else
         {
            return NULL;
         }
      }
      else if (p->pNext == NULL)
      {
         insert(p, t, true);
         return NULL;
      }
   }
}

#endif // INSERTION_SORT_H

