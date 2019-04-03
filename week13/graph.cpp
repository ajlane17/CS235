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
#include "vertex.h"
#include "set.h"
#include "graph.h"

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
   // If it's the same object, return
   if (matrix == rhs.matrix)
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
}

/**************************************************
 * GRAPH :: ADD
 * Adds an edge to set of vertices
 *************************************************/
void Graph :: add(const Vertex & v1, const custom::set <Vertex> & s)
{
   // grid location [v1, set 0...n] = true
}

/**************************************************
 * GRAPH :: IS EDGE
 * Returns whether an edge exists
 *************************************************/
bool Graph :: isEdge(const Vertex & v1, const Vertex & v2) const
{
   // Return value in grid location [v1, v2]
   return true;
}
/**************************************************
 * GRAPH :: FIND EDGES
 * Returns a set of connected vertices
 *************************************************/
custom::set <Vertex> Graph :: findEdges(const Vertex & v)
{
   // Return a set of connected vertices
   custom::set <Vertex> s;
   return s;
}

/**************************************************
 * GRAPH :: IS EDGE
 * Returns a set of vertices that connect two
 *************************************************/
custom::set <Vertex> findPath(const Vertex & v1, const Vertex & v2)
{
   // Return a set of the connected vertex between two vertices
   custom::set <Vertex> s;
   return s;
}