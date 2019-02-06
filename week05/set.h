/***********************************************************************
 * Header:
 *    Set
 * Summary:
 *    This class contains the notion of an set: a bucket to hold
 *    data for the user and can be expanded as needed.
 *
 *    This will contain the class definition of:
 *       set                   : similar to std::set
 *       set :: iterator : an iterator through the set
 * Author
 *    Adrian Lane, Ethan Holden
 ************************************************************************/

#ifndef SET_H
#define SET_H

#include <cassert>  // because I am paranoid

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{

/************************************************
 * SET
 * A class that holds stuff and can be expanded.
 ***********************************************/
template <class T>
class set
{
public:
   // constructors and destructors
   set() : data(NULL), numCapacity(0), numElements(0)          { }
   set(int numCapacity)                      throw (const char *):
      numCapacity(numCapacity), numElements(0)
      { data = new T[numCapacity]; }
   ~set()                                      { delete [] data; }
   set(const set & rhs)                      throw (const char *):
      data(NULL), numCapacity(0), numElements(0)
      { if (!rhs.empty()) *this = rhs; }
   
   set & operator = (const set & rhs)        throw (const char *);
   
   // standard container interfaces
   int  size() const                       { return numElements; }
   int  capacity() const                   { return numCapacity; }
   bool empty() const                 { return numElements == 0; }
   void clear()                               { numElements = 0; }

   // operator overloading
   set  operator || (const set <T> & rhs) const throw (const char *);
   set  operator && (const set <T> & rhs) const throw (const char *);
   set  operator - (const set <T> & rhs) const throw (const char *);
   
   // the various iterator interfaces
   class iterator;
   iterator fintd(T t);
   void insert(T t);
   iterator erase (iterator it);
   iterator begin()                    { return iterator (data); }
   iterator end()         { return iterator(data + numElements); }

   // constant iterator
   class const_iterator;
   const_iterator cbegin() const { return const_iterator (data); }
   const_iterator cend() const { return const_iterator(data + numElements); }

private:
   T * data;              // dynamically allocated array of T
   int numElements;
   int numCapacity;

   int findIndex(T t);
   void resize(int numCapacity) throw (const char *);

};

/**************************************************
 * SET ITERATOR
 * An iterator through set
 *************************************************/
template <class T>
class set <T> :: iterator
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
 * SET CONST_ITERATOR
 * A constant iterator through set
 *************************************************/
template <class T>
class set <T> :: const_iterator
{
public:
   // constructors, destructors, and assignment operator
   const_iterator()      : p(NULL)      {              }
   const_iterator(T * p) : p(p)         {              }
   const_iterator(const const_iterator & rhs) { *this = rhs; }
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
         T & operator * ()       { return *p; }
   const T & operator * () const { return *p; }

   // prefix increment
   const_iterator & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   const_iterator operator ++ (int postfix)
   {
      const_iterator tmp(*this);
      p++;
      return tmp;
   }

   // prefix decrement
   const_iterator & operator -- ()
   {
      p--;
      return *this;
   }

   // postfix decrement
   const_iterator operator -- (int postfix)
   {
      const_iterator tmp(*this);
      p--;
      return tmp;
   }
   
private:
   T * p;
};

/*******************************************
 * SET :: Assignment
 *******************************************/
template <class T>
set <T> & set <T> :: opera
   tor = (const set <T> & rhs)
          throw (const char *)
{
   // set size equal to rhs
   if (rhs.capacity() != capacity())
   {
      numCapacity = rhs.numCapacity;
   }

   numElements = rhs.numElements;

   // attempt to allocate
      try
   {
      data = new T[rhs.numCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for set";
   }
   
   assert(numCapacity == rhs.numCapacity);
   for (int i = 0; i < numElements; i++)
      data[i] = rhs.data[i];

   return *this;
}

/********************************************
 * SET : FIND
 * A method used to find a given item in the set
 *******************************************/
template <class T>
iterator set <T> :: find(T t)
{
   
}

/********************************************
 * SET : INSERT
 * A method used to insert a given item
 * into the set
 *******************************************/
template <class T>
void set <T> :: insert(T t)
{
   
}

/********************************************
 * SET : RESIZE
 * A method used to resize the set when
 * called upon.
 *******************************************/
template <class T>
void set <T> :: resize(int newCapacity) throw (const char*)
{
   // allocate a new array
   T *pNew;
   try
   {
      pNew = new T[newCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for set";
   }

   // copy over the data
   for (int i = 0; i < numElements; i++)
      pNew[i] = data[i];

   // delete the old data and reassign the new
   if (NULL != data)
      delete [] data;
   data = pNew;
   numCapacity = newCapacity;
}

}; // namespace custom

#endif // SET_H

