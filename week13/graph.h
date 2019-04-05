/*****************************************************************************
 * Header:
 *    Graph
 * Summary:
 *    This class contains the notion of a graph: an object to hold data
 *    that represents vertices, points, and edges, the connections between.
 *
 * Author
 *    Adrian Lane, Ethan Holden, Kenyon Bunker
 *****************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "set.h"

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

/**************************************************
 * GRAPH
 * A GRAPH
 *************************************************/
class Graph
{
   public:
      // Non-default constructor
      Graph(int numVertices) throw (const char *);

      // Assignment operator
      Graph & operator = (const Graph & rhs) throw (const char *);

      // Standard interfaces
      bool empty() const { return numVertices > 0; }
      int size() const { return numVertices; }
      int capacity() const { return numVertices * numVertices; }
      void clear();

      // Graph interfaces
      void add(const Vertex & v1, const Vertex & v2);
      void add(const Vertex & v1, const custom::set <Vertex> & s);
      bool isEdge(const Vertex & v1,const Vertex & v2) const;
      custom::set <Vertex> findEdges(const Vertex & v) const;
      custom::set <Vertex> findPath(const Vertex & source, const Vertex & destination);


   private:
      bool * matrix;
      int numVertices;
      int getGridPos(int row, int col) const;
};

#endif // GRAPH_h