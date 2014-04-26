EXE		 = ../../../../regpot
INCLUDES = ../../../includes
COMMON   = ../../../common

CC = g++
FLAGS = -g

$(EXE) : regpot.o regularPower.o $(COMMON)/samplePower.o $(COMMON)/Matrix.o
	$(CC) $(FLAGS) -o $(EXE) regpot.o regularPower.o $(COMMON)/samplePower.o $(COMMON)/Matrix.o

regularPower.o : regularPower.cpp regularPower.h $(INCLUDES)/IMethod.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c regularPower.cpp $(COMMON)/Matrix.cpp

samplePower.o : $(COMMON)/samplePower.cpp $(COMMON)/samplePower.h $(INCLUDES)/ISample.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/samplePower.cpp $(COMMON)/Matrix.cpp

Matrix.o :  $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/Matrix.cpp