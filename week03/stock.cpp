/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Adrian Lane, Ethan Holden
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <sstream>     // for STRING STREAM
#include <vector>      // for VECTOR
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
#include "dollars.h"   // for DOLLARS
using namespace std;

class Stock
{
private:
   int quantity;
   Dollars cost;
public:
   // constructors
   Stock() : quantity(0), cost(0) {}
   Stock(const int & quantity, const Dollars & cost)
   { this->quantity = quantity; this->cost = cost; }

   // getters and setters
   int getQuantity() { return quantity; }
   Dollars getCost() { return cost; }

   void setQuantity(int quantity)
   { this->quantity = quantity; }
   void setCost(Dollars cost)
   { this->cost = cost; }
   
   //operators
   Stock operator - (const int & rhs) const
   {
      return Stock(quantity - rhs, cost);
   }
   Stock operator + (const int & rhs) const
   {
      return Stock(quantity + rhs, cost);
   }
};

void buyStocks(const int & q, const Dollars & p,
               custom::queue <Stock> & portfolio)
{
   
}

void sellStocks(const int & q, const Dollars & p,
                custom::queue <Stock> & portfolio)
{

}

void display(custom::queue <Stock> & portfolio)
{
   
}

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   // your code here...
   string command;
   int quantity;
   Dollars price;
   string input;
   custom::queue <Stock> portfolio;

   while (input != "quit")
   {
      // get input
      cout << "> ";
      cin.ignore();
      getline(cin, input);

      // parse input
      stringstream ss(input);
      ss >> command;
      ss >> quantity;
      ss >> price;

      if (command == "buy")
      {
         buyStocks(quantity, price, portfolio);
      }
      else if (command == "sell")
      {
         sellStocks(quantity, price, portfolio);
      }
      else if (command == "display")
      {
         display(portfolio);
      }
   }
}
