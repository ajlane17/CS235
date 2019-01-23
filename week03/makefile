###############################################################
# Program:
#     Assignment 03, QUEUE
#     Brother Kirby, CS235
# Author:
#     Adrian lane, Ethan Holden
# Summary:
#     <put a description here>
# Time:
#	Ethan - 1.5 hr
#     <how long did it take to complete this program>?
# Hardest Part:
#     <>
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
