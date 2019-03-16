/***********************************************************************
 * Component:
 *    Assignment 10, Map
 *    Brother Kirby, CS 235
 * Author:
 *    Adrian Lane, Kenyon Bunker, Ethan Holden
 * Summary:
 *    Create a map
 ************************************************************************/
#ifndef MAP_H
#define MAP_H

#include <cassert>
//#include "C:\Users\Kenyon B\source\repos\ajlane17\cs235\week10\bst.h"
#include "bst.h"
#include "pair.h"

namespace custom
{

/**********************************************************************
* MAP
* A customn map class
***********************************************************************/
template <class K, class V>
class map
{
   public:
      //Constructors
      map() { bst->size() = 0; };

      map(const map <K, V> & rhs) throw (const char *)
      {
         *this = rhs;
      }
      ~map() { clear(); };

      //Operators
      map <K, V> & operator =  (const map <K, V> & rhs)  throw (const char *)
                                 { bst = rhs->bst; return *this; }
      map <K, V> & operator [] (const K & k)             throw (const char *);
      map <K, V> & operator [] (const K & k) const       throw (const char *);

      // Nested iterator class & related functions
      class iterator;
      iterator it;
      iterator begin()           { return bst->begin(); }
      iterator begin() const     { return bst->begin(); }

      iterator rbegin()          { return bst->rbegin(); }
      iterator rbegin() const    { return bst->rbegin(); }

      iterator end()             { return bst->end(); }
      iterator end() const       { return bst->end();; }

      iterator rend()            { return bst->rend(); }
      iterator rend() const      { return bst->rend();; }

      iterator find(const K & k) { return bst->find(); }

      // Standard container functions
      int size() const           { return bst->size();   }
      bool empty() const         { return bst->empty();  }
      void clear()               { return bst->clear();  }

      //map specific functions
      void insert(const pair <K, V> & input) throw (const char *);
      void insert(const K & k, const V & v) throw (const char *);

  private:
      
      BST <pair<K, V>> * bst;
};

/**************************************************
 * MAP :: ITERATOR
 * An iterator through the map
 *************************************************/
template <class K, class V>
class map <K, V> ::iterator
{
  public:
   iterator() { }
   iterator(typename BST <pair<V, K>> :: iterator rhs) { it = rhs; }
   iterator(const iterator & it) { this->it = it; }
   iterator & operator = (const iterator & rhs) { it = rhs; }
   bool operator != (const iterator & rhs) const { return it != rhs; }
   bool operator == (const iterator & rhs) const { return it == rhs; }
   V & operator * () { return *it->second; }
   const V & operator * () { return *it; }
   iterator & operator ++ () { ++it; }
   iterator & operator ++ (int postfix) { it++; }
   iterator & operator -- () { --it; }
   iterator & operator -- (int postfix) { it--; }
  
  private:
   typename BST <pair<K, V>> :: iterator it;
};

/*****************************************
* Access Operator
*****************************************/
template<class K, class V>
 map <K, V> & map <K, V> :: operator [] (const K & key) throw(const char *)
{
   pair <K,V> input (key, V{});
   it = bst->find(input);
   if (it != NULL)
      return (*it).second;
   else
   {
      bst->insert(input);
      return bst->find(input).second;
   }
   return *this;
}

/*****************************************
 * Access Operator (CONST)
 *****************************************/
template<class K, class V>
 map <K, V> & map <K, V> :: operator [] (const K & key) const throw(const char *)
{
   pair <K, V> input (key, V{});
   it = bst->find(input);
   if (it != NULL)
      return (*it).second;
   else
   {
      bst->insert(input);
      return bst->find(input).second;
   }
   return *this;
}

/*****************************************
* MAP: INSERT
* Inserts data into the map
*****************************************/
template<class K, class V>
void map<K, V>::insert(const pair<K, V>& input) throw(const char *)
{
   it = bst->find(input);
   if (it != NULL)
   {
      *it = input;
   }
   else
   {
      bst->insert(input);
   }
}

/*****************************************
* MAP: INSERT (CONST)
* Inserts data into the map
*****************************************/
template<class K, class V>
void map<K, V>::insert(const K & k, const V & v) throw(const char *)
{
   it = bst->find(pair<K, V>(k,v));
   if (it != NULL)
   {
      *it = pair<K, V>(k,v);
   }
   else
   {
      bst->insert(pair<K, V>(k,v));
   }
}

}//end customn
#endif // MAP
