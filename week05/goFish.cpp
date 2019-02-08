/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    Adrian Lane, Ethan Holden
* Summary: 
*    This is all the functions necessary to play Go Fish!
*
*    Estimated:  4.0 hrs   
*    Actual:     2.0 hrs
*      The most difficult part of this section was the iterator. It took
*      me a little while to figure out the syntax for checking if the
*      input is in the set or not, but once I looked it up it wasn't
*      too bad.
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
   custom::set <string> hand;
   
   // pull the file 
   ifstream fin("/home/cs235/week05/hand.txt");
   if (fin.fail())
      return;

   // extract file and close it.
   string temp;
   while (fin)
   {
      fin >> temp;
      hand.insert(temp);
   }
   fin.close();

   // display the game
   cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";

   // markers to check round and number of matches
   int round = 1;
   int matches = 0;
   string input;

   // Accept input
   while (round <= 5)
   {
      cout << "round " << round << ": ";
      cin  >> input;

      // check if it is in the set or not
      custom::set <string> :: iterator it = hand.find(input);
      if(hand.end() != it)
      {
         cout << "\tYou got a match!\n";
         hand.erase(it);
         matches++;
      }
      else
         cout << "\tGo Fish!\n";
      
      round++;
   }

   // count to check if end of the set
   int count = 0;
   cout << "You have " << matches << " matches!\n"
        << "The remaining cards: ";

   // display remaining cards in hand
   for (custom::set <string> :: iterator it = hand.begin(); it != hand.end(); ++it)
   {
      count++;
      if (count == hand.size())
         cout << *it << endl;
      else
         cout << *it << ", ";
   }
   
      return ;
}
