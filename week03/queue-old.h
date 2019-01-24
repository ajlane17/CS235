/***********************************************************************
 * Header:
 *    Queue
 * Summary:
 *    This class contains the notion of a queue: a container that only 
 *    works by interacting with the first and last elements in the
 *    collection, with functionality that follows first-in-first-out.
 *
 *    This will contain the class definition of:
 *       queue          : similar to std::queue
 *       
 * Authors
 *    Adrian Lane, Ethan Holden
 ************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

// For debugging purposes
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

#include <cassert>

namespace custom
{
   /************************************************
    * QUEUE
    * A class that is a container using FIFO
    ***********************************************/
   template <class T>
   class queue
   {
      public:
         // Constructors and desctructors
         queue() : data(NULL), numPush(0), numPop(0), numCapacity(0)
          {}
         queue(int numCapacity)                 throw (const char *);
         queue(const queue & rhs)               throw (const char *);
         ~queue()                                { delete [] data; }
         queue & operator = (const queue & rhs) throw (const char *);

         // standard container interfaces
         int size() const             { return (numPush - numPop); }
         bool empty() const                { return (size() == 0); }
         void clear();
         
         // Queue-specific interfaces
         void push(const T & t)                 throw (const char *);
         void pop()                             throw (const char *);
         T & front()                            throw (const char *);
         T front() const                        throw (const char *);
         T & back()                             throw (const char *);
         T back() const                         throw (const char *);
         

      private: 
         T * data;               // dynamically allocated queue of T
         int numPush;          // The number of times push is called
         int numPop;            // The number of times pop is called
         int numCapacity;         // the total capacity of the queue

         // Resizes capacity to set size
         void resize(int newCapacity)           throw (const char *);
         int iHead() const        { return (numPop % numCapacity); }
         int iTail() const { return ((numPush - 1) % numCapacity); }
            
   }; // QUEUE

   /********************************************
    * QUEUE :: NON-DEFAULT CONSTRUCTOR
    ********************************************/
   template <class T>
   queue <T> :: queue(int numCapacity) throw (const char *)
   {
      numPush = 0;
      numPop = 0;
      this->numCapacity = numCapacity;

      try
      {
         data = new T[numCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for queue";
      }
   }

   /********************************************
    * QUEUE :: COPY CONSTRUCTOR
    ********************************************/
   template <class T>
   queue <T> :: queue(const queue & rhs) throw (const char *)
   {
      std::cout << "numCpacity: " << numCapacity << std::endl;
      if (!(rhs.numCapacity < 0))
      {
         *this = rhs;
      }
      else
      {
         throw "ERROR: Unable to allocate a new buffer for queue";
      }
   }

   /********************************************
    * QUEUE :: ASSIGNMENT
    ********************************************/
   template <class T>
   queue <T> & queue <T> :: operator = (const queue <T> & rhs)
      throw (const char *)
   {
      // reallocate capacity if needed.
      if (numCapacity < rhs.size())
      {
         resize(rhs.size());
      }

      // attempt to allocate
      try
      {
         data = new T[numCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for stack";
      }

      // Reset push and pop
      numPush = 0;
      numPop = 0;

      // move the data over
      // for (int i = 0; i < size(); i++)
      //    data[i] = rhs.data[i];
      for (int i = rhs.numPop; i < rhs.numPush; i++)
      {
         this->push(rhs.data[i % rhs.numCapacity]);
      }

      return *this;
   }

   /********************************************
    * QUEUE :: CLEAR
    * Clears the queue of all data
    ********************************************/
   template <class T>
   void queue <T> :: clear()
   {
      delete [] data;
      data = NULL;
      numPush = 0;
      numPop = 0;
   }
   
   /********************************************
    * QUEUE :: PUSH
    * Adds a new element to the back of the queue
    ********************************************/
   template <class T>
   void queue <T> :: push(const T & t) throw (const char *)
   {
      if (size() == numCapacity)
         resize(numCapacity * 2);
      numPush++;
      data[iTail()] = t;
   }
   
   /********************************************
    * QUEUE :: POP
    * Deletes the front element from the queue
    ********************************************/
   template <class T>
   void queue <T> :: pop() throw (const char *)
   {
      if(!empty())
      {
         //data[iHead()] = NULL;
         numPop++;
      }
   }
   
   /********************************************
    * QUEUE :: FRONT
    * Returns the first element
    ********************************************/
   template <class T>
   T & queue <T> :: front() throw (const char *)
   {
      if (empty())
         throw "ERROR: attempting to access an element in an empty queue";
      else
         return data[iHead()];
   }

   /********************************************
    * QUEUE :: FRONT (READ ONLY)
    * Returns a read-only version of the first element
    ********************************************/
   template <class T>
   T queue <T> :: front() const throw (const char *)
   {
      if (empty())
         throw "ERROR: attempting to access an element in an empty queue";
      else
         return data[iHead()];
   }

   /********************************************
    * QUEUE :: Back
    * Returns the last element
    ********************************************/
   template <class T>
   T & queue <T> :: back() throw (const char *)
   {
      if (empty())
         throw "ERROR: attempting to access an element in an empty queue";
      else
         return data[iTail()];
   }

   /********************************************
    * QUEUE :: BACK (READ ONLY)
    * Returns a read-only version of the last element
    ********************************************/
   template <class T>
   T queue <T> :: back() const throw (const char *)
   {
      if (empty())
         throw "ERROR: attempting to access an element in an empty queue";
      else
         return data[iTail()];
   }

   /********************************************
    * QUEUE :: Resize
    * Resizes the capacity of the queue to the specified size
    ********************************************/
   template <class T>
   void queue <T> :: resize(int newCapacity) throw (const char *)
   {
      T * pNew;

      try
      {
         pNew = new T[newCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for stack";
      }

      // move the data over
      int j = 0;
      for (int i = numPop; i < numPush; i++)
      {
         pNew[j] = data[i];
         j++;
      }

      delete [] data;
      data = pNew;

      numPop = 0;
      numPush = size();
   }

}; // namespace custom

#endif // QUEUE_H
