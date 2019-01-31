###############################################################
# Program:
#     Assignment 04, DEQUE
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden
# Summary:
#     <put a description here>
# Time:
#     <how long did it take to complete this program>?
# Hardest Part:
#     <fill out here>
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h assignment04.o nowServing.o
	g++ -o a.out assignment04.o nowServing.o -std=c++11 -DDEBUG
	tar -cf assignment04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment04.o : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
assignment04.o: deque.h assignment04.cpp
	g++ -c assignment04.cpp -std=c++11 -DDEBUG

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp -std=c++11 -DDEBUG
clean:
	rm *.o *.tar a.out
