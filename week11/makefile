###############################################################
# Program:
#     Assignment 11, Sorts
#     Brother Kirby, CS235
# Author:
#     Ethan Holden, Adrian Lane, Kenyon Bunker.
# Summary:
#     A program that uses seven sort functions to sort an array. 
#     They are Bubble Sort, Selection Sort, Insertion Sort, 
#     Binary Sort, Heap Sort, Merge Sort, and Quick Sort.
# Time:
#     Ethan: 4 hours
#     Adrian:
#     Kenyon:
#     Paired:
# Hardest Part:
#     Ethan:
#        THe hardest part was working on the heap sort. I had 
#        coppied the array to the class and sorted it, instead 
#        of using a pointer to change the original array itself. 
#        But once I got that, it worked great.
#     Adrian:
#     Kenyon:
###############################################################

##############################################################
# The main rule
##############################################################
a.out: assignment11.o
	g++ -o a.out assignment11.o -g -std=c++11
	tar -cf assignment11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      assignment11.o     : the driver program
##############################################################
assignment11.o: assignment11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c assignment11.cpp -g -std=c++11

clean:
	rm a.out *.o *.tar
