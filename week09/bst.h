/***********************************************************************
 * Component:
 *    Assignment 09, Binary Search Tree (BST)
 *    Brother <your instructor name here>, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    Create a binary search tree
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include <cassert> 
#include "stack.h"

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{

/**************************************************
 * BST
 * A Binary Search Tree
 *************************************************/
template <class T>
class BST
{
   public:
      // Constrcutors
      BST(): root(NULL), numElements(0) {}
      BST(const BST <T> & rhs) throw (const char *)
      {
         root = NULL;
         numElements = 0;
         *this = rhs;
      }
      ~BST() {}

      // Operators
      BST <T> & operator = (const BST <T> & rhs) throw (const char *);

      // Nested BNode class & related functions
      class BNode;
      BNode * getRoot() const { return root; }

      // Nested iterator class & related functions
      class iterator;

      iterator begin();
      iterator begin() const;

      iterator rbegin();
      iterator rbegin() const;

      iterator end() { return iterator(NULL); }
      iterator end() const { return iterator(NULL); }

      iterator rend() { return iterator(NULL); }
      iterator rend() const { return iterator(NULL); }

      iterator find(const T & t);

      // Standard container functions
      int size() const { return numElements; };
      bool empty() const { return numElements == 0; }
      void clear();

      // BST-specific functions
      void insert(const T & t) throw (const char *);
      void erase(BST <T> :: iterator & it);

   private:
      BNode * root;
      int numElements;
      void deleteNode(BNode * pNode, bool right); // Used for erase(?)
      void deleteBinaryTree(BNode * pNode);
      void copyBinaryTree(const BNode * src, BNode * dest);
};

 /*****************************************************************************
 * BST :: BNODE
 * A custom Binary Tree class
 *****************************************************************************/
template <class T>
class BST <T> :: BNode
{
   public:
   // Member variables
      T data;
      BNode * pLeft;
      BNode * pRight;
      BNode * pParent;
      bool isRed;

      // Constructors and destructors
      BNode() :pLeft(NULL), pRight(NULL), pParent(NULL), isRed(false),
         data() {}
      BNode(const T & t) :pLeft(NULL), pRight(NULL), pParent(NULL), 
         isRed(false), data(t) {}
      ~BNode() {}

      // Red-Black Balancing helpers
      void verifyBTree();
      void findDepth();
      void verifyRedBlack(int depth);
      void balance();
};

/**************************************************
 * BST :: ITERATOR
 * An iterator through the BST
 *************************************************/
template <class T>
class BST <T> :: iterator
{
   public:
      /* constructors, destructors, and assignment operator */
      // push a null BNode onto the stack
      iterator()
      {
         BNode * t = new BNode();
         nodes.push(t);
      }
      // If a BNode is passed, push it onto the stack
      iterator(BNode * p)
      {
         nodes.push(p);
      }
      // Copy constructor uses assignment operator
      iterator(const iterator & rhs) { *this = rhs; }
      
      /*Operator overloads*/
      // Assignment operator leverages stack assignment operator
      iterator & operator = (const iterator & rhs)
      {
         this->nodes = rhs.nodes;
         return *this;
      }
      // equals, not equals operator
      bool operator != (const iterator & rhs) const
      {
         return rhs.nodes.top() != this->nodes.top();
      }
      bool operator == (const iterator & rhs) const
      {
         return rhs.nodes.top() == this->nodes.top();
      }

      // dereference operator
      T & operator * ()       { return nodes.top()->data; }
      const T & operator * () const { return nodes.top()->data; }

      // prefix increment
      iterator & operator ++ ();

      // postfix increment
      iterator operator ++ (int postfix)
      {
         iterator tmp(*this);
         ++(*this);
         return tmp;
      }

      // prefix decrement
      iterator & operator -- ();

      // postfix decrement
      iterator operator -- (int postfix)
      {
         iterator tmp(*this);
         --(*this);
         return tmp;
      }

   private:
      stack <BNode *> nodes; // Per the intro
      //BSTneeds access to the private stack in order to traverse 
      //the using the iterator.
      friend class BST;       
};

/**************************************************
 * BST ITERATOR :: DECREMENT PREFIX
 *     advance by one. 
 * Author:      Br. Helfrich + team
 * Performance: O(log n) though O(1) in the common case
 * Modified by team: Because we're using a stack now, 
 * we had to refactor this to work with a collection. 
 * Also, because we don't need to "go up"in the 
 * traditional sense, we don't directly reference the
 * parent, and instead, just pop from the collection.
 *************************************************/
template <class T>
typename BST <T> :: iterator & BST <T> :: iterator :: operator -- ()
{
   // do nothing if we have nothing
   if (NULL == nodes.top())
      return *this;

   // if there is a left node, take it
   if (NULL != nodes.top()->pLeft)
   {
      // go left
      nodes.push(nodes.top()->pLeft);

      // jig right - there might be more right-most children
      while (nodes.top()->pRight)
         nodes.push(nodes.top()->pRight);
      return *this;
   }

   // there are no left children, the right are done
   assert(NULL == nodes.top()->pLeft);
   BNode * pSave = nodes.top();

   // go up, don't need to reference parent because it should
   // be the previous node in the stack
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (NULL != nodes.top() && pSave == nodes.top()->pLeft)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}

/**************************************************
 * BST ITERATOR :: INCREMENT PREFIX
 *************************************************/
template <class T>
typename BST <T> :: iterator & BST <T> :: iterator :: operator ++ ()
{
   // do nothing if we have nothing
   if (NULL == nodes.top())
      return *this;

   // if there is a left node, take it
   if (NULL != nodes.top()->pRight)
   {
      // go left
      nodes.push(nodes.top()->pRight);

      // jig left - there might be more left-most children
      while (nodes.top()->pLeft)
         nodes.push(nodes.top()->pLeft);
      return *this;
   }

   // there are no left children, the right are done
   assert(NULL == nodes.top()->pRight);
   BNode * pSave = nodes.top();

   // go up, don't need to reference parent because it should
   // be the previous node in the stack
   nodes.pop();

   // if the parent is the NULL, we are done!
   if (NULL == nodes.top())
      return *this;

   // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
      return *this;

   // we are the left-child, go up as long as we are the left child!
   while (NULL != nodes.top() && pSave == nodes.top()->pRight)
   {
      pSave = nodes.top();
      nodes.pop();
   }

   return *this;
}

/**************************************************
 * BST :: COPY BINARY TREE
 * ***********************************************/
template <class T>
void BST <T> :: copyBinaryTree(const BNode * src, BNode * dest)
{
   if (src == NULL)
      return;

   // Copy root node data
   dest->data = src->data;

   // Move down the left side
   if (src->pLeft != NULL)
   {
      BNode * pLeftTmp = new BNode();
      pLeftTmp = dest->pLeft;
      copyBinaryTree(src->pLeft, dest->pLeft);

      if (dest->pLeft != NULL)
         dest->pLeft->pParent = dest;
   }

   // Move down the right side
   if (src->pLeft != NULL)
   {
      BNode * pRightTmp = new BNode();
      pRightTmp = dest->pRight;
      copyBinaryTree(src->pRight, dest->pRight);

      if (dest->pRight != NULL)
         dest->pRight->pParent = dest;
   }
}

/**************************************************
 * BST :: ASSIGNMENT OPERATOR
 * ***********************************************/
template <class T>
BST <T> & BST <T> :: operator = (const BST <T> & rhs) throw (const char *)
{
   if (rhs.root != NULL)
   {
      // Create a new tree by copying the root data
      BNode * pNode = new BNode(rhs.root->data);

      // Copy the rest of the tree
      copyBinaryTree(rhs.root, pNode);

      // Assign the newly created tree to this object
      this->root = pNode;
   }
   
   return *this;
}

/**************************************************
 * BST :: INSERT
 * ***********************************************/
template <class T>
void BST <T> :: insert(const T & t) throw (const char *)
{
   BNode * temp = new BNode();
   temp->data = t;
   //Case 1: No Parent
   if (root == NULL)
   {
      root = temp;

      //need to set is isRed as false. not sure if this is correct
      temp->isRed = false;
      return;
   }

   //Case 2: Parent is black
   if (temp->pParent->isRed == false)
   {
      //insert to left if temp is less than parent

      //insert to right if temp is more than parent
      return;
   }

   //Case 3: Parent and aunt are red
   if (temp->pParent->isRed == true)//and anut is red. how do I find/define aunt)
   {
      //insert to left if temp is less than parent

      //insert to right if temp is more than parent
      return;
   }

   //Case 4: Parent is red, aunt is black or non existant
   if (temp->pParent->isRed == false) //and aunt is black or NULL)
   {
      //insert to left if temp is less than parent

      //insert to right if temp is more than parent
      return;
   }

}

/**************************************************
 * BST :: ERASE
 * ***********************************************/
template <class T>
void BST <T> :: erase(BST <T> :: iterator & it)
{
   BNode * temp = it.nodes.top();

   //Case 1: No children
   if (temp->pLeft == NULL && temp->pRight == NULL)
   {
      if (temp->pParent != NULL && temp->pParent->pRight == temp)
      {
         temp->pParent->pRight = NULL;
      }
      if (temp->pParent != NULL && temp->pParent->pLeft == temp)
      {
         temp->pParent->pLeft = NULL;
      }
      delete temp;
   }

   //Case 2: One Child
   //Check left
   if (temp->pRight == NULL && temp->pLeft != NULL)
   {
      temp->pRight->pParent = temp->pParent;
      if (temp->pParent != NULL && temp->pParent->pRight == temp)
      {
         temp->pParent->pRight = temp->pLeft;
      }
      if (temp->pParent != NULL && temp->pParent->pLeft == temp)
      {
         temp->pParent->pLeft = temp->pLeft;
      }
      delete temp;
   }  

   //Check right
   if (temp->pLeft == NULL && temp->pRight != NULL)
   {
      temp->pRight->pParent = temp->pParent;
      if (temp->pParent != NULL && temp->pParent->pRight == temp)
      {
         temp->pParent->pRight = temp->pRight;
      }
      if (temp->pParent != NULL && temp->pParent->pLeft == temp)
      {
         temp->pParent->pLeft = temp->pRight;
      }
      delete temp;
   } 

   //Case 3: Two Children
   if (temp->pLeft != NULL && temp->pRight != NULL)
   {
      //TODO: code here
   }
}





/**************************************************
 * BST :: CLEAR
 * ***********************************************/
template <class T>
void BST <T> :: clear()
{

}

/**************************************************
 * BST :: FIND
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: find(const T & t)
{

}

/**************************************************
 * BST :: BEGIN
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: begin()
{

}

/**************************************************
 * BST :: BEGIN (CONST)
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: begin() const
{

}

/**************************************************
 * BST :: RBEGIN
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: rbegin()
{

}

/**************************************************
 * BST :: BEGIN (CONST)
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: rbegin() const
{

}

} // namespace custom

#endif // BST_H
