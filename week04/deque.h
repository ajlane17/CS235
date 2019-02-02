/***********************************************************************
 * Header:
 *    Deque
 * Summary:
 *    This class contains the notion of a deque: a container that only 
 *    works by interacting with the first and last elements in the
 *    collection, withe ability to manipulate elements on either end, 
 *    as well as add and remove elements at either end.
 *
 *    This will contain the class definition of:
 *       deque          : similar to std::deque
 *       
 * Authors
 *    Adrian Lane, Ethan Holden
 ************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

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
    * DEQUE
    * A class that is a double-ended queue
    ***********************************************/
   template <class T>
   class deque
   {
      public:
         // Constructors and desctructors (inline)
         deque() : iFront(0), iBack(-1), numCapacity(0)                  
            { data = new T[numCapacity]; }
         deque(int numCapacity)                    throw (const char *): 
            iFront(0), iBack(-1), numCapacity(numCapacity) 
            { data = new T[numCapacity]; }                               
        ~deque()                                     { delete [] data; } 
         deque(const deque & rhs)                  throw (const char *): 
            data(NULL), iFront(0), iBack(-1), numCapacity(0)
            { if (!rhs.empty()) *this = rhs; }
        // Operators (prototypes)
         deque & operator = (const deque & rhs)    throw (const char *); 

         // standard container interfaces
         int size() const               { return (iBack - iFront + 1); } 
         bool empty() const                    { return (size() == 0); } 
         void clear()                       { iFront = 0; iBack = -1; }; 
         
         // Deque-specific interfaces
         void push_front(const T & t)              throw (const char *); 
         void push_back(const T & t)               throw (const char *); 
         void pop_front();
         void pop_back();
         T & front()                               throw (const char *); 
         T front() const                           throw (const char *); 
         T & back()                                throw (const char *); 
         T back() const                            throw (const char *); 

      private: 
         T * data;                   // dynamically allocated deque of T
         int iFront;                // The position of the front element
         int iBack;                  // The position of the back element
         int numCapacity;             // the total capacity of the deque

         // Resizes capacity to set size
         void resize(int newCapacity)              throw (const char *); 
         int capacity() const                    { return numCapacity; } 
         int iFrontNormalize() const      { return iNormalize(iFront); } 
         int iBackNormalize() const        { return iNormalize(iBack); } 
         int iNormalize(int index) const
         { return (index % capacity() + capacity()) % capacity(); }      
            
   }; // DEQUE

   /********************************************
    * DEQUE :: ASSIGNMENT
    ********************************************/
   template <class T>
   deque <T> & deque <T> :: operator = (const deque <T> & rhs)
      throw (const char *)
   {
      clear();
      
      if (capacity() < rhs.size())
      {
         resize(rhs.size());
      }

      // push data from rhs to the lhs of the = sign
      for (int i = rhs.iFront; i <= rhs.iBack; i++)
      {
         push_back(rhs.data[(rhs.iNormalize(i))]);
      }

      return *this;
   }

   /********************************************
    * DEQUE :: PUSH_BACK
    * Adds an element to the back of the deque
    ********************************************/
   template <class T>
   void deque <T> :: push_back(const T & t) throw (const char *)
   {
      if (numCapacity == 0)
      {
         resize(1);
      }

      if (size() == numCapacity)
      {
         resize(numCapacity * 2);
      }

      iBack++;
      data[iBackNormalize()] = t;
   }

   /********************************************
    * DEQUE :: PUSH_FRONT
    * Adds an element to the front of the deque
    ********************************************/
   template <class T>
   void deque <T> :: push_front(const T & t) throw (const char *)
   {
      if (numCapacity == 0)
      {
         resize(1);
      }

      if (size() == numCapacity)
      {
         resize(numCapacity * 2);
      }

      iFront--;
      data[iFrontNormalize()] = t;
   }

   /********************************************
    * DEQUE :: POP_BACK
    * Removes an element from the back of the deque
    ********************************************/
   template <class T>
   void deque <T> :: pop_back()
   {
      if (!empty())
      {
         iBack--;
      }
   }

   /********************************************
    * DEQUE :: POP_FRONT
    * Removes an element from the front of the deque
    ********************************************/
   template <class T>
   void deque <T> :: pop_front()
   {
      if (!empty())
      {
         iFront++;
      }
   }

   /********************************************
    * DEQUE :: FRONT
    * Returns the first element
    ********************************************/
   template <class T>
   T & deque <T> :: front() throw (const char *)
   {
      if (empty())
         throw "ERROR: unable to access data from an empty deque";
      else
         return data[iFrontNormalize()];
   }

   /********************************************
    * QUEUE :: FRONT (READ ONLY)
    * Returns a read-only version of the first element
    ********************************************/
   template <class T>
   T deque <T> :: front() const throw (const char *)
   {
      if (empty())
         throw "ERROR: unable to access data from an empty deque";
      else
         return data[iFrontNormalize()];
   }

   /********************************************
    * DEQUE :: BACK
    * Returns the first element
    ********************************************/
   template <class T>
   T & deque <T> :: back() throw (const char *)
   {
      if (empty())
         throw "ERROR: unable to access data from an empty deque";
      else
         return data[iBackNormalize()];
   }

   /********************************************
    * QUEUE :: BACK (READ ONLY)
    * Returns a read-only version of the last element
    ********************************************/
   template <class T>
   T deque <T> :: back() const throw (const char *)
   {
      if (empty())
         throw "ERROR: unable to access data from an empty deque";
      else
         return data[iBackNormalize()];
   }

   /********************************************
    * DEQUE :: Resize
    * Resizes the capacity of the deque to the specified size
    ********************************************/
   template <class T>
   void deque <T> :: resize(int newCapacity) throw (const char *)
   {
      // Allocate new array
      T *pNew;

      try
      {
         pNew = new T[newCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for deque";
      }

      // do nothing if empty
      if (size() != 0)
      {
         // Keep track of the original size for the new iBack tracker
         int oldSize = size();

         // Copy the data to the new array
         int x = 0;
         for (int i = iFront; i <= iBack; i++)
         {
            pNew[x] = data[iNormalize(i)];
            x++;
         }

         // Update the object's collection and tracking properties
         iFront = 0;
         iBack = oldSize - 1;

         if (data != NULL)
            delete [] data;
      }
      numCapacity = newCapacity;
      data = pNew;
   }

}; // namespace custom

#endif // DEQUE_H
