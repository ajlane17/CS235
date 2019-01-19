/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <sstream>     // for STRING STREAM
#include <vector>      // for VECTOR
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
using namespace std;

int opPriority(char op);

/*****************************************************
 * CONVERT INFIX TO POSTFIX  4 * (5 + 6) ^ 2
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   string postfix;
   // Add starting space
   postfix += ' ';

   custom::stack <char> tempStack;

   for (int i = 0; i < infix.size(); i++)
   {
      char currChar = infix[i];

      if (isalpha(currChar) || isdigit(currChar) || currChar == '.')
      {
         //cout << "adding alphanumeric to postfix: " << currChar << endl;
         if (i != 0 && (opPriority(postfix[postfix.size() - 1]) != 0))
            postfix += ' ';
         postfix += currChar;
      }
      else
      {
         switch (currChar)
         {
            case ' ':
               // cout << "found a space, adding a space" << endl;
               break;
            case '(':
               // cout << "a '(' found" << endl;
               tempStack.push(currChar);
               break;
            case ')':
               // cout << "a ')' found" << endl;
               if (postfix[postfix.size() - 1] != ' ')
                  postfix += ' ';
               while (tempStack.top() != '(')
               {
                  postfix += tempStack.top();
                  tempStack.pop();
               }
               tempStack.pop();
               break;
            default:
               while (!tempStack.empty() && opPriority(currChar) <= opPriority(tempStack.top()))
               {
                  // cout << "adding operator to postfix: " << tempStack.top() << endl;
                  if (postfix[postfix.size() - 1] != ' ')
                     postfix += ' ';

                  postfix += tempStack.top();
                  tempStack.pop();
               }
               // cout << "adding operator to the stack: " << currChar << endl;
               tempStack.push(currChar);
               postfix += ' ';
         }
      }
   }

   while (!tempStack.empty())
   {
      // cout << "pushing remaining operators to postfix: " << tempStack.top() << endl;
      if (postfix[postfix.size() - 1] != ' ')
         postfix += ' ';

      postfix += tempStack.top();
      tempStack.pop();
   }

   return postfix;
}

/*****************************************************
 * OP PRIORITY
 * Returns the operator priority regarding order of operations
 *****************************************************/
int opPriority(char op)
{
   switch (op)
   {
      case '+':
      case '-':
         return 1;
      case '*':
      case '/':
         return 2;
      case '^':
         return 3;
      default:
         return 0;
   }
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);

      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;
   custom::stack <string> tempStorage;
   char memVar = 'A';

   // TODO: REMOVE TEST STRING
   // Test string instead of postfix
   // string testString = "3 4 5 + * 6 -";

   // Split string by spaces into vector
   vector <string> splitString;

   stringstream ss;
   string strBuffer;
   ss.str(postfix);

   while (ss >> strBuffer)
   {
      splitString.push_back(strBuffer);
   }

   // Loop through array
   for (int i = 0; i < splitString.size(); i++)
   {
      // This will hold the assembly instruction to add to the string
      string assemblyDirective;

      // These will hold the left and right operands
      string lhs;
      string rhs;

      // We need the first char from each string
      char tempChar = (char)splitString.at(i)[0];

      // Determine alphanumeric or operator
      if (isalpha(tempChar) || isdigit(tempChar) || tempChar == '.')
      {
         // If alphanumeric, add to the stack
         tempStorage.push(splitString.at(i));
      }
      else
      {
         // Determine the operand and assembly directive match
         switch (tempChar)
         {
            case '+':
               assemblyDirective = "\tADD ";
               break;
            case '-':
               assemblyDirective = "\tSUB ";
               break;
            case '*':
               assemblyDirective = "\tMUL ";
               break;
            case '/':
               assemblyDirective = "\tDIV ";
               break;
            case '%':
               assemblyDirective = "\tMOD ";
               break;
            case '^':
               assemblyDirective = "\tEXP ";
               break;
            default:
               break;
         }

         // Get the left and right operands assigned
         rhs = tempStorage.top();
         tempStorage.pop();

         lhs = tempStorage.top();
         tempStorage.pop();

         // Decide between LOD and SET and add to the string
         if (isalpha(lhs[0]))
            assembly += "\tLOD " + lhs + '\n';
         else 
            assembly += "\tSET " + lhs + '\n';

         // Add the operator and right operand
         assembly += assemblyDirective + rhs + '\n';

         // "Assign" the result to a variable, put on the stack
         string s(1, memVar); // cast the CHAR to a string
         assembly += "\tSAV " + s + '\n';
         tempStorage.push(s);

         // Increase the variable
         memVar++;
      }
   }
   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}
