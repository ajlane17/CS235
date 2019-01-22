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
         queue(int numCapacity)                 throw (const char *):
         data(NULL), numCapacity(numCapacity), numPush(0), numPop(0)
          {}
         queue(const queue & rhs)               throw (const char *);          
        ~queue()                                { delete [] data;   }
         queue & operator = (const queue & rhs) throw (const char *);

         // standard container interfaces
         int size() const                     { return numElements; }
         bool empty() const              { return numElements == 0; }
         void clear()                            { numElements = 0; }
         
         // Queue-specific interfaces
         void push(const T & t)                 throw (const char *);
         void pop()                             throw (const char *);
         T & front()                            throw (const char *);
         T front() const                        throw (const char *);
         T & back()                             throw (const char *);
         T back() const                         throw (const char *);
         

      private: 
         T * data;             // dynamically allocated queue of T
         int numPush;
         int numPop;
         int numCapacity;      // the total capacity of the queue

         // Resizes capacity to set size
         void resize(int newCapacity)           throw (const char *);
         int iHead()                            throw (const char *);
         int iTail()                            throw (const char *);
            
   }; // QUEUE

   /********************************************
    * QUEUE :: Assignment
    ********************************************/
   template <class T>
   queue <T> & queue <T> :: operator = (const queue <T> & rhs)
      throw (const char *)
   {
      return *this;
   }

   /********************************************
    * QUEUE :: PUSH
    * Adds a new element to the back of the queue
    ********************************************/
   template <class T>
   void queue <T> :: push(const T & t) throw (const char *)
   {

   }
   
   /********************************************
    * QUEUE :: POP
    * Deletes the front element from the queue
    ********************************************/
   template <class T>
   void queue <T> :: pop() throw (const char *)
   {

   }
   
   /********************************************
    * QUEUE :: FRONT
    * Returns the first element
    ********************************************/
   template <class T>
   T & queue <T> :: front() throw (const char *)
   {

   }

   /********************************************
    * QUEUE :: FRONT (READ ONLY)
    * Returns a read-only version of the first element
    ********************************************/
   template <class T>
   T queue <T> :: front() const throw (const char *)
   {

   }

   /********************************************
    * QUEUE :: Back
    * Returns the last element
    ********************************************/
   template <class T>
   T & queue <T> :: back() throw (const char *)
   {

   }

   /********************************************
    * QUEUE :: FRONT (READ ONLY)
    * Returns a read-only version of the last element
    ********************************************/
   template <class T>
   T queue <T> :: back() const throw (const char *)
   {

   }

   /********************************************
    * QUEUE :: Resize
    * Resizes the capacity of the queue to the specified size
    ********************************************/
   template <class T>
   void queue <T> :: resize(int newCapacity) throw (const char *)
   {

   }

   /********************************************
    * QUEUE :: I_HEAD
    * Returns the index for the front of the queue
    ********************************************/
   template <class T>
   int queue <T> :: iHead() throw (const char *)
   {
      
   }

   /********************************************
    * QUEUE :: I_TAIL
    * Returns the index for the back of the queue
    ********************************************/
   template <class T>
   int queue <T> :: iTail() throw (const char *)
   {
      
   }

}; // namespace custom

#endif // QUEUE_H
