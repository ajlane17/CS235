/***********************************************************************
 * Header:
 *    Vector
 * Summary:
 *    This class contains the notion of an vector: a bucket to hold
 *    data for the user and can be expanded as needed.
 *
 *    This will contain the class definition of:
 *       vector                   : similar to std::vector
 *       vector :: iterator : an iterator through the vector
 * Author
 *    Br. Helfrich modified by Ethan Holden
 ************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

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
 * VECTOR
 * A class that holds stuff and can be expanded.
 ***********************************************/
template <class T>
class vector
{
public:
   // constructors and destructors
   vector() : data(NULL), numCapacity(0), numElements(0) {}
   vector(int numElements) throw (const char *);
   vector(const vector & rhs)        throw (const char *);
   ~vector()                         { delete [] data;   }
   vector & operator = (const vector & rhs) throw (const char *);
   
   // standard container interfaces
   int  size()     const { return numElements; }
   int  capacity() const { return numCapacity; }

   //vector-specific interfaces
   bool empty() const { return numElements == 0; }
   void clear() { numElements = 0; }
   void push_back(T t);
   
   // array-specific interfaces
   // what would happen if I passed -1 or something greater than num?
   T & operator [] (int index)       throw (const char *)
   {
      if (index < 0 || index > numElements)
         throw "ERROR: Invalid index";
      else
         return data[index];
   }
   const T & operator [] (int index) const throw (const char *)
   {
      if (index < 0 || index > numElements)
         throw "ERROR: Invalid index";
      else
         return data[index];
   }
   
   // the various iterator interfaces
   class iterator;
   iterator begin() { return iterator (data); }
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

   void resize(int numCapacity) throw (const char *);

};

/**************************************************
 * VECTOR ITERATOR
 * An iterator through vector
 *************************************************/
template <class T>
class vector <T> :: iterator
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
 * VECTOR :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename vector <T> :: iterator vector <T> :: end ()
{
   return iterator (data + numElements);
}

/**************************************************
 * VECTOR CONST_ITERATOR
 * A constant iterator through vector
 *************************************************/
template <class T>
class vector <T> :: const_iterator
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
 * VECTOR :: C_END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename vector <T> :: const_iterator vector <T> :: cend () const
{
   return const_iterator (data + numElements);
}

/*******************************************
 * VECTOR :: Assignment
 *******************************************/
template <class T>
vector <T> & vector <T> :: operator = (const vector <T> & rhs)
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
      throw "ERROR: Unable to allocate a new buffer for vector";
   }
   
   assert(numCapacity == rhs.numCapacity);
   for (int i = 0; i < numElements; i++)
      data[i] = rhs.data[i];

   return *this;
}

/*******************************************
 * VECTOR :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
   vector <T> :: vector(const vector <T> & rhs) throw (const char *):
data(NULL), numCapacity(0), numElements(0)
{
   assert(rhs.numCapacity >= 0);
   
   if (!rhs.empty())    // do nothing if there is nothing to do
      *this = rhs;      // reuse the assignment operator
}

/**********************************************
 * VECTOR : NON-DEFAULT CONSTRUCTOR
 * Preallocate the vector to "capacity"
 **********************************************/
template <class T>
vector <T> :: vector(int numElements) throw (const char *):
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
 * VECTOR : DISPLAY
 * A debug utility to display the contents of the vector
 *******************************************/
template <class T>
void vector <T> :: display() const
{
#ifndef NDEBUG
   std::cerr << "vector<T>::display()\n";
   std::cerr << "\tnumElements = " << numElements << "\n";
   for (int i = 0; i < numElements; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";
#endif // NDEBUG
}

/********************************************
 * VECTOR : RESIZE
 * A method used to resize the vector when
 * called upon.
 *******************************************/
template <class T>
void vector <T> :: resize(int newCapacity) throw (const char*)
{
   // allocate a new array
   T *pNew;
   try
   {
      pNew = new T[newCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for vector";
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
 * VECTOR : PUSH_BACK
 * A method used to add to the vector and
 * resize it if it is needed.
 *******************************************/
template <class T>
void vector <T> :: push_back(T t)
{
   // check if vector is empty
   if (numElements == 0)
   {
      resize(1);
   }
   // check if vector is full
   else if (numElements == numCapacity)
   {
      resize(numCapacity * 2);
   }

   // add new element to vector
   data[numElements++] = t;

}

}; // namespace custom

#endif // VECTOR_H

