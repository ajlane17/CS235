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
   Dollars profit;
public:
   // constructors
   Stock() : quantity(0), cost(0) {}
   Stock(const int & quantity, const Dollars & cost)
   { this->quantity = quantity; this->cost = cost; }
   Stock(const int & quantity, const Dollars & cost,
         const Dollars & profit)
   {
      this->quantity = quantity;
      this->cost = cost;
      this->profit = profit;
   }

   // getters and setters
   int getQuantity()   { return quantity; }
   Dollars getCost()   { return cost; }
   Dollars getProfit() { return profit; }

   void setQuantity(int quantity)
   { this->quantity = quantity; }
   void setCost(Dollars cost)
   { this->cost = cost; }
   void setProfit(Dollars profit)
   { this->profit = profit; }
   
   //operators
   Stock operator -= (const int & rhs)
   {
      return *this = Stock(quantity - rhs, cost, profit);
   }
   Stock operator += (const int & rhs) 
   {
      return *this = Stock(quantity + rhs, cost, profit);
   }
};

/************************************************
 * BUY STOCKS
 * Buys specified stocks and adds them to the protfolio
 ***********************************************/
void buyStocks(const int & q, const Dollars & p,
               custom::queue <Stock> & portfolio)
{
   portfolio.push(Stock(q, p));
}

/************************************************
 * SELL STOCKS
 * Sells stocks and calculates the profit or loss
 * incurred by the transaction. Then saves the
 * portfolio and sales history into their queues.
 ***********************************************/
void sellStocks(const int & q, const Dollars & p,
                custom::queue <Stock> & portfolio,
               custom::queue <Stock> & sellHistory)
{
   // change = 0
   //
   // for each stock item in sell command
   //    remove one from front of history
   //    add cost diff to change
   //    if front count = 0
   //       pop front of history
   //
   // add change to profit

   int sellQuantity = q;
   Dollars totChange;
   int frontQuantity = 0;
   Dollars frontCost;
   Stock sellItem;

   sellItem.setQuantity(q);
   sellItem.setCost(p);

   while (sellQuantity > 0)
   {
      frontQuantity = portfolio.front().getQuantity();
      frontCost = portfolio.front().getCost();

      if (sellQuantity > frontQuantity)
      {
         sellQuantity -= frontQuantity;
         totChange = totChange + ((p - frontCost) * frontQuantity);
         portfolio.pop();
      }
      else
      {
         portfolio.front().setQuantity(sellQuantity);
         totChange = totChange + ((p - frontCost) * sellQuantity);
         sellQuantity = 0;
      }
   }

   sellItem.setProfit(totChange);
   sellHistory.push(sellItem);
}

/************************************************
 * DISPLAY
 * Displays the current stocks in the portfolio,
 * the sales history and the total proceeds made
 * for the client, but if there is anything to display.
 ***********************************************/
void display(const custom::queue <Stock> & portfolio,
             const custom::queue <Stock> & sellHistory)
{
   custom::queue <Stock> tempQ = portfolio;

   // display current bought stocks
   if (!tempQ.empty())
   {
      cout << "Currently held:\n";
      while (!tempQ.empty())
      {      
         cout << "\tBought " << tempQ.front().getQuantity()
              << " shares at " << tempQ.front().getCost()
              << endl;
         tempQ.pop();
      }
   }

   tempQ = sellHistory;
   Dollars proceeds = 0;
   
   // display the sales history as well as total proceeds
   if (!tempQ.empty())
   {
      cout << "Sell History:\n";
      while (!tempQ.empty())
      {
         cout << "\tSold " << tempQ.front().getQuantity()
              << " shares at " << tempQ.front().getCost()
              << " for a profit of " << tempQ.front().getProfit()
              << endl;
         proceeds += tempQ.front().getProfit();
         tempQ.pop();
      }
   }

   cout << "Proceeds: " << proceeds << endl;
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
   cin.ignore();

// your code here...
   string command;
   int quantity;
   Dollars price;
   string input;
   int totalStock;
   custom::queue <Stock> portfolio;
   custom::queue <Stock> sellHistory;
   
   while (true)
   {
      // get input
      cout << "> ";
      getline(cin, input);

      // parse input
      stringstream ss(input);
      ss >> command;
      ss >> quantity;
      ss >> price;

      // call various methods depending on input
      if (command == "buy")
      {
         totalStock += quantity;
         buyStocks(quantity, price, portfolio);
      }
      else if (command == "sell")
      {
         if (quantity > totalStock)
         {
            cout << "ERROR: That's more stock than you have";
         }
         else
         {
            totalStock -= quantity;
            sellStocks(quantity, price, portfolio, sellHistory);
         }
      }
      else if (command == "display")
      {
         display(portfolio, sellHistory);
      }
      else if (command == "quit")
      {
         display(portfolio, sellHistory);
         return;
      }
   }
}
