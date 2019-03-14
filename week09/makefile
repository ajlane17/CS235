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
#     Adrian: 12 hours
#     Kenyon: 6 hours
#     Ethan: 6 hours
#     Paired 8.5 hours
# Hardest Part:
#     Adrian:
#   The most difficult part was in working through the iterator 
#       with the "BIG" hint. Refactoring the prefix decrement 
#       operator and the iterator itself were a huge challenge. 
#       To a lesser degree, working through how begin and rbegin
#       should work were also difficult. Lastly, figuring out 
#       how to make the CopyBinaryTree recursive while accepting 
#       a source and destination tree as paramenters was also 
#       quite tricky.
#     Kenyon:
#   The hardest part for me was Erase case 3/ The logic was 
#       difficult to wrap my head around. I also sturggle with
#       just wrappign my head aroudn the logic of the BST in 
#       general. But after seeing a live, animateed version that 
#       I could manipulate I understood.
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
