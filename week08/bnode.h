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
      BNode()              { pLeft = NULL; pRight = NULL; pParent = NULL; }
      BNode(const T & t)
                 { pLeft = NULL; pRight = NULL; pParent = NULL; data = t; }
      ~BNode()             { }
};

/**********************************************************************
* ADD LEFT
* Adds an existing node to the left of the current node.
***********************************************************************/
template <class T>
void addLeft(BNode <T> * pNode, BNode <T> * pAdd)
{

}

/**********************************************************************
* ADD RIGHT
* Adds an existing node to the right of the current node.
***********************************************************************/
template <class T>
void addRight(BNode <T> * pNode, BNode <T> * pAdd)
{

}

/**********************************************************************
* ADD LEFT
* Allocates and adds a node to the right of the current node.
***********************************************************************/
template <class T>
void addLeft(BNode <T> * pNode, const T & t) throw (const char *)
{

}

/**********************************************************************
* ADD RIGHT 
* Allocates and adds a node to the right of the current node.
***********************************************************************/
template <class T>
void addRight(BNode <T> * pNode, const T & t) throw (const char *)
{

}

/**********************************************************************
* sizeBTree
* determines the size of the binary tree
***********************************************************************/
template <class T>
int sizeBTree(const BNode <T> * pRoot)
{
   return 0;
}

/**********************************************************************
* copyBTree
* Makes copy of the binary tree
***********************************************************************/
template <class T>
BNode <T> * copyBTree(const BNode <T> * pSrc) throw (const char *)
{
   BNode <T> * newTree = new BNode <T>;  //Temp/place holder
   return newTree;
}

/**********************************************************************
* deleteBTree
* Deletes the tree and all its children **sounds aweful**
***********************************************************************/
template <class T>
void deleteBTree(BNode <T> * & pNode)
{

}

/**********************************************************************
* Insertion Operator
***********************************************************************/
template <class T>
   std:: ostream & operator << (std::ostream & out, const BNode<T> & rhs)
{
   return out;
}

#endif // BNODE_H
