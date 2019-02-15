###############################################################
# Program:
#     Assignment 06, NODE
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden, Kenyon Bunker
# Summary:
#     Custom Node/Linked list
# Time:
#     Kenyon:   3
#     Ethan:    3
#     Adrian:   
#     Together: 1
# Hardest Part:
#     Kenyon: The hardest part for me was insert. Particulary
#       the second if statement.
#     Ethan:
#       The hardest part for me was figuring out where the 
#       segmentation fault was in test 4. After using the gdb 
#       tool, I found out it was in the << operator because it 
#       didn't make an exception for when the list was empty.
#     Adrian:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: node.h assignment06.o 
	g++ -o a.out assignment06.o  -g -std=c++11
	tar -cf assignment06.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment06.o      : the driver program
#      <anything else?>
##############################################################
assignment06.o: node.h assignment06.cpp sortInsertion.h
	g++ -c assignment06.cpp -g -std=c++11
clean:
	rm a.out *.o *.tar;
