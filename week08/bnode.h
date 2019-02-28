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
      BNode(const T & t)
                 { pLeft = NULL; pRight = NULL; pParent = NULL; data = t; }
      ~BNode()             { }
};



/**********************************************************************
* AddLeft
* Adds a node to the left of the current node.
* Version : Template
***********************************************************************/
template <class T>
void addLeft(T t)
{

}

/**********************************************************************
* AddLeft
* Adds a node to the left of the current node.
* Version : BNode
***********************************************************************/
template <class T>
void addLeft(custom::BNode<T> t)
{

}

/**********************************************************************
* addRight
* Adds a node to the right of the current node.
* Version: Template
***********************************************************************/
template <class T>
void addRight(T t)
{

}

/**********************************************************************
* addRight
* Adds a node to the right of the current node.
* Version : BNode
***********************************************************************/
template <class T>
void addRight(custom::BNode<T> t)
{

}

/**********************************************************************
* sizeBTree
* determines the size of the binary tree
***********************************************************************/
template <class T>
void sizeBTree(custom::BNode<T> * t)
{

}

/**********************************************************************
* copyBTree
* Makes copy of the binary tree
***********************************************************************/
template <class T>
custom::BNode<T> copyBTree(custom::BNode<T> t)
{
   custom::BNode<T> newTree;  //Temp/place holder
   return newTree;
}

/**********************************************************************
* deleteBTree
* Deletes the tree and all its children **sounds aweful**
***********************************************************************/
template <class T>
void deleteBTree(custom::BNode<T> t)
{

}

/**********************************************************************
*
*
***********************************************************************/
template <class T>
   std:: ostream & operator << (std::ostream & out, const BNode<T> & rhs)
{
   return out;
}

}//end custom namespace
#endif // BNODE_H
