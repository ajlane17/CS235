/*****************************************************************************
 * Header:
 *    Node
 * Summary:
 *    This class contains the notion of a node: an object to hold data
 *    for the user as well as its relative position to other objects it
 *    is in a collection with.
 *
 *    This will contain the class definition of:
 *       node : an object that holds data and its relative position
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 *****************************************************************************/

#ifndef NODE_H
#define NODE_H

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
   Node() : data(NULL), pNext(NULL), pPrev(NULL) {}
   Node(const T & t) : data(t), pNext(NULL), pPrev(NULL) {}
};

/*****************************************************************************
 * COPY
 * Copy a linked-list
 *****************************************************************************/
template <class T>
Node <T> * copy(const Node <T> * pSource) throw (const char *)
{
   Node<T> * pDestination = new Node<T>(pSource->data);
   const Node<T> * pDes = pDestination;

   //Copies the data. calls insert
   for (const Node<T> * pSrc = pSource; pSrc; pSrc = pSrc->pNext)
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
Node <T> * insert(const Node <T> * pNode, const T & element, bool after = false)
   throw (const char *)
{
   //TODO: Under construction
   
   Node<T> * pNew = new Node<T>(element);

   /*if (pNode != NULL && after = false)
   {

   }*/
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
   return NULL;
}

/*****************************************************************************
 * OPERATOR <<
 * Display the contents of a given linked-list
 *****************************************************************************/
template <class T>
std::ostream & operator << (std::ostream & out, Node <T> * rhs)
{
   // Display the linked list, format unknown at the moment
   return out;
}

/*****************************************************************************
 * FREE DATA
 * Release all the memory contained in a given linked-list
 *****************************************************************************/
template <class T>
void freeData(Node <T> * & pHead)
{
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
   // Return point to the previous node if it exists, else return next node
   return NULL;
}


#endif // NODE_H