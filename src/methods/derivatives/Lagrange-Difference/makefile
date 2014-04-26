EXE		 = ../../../../gendiff
INCLUDES = ../../../includes
COMMON   = ../../../common
DERIVATIVES = ..

CC = g++
FLAGS = -g

$(EXE) : gendiff.o $(DERIVATIVES)/Derivative.o $(COMMON)/Function.o
	$(CC) $(FLAGS) -o $(EXE) gendiff.o $(DERIVATIVES)/Derivative.o $(COMMON)/Function.o

Derivative.o : $(DERIVATIVES)/Derivative.cpp $(DERIVATIVES)/Derivative.h $(COMMON)/Function.cpp $(COMMON)/Function.h $(INCLUDES)/point.h
	$(CC) $(CFLAGS) -c $(DERIVATIVES)/Derivative.cpp $(COMMON)/Function.cpp

Function.o : $(COMMON)/Function.cpp $(COMMON)/Function.h $(INCLUDES)/IFunction.h
	$(CC) $(CFLAGS) -c $(COMMON)/Function.cpp