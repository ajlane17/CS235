###############################################################
# Program:
#     Assignment 10, Map
#     Brother Kirby, CS 235
# Author:
#     Adrian Lane, Ethan Holden, Kenyon Bunker
# Summary:
#     <put a descriptoin here>
# Time:
#     Adrian:
#     Ethan: 7 hours
#     Kenyon:
#     Paired:
# Hardest Part:
#     Adrian:
#     Ethan: 
#        The hardest part for me was the understnding the 
#        pointer logic and the logic in getting insert to sort 
#        the BST properly using the red black sorting.
#     Kenyon:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment10.o wordCount.o
	g++ -o a.out assignment10.o wordCount.o -g -std=c++11
	tar -cf assignment10.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment10.o : the driver program
#      wordCount.o    : the wordCount() function
##############################################################
assignment10.o: pair.h map.h bst.h assignment10.cpp
	g++ -c assignment10.cpp -g -std=c++11

wordCount.o: map.h bst.h wordCount.h wordCount.cpp 
	g++ -c wordCount.cpp -g  -std=c++11

clean:
	rm a.out *.tar *.o
