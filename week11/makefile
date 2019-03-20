###############################################################
# Program:
#     Assignment 11, Sorts
#     Brother Kirby, CS235
# Author:
#     Ethan Holden, Adrian Lane, Kenyon Bunker.
# Summary:
#     <put a description here>
# Time:
#     Ethan:
#     Adrian:
#     Kenyon:
#     Paired:
# Hardest Part:
#     Ethan:
#     Adrian:
#     Kenyon:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment11.o
	g++ -o a.out assignment11.o -g -std=c++11
	tar -cf assignment11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment11.o     : the driver program
##############################################################
assignment11.o: assignment11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c assignment11.cpp -g -std=c++11

clean:
	rm a.out *.o *.tar
