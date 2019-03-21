/***********************************************************************
 * Component:
 *    Assignment 09, Binary Search Tree (BST)
 *    Brother Kirby, CS 235
 * Author:
 *    Adrian Lane, Kenyon Bunker, Ethan Holden
 * Summary:
 *    Create a binary search tree
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include <cassert>
#include <cstddef> 
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
      void deleteNode(BNode * pNode, bool right); 
      void deleteBinaryTree(BNode * & pNode);
      void copyBinaryTree(const BNode * src, BNode * dest);
      //Red Black Methods
      void balance(BNode * temp);
      void rotateLeft(BNode *& temp);
      void rotateRight(BNode *& temp);
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
      BNode() :pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true),
         data() {}
      BNode(const T & t) :pLeft(NULL), pRight(NULL), pParent(NULL), 
         isRed(true), data(t) {}
      ~BNode() {}

      // Red-Black Balancing helpers
      void verifyBTree();
      void findDepth();
      void verifyRedBlack(int depth);
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
      // If a stack is passed, assign it to nodes
      iterator(stack <BNode *> & nodeStack)
      {
         nodes = nodeStack;
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
      // BST needs access to the private stack in order to traverse 
      // the using the iterator.
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
   // if (pSave == nodes.top()->pRight)
   //    return *this;

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
      dest->pLeft = pLeftTmp;
      copyBinaryTree(src->pLeft, dest->pLeft);

      if (dest->pLeft != NULL)
         dest->pLeft->pParent = dest;
   }

   // Move down the right side
   if (src->pRight != NULL)
   {
      BNode * pRightTmp = new BNode();
      dest->pRight = pRightTmp;
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
      BNode * pNewTree = new BNode();

      // Copy the rest of the tree
      copyBinaryTree(rhs.root, pNewTree);

      // Assign the newly created tree to this object
      this->root = pNewTree;

      // Set the size
      this->numElements = rhs.numElements;
   }
   
   return *this;
}

/**************************************************
 * BST :: INSERT
 * ***********************************************/
template <class T>
void BST <T> :: insert(const T & t) throw (const char *)
{
   //Case 1: No Parent
   if (root == NULL)
   {
      // Create a new BNode and create a new root, root is always black
      BNode * temp = new BNode(t);
      temp->isRed = false;
      root = temp;
      numElements++;
      return;
   }

   // Create a traversal node and start at root
   // Create a node pointer to track current position
   BNode * pBTree = root;
   BNode * pCurPos = NULL;

   // using <=>, find location for new item
   while (pBTree != NULL)
   {
      // Store the current position prior to NULL
      // This will be our parent node for assignment
      pCurPos = pBTree;

      // Compare to determine which direction to go
      if (pBTree->data >= t)
      {
         pBTree = pBTree->pLeft;
      }
      else
      {
         pBTree = pBTree->pRight; 
      }
   }

   // Create the node to insert into the tree
   BNode * pNew = new BNode(t);
   pNew->pParent = pCurPos;

   // New node goes left
   if (pCurPos->data >= t)
   {
      pCurPos->pLeft = pNew;
      numElements++;
   }
   // New node goes right
   else
   {
      pCurPos->pRight = pNew;
      numElements++;
   }
   // balance(pNew);
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
   //Case 2: One Child: Check left
   if (temp->pRight == NULL && temp->pLeft != NULL)
   {
      temp->pLeft->pParent = temp->pParent;
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

   //Case 2: One Child: Check right
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
      //if no grandchildren, or only right grandchild then right replaces node
      if ((temp->pRight->pRight == NULL && temp->pRight->pLeft == NULL) ||
          (temp->pRight->pRight != NULL && temp->pRight->pLeft == NULL))
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
            
      //if there is a left grandchild, node is replaced by left
      //   grandchild and it's right child replaces it.
      else if (temp->pRight->pLeft != NULL)
      {
         BNode * leftMin = temp->pRight;
         while(leftMin->pLeft != NULL)
         {
            leftMin = leftMin->pLeft;
         }

         temp->data = leftMin->data;

         if (leftMin->pRight == NULL)
         {
            leftMin->pParent->pLeft = NULL;
            delete leftMin;
         }
         else
         {
            leftMin->pRight->pParent = leftMin->pParent;
            leftMin->pParent->pLeft = leftMin->pRight;
            delete leftMin;
         }
      }
   }
}

/**************************************************
 * BST :: CLEAR
 * ***********************************************/
template <class T>
void BST <T> :: clear()
{
   deleteBinaryTree(root);
   root = NULL;
   numElements = 0;
}

/**************************************************
 * BST :: FIND
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: find(const T & t)
{
   BNode * pBTree = root;

   while (pBTree != NULL)
   {
      //std::cout << "Start Find Loop\n";
      if (pBTree->data > t)
      {
         //std::cout << "Went Left: ";
         pBTree = pBTree->pLeft;
         //std::cout << pBTree->data << std::endl;
      }
      else if (pBTree->data < t)
      {
         //std::cout << "Went Right: ";
         pBTree = pBTree->pRight;
         //std::cout << pBTree->data << std::endl;
      }
      else if (pBTree->data == t)
         return iterator(pBTree);
   }

   return iterator(NULL);
}

/**************************************************
 * BST :: BEGIN
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: begin()
{
   // If the tree is empty, return NULL
   if (root == NULL)
      return iterator(NULL);

   // Create a new stack to pop the left nodes onto
   
   stack <BNode *> nodeStack;

   // Push a NULL point first to signify the end is reached
   nodeStack.push(NULL);

   // Start top-down so begin is the left-most bottom node
   BNode * pBTree = root;

   while (pBTree != NULL)
   {
      nodeStack.push(pBTree);
      pBTree = pBTree->pLeft;
   }

   // Return an iterator with the complete node path
   return iterator(nodeStack);
}

/**************************************************
 * BST :: BEGIN (CONST)
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: begin() const
{
   // If the tree is empty, return NULL
   if (root == NULL)
      return iterator(NULL);

   // Create a new stack to pop the left nodes onto
   
   stack <BNode *> nodeStack;

   // Push a NULL point first to signify the end is reached
   nodeStack.push(NULL);

   // Start top-down so begin is the left-most bottom node
   BNode * pBTree = root;

   while (pBTree != NULL)
   {
      nodeStack.push(pBTree);
      pBTree = pBTree->pLeft;
   }

   // Return an iterator with the complete node path
   return iterator(nodeStack);
}

/**************************************************
 * BST :: RBEGIN
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: rbegin()
{
   // If the tree is empty, return NULL
   if (root == NULL)
      return iterator(NULL);

   // Create a new stack to pop the right nodes onto
   
   stack <BNode *> nodeStack;

   // Push a NULL point first to signify the end is reached
   nodeStack.push(NULL);

   // Start top-down so begin is the right-most bottom node
   BNode * pBTree = root;

   while (pBTree != NULL)
   {
      nodeStack.push(pBTree);
      pBTree = pBTree->pRight;
   }

   // Return an iterator with the complete node path
   return iterator(nodeStack);
}

/**************************************************
 * BST :: RBEGIN (CONST)
 * ***********************************************/
template <class T>
typename BST <T> :: iterator BST <T> :: rbegin() const
{
   // If the tree is empty, return NULL
   if (root == NULL)
      return iterator(NULL);

   // Create a new stack to pop the right nodes onto
   
   stack <BNode *> nodeStack;

   // Push a NULL point first to signify the end is reached
   nodeStack.push(NULL);

   // Start top-down so begin is the right-most bottom node
   BNode * pBTree = root;

   while (pBTree != NULL)
   {
      nodeStack.push(pBTree);
      pBTree = pBTree->pRight;
   }

   // Return an iterator with the complete node path
   return iterator(nodeStack);
}

/**************************************************
 * BST :: DELETE BINARY TREE
 * ***********************************************/
template <class T>
void BST <T> :: deleteBinaryTree(BNode * & pNode)
{
   if (pNode == NULL)
      return;
   
   // Recursively delete all nodes using LRV (Post-Order Traversal)
   deleteBinaryTree(pNode->pLeft);
   deleteBinaryTree(pNode->pRight);
   delete pNode;
   // After deleting the data, set the pointer to NULL
   pNode = NULL;
}

/**************************************************
 * BST :: BALANCE
 * ***********************************************/
template <class T>
void BST<T>::balance(BNode * temp)
{
   // root has to be black
   if (temp == root)
   {
      temp->isRed = false;
      return;
   }

   BNode * aunt;
   // work our way through the tree to the root
   while(temp->pParent != NULL && temp->pParent->isRed == true)
   {
      BNode * grandparent = temp->pParent->pParent;
      // if the parent is the left child of the grandparent
      if (grandparent->pLeft == temp->pParent)
      {
         // if a right aunt exists and is red
         if (grandparent->pRight != NULL)
         {
            aunt = grandparent->pRight;
            if (aunt->isRed == true)
            {
               // set parent and aunt to black and grandparent to red.
               temp->pParent->isRed = false;
               aunt->isRed = false;
               grandparent->isRed = true;
               
               //move up the tree and repeat the while loop
               temp = grandparent;  
            }
         }
         // else if there is no right aunt 
         else
         {
            // and the node is the right child
            if (temp->pParent->pRight == temp)
            {
               // move up the tree and rotate left what used to be the parent.
               temp = temp->pParent;
               rotateLeft(temp);
            }
            // then set parent to black, grandparent to red
            //    and rotate right grandparent
            temp->pParent->isRed = false;
            grandparent->isRed = true;
            temp = grandparent;
            rotateRight(temp);
         }
      }
      else
      {
         // if a left aunt exists and is red
         if (grandparent->pLeft != NULL)
         {
            aunt = grandparent->pLeft;
            if (aunt->isRed == true)
            {
               // set parent and aunt to black and grandparent to red
               temp->pParent->isRed = false;
               aunt->isRed = false;
               grandparent->isRed = true;
               // move up the tree and repeat the while loop
               temp = grandparent;
            }
         }
         else
         {
            //if temp is left child, move up and rotate right the parent
            if (temp->pParent->pLeft == temp)
            {
               temp = temp->pParent;
               rotateRight(temp);
            }
            // then set parent to black, grandparent to red
            //    and rotate right grandparent
            temp->pParent->isRed = false;
            grandparent->isRed = true;
            temp = grandparent;
            rotateLeft(temp);
         }
      }
      //make sure root stays black
      root->isRed = false;
   }
}

/**************************************************
 * BST :: ROTATELEFT
 * ***********************************************/
template <class T>
   void BST<T>::rotateLeft(BNode *& temp)
{
   // if there is no right check if there is a left of the left
   //   and rotate so the left becomes the node with the node and
   //   the grandchild as children
   if (temp->pRight == NULL)
   {
      return;
      if (temp->pLeft == NULL)
      {
         return;
      }
      if (temp->pLeft->pLeft != NULL)
      {
         temp->pLeft->pParent = temp->pParent;
         temp->pLeft->pRight = temp;
         if (temp == temp->pParent->pLeft)
            temp->pParent->pLeft = temp->pLeft;
         else
            temp->pParent->pRight = temp->pLeft;
         temp->pLeft = NULL;
      }
      // if no left grandchild do nothing
      return;
   }
   else
   {
      // if right has a left right's left bcomes the node's right
      BNode * right = temp->pRight;
      if (right->pLeft != NULL)
      {
         temp->pRight = right->pLeft;
         right->pLeft->pParent = temp;
      }
      else
         // else the node's right is NULL
         temp->pRight = NULL;

      // if the node has a parent, set right to be the parent's right
      //   else if the node is the root, set right as the new root.
      if (temp->pParent != NULL)
         right->pParent = temp->pParent;
      if (temp->pParent == NULL)
      {
         root = right;
         right->pParent = NULL;
      }
      else
      {
         if (temp == temp->pParent->pLeft)
            temp->pParent->pLeft = right;
         else
            temp->pParent->pRight = right;
      }
      // update pointers appropriately
      right->pLeft = temp;
      temp->pParent = right;
   }
}

/**************************************************
 * BST :: ROTATE RIGHT
 * ***********************************************/
template <class T>
   void BST<T>::rotateRight(BNode *& temp)
{
   // if there is no left check if there is a right of the right
   //   and rotate so the right becomes the node with the node and
   //   the grandchild as children
   if (temp->pLeft == NULL)
   {
      if (temp->pRight->pRight != NULL)
      {
         temp->pRight->pParent = temp->pParent;
         temp->pRight->pLeft = temp;
         if (temp == temp->pParent->pLeft)
            temp->pParent->pLeft = temp->pRight;
         else
            temp->pParent->pRight = temp->pRight;
         temp->pLeft = NULL;
      }
      // if no left grandchild do nothing
      return;
   }
   else
   {
      // if left has a left left's right bcomes the node's left
      BNode * left = temp->pLeft;
      if (left->pLeft != NULL)
      {
         temp->pLeft = left->pRight;
         left->pLeft->pParent = temp;
      }
      // else the node's right is NULL
      else
         temp->pLeft = NULL;

      // if the node has a parent, set left to be the parent's left
      //   else if the node is the root, set left as the new root.
      if (temp->pParent != NULL)
         left->pParent = temp->pParent;
      if (temp->pParent == NULL)
      {
         root = left;
         left->pParent = NULL;
      }
      else
      {
         if (temp == temp->pParent->pLeft)
            temp->pParent->pLeft = left;
         else
            temp->pParent->pRight = left;
      }
      // update pointers appropriately
      left->pRight = temp;
      temp->pParent = left;
   }
}

} // namespace custom

#endif // BST_H
