###############################################################
# Program:
#     Assignment 02, STACK
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden
# Summary:
#     This program is a custom version of the stack class that 
#     stores values is a first in last out manner. It provides 
#     methods that allow the user to add to the stack, as well 
#     as take the top item off of the stack.
#     The second part is there is a separate set of functions 
#     that first allow the user to change an infix equation 
#     into a postfix equation. Then we also made it so that 
#     the program can also convert that same postfix equation 
#     into assembly language.
# Time:
#     Ethan  = 9 hours
#     Adrian = 9 hours
#     Total  = 18 hours
# The most difficult part:
#     The most difficult parts of this project were in the 
#     infix to postfix section of the project. The first was 
#     figuring out how to check against the order of operations 
#     and made a separate function to do that. Second we had 
#     trouble with the spacing on the output of postfix 
#     equations. Then finally we kept getting this error that 
#     terminated the program after throwing an instance of 
#     'char const*', and we still don't know exactly what 
#     caused that.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: stack.h assignment02.o infix.o 
	g++ -o a.out assignment02.o infix.o  -std=c++11
	tar -cf assignment02.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment02.o : the driver program
#      infix.o        : the logic for the infix --> postfix program
##############################################################
assignment02.o: stack.h infix.h assignment02.cpp
	g++ -c assignment02.cpp  -std=c++11

infix.o: stack.h infix.h infix.cpp
	g++ -c infix.cpp -std=c++11

clean:
	rm a.out *.o *.tar
