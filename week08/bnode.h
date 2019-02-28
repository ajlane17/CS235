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

#ifndef LIST_H
#define LIST_H

#include <cassert>  
#include <ostream>
#include <iostream>
using namespace std;

 // a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG
namespace custom
{
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
      BNode * pLeft;
      BNode * pRight;
      BNode * pParent;

      // Constructors and destructors
      BNode()              { pLeft = NULL; pRight = NULL; pParent = NULL; }
      BNode(const T & t)   { pLeft = NULL; pRight = NULL; pParent = NULL; }
      ~BNode()             { }
};

/**********************************************************************
* AddLeft
* Adds a node to the left of the current node.
* Version : Template
***********************************************************************/
template <class T>
void addLeft(BNode<T> * pTree, int t)
{

}

/**********************************************************************
* AddLeft
* Adds a node to the left of the current node.
* Version : BNode
***********************************************************************/
template <class T>
void addLeft(BNode<T> * pTree, BNode<T> * t)
{

}

/**********************************************************************
* addRight
* Adds a node to the right of the current node.
* Version: Template
***********************************************************************/
template <class T>
void addRight(BNode<T> * pTree, int t)
{

}

/**********************************************************************
* addRight
* Adds a node to the right of the current node.
* Version : BNode
***********************************************************************/
template <class T>
void addRight(BNode<T> * pTree, BNode<T> * t)
{

}

/**********************************************************************
* sizeBTree
* determines the size of the binary tree
***********************************************************************/
template <class T>
int sizeBTree(BNode<T> * t)
{
   return 0;
}

/**********************************************************************
* copyBTree
* Makes copy of the binary tree
***********************************************************************/
template <class T>
BNode<T> copyBTree(BNode<T> * source)
{
   BNode<T> * newTree = new BNode;  //Temp/place holder
   return newTree;
}

/**********************************************************************
* deleteBTree
* Deletes the tree and all its children **sounds aweful**
***********************************************************************/
template <class T>
void deleteBTree(BNode<T> * t)
{

}

/**********************************************************************
* Insertion Operator
***********************************************************************/
template <class T>
ostream & operator<<(ostream & out, const BNode<T> & rhs)
{
   return out;
}

}//end custom namespace
#endif // LIST_H