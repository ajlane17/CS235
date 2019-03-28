/***********************************************************************
 * Module:
 *    Assignment 12, Spell Check
 *    Brother Kirby, CS 235
 * Author:
 *    Ethan Holden, Adrian Lane, Kenyon Bunker
 * Summary:
 *    This program will implement the hash class
 ************************************************************************/

#ifndef HASH_H
#define HASH_H

#include <cassert>
#include "list.h"

/**************************************************
 * HASH
 * A hash table storage that allows quick access to
 * the items stored in it
***************************************************/
template <class T>
class Hash
{
  public:
   // constructors
   Hash(int numBuckets)                              throw (const char *);
   Hash(const Hash & rhs)                            throw (const char *);
   ~Hash()                                             {}// delete[] table; }

   // operator overloading
   Hash & operator = (const Hash & rhs)          throw (const char *);

   //standard ADT storage functions
   int size()     const                            { return numElements; }
   int capacity() const                             { return numBuckets; }
   bool empty()                             { return (numElements == 0); }
   void insert(T t);
   bool find(T t);
   void erase(T t);

   // Hash specific functions
   virtual int hash(const T & value)const = 0;
   
  private:
   custom::list <T> * table;
   int numElements;
   int numBuckets;
};

/*************************************************
 * NON DEFAULT CONSTRUCTOR
 * Create an empty hash table of a specified size
 *************************************************/
template <class T>
Hash <T> :: Hash (int numBuckets) throw (const char *)
{
   this->numBuckets = numBuckets;
   numElements = 0;
   try
   {
      table = new custom::list <T>[numBuckets];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate memory for the hash.";
   }
}

/*************************************************
 * COPY CONSTRUCTOR
 * Copy a hash table
 *************************************************/
template <class T>
Hash <T> :: Hash (const Hash <T> & rhs) throw (const char *)
{
   *this = rhs;
}

/*******************************************
 * HASH :: ASSIGNMENT
 *******************************************/
template <class T>
Hash <T> & Hash <T> :: operator = (const Hash <T> & rhs)
   throw (const char *)
{
   numElements = rhs.numElements;
   numBuckets = rhs.numBuckets;
   
   try
   {
      table = rhs.table;
      //table = new custom::list <T>[numBuckets];
      //table = rhs.table;
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate memory for the hash.";
   }

//   for (int i = 0; i < size(); i++)
//      table[i] = rhs.table[i];

}

/*************************************************
 * INSERT
 * Inserts an element into the table
 *************************************************/
template <class T>
void Hash <T> :: insert(T t)
{
   // find the hash index
   int i = hash(t);
   // add element to the index's list
   table[i].push_back(t);
   // increase the numElements by one
   numElements++;
}
   
/*************************************************
 * FIND
 * Finds if an element is in the table
 *************************************************/
template <class T>
bool Hash <T> :: find(T t)
{
   // find the hash index
   int i = hash(t);
   // check if the element is at that index
   return (table[i].find(t) != NULL);
}
   
/*************************************************
 * ERASE
 * Erases an element from the table
 *************************************************/
template <class T>
void Hash <T> :: erase(T t)
{
   // find the hash index
   int i = hash(t);
   // check if element is there, and if it is erase it
   if (table[i].find(t) != NULL)
      table[i].erase(table[i].find(t));
   // subtract one from total elements
   numElements--;
}

#endif // HASH_H
