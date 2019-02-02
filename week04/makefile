###############################################################
# Program:
#     Assignment 04, DEQUE
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden
# Summary:
#     This is a custom double-ended queue or deque class. This
#     class stores values of a given type and allows access 
#     from either the front or back. Items can be added by 
#     pushing them onto either the front or back and can be 
#     taken off by poping either front or back. 
#     The second program is that of a now serving queue to 
#     handle help requests. Students can add a request to the 
#     queue that is put in the back, but if they have an 
#     emergency, they can be bumped to the front of the line 
#     so that they can be taken care of first.
# Time:
#     Total = 28 hours
#      Adrian = 16 hours
#      Ethan  = 12 hours
# Hardest Part:
#     The hardest part was figuring out the assignment operator. 
#     For a long while we thought we had the push front and 
#     back messed up some how, but eventually we found that it 
#     was the assignment operator. After several more hours, we 
#     found that we were calling iNormalize() for the left hand 
#     side of the opperator when we wanted the right hand side 
#     (thus using the wrong capacity to do the calculations).
###############################################################

##############################################################
# The main rule
##############################################################
a.out: deque.h assignment04.o nowServing.o
	g++ -o a.out assignment04.o nowServing.o -std=c++11
	tar -cf assignment04.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment04.o : the driver program
#      nowServing.o   : the logic for the now serving program
##############################################################
assignment04.o: deque.h assignment04.cpp
	g++ -c assignment04.cpp -std=c++11

nowServing.o: nowServing.h nowServing.cpp deque.h
	g++ -c nowServing.cpp -std=c++11
clean:
	rm *.o *.tar a.out
