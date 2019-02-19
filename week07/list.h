/*****************************************************************************
 * Header:
 *    List
 * Summary:
 *    This class contains the notion of a list: an object to hold data
 *    for the user in squential order using nodes and allows the user to
 *    manipulate the list through various functions
 *
 *    This will contain the class definition of:
 *       node : an object that holds data and its relative position
 *       list : a set of nodes connected to store data in sequential order
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 *****************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <cassert>  

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

/*****************************************************************************
 * NODE
 * an object that holds data and its relative position
 *****************************************************************************/
template <class T>
class Node
{
   public:
   // Member variables
   T data;
   Node <T> * pNext;
   Node <T> * pPrev;

   // Constructors
   Node() : data(), pNext(NULL), pPrev(NULL) {}
   Node(const T & t) : data(t), pNext(NULL), pPrev(NULL) {}
};

/*****************************************************************************
 * COPY
 * Copy a linked-list
 *****************************************************************************/
template <class T>
Node <T> * copy(Node <T> * pSource) throw (const char *)
{
   Node<T> * pDestination = new Node<T>(pSource->data);
   Node<T> * pDes = pDestination;

   //Copies the data. calls insert
   for (const Node<T> * pSrc = pSource->pNext; pSrc; pSrc = pSrc->pNext)
   {
      pDes = insert(pDes, pSrc->data, true);
   }
   // Return the pointer to the new linked-list
   return pDestination;
}

/*****************************************************************************
 * INSERT
 * Inserts a node into the current linked-list
 *****************************************************************************/
template <class T>
Node <T> * insert(Node <T> * pNode, const T & element, bool after = false)
   throw (const char *)
{
   Node<T> * pNew = new Node<T>(element);

   //Before node
   if (pNode != NULL && after == false)
   {
      pNew->pNext = pNode;
      pNew->pPrev = pNode->pPrev;
      pNode->pPrev = pNew;
      if (pNew->pPrev)
      {
         pNew->pPrev->pNext = pNew;
      }
   }

   //after node
   if (pNode != NULL && after == true)
   {
      pNew->pPrev = pNode;
      pNew->pNext = pNode->pNext;
      pNode->pNext = pNew;
      if (pNew->pNext)
      {
         pNew->pNext->pPrev = pNew;
      }
   }

   // Return the pointer to the newly created node
   return pNew;
}

/*****************************************************************************
 * FIND
 * Find the node corresponding to the given value from the given linked-list
 *****************************************************************************/
template <class T>
Node <T> * find(Node <T> * pHead, const T & t)
{
   // Return the pointer to the found node else NULL
   for(Node <T> * p = pHead; p; p = p->pNext)
   {
      if (p->data == t)
         return p;
   } 
   
   return NULL;
}

/*****************************************************************************
 * OPERATOR <<
 * Display the contents of a given linked-list
 *****************************************************************************/
template <class T>
std::ostream & operator << (std::ostream & out, Node <T> * rhs)
{
   // do nothing if empty
   if (rhs == NULL)
      return out;

   while (rhs != NULL)
   {
      out << rhs->data;
      // only display a comma if not the end of the list
      if (rhs->pNext)
      {
         rhs = rhs->pNext;
         out << ", ";
      }
      else
         rhs = rhs->pNext;
   }

   // Display the linked list
   return out;
}

/*****************************************************************************
 * FREE DATA
 * Release all the memory contained in a given linked-list
 *****************************************************************************/
template <class T>
void freeData(Node <T> * & pHead)
{
   Node <T> * pDelete;
   while (pHead != NULL)
   {
      pDelete = pHead;
      pHead = pHead->pNext;
      delete pDelete;
   }
   // No return
   return;
}

/*****************************************************************************
 * REMOVE
 * Remove the given node from the linked list it is attached to
 *****************************************************************************/
template <class T>
Node <T> * remove(const Node <T> * pRemove)
{
   Node <T> * pReturn;
   
   // Return point to the previous node if it exists, else return next node
   if (NULL == pRemove)
      return NULL;

   if (pRemove->pPrev)
      pRemove->pPrev->pNext = pRemove->pNext;
   if (pRemove->pNext)
      pRemove->pNext->pPrev = pRemove->pPrev;

   if (pRemove->pPrev)
      pReturn = pRemove->pPrev;
   else
      pReturn = pRemove->pNext;

   delete pRemove;
   return pReturn;
}

#endif // LIST_H
