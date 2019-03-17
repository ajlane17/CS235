###############################################################
# Program:
#     Assignment 10, Map
#     Brother Kirby, CS 235
# Author:
#     Adrian Lane, Ethan Holden, Kenyon Bunker
# Summary:
#     Custom Map Program
# Time:
#     Adrian: 9 hours
#     Ethan: 7 hours
#     Kenyon: 8 hours
#     Paired: 2.5 hours
# Hardest Part:
#     Adrian:
#        Figuring out the "NULL not in scope issue" and then 
#        trying to figure out how to get around an empty stack 
#        when using the decrement opperator for the iterator. 
#        This is why testbed 3 has the extra line of print with 
#        the error.
#     Ethan: 
#        The hardest part for me was the understnding the 
#        pointer logic and the logic in getting insert to sort 
#        the BST properly using the red black sorting.
#     Kenyon:
#        My hardest part was identifying why the program hung 
#        when opening larger files.
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
