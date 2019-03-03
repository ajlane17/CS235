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
#     The second part convers a file of data sets and displays 
#     their Huffman Code.
# Time:
#     Kenyon: 7 hours
#     Adrian: 4 hours
#     Ethan:  6 hours 
#     Paired: 8 hours
# Hardest Part:
#     Kenyon:
#        Same as Adrian plus issue doing the stub of copyBTree
#        could not get the right paramaters.
#     Adrian:
#        The difficulty this week was in working through the
#        recursive functions. They weren't hard to implement,
#        but they were hard to understand conceptually. The 
#        only other tricky part was in realizing I needed to 
#        pass a pointer by reference for the delete operation.
#     Ethan:
#        My hardest part was figuring out how to set up 
#        functions so that pointers were passed so that the 
#        BNode functions could be used properly. Then after 
#        that, like Adrian, it was hard understanding the 
#        concept of the recursions so that they worked properly.
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
