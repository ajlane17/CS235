/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    Adrian Lane, Ethan Holden
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here

   int count = 0;
   custom::deque <Request> requests;

   string firstWord;
   string text;
   int minutes;
   bool isPriority;
   do
   {
      // set up our objects and references for the request deque
      Request newRequest;
      Request tmpCurrRequest;
      Request *currRequest;
      isPriority = false;

      // prompt for input
      cout << "<" << count << "> ";
      cin  >> firstWord;

      try
      {
         // If it's a priority, push it to the front
         if (firstWord == "!!")
         {
            isPriority = true;
            cin >> text;
            newRequest.classCode = text;
            cin >> text;
            newRequest.name = text;
            cin >> minutes;
            newRequest.minutes = minutes;
            newRequest.isPriority = true;

            // Temporarily pop the current front to
            // insert the new priority request right
            // behind it and push the current back
            // in front 
            tmpCurrRequest = requests.front();
            requests.pop_front();
            requests.push_front(newRequest);
            requests.push_front(tmpCurrRequest);
         }
         // If it's 'none', do nothing
         else if (firstWord  == "none")
         {
            // Do nothing
         }
         // Otherwise, treat it as a normal request
         else if (firstWord != "finished")
         {
            newRequest.classCode = firstWord;
            cin >> text;
            newRequest.name = text;
            cin >> minutes;
            newRequest.minutes = minutes;
            requests.push_back(newRequest);
         }

         // Increment the minute tracker
         count++;

         // Display the currently serving info
         if (!requests.empty())
         {
            currRequest = &requests.front();

            // Handle time requests for 0 or less
            if (currRequest->minutes > 0)
            {
               // Text is based on priority of the request
               if (!currRequest->isPriority)
               {
                  cout << "\tCurrently serving " << currRequest->name << " for class "
                     << currRequest->classCode << ". Time left: "
                     << currRequest->minutes << endl;
               }
               else
               {
                  cout << "\tEmergency for " << currRequest->name << " for class "
                     << currRequest->classCode << ". Time left: "
                     << currRequest->minutes << endl;
               }
               currRequest->minutes = currRequest->minutes - 1;
            }

            if (currRequest->minutes == 0)
               requests.pop_front();
         }
      }
      catch (const char * e)
      {
         cout << '\t' << e << endl;
      }
   }
   while (firstWord != "finished");

   // end
   cout << "End of simulation\n";
}



