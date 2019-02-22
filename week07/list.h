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

namespace custom
{

template <class T>
class list
{
  public:
   list()         {pHead = NULL; pTail = NULL; numElements = 0;}
   list(const list & rhs)                 throw (const char *);
   ~list();
   
   int size() const                       {return numElements;}
   bool empty() const                    {return pHead = NULL;}
   void clear();

   void push_back(const T & t)            throw (const char *);
   void push_front(const T & t)           throw (const char *);
   void pop_back();
   void pop_front();
   
   T & front()                            throw (const char *);
   T front() const                        throw (const char *);
   T & back()                             throw (const char *);
   T back() const                         throw (const char *);

   class iterator;
   iterator find(T & t);
   void erase(iterator it);
   void insert(iterator it, T t);
   iterator begin()                   {return iterator (pHead);}
   iterator end()                     {return iterator (pTail);}

   class reverse_iterator;
   reverse_iterator rbegin() {return reverse_iterator (pTail);}
   reverse_iterator rend() {return reverse_iterator (pHead);}

  private:
   class Node;
   Node pHead();
   Node pTail();
   int numElements;
};

/**************************************************
 * LIST ITERATOR
 * An iterator through the linked list
 *************************************************/
template <class T>
class list <T> :: iterator
{
  public:
   // constructors, destructors, and assignment operator
  iterator()      : p(NULL)      {              }
  iterator(T * p) : p(p)         {              }
   iterator(const iterator & rhs) { *this = rhs; }
   iterator & operator = (const iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const
   {
      return rhs.p != this->p;
   }
   bool operator == (const iterator & rhs) const
   {
      return rhs.p == this->p;
   }

   // dereference operator
   T & operator * ()       { return *p; }
   const T & operator * () const { return *p; }

   // prefix increment
   iterator & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   iterator operator ++ (int postfix)
   {
      iterator tmp(*this);
      p++;
      return tmp;
   }

   // prefix decrement
   iterator & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix decrement
   iterator operator -- (int postfix)
   {
      iterator tmp(*this);
      p--;
      return tmp;
   }

  private:
   T * p;
   
};

/**************************************************
 * LIST REVERSE_ITERATOR
 * A reverse iterator through the linked list
 *************************************************/
template <class T>
class list <T> :: reverse_iterator
{
  public:
   // constructors, destructors, and assignment operator
  reverse_iterator()      : p(NULL)      {              }
  reverse_iterator(T * p) : p(p)         {              }
   reverse_iterator(const reverse_iterator & rhs) { *this = rhs; }
   reverse_iterator & operator = (const reverse_iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const reverse_iterator & rhs) const
   {
      return rhs.p != this->p;
   }
   bool operator == (const reverse_iterator & rhs) const
   {
      return rhs.p == this->p;
   }

   // dereference operator
   T & operator * ()       { return *p; }
   const T & operator * () const { return *p; }

   // prefix increment
   reverse_iterator & operator ++ ()
   {
      p--;
      return *this;
   }

   // postfix increment
   reverse_iterator operator ++ (int postfix)
   {
      reverse_iterator tmp(*this);
      p--;
      return tmp;
   }

   // prefix decrement
   reverse_iterator & operator -- ()
   {
      p++;
      return *this;
   }

   // postfix decrement
   reverse_iterator operator -- (int postfix)
   {
      reverse_iterator tmp(*this);
      p++;
      return tmp;
   }

  private:
   T * p;
   
};

/*****************************************************************************
 * NODE
 * an object that holds data and its relative position
 *****************************************************************************/
template <class T>
class list <T> :: Node
{
   public:
   // Member variables
   T data;
   Node * pNext;
   Node * pPrev;

   // Constructors
   Node() : data(), pNext(NULL), pPrev(NULL) {}
   Node(const T & t) : data(t), pNext(NULL), pPrev(NULL) {}
};

/*****************************************************************************
 * COPY CONSTRUCTOR
 * Copy a linked-list
 *****************************************************************************/
template <class T>
list <T> :: list(const list & rhs) throw (const char *)
{
   Node * pDestination = new Node(rhs->data);
   Node * pDes = pDestination;

   //Copies the data. calls insert
   for (const Node * pSrc = rhs->pNext; pSrc; pSrc = pSrc->pNext)
   {
      pDes = insert(pDes, pSrc->data, true);
   }
}

/*****************************************************************************
 * DESTRUCTOR
 *****************************************************************************/
template <class T>
list <T> :: ~list()
{
   
}

/*****************************************************************************
 * CLEAR
 * Release all the memory contained in a given linked-list
 *****************************************************************************/
template <class T>
void list <T> :: clear()
{
   Node * pDelete;
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
 * PUSH_BACK
 * Inserts a node onto the back of the linked-list
 *****************************************************************************/
template <class T>
void list <T> :: push_back(const T & t)            throw (const char *)
{
   
}

/*****************************************************************************
 * PUSH_FRONT
 * Inserts a node onto the front of the linked-list
 *****************************************************************************/
template <class T>
void list <T> :: push_front(const T & t)           throw (const char *)
{
   
}

/*****************************************************************************
 * POP_BACK
 * Removes the last node in the linked-list
 *****************************************************************************/
template <class T>
void list <T> :: pop_back()
{
   
}

/*****************************************************************************
 * PUSH_FRONT
 * Removes the first node in the linked-list
 *****************************************************************************/
template <class T>
void list <T> :: pop_front()
{
   
}

/*****************************************************************************
 * FRONT
 * Returns the first element
 *****************************************************************************/
template <class T>
T & list <T> :: front() throw (const char *)
{
   if (empty())
      throw "ERROR: unable to access data from an empty list";
   else
      return pHead->data;
}

/*****************************************************************************
 * FRONT (READ ONLY)
 * Returns a read-only version of the first element
 *****************************************************************************/
template <class T>
T list <T> :: front() const throw (const char *)
{
   if (empty())
      throw "ERROR: unable to access data from an empty list";
   else
      return pHead->data;
}

/*****************************************************************************
 * BACK
 * Returns the last element
 *****************************************************************************/
template <class T>
T & list <T> :: back() throw (const char *)
{
   if (empty())
      throw "ERROR: unable to access data from an empty list";
   else
      return pTail->data;
}

/*****************************************************************************
 * BACK (READ-ONLY)
 * Returns a read-only version of the last element
 *****************************************************************************/
template <class T>
T list <T> ::  back() const throw (const char *)
{
   if (empty())
      throw "ERROR: unable to access data from an empty list";
   else
      return pTail->data;
}

/*****************************************************************************
 * FIND
 * Find the node corresponding to the given value from the given linked-list
 *****************************************************************************/
//iterator find(T t);
template <class T>
typename list <T> :: iterator list <T> ::  find(T & t)
{
   // Return the pointer to the found node else NULL
   for(Node * p = pHead; p; p = p->pNext)
   {
      if (p->data == t)
         return p;
   } 
   
   return NULL;
}

/*****************************************************************************
 * ERASE
 * Remove the given node from the linked list it is attached to
 *****************************************************************************/
template <class T>
void list <T> :: erase(iterator it)
{
   Node * pReturn;
   
   // Return point to the previous node if it exists, else return next node
   if (NULL == it)
      return NULL;

   if (it->pPrev)
      it->pPrev->pNext = it->pNext;
   if (it->pNext)
      it->pNext->pPrev = it->pPrev;

   if (it->pPrev)
      pReturn = it->pPrev;
   else
      pReturn = it->pNext;

   delete it;
   it = pReturn;
}

/*****************************************************************************
 * INSERT
 * Inserts a node into the current linked-list
 *****************************************************************************/
template <class T>
void list <T> :: insert(iterator it, T t)
   throw (const char *)
{
   Node * pNew = new Node(t);

   pNew->pNext = it;
   pNew->pPrev = it->pPrev;
   it->pPrev = pNew;
   if (pNew->pPrev)
   {
      pNew->pPrev->pNext = pNew;
   }
   
   // add to the size
   numElements++;
   
   // Return the pointer to the newly created node
   it = pNew;
}
}

#endif // LIST_H
