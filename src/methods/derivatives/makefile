EXE		 = ../../../derivatives
INCLUDES = ../../includes
COMMON   = ../../common

CC = g++
FLAGS = -g

$(EXE) : derivativesMain.o derivatives.o $(COMMON)/Function.o
	$(CC) $(FLAGS) -o $(EXE) derivativesMain.o derivatives.o $(COMMON)/Function.o

derivatives.o : derivatives.cpp derivatives.h $(COMMON)/Function.cpp $(COMMON)/Function.h
	$(CC) $(CFLAGS) -c derivatives.cpp $(COMMON)/Function.cpp

Function.o : $(COMMON)/Function.cpp $(COMMON)/Function.h $(INCLUDES)/IFunction.h
	$(CC) $(CFLAGS) -c $(COMMON)/Function.cpp