/***********************************************************************
* Source File:
*    Implementation of the Graph class.
* Summary: 
*    This file will implement all the methods described in Graph.h
* Author:
*    Adrian Lane, Ethan Holden, Kenyon Bunker
************************************************************************/

#include <cassert>
#include <new>      // required for std::bad_alloc
#include <cstddef>  // required for NULL
#include <iostream> // required for DEBUG output
#include "vertex.h"
#include "set.h"
#include "graph.h"
#include "stack.h"
#include "list.h"
using namespace custom;
/**************************************************
 * GRAPH :: NON-DEFAULT CONSTRUCTOR
 * Creates a graph of specified size
 *************************************************/
Graph :: Graph(int numVertices) throw (const char *)
{
   // Allocate array
   try
   {
      matrix = new bool[numVertices * numVertices];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate memory for the graph.";
   }
   
   // Assign capacity
   this->numVertices = numVertices;

   // Set all locations to false
   for (int i = 0; i < numVertices * numVertices; i++)
      matrix[i] = false;
}

/**************************************************
 * GRAPH :: ASSIGNMENT OPERATOR
 * Creates & assigns a copy of the graph provided
 *************************************************/
Graph & Graph :: operator = (const Graph & rhs) throw (const char *)
{
   // If it's the same object or empty, return
   if (matrix == rhs.matrix || rhs.size() == 0)
      return *this;

   // Assign the new capacity
   numVertices == rhs.numVertices;
   
   // Delete the old matrix object
   if (matrix != NULL)
      delete [] matrix;

   // Allocate a new array
   try
   {
      matrix = new bool[numVertices * numVertices];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate memory for the graph.";
   }
   
   // Copy the data
   for (int i = 0; i < numVertices * numVertices; i++)
      matrix[i] = rhs.matrix[i];

   // Return the new object
   return *this;
}

/**************************************************
 * GRAPH :: CLEAR
 * Removes all edges from the graph
 *************************************************/
void Graph :: clear()
{
   for (int i = 0; i < numVertices * numVertices; i++)
      matrix[i] = false;
}

/**************************************************
 * GRAPH :: ADD
 * Adds an edge to set of vertices
 *************************************************/
void Graph :: add(const Vertex & v1, const Vertex & v2)
{
   // grid location [v1, v2] = true
   int gridPos = getGridPos(v1.index(), v2.index());
   matrix[gridPos] = true;
   // std::cout << "set " << v1.index() << "," << v2.index() << " to TRUE" << std::endl;
}

/**************************************************
 * GRAPH :: ADD
 * Adds an edge to set of vertices
 *************************************************/
void Graph :: add(const Vertex & v1, const custom::set <Vertex> & s)
{
   // grid location [v1, set 0...n] = true
   int gridPos;
   for (custom::set <Vertex> :: const_iterator it = s.cbegin(); it != s.cend(); it++)
   {
      gridPos = getGridPos(v1.index(), (*it).index());
      matrix[gridPos] = true;
      // std::cout << "set " << v1.index() << "," << (*it).index() << " to TRUE" << std::endl;
   }
}

/**************************************************
 * GRAPH :: IS EDGE
 * Returns whether an edge exists
 *************************************************/
bool Graph :: isEdge(const Vertex & v1, const Vertex & v2) const
{
   // Return value in grid location [v1, v2]
   int gridPos = getGridPos(v1.index(), v2.index());
   
   char c;
   if (matrix[gridPos])
      c = 'T';
   else
      c = 'F';
   // std::cout << "isEdge: " << v1.index() << "," << v2.index() << " " << c << std::endl;
   
   return matrix[gridPos];
}
/**************************************************
 * GRAPH :: FIND EDGES
 * Returns a set of connected vertices
 *************************************************/
custom::set <Vertex> Graph :: findEdges(const Vertex & v) const
{
   // Return a set of connected vertices
   Vertex v2;
   custom::set <Vertex> s;
   for (int i = 0; i < size(); i++)
   {
      v2.set(i);
      if (isEdge(v, v2))
      {
         s.insert(v2);
         // std::cout << "findEdges: Inserted v2:" << v2.index() << ", set size is: " << s.size() << std::endl;
      }
   }
   return s;
}

/**************************************************
 * GRAPH :: FIND PATH
 * Returns a set of vertices that connect two
 *************************************************/
custom::set<Vertex> Graph::findPath(const Vertex & source, const Vertex & destination)
{
   int distance = 0;
   custom::list <Vertex> toVisit;

   //Path between connected vertex(s)
   custom::set <Vertex> path;


   int *distances = new int[size()];
   Vertex *predecessor = new Vertex[size()];

   toVisit.push_back(source);

   for (int i = 0; i < size(); i++)
   {
      distances[i] = -1;
   }

   while (!toVisit.empty() && distances[destination] == -1)
   {
      Vertex v = toVisit.front();
      toVisit.pop_front();

      if (distances[v] > distance)
      {
         distance++;
      }

      custom::set <Vertex> s = findEdges(v);

      custom::set <Vertex> ::const_iterator it;
      for (it = s.cbegin(); it < s.cend(); it++)
      {
         if (distances[it] = -1)
         {
            distances[it] = distance + 1;
            predecessor[it] = v;
            toVisit.push_back(*it);
            distance++;
         }
      }
   }

   if (distances[destination] == -1)
   {
      return path; //TODO: insert error
   }

   path.insert(destination);

   for (int i = 1; i < distance; i++)
   {
      path.insert(predecessor[path[i - 1]]);
   }
   // Return a set of the connected vertex (path) between two vertices
   return path;
}

/**************************************************
 * GRAPH :: GET GRID POS
 * Returns the matrix array index of the edge
 *************************************************/
int Graph :: getGridPos(int row, int col) const
{
   int gridPos;
   gridPos = size() * row + col;
   return gridPos;
}