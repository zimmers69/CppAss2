#Makefile for Assignment 2
#Alexander Zimmermann ZMMALE001

CC=g++
CCFLAGS=-std=c++11

SRC = $(wildcard src/*.cpp *.h)
OBJ = $(SRC:.cpp=.o)

PROG = volimage

$(PROG) : $(OBJ)
	$(CC) $(CCFLAGS) $(SRC) -o volimage
	
.cpp.o:
	$(CC) $(CCFLAGS) -c $<

depend:
	$(CC) -M $(SRC) > incl.defs

clean:
	rm -f *.o
	rm -f volimage
