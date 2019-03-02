###############################################################
# Program:
#     Assignment 08, Binary Tree
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden, Kenyon Bunker
# Summary:
#     This program provides a custom implementation of the 
#     binary node and supporting functions for basic 
#     binary node tree operations.
# Time:
#     Kenyon:
#     Adrian: 4 hours
#     Ethan:
# Hardest Part:
#     Kenyon:
#     Adrian:
#        The difficulty this week was in working through the
#        recursive functions. They weren't hard to implement,
#        but they were hard to understand conceptually. The 
#        only other tricky part was in realizing I needed to 
#        pass a pointer by reference for the delete operation.
#     Ethan:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment08.o huffman.o 
	g++ -o a.out assignment08.o huffman.o -g -std=c++11
	tar -cf assignment08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment08.o : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
assignment08.o: bnode.h huffman.h assignment08.cpp
	g++ -c assignment08.cpp -g -std=c++11

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g -std=c++11

clean: 
	rm a.out *.tar *.o
