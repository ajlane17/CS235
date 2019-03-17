/***********************************************************************
 * Header:
 *    Stack
 * Summary:
 *    This class contains the notion of a stack: a container that only 
 *    works by interacting with the last element in the collection, with
 *    functionality that follows last-in-first-out.
 *
 *    This will contain the class definition of:
 *       stack          : similar to std::stack
 *       
 * Authors
 *    Adrian Lane, Ethan Holden
 ************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <new>

// For debugging purposes
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{
   /************************************************
    * STACK
    * A class that is a container using FILO
    ***********************************************/
   template <class T>
   class stack
   {
      public:
         // Constructors and desctructors
         stack() : data(NULL), numElements(0), numCapacity(0)      {}
         stack(int numCapacity)                 throw (const char *):
          data(NULL), numCapacity(numCapacity), numElements(0)     {}
         stack(const stack & rhs)               throw (const char *):
          data(NULL), numCapacity(0), numElements(0)
          { if (!rhs.empty()) *this = rhs; }
        ~stack()                                { delete [] data;   }
         stack & operator = (const stack & rhs) throw (const char *);

         // standard container interfaces
         int size() const                     { return numElements; }
         int capacity() const                 { return numCapacity; }
         bool empty() const              { return numElements == 0; }
         void clear()                            { numElements = 0; }
         
         // Stack-specific interfaces
         void push(const T & t)                 throw (const char *);
         void pop()                             throw (const char *);
         T & top()                              throw (const char *);
         T top() const                          throw (const char *);
         

      private: 
         T * data;             // dynamically allocated stack of T
         int numElements;      // the number of elements in the stack
         int numCapacity;      // the total capacity of the stack

         // Resizes capacity to set size
         void resize(int newCapacity)           throw (const char *);
            
   }; // STACK

   /********************************************
    * STACK :: Assignment
    ********************************************/
   template <class T>
   stack <T> & stack <T> :: operator = (const stack <T> & rhs)
      throw (const char *)
   {
      // set size equal to rhs
      numElements = rhs.numElements;
      
      // new stack only needs as much capacity as the
      //        number of elements
      numCapacity = numElements;

      // attempt to allocate
      try
      {
         data = new T[numCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for stack";
      }

      // move the data over
      for (int i = 0; i < numElements; i++)
         data[i] = rhs.data[i];
      return *this;
      
   }

   /********************************************
    * STACK :: PUSH
    * Adds a new element to the top of the stack
    ********************************************/
   template <class T>
   void stack <T> :: push(const T & t) throw (const char *)
   {
      // check if stack is empty
      if (numElements == 0)
      {
         resize(1);
      }
      // check if stack is full
      if (numElements == numCapacity)
      {
         resize(numCapacity * 2);
      }

      // add new element to stack
      data[numElements++] = t;
   }
   
   /********************************************
    * STACK :: POP
    * Deletes the top element from the stack
    ********************************************/
   template <class T>
   void stack <T> :: pop() throw (const char *)
   {
      if (data != NULL)
      {
         T *pNew;
         // attempt to allocate
         try
         {
            pNew = new T[--numElements];
         }
         catch (std::bad_alloc)
         {
            throw "ERROR: Unable to allocate a new buffer for stack";
         }

         // move the data over
         for (int i = 0; i < numElements; i++)
            pNew[i] = data[i];
         // delete the old data and reassign the new
         if (NULL != data)
            delete [] data;
         data = pNew;
         numCapacity = numElements;
      }
   }
   
   /********************************************
    * STACK :: TOP
    * Returns the last element
    ********************************************/
   template <class T>
   T & stack <T> :: top() throw (const char *)
   {
      if (!empty())
         return data[numElements - 1];
      else
         throw "ERROR: Unable to reference the element from an empty Stack";
   }

   /********************************************
    * STACK :: TOP (READ ONLY)
    * Returns a read-only version of the last element
    ********************************************/
   template <class T>
   T stack <T> :: top() const throw (const char *)
   {
      if (!empty())
         return data[numElements - 1];
      else
         throw "ERROR: Unable to reference the element from an empty Stack";
   }

   /********************************************
    * STACK :: Resize
    * Resizes the capacity of the stack to the specified size
    ********************************************/
   template <class T>
   void stack <T> :: resize(int newCapacity) throw (const char *)
   {
      // allocate a new array
      T *pNew;
      try
      {
         pNew = new T[newCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for stack";
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

#endif // STACK_H
