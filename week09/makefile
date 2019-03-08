###############################################################
# Program:
#     Assignment 09, Binary Search Tree
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Kenyon Bunker, Ethan Holden
# Summary:
#     This program creates a binary search tree that adds data 
#     in order and then allows the user to find and manipulate 
#     the data.
# Time:
#     Adrian:
#     Kenyon: 6 hours
#     Ethan: 6 hours
# Hardest Part:
#     Adrian:
#     Kenyon:
#     Ethan:
#	The hardest part for me was understanding the logic of 
#       getting the pointers to rearrange when one was being 
#       removed from the BST.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment09.o
	g++ -o a.out assignment09.o -g -std=c++11
	tar -cf assignment09.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment09.o     : the driver program
##############################################################
assignment09.o: bst.h assignment09.cpp
	g++ -c assignment09.cpp -g -std=c++11

clean: 
	rm a.out *.tar *.o
