###############################################################
# Program:
#     Assignment 05, SET
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden
# Summary:
#     This program is first a custom data structure of the set. 
#     It stores a user defined "set" of elements that is a list 
#     of all non-repeated elements enter into it. It also 
#     defines the ability for the user to combine and compare 
#     sets with various opperators. 
#     The second part is a simple Go Fish! program that has the 
#     user guess 5 times which cards are in the comupter's 
#     "hand." For each correct guess it removes the card from 
#     the hand and then after 5 guesses the program displays 
#     all remaining cards in the hand.
# Time:
#     Adrian: 8 hrs
#     Ethan:  4 hrs
#       Total: 12 hrs
# Hardest Part:
#     The hardest part for this week was in trying to get the 
#     binary search and insert to work as intended. The pseudo
#     code did a great job in showing how to return a match,
#     but figuring out the insert location was more diffucult
#     than I thought, but redicuously simple to implement. The
#     insert gave me a lot of problems in how I was trying to
#     initially handle an empty collection, but once I figured
#     out my incrementor wasn't working as intented, it was an
#     easy fix. An honorable mention would be working through 
#     through operator overrides. I had quite a few bugs to 
#     work through that were either the wrong comparison 
#     operator, or using the wrong iterator against the wrong
#     the wrong collection. The common theme for this week's
#     difficulties could be "hard to think through, easy to 
#     fix."
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment05.o goFish.o card.o
	g++ -o a.out assignment05.o goFish.o card.o -std=c++11
	tar -cf assignment05.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment05.o : the driver program
#      goFish.o       : the logic for the goFish game
#      card.o         : a single playing card
##############################################################
assignment05.o: set.h goFish.h assignment05.cpp
	g++ -c assignment05.cpp -std=c++11

goFish.o: set.h goFish.h goFish.cpp card.h
	g++ -c goFish.cpp -std=c++11

card.o: card.h card.cpp
	g++ -c card.cpp  -std=c++11

clean:
	rm a.out *.o *.tar
