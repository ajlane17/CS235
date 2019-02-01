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
         deque() : iFront(0), iBack(-1), numCapacity(0)                  // done
            { data = new T[numCapacity]; }
         deque(int numCapacity)                    throw (const char *): // done
            iFront(0), iBack(-1), numCapacity(numCapacity) 
            { data = new T[numCapacity]; }                               // done
        ~deque()                                     { delete [] data; } // done
         deque(const deque & rhs)                  throw (const char *): // done
            data(NULL), iFront(0), iBack(-1), numCapacity(0)
            { if (!rhs.empty()) *this = rhs; }
        // Operators (prototypes)
         deque & operator = (const deque & rhs)    throw (const char *); // testing

         // standard container interfaces
         int size() const               { return (iBack - iFront + 1); } // done
         bool empty() const                    { return (size() == 0); } // done
         void clear()                       { iFront = 0; iBack = -1; }; // done
         
         // Deque-specific interfaces
         void push_front(const T & t)              throw (const char *); // testing
         void push_back(const T & t)               throw (const char *); // testing
         void pop_front();
         void pop_back();
         T & front()                               throw (const char *); // testing
         T front() const                           throw (const char *); // testing
         T & back()                                throw (const char *); // testing
         T back() const                            throw (const char *); // testing

         //debug
         void display() const;
         
      private: 
         T * data;                   // dynamically allocated deque of T
         int iFront;                // The position of the front element
         int iBack;                  // The position of the back element
         int numCapacity;             // the total capacity of the deque

         // Resizes capacity to set size
         void resize(int newCapacity)              throw (const char *); // testing
         int capacity() const                    { return numCapacity; } // done
         int iFrontNormalize() const      { return iNormalize(iFront); } // done
         int iBackNormalize() const        { return iNormalize(iBack); } // done
         int iNormalize(int index) const
         { return (index % capacity() + capacity()) % capacity(); }      // done
            
   }; // DEQUE

#ifdef DEBUG

using std::cerr;
/****************************************************
 * DISPLAY DEQUE
 * Display the contents of a deque for debug purposes
 ****************************************************/
template <class T>
   void deque <T> :: display() const
{
   // Display the header info
   cerr << "\ndeque<T>:: display()\n";
   cerr << "\tnumCapacity = " << numCapacity << "\n";

   // Display the contents of the array
   cerr << "\tdata = ";
   if (numCapacity == 0)
      cerr << "NULL";
   else
   {
      cerr << "{ ";
      for (int i = 0; i < numCapacity; i++)
      {
         if (i != 0)
            cerr << ", ";

         // not wrapped
         //      0   1   2   3   4   5   6
         //    +---+---+---+---+---+---+---+
         //    |   |   | A | B | C |   |   |
         //    +---+---+---+---+---+---+---+
         // iFront = 9     iFrontNormalize() = 2
         // iBack  = 11    iBackNormalize()  = 4
         if (iFrontNormalize() <= iBackNormalize() &&  // not wrapped
             iFrontNormalize() <= i &&
             i <= iBackNormalize())                        // in range
            cerr << data[i];

         // wrapped
         //      0   1   2   3   4   5   6
         //    +---+---+---+---+---+---+---+
         //    | B | C |   |   |   |   | A |
         //    +---+---+---+---+---+---+---+
         // iFront = -8    iFrontNormalize() = 6
         // iBack  = -6    iBackNormalize()  = 1
         else if (iFrontNormalize() > iBackNormalize() && // wrapped
                  size() != 0 &&                              // not empty
                  (i <= iBackNormalize() ||
                   i >= iFrontNormalize()))                   // in range
            cerr << data[i];
      }
      cerr << " }";
   }
   cerr << "\n";

   // display the front and back with the normalized values in ()s
   if (numCapacity)
   {
      cerr << "\tiFront = " << iFront
           << " ("          << iFrontNormalize() << ")\n";
      cerr << "\tiBack  = " << iBack
           << " ("          << iBackNormalize()  << ")\n";
   }
}
#else
template <class T>
   void deque <T> :: display() const
{
}
#endif // DEBUG
   
   
   /********************************************
    * DEQUE :: ASSIGNMENT
    ********************************************/
   template <class T>
   deque <T> & deque <T> :: operator = (const deque <T> & rhs)
      throw (const char *)
   {
      // std::cout << "\nCalling Assignment:";
      clear();
      
      if (capacity() < rhs.size())
      {
         resize(rhs.size());
      }

      for (int i = rhs.iFront; i <= rhs.iBack; i++)
      {
         // std::cout << "rhs.iFront = " << i << " rhs.iBack = " << rhs.iBack << " iNormalize: " << iNormalize(i) << " Pushing: " << rhs.data[iNormalize(i)] << std::endl;
         push_back(rhs.data[(rhs.iNormalize(i))]);
      }
   // std::cout << "\nCalled Assignment:";
   // display();
   return *this;
   }

   /********************************************
    * DEQUE :: PUSH_BACK
    * Adds an element to the back of the deque
    ********************************************/
   template <class T>
   void deque <T> :: push_back(const T & t) throw (const char *)
   {
      // std::cout << "\nCalling Push_Back:";
      // display();
      
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
      // std::cout << "\nCalled Push_Back:";
      // display();
   }

   /********************************************
    * DEQUE :: PUSH_FRONT
    * Adds an element to the front of the deque
    ********************************************/
   template <class T>
   void deque <T> :: push_front(const T & t) throw (const char *)
   {
      // std::cout << "\nCalling Push_Front:";
      // display();
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
      // std::cout << "\nCalled Push_Front:";
      // display();
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
      // std::cout << "\nCalling Resize: ";
      // display();
      T *pNew;

      try
      {
         pNew = new T[newCapacity];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for deque";
      }

      if (size() != 0)
      {
         // Keep track of the original size for the new iBack tracker
         int oldSize = size();

         // Copy the data to the new array
         int x = 0;
         for (int i = iFront; i <= iBack; i++)
         {
            // std::cout << "adding: " << data[iNormalize(i)] << " to " << x << std::endl;
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
            
      // std::cout << "\nCalled Resize:";
      // display();
   }

}; // namespace custom

#endif // DEQUE_H
