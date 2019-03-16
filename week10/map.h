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
      map()
      {
         bst->size() = 0;
      };

      map(const map <K, V> & rhs) throw (const char *)
      {
         bst->size() = 0;
         *this = rhs;
      }
      ~map() { clear(); };

      //Operators
      map <K, V> & operator =  (const map <K, V> & rhs)  throw (const char *);
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
      int numElements;
};

/**************************************************
 * MAP :: ITERATOR
 * An iterator through the map
 *************************************************/
template <class K, class V>
class map <K, V> ::iterator
{

};

/*****************************************
* Assignment Operator
*****************************************/
template<class K, class V>
 map <K, V> & map <K, V> :: operator = (const map <K, V> & rhs) throw(const char *)
{
    return *this;
}

/*****************************************
* Access Operator
*****************************************/
template<class K, class V>
 map <K, V> & map <K, V> :: operator [] (const K & k) throw(const char *)
{
    return *this;
}

/*****************************************
 * Access Operator (CONST)
 *****************************************/
template<class K, class V>
 map <K, V> & map <K, V> :: operator [] (const K & k) const throw(const char *)
{
    return *this;
}

 /*****************************************
 * MAP: BEGIN
 *****************************************/
/*template<class K, class V>
typename map<K, V> :: iterator map<K, V>::begin()
{
   return iterator();
}

/*****************************************
* MAP: BEGIN (CONST)
*****************************************/
/*template<class K, class V>
typename map<K, V> :: iterator map<K, V>::begin() const
{
   return iterator();
}

/*****************************************
* MAP: RBEGIN
*****************************************/
/*template<class K, class V>
typename map<K, V> :: iterator map<K, V>::rbegin()
{
   return iterator();
}

/*****************************************
* MAP: RBEGIN (CONST)
//*****************************************/
//template<class K, class V>
//typename map<K, V> :: iterator map<K, V>::rbegin() const
//{
//   return iterator();
//}
//
///*****************************************
//* MAP: FIND
//* Finds data based on a key (k)
//*****************************************/
//template<class K, class V>
//typename map<K, V> :: iterator map<K, V>::find(const K & k)
//{
//   return iterator();
//}

/*****************************************
* MAP: INSERT
* Inserts data into the map
*****************************************/
template<class K, class V>
void map<K, V>::insert(const pair<K, V>& input) throw(const char *)
{
   it = bst->find(pair<K, V>);
   if (it != NULL)
   {
      *it = pair<K, V>;
   }
   else
   {
      bst->insert(pair<K, V>);
   }
}

/*****************************************
* MAP: INSERT (CONST)
* Inserts data into the map
*****************************************/
template<class K, class V>
void map<K, V>::insert(const K & k, const V & v) throw(const char *)
{
   it = bst->find(pair<K, V>);
   if (it != NULL)
   {
      *it = pair<K, V>;
   }
   else
   {
      bst->insert(pair<K, V>);
   }
}

}//end customn
#endif // MAP