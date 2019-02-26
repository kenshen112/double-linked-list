###############################################################
# Program:
#     Assignment 07, LIST
#     Brother Kirby, CS235
# Author:
#     Tim Obarr
#     Jessica Smith
#     Ken Smith
# Summary:
#     A contained ADT implementation of a doubly linked list,
#     as well as driver programs to test that implementation
# Time:
#     Group:
#     Solo:
#        Tim: 12+ 
#        Jessica: 4 hours
#        Ken: 9 hours
# Difficulties:
#     Tim: Figureing out how to declare insert was the MOST DIFFICULT thing i've had to do all semester
#     Jessica: Figuring out how to implement the big number class into
#	the fibonacci algorithm.
#     Ken: properly declaring the operators in the big numbers class
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

