/*****************************************************************************
 * Header:
 *    BNode
 * Summary:
 *    Custom binary tree. 
 *    This will contain the class definition of:
 *    BNode:
 *    There will be four member variables: a pointer to 
 *    the node to the right child (pRight), a pointer to the node to the left
 *    child (pLeft), a pointer to the parent (pParent), and the data associated
 *    with the node.
 *    Various stand-alone functions:
 *    addLeft(), addRight(), copyBTree(), deleteBTree(), 
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 *****************************************************************************/

#ifndef BNODE_H
#define BNODE_H

#include <cassert>  
#include <ostream>
#include <iostream>

 // a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

 /*****************************************************************************
 * BNODE
 * A custom Binary Tree class
 *****************************************************************************/
template <class T>
class BNode
{
   public:
   // Member variables
      T data;
      BNode <T> * pLeft;
      BNode <T> * pRight;
      BNode <T> * pParent;

      // Constructors and destructors
      BNode()      { pLeft = NULL; pRight = NULL; pParent = NULL; data = T(); }
      BNode(const T & t)
                     { pLeft = NULL; pRight = NULL; pParent = NULL; data = t; }
      ~BNode()    {}
};

/**********************************************************************
* ADD LEFT
* Adds an existing node to the left of the current node.
***********************************************************************/
template <class T>
void addLeft(BNode <T> * pNode, BNode <T> * pAdd)
{
   if (pAdd != NULL)
      pAdd->pParent = pNode;
   
   pNode->pLeft = pAdd;
}

/**********************************************************************
* ADD RIGHT
* Adds an existing node to the right of the current node.
***********************************************************************/
template <class T>
void addRight(BNode <T> * pNode, BNode <T> * pAdd)
{
   if (pAdd != NULL)
      pAdd->pParent = pNode;
   
   pNode->pRight = pAdd;
}

/**********************************************************************
* ADD LEFT
* Allocates and adds a node to the right of the current node.
***********************************************************************/
template <class T>
void addLeft(BNode <T> * pNode, const T & t) throw (const char *)
{
   BNode <T> * pAdd;

   try
   {
      pAdd = new BNode <T> (t);
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for bnode";
   }

   pAdd->pParent = pNode;
   pNode->pLeft = pAdd;
}

/**********************************************************************
* ADD RIGHT 
* Allocates and adds a node to the right of the current node.
***********************************************************************/
template <class T>
void addRight(BNode <T> * pNode, const T & t) throw (const char *)
{
   BNode <T> * pAdd;

   try
   {
      pAdd = new BNode <T> (t);
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for bnode";
   }

   pAdd->pParent = pNode;
   pNode->pRight = pAdd;
}

/**********************************************************************
* sizeBTree
* determines the size of the binary tree
***********************************************************************/
template <class T>
int sizeBTree(const BNode <T> * pRoot)
{
   // Recursively iterate through the collection to get the size
   if (pRoot == NULL)
      return 0;
   else
      return sizeBTree(pRoot->pLeft) + 1 + sizeBTree(pRoot->pRight);
}

/**********************************************************************
* copyBTree
* Makes copy of the binary tree
***********************************************************************/
template <class T>
BNode <T> * copyBTree(const BNode <T> * pSrc) throw (const char *)
{
   if (pSrc == NULL)
      return NULL;

   // Create a destination tree with the root node's data
   BNode <T> * pDestination;

   try
   {
      pDestination = new BNode <T> (pSrc->data);
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for bnode";
   }

   // Recursively copy BTree data using VLR (Pre-Order Traversal)

   // Traverse left nodes, create and assign to new tree
   pDestination->pLeft = copyBTree(pSrc->pLeft);
   if (pDestination->pLeft != NULL)
      pDestination->pLeft->pParent = pDestination;

   // Traverse right nodes, create and assign to new tree
   pDestination->pRight = copyBTree(pSrc->pRight);
   if (pDestination->pRight != NULL)
      pDestination->pRight->pParent = pDestination;

   return pDestination;
}

/**********************************************************************
* deleteBTree
* Deletes the tree and all its children **sounds awful**
***********************************************************************/
template <class T>
void deleteBTree(BNode <T> * & pNode)
{
   if (pNode == NULL)
      return;
   
   // Recursively delete all nodes using LRV (Post-Order Traversal)
   deleteBTree(pNode->pLeft);
   deleteBTree(pNode->pRight);
   delete pNode;
   // After deleting the data, set the pointer to NULL
   pNode = NULL;
}

/**********************************************************************
* Insertion Operator
***********************************************************************/
template <class T>
std::ostream & operator << (std::ostream & out, const BNode <T> * pHead)
{
   if (pHead == NULL)
      return out;

   // Recursively display BTree data using VLR (Pre-Order Traversal)
   std::cout << pHead->pLeft;
   out << pHead->data << " ";
   std::cout << pHead->pRight;

   return out;
}

#endif // BNODE_H
