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
         stack(int numCapacity)                 throw (const char *);
         stack(const stack & rhs)               throw (const char *);
        ~stack()                                { delete [] data;   }
         stack & operator = (const stack & rhs) throw (const char *);

         // standard container interfaces
         int size() const                     { return numElements; }
         int capacity() const                 { return numCapacity; }
         bool empty() const              { return numElements == 0; }
         void clear()                            { numElements = 0; }
         
         // Stack-specific interfaces
         void push(const T & t)                 throw (const char *);
         void pop();
         T & top()                              throw (const char *);
         const & T top() const                  throw (const char *);
         

      private: 
         T * data;             // dynamically allocated stack of T
         int numElements;      // the number of elements in the stack
         int numCapacity;      // the total capacity of the stack
   }; // STACK

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
         throw "ERROR: Unable to reference the element from an empty stack";
   }

   /********************************************
    * STACK :: TOP (READ ONLY)
    * Returns a read-only version of the last element
    ********************************************/
   template <class T>
   const T & stack <T> :: top() const throw (const char *)
   {
      if (!empty())
         return data[numElements - 1];
      else
         throw "ERROR: Unable to reference the element from an empty stack";
   }

}; // namespace custom

#endif // STACK_H
