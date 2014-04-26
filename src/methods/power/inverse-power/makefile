EXE		 = ../../../../invpot
INCLUDES = ../../../includes
COMMON   = ../../../common

CC = g++
FLAGS = -g

$(EXE) : invpot.o inversePower.o $(COMMON)/samplePower.o  $(COMMON)/lu.o $(COMMON)/EquationSystem.o $(COMMON)/Matrix.o
	$(CC) $(FLAGS) -o $(EXE) invpot.o inversePower.o $(COMMON)/samplePower.o $(COMMON)/Matrix.o $(COMMON)/lu.o $(COMMON)/EquationSystem.o

inversePower.o : inversePower.cpp inversePower.h $(INCLUDES)/IMethod.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h $(COMMON)/lu.cpp $(COMMON)/lu.h $(COMMON)/EquationSystem.cpp $(COMMON)/EquationSystem.h
	$(CC) $(CFLAGS) -c inversePower.cpp $(COMMON)/Matrix.cpp $(COMMON)/lu.cpp

samplePower.o : $(COMMON)/samplePower.cpp $(COMMON)/samplePower.h $(INCLUDES)/ISample.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/samplePower.cpp $(COMMON)/Matrix.cpp

lu.o :  $(COMMON)/lu.cpp $(COMMON)/lu.h $(COMMON)/EquationSystem.cpp $(COMMON)/EquationSystem.h
	$(CC) $(CFLAGS) -c $(COMMON)/lu.cpp $(COMMON)/EquationSytem.cpp

Matrix.o :  $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/Matrix.cpp

EquationSystem.o :  $(COMMON)/EquationSystem.cpp  $(COMMON)/EquationSystem.h
	$(CC) $(CFLAGS) -c $(COMMON)/EquationSystem.cpp
