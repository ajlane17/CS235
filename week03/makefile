###############################################################
# Program:
#     Assignment 03, QUEUE
#     Brother Kirby, CS235
# Author:
#     Adrian lane, Ethan Holden
# Summary:
#     This program is a custom implementation of the queue
#     class that manages collections in a first-in-first-out
#     manner, also referred to as FIFO. Items are added on to
#     the back and may only be removed from the front.
#     Additionally, items in front may be manipulated while a
#     part of the collection. This program also contains a 
#     simple stock trading component to exercise our queue
#     class for managing buy and sell orders and tracking our 
#     profits and losses. 
# Time:
#	Adrian - 8 hours
#	Ethan  - 8 hours
#     Total - 16 hours
# Hardest Part:
#     The difficulty for this assignment can be found in two 
#     places with similar functionality. The first is the 
#     assignment operator and the second is the private resize
#     method, both of which perform a similar task. Each of
#     these copies data from one array to the next, but each
#     take a slightly different approach based on the source
#     for the copied data. In both instances, it took quite 
#     some time to identify where our issues were and how we 
#     we could resolve them. It was only through much trial 
#     and error that we finally reached a point where we felt
#     we grasped the role the pop and push trackers played for
#     this collection, and how to use them when moving through
#     the collection.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: queue.h assignment03.o dollars.o stock.o
	g++ -o a.out assignment03.o dollars.o stock.o -std=c++11
	tar -cf assignment03.tar *.h *.cpp makefile

dollarsTest: dollars.o dollarsTest.cpp
	g++ -o dollarsTest dollars.o dollarsTest.cpp

##############################################################
# The individual components
#      assignment03.o : the driver program
#      dollars.o      : the Dollars class
#      stock.o        : the logic for the stock program
##############################################################
assignment03.o: queue.h assignment03.cpp
	g++ -c assignment03.cpp -std=c++11

dollars.o: dollars.h dollars.cpp
	g++ -c dollars.cpp -std=c++11

stock.o: stock.h stock.cpp queue.h
	g++ -c stock.cpp -std=c++11

clean:
	rm a.out *.o *.tar
