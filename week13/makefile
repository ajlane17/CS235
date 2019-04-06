###############################################################
# Program:
#     Assignment 13, Graph
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Kenyon Bunker, Ethan Holden
# Summary:
#     This is a program that stores a custom graph ADT. This 
#     graph will store the connections that each element within 
#     the graph have to one another. The second part is where it  
#     takes a maze from a file and first displays a 
#     pictoral representation of the maze and then solves it by 
#     showing where the shortest path from start to finish is.
# Time Spent:
#     Adrian: 6 hours
#     Kenyon: 5 hours
#     Ethan: 4 hours
#     Paired: 2 hours
# Hardest Part:
#     Adrian:
#       The most difficult part was in trying to figure out 
#       how to return a list with the findpath method, because 
#       the pseudocode was building the return object using 
#       the random access operator, which isn't allowed for a 
#       list. Luckily, the findpath method is only used by the 
#       maze functionality, which we were also responsible for 
#       implementing, so we took liberties in changing the 
#       return object to something more random-access friendly.
#     Kenyon:
#       My hardest part was determining which data structure to 
#       use for the given variables in findPath. I honestly 
#       expected  in the for loops in findPath for the 
#       comparison operators to need tweaking like we had to do 
#       a few weeks ago. So glad it just worked.
#     Ethan:
#     	The hardest part for me was trying to figure out how 
#     	to get the display graph functions to show only a 
#     	blank graph. I ended up having to modify the display 
#     	functions to do so.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment13.o graph.o maze.o
	g++ -o a.out assignment13.o graph.o maze.o -g -std=c++11
	tar -cf assignment13.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment13.o     : the driver program
#      graph.o            : the graph code
#      maze.o             : the maze reading and solving code
##############################################################
assignment13.o: graph.h vertex.h set.h assignment13.cpp
	g++ -c assignment13.cpp -g -std=c++11

graph.o: graph.h set.h vector.h vertex.h graph.cpp
	g++ -c graph.cpp -g -std=c++11

maze.o: maze.cpp maze.h vertex.h graph.h
	g++ -c maze.cpp -g -std=c++11

clean: 
	rm a.out *.tar *.o
