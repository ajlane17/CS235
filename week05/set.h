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

   // operator overloading (These probably need to be changed,
   //    but I wanted to put what the book had in until we can fix it)
   set <T> set <T> :: operator || (const set <T> & rhs) const throw (const char *);
   set <T> set <T> :: operator && (const set <T> & rhs) const throw (const char *);
   set <T> set <T> :: operator - (const set <T> & rhs) const throw (const char *);
   
   // the various iterator interfaces
   class iterator;
   iterator fintd(T t);
   void insert(T t);
   iterator erase (iterator it);
   iterator begin()                    { return iterator (data); }
   iterator end();

   // constant iterator
   class const_iterator;
   const_iterator cbegin() const { return const_iterator (data); }
   const_iterator cend() const;
   
   // a debug utility to display the array
   // this gets compiled to nothing if NDEBUG is defined
   void display() const; 
   
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


/********************************************
 * SET :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename set <T> :: iterator set <T> :: end ()
{
   return iterator (data + numElements);
}

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


/********************************************
 * SET :: C_END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename set <T> :: const_iterator set <T> :: cend () const
{
   return const_iterator (data + numElements);
}

/*******************************************
 * SET :: Assignment
 *******************************************/
template <class T>
set <T> & set <T> :: operator = (const set <T> & rhs)
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

/*******************************************
 * SET :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
   set <T> :: set(const set <T> & rhs) throw (const char *):
data(NULL), numCapacity(0), numElements(0)
{
   assert(rhs.numCapacity >= 0);
   
   
}

/**********************************************
 * SET : NON-DEFAULT CONSTRUCTOR
 * Preallocate the set to "capacity"
 **********************************************/
template <class T>
set <T> :: set(int numElements) throw (const char *):
data(NULL), numCapacity(0), numElements(0)
{
   assert(numElements >= 0);

   if (numElements > 0)
   {
      resize(numElements);
      this->numElements = numElements;
   }
}

/********************************************
 * SET : DISPLAY
 * A debug utility to display the contents of the set
 *******************************************/
template <class T>
void set <T> :: display() const
{
#ifndef NDEBUG
   std::cerr << "set<T>::display()\n";
   std::cerr << "\tnumElements = " << numElements << "\n";
   for (int i = 0; i < numElements; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";
#endif // NDEBUG
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

/********************************************
 * SET : PUSH_BACK
 * A method used to add to the set and
 * resize it if it is needed.
 *******************************************/
template <class T>
void set <T> :: push_back(T t)
{
   // check if set is empty
   if (numElements == 0)
   {
      resize(1);
   }
   // check if set is full
   else if (numElements == numCapacity)
   {
      resize(numCapacity * 2);
   }

   // add new element to set
   data[numElements++] = t;

}

}; // namespace custom

#endif // SET_H

