###############################################################
# Program:
#     Assignment 07, LIST
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden, Kenyon Bunker
# Summary:
#     This a program that can caluclate large fibnocci sequences
#     It uses a custom list class.
# Time Spent:
#     Adrian: 5 hours
#      Ethan: 7 hours
#     Kenyon: 7 hours
#       Pair: 6 hours
#      Total: 37 hours
# Hardest Part:
#    Adrian:
#        The most difficult part for me was in getting the 
#        insert method working. I still don't quite understand
#        the syntax around the friend prototype. The other 
#        difficult part was in figuring out the logic to insert
#        the next element in the list collection for wholenumber.
#     Ethan:
#        So far the hardest part for me is figuring out the 
#        correct syntax for declairing the node and iterator 
#        classes in within the list class, then figuring out 
#        that the Node class no longer needed <T> on 
#        declaration because Node is not part of the list class.
#     Kenyon:
#        For me the toughest part was tryto figure out how to 
#        lay out wholeNumber. Once I udnerstood the general
#        body it became easier
###############################################################

##############################################################
# The main rule
##############################################################
a.out: list.h assignment07.o fibonacci.o wholeNumber.o
	g++ -o a.out assignment07.o fibonacci.o wholeNumber.o -g  -std=c++11
	tar -cf assignment07.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment07.o : the driver program
#      fibonacci.o    : the logic for the fibonacci-generating function
#      <anything else?>
##############################################################
assignment07.o: list.h assignment07.cpp
	g++ -c assignment07.cpp -g  -std=c++11

fibonacci.o: fibonacci.h fibonacci.cpp list.h
	g++ -c fibonacci.cpp -g  -std=c++11

wholeNumber.o: wholeNumber.h wholeNumber.cpp list.h
	g++ -c wholeNumber.cpp -g  -std=c++11

clean:
	rm *.o a.out *.tar
