EXE		 = ../../../../simp38
INCLUDES = ../../../includes
COMMON   = ../../../common

CC = g++
FLAGS = -g

$(EXE) : simpsons38Main.o simpsons38.o $(COMMON)/sampleClosed.o
	$(CC) $(FLAGS) -o $(EXE) simpsons38Main.o simpsons38.o $(COMMON)/sampleClosed.o

simpsons13.o : simpsons38.cpp simpsons38.h $(INCLUDES)/IMethod.h
	$(CC) $(CFLAGS) -c simpsons38.cpp

sampleOpen.o : $(COMMON)/sampleOpen.cpp $(COMMON)/sampleOpen.h $(INCLUDES)/ISample.h $(INCLUDES)/point.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleOpen.cpp
