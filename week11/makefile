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
#     Adrian: 7 hours
#     Kenyon: 5
#     Paired: 1 hour
# Hardest Part:
#     Ethan:
#        THe hardest part was working on the heap sort. I had 
#        coppied the array to the class and sorted it, instead 
#        of using a pointer to change the original array itself. 
#        But once I got that, it worked great.
#     Adrian:
#       I worked on merge sort, and I could not get most of it to
#       work following the pseudocode, wheras the other algorithms
#       seemed to work apples to apples. I clearly drew the short
#       end of the stick with that one. I left comments in the code
#       where I was unable to replicate the pseudocode logic.
#     Kenyon:
#       My hardest part was selection sort. in sortSelection. i 
#       was getting this error: binary '<=': 'T' does not define 
#       this operator or a conversion to a type acceptable to the 
#       predefined operator, on this line of code: 
#       if (array[iLargest] <= array[iCheck].) 
#       The fix was to add <= operator overlaod to sortValue
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
