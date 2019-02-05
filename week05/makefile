###############################################################
# Program:
#     Assignment 05, SET
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden
# Summary:
#     <put a description here>
# Time:
#     Adrian: __hrs
#     Ethan:  __hrs
#       Total:
# Hardest Part:
#     <What was the hardest part?>
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
