EXE		 = ../../../../simp13
INCLUDES = ../../../includes
COMMON   = ../../../common

CC = g++
FLAGS = -g

$(EXE) : simpsons13Main.o simpsons13.o $(COMMON)/sampleClosed.o
	$(CC) $(FLAGS) -o $(EXE) simpsons13Main.o simpsons13.o $(COMMON)/sampleClosed.o

simpsons13.o : simpsons13.cpp simpsons13.h $(INCLUDES)/IMethod.h
	$(CC) $(CFLAGS) -c simpsons13.cpp

sampleClosed.o : $(COMMON)/sampleClosed.cpp $(COMMON)/sampleClosed.h $(INCLUDES)/ISample.h $(INCLUDES)/point.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleClosed.cpp
