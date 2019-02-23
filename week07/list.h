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

/**************************************************
 * LIST
 * A linked list
 *************************************************/
template <class T>
class list
{
   public:
      list() : pHead(NULL), pTail(NULL), numElements(0)                      {}
      list(list & rhs)                                    throw (const char *);
      ~list();

      list & operator = (const list <T> & rhs)            throw (const char *);
   
      int size() const                                    {return numElements;}
      bool empty() const                                {return pHead == NULL;}
      void clear();

      void push_back(const T & t)                         throw (const char *);
      void push_front(const T & t)                        throw (const char *);
      void pop_back();
      void pop_front();
      
      T & front()                                         throw (const char *);
      T front() const                                     throw (const char *);
      T & back()                                          throw (const char *);
      T back() const                                      throw (const char *);

      class iterator;
      iterator insert(iterator & it, const T & t)         throw (const char *);
      iterator find(const T & t);
      void erase(iterator & it);

      iterator begin()                               {return iterator (pHead);}
      iterator begin() const                         {return iterator (pHead);}
      iterator end()                                  {return iterator (NULL);}
      iterator end() const                            {return iterator (NULL);}

      class const_iterator;
      const_iterator cbegin() const            {return const_iterator (pHead);}
      const_iterator cend() const               {return const_iterator (NULL);}

      class reverse_iterator;
      reverse_iterator rbegin()              {return reverse_iterator (pTail);}
      reverse_iterator rend()                 {return reverse_iterator (NULL);}

      class const_reverse_iterator;
      const_reverse_iterator crbegin() const {return reverse_iterator (pTail);}
      const_reverse_iterator crend() const    {return reverse_iterator (NULL);}

   private:
      class Node;
      Node * pHead;
      Node * pTail;
      int numElements;
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
      iterator(Node * p) : p(p)         {              }
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
      T & operator * ()       { return p->data; }
      const T & operator * () const { return p->data; }

      // prefix increment
      iterator & operator ++ ()
      {
         p = p->pNext;
         return *this;
      }

      // postfix increment
      iterator operator ++ (int postfix)
      {
         iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }

      // prefix decrement
      iterator & operator -- ()
      {
         p = p->pPrev;
         return *this;
      }

      // postfix decrement
      iterator operator -- (int postfix)
      {
         iterator tmp(*this);
         p = p->pPrev;
         return tmp;
      }

   private:
      typename list <T> :: Node * p;
   
   friend iterator list <T> :: insert(iterator & it, const T & t) throw (const char *);
   friend void list <T> :: erase(iterator & it);
};

/**************************************************
 * LIST CONST ITERATOR
 * An iterator through the linked list
 *************************************************/
template <class T>
class list <T> :: const_iterator
{
   public:
      // constructors, destructors, and assignment operator
      const_iterator()      : p(NULL)               {              }
      const_iterator(Node * p) : p(p)               {              }
      const_iterator(const const_iterator & rhs)    { *this = rhs; }
      const_iterator & operator = (const const_iterator & rhs)
      {
         this->p = rhs.p;
         return *this;
      }

      // equals, not equals operator
      bool operator != (const const_iterator & rhs) const
      {
         return rhs.p != this->p;
      }
      bool operator == (const const_iterator & rhs) const
      {
         return rhs.p == this->p;
      }

      // dereference operator
      const T & operator * () const { return p->data; }

      // prefix increment
      const_iterator & operator ++ ()
      {
         p = p->pNext;
         return *this;
      }

      // postfix increment
      const_iterator operator ++ (int postfix)
      {
         const_iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }

      // prefix decrement
      const_iterator & operator -- ()
      {
         p = p->pPrev;
         return *this;
      }

      // postfix decrement
      const_iterator operator -- (int postfix)
      {
         const_iterator tmp(*this);
         p = p->pPrev;
         return tmp;
      }

   private:
      typename list <T> :: Node * p;
   
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
      reverse_iterator(Node * p) : p(p)         {              }
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
      T & operator * ()       { return p->data; }
      const T & operator * () const { return p->data; }

      // prefix increment
      reverse_iterator & operator ++ ()
      {
         p = p->pPrev;
         return *this;
      }

      // postfix increment
      reverse_iterator operator ++ (int postfix)
      {
         reverse_iterator tmp(*this);
         p = p->pPrev;
         return tmp;
      }

      // prefix decrement
      reverse_iterator & operator -- ()
      {
         p = p->pNext;
         return *this;
      }

      // postfix decrement
      reverse_iterator operator -- (int postfix)
      {
         reverse_iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }

  private:
   typename list <T> :: Node * p;
   
};

/**************************************************
 * LIST CONST REVERSE_ITERATOR
 * A reverse iterator through the linked list
 *************************************************/
template <class T>
class list <T> :: const_reverse_iterator
{
  public:
      // constructors, destructors, and assignment operator
      const_reverse_iterator()      : p(NULL)                  {              }
      const_reverse_iterator(Node * p) : p(p)                     {              }
      const_reverse_iterator(const const_reverse_iterator & rhs) {*this = rhs;}
      const_reverse_iterator & operator = (const const_reverse_iterator & rhs)
      {
         this->p = rhs.p;
         return *this;
      }

      // equals, not equals operator
      bool operator != (const const_reverse_iterator & rhs) const
      {
         return rhs.p != this->p;
      }
      bool operator == (const const_reverse_iterator & rhs) const
      {
         return rhs.p == this->p;
      }

      // dereference operator
      const T & operator * () const { return p->data; }

      // prefix increment
      const_reverse_iterator & operator ++ ()
      {
         p = p->pPrev;
         return *this;
      }

      // postfix increment
      const_reverse_iterator operator ++ (int postfix)
      {
         reverse_iterator tmp(*this);
         p = p->pPrev;
         return tmp;
      }

      // prefix decrement
      const_reverse_iterator & operator -- ()
      {
         p = p->pNext;
         return *this;
      }

      // postfix decrement
      const_reverse_iterator operator -- (int postfix)
      {
         const_reverse_iterator tmp(*this);
         p = p->pNext;
         return tmp;
      }

  private:
   typename list <T> :: Node * p;
   
};

/*******************************************
 * LIST :: ASSIGNMENT
 *******************************************/
template <class T>
list <T> & list <T> :: operator = (const list <T> & rhs)
   throw (const char *)
{
   numElements = 0;
   pHead = NULL;
   pTail = NULL;

   if (!(rhs.empty()))
   {
      for (const_iterator it = rhs.cbegin(); it != rhs.cend(); it++)
      {
         this->push_back(*it);
      }
   }
   return *this;
}

/*****************************************************************************
 * COPY CONSTRUCTOR
 * Copy a linked-list
 *****************************************************************************/
template <class T>
list <T> :: list(list <T> & rhs) throw (const char *)
{
   if (!rhs.empty())
   {
      *this = rhs;
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

   numElements = 0;
   pHead = NULL;
   pTail = NULL;
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
   Node * pNew = new Node(t);

   if (pTail == NULL && pHead == NULL)
   {
      pHead = pNew;
      pTail = pNew;
   }
   else 
   {
      pNew->pPrev = pTail;
      pTail->pNext = pNew;
      pNew->pNext = NULL;
      pTail = pNew;
   }

   numElements++;
}

/*****************************************************************************
 * PUSH_FRONT
 * Inserts a node onto the front of the linked-list
 *****************************************************************************/
template <class T>
void list <T> :: push_front(const T & t)           throw (const char *)
{
   Node * pNew = new Node(t);

   if (pHead == NULL)
   {
      pHead = pNew;
      pTail = pNew;
   }
   else 
   {
      pNew->pNext = pHead;
      pHead->pPrev = pNew;
      pNew->pPrev = NULL;
      pHead = pNew;
   }

   numElements++;
}

/*****************************************************************************
 * POP_BACK
 * Removes the last node in the linked-list
 *****************************************************************************/
template <class T>
void list <T> :: pop_back()
{
   pTail = pTail->pPrev;
   delete pTail->pNext;

   numElements--;
}

/*****************************************************************************
 * PUSH_FRONT
 * Removes the first node in the linked-list
 *****************************************************************************/
template <class T>
void list <T> :: pop_front()
{
   pHead = pHead->pNext;
   delete pHead->pPrev;

   numElements--;
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
typename list <T> :: iterator list <T> ::  find(const T & t)
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
void list <T> :: erase(iterator & it)
{
   if (it == end())
      return;

   if (it.p->pPrev)
      it.p->pPrev->pNext = it.p->pNext;
   else
      pHead = pHead->pNext;

   if (it.p->pNext)
      it.p->pNext->pPrev = it.p->pPrev;
   else
      pTail = pTail->pPrev;

   numElements--;
   delete it.p;
}

/*****************************************************************************
 * INSERT
 * Inserts a node into the current linked-list
 *****************************************************************************/
template <class T>
typename list <T> :: iterator list <T> :: insert(iterator & it, const T & t)
   throw (const char *)
{
   Node * pNew = new Node(t);

   if (it != end())
   {
      pNew->pNext = it.p;
      pNew->pPrev = it.p->pPrev;
      it.p->pPrev = pNew;
      
      if (pNew->pPrev)
         pNew->pPrev->pNext = pNew;
      else
         pHead = pNew;
   }
   else
   {
      pTail->pNext = pNew;
      pNew->pPrev = pTail;
      pTail = pNew;
      it.p = pNew;
   }
   
   // add to the size
   numElements++;
   
   // Return the pointer to the newly created node
   return pNew;
}
}

#endif // LIST_H
