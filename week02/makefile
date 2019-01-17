###############################################################
# Program:
#     Assignment 02, STACK
#     Brother Kirby, CS235
# Author:
#     Adrian Lane, Ethan Holden
# Summary:
#     <put a description here>
# Time:
#	Ethan -- 1 hr 20 min.
#	Adrian --
#     <how long did it take to complete this program>?
# The most difficult part:
#     <what was the most difficult part>?
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
