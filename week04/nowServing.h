/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Adrian Lane, Ethan Holden
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

#include <string>
#include "deque.h"     // for DEQUE

/********************************************
 * REQUEST
 * Stores the properties of a queue request
 ********************************************/
struct Request
{
   std::string classCode;
   std::string name;
   int minutes;
   bool isPriority = false;
};

// the interactive nowServing program
void nowServing();

#endif // NOW_SERVING_H

