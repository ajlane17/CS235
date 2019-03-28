###############################################################
# Program:
#     Assignment 12, Hash
#     Brother Kirby, CS235
# Author:
#     Kenyon Bunker, Adrian Lane, Ethan Holden
# Summary:
#     A custom class that stores values in a hash table so that 
#     they can be accessed quickly.
# Time Spent:
#     Kenyon:
#     Adrian:
#     Ethan:
#        6.5 hours
#     Paired:
# Hardest Part:
#     Kenyon:
#     Adrian:
#     Ethan:
#        The hardest part for me was figuring out how to make 
#        the derived classes connect properly to the hash class.
#        Turns out I was using a custom namespace for the hash.h 
#        file that was not needed. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment12.o spellCheck.o
	g++ -o a.out assignment12.o spellCheck.o -g -std=c++11
	tar -cf assignment12.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment12.o     : the driver program
#      spellCheck.o       : the spell-check program and driver
##############################################################
assignment12.o: hash.h assignment12.cpp list.h
	g++ -c assignment12.cpp -g -std=c++11

spellCheck.o: hash.h spellCheck.h spellCheck.cpp
	g++ -c spellCheck.cpp -g -std=c++11

clean: 
	rm a.out *.tar *.o
