EXE		 = ../../../../despot
INCLUDES = ../../../includes
COMMON   = ../../../common

CC = g++
FLAGS = -g

$(EXE) : despot.o shiftedPower.o $(COMMON)/sampleShiftedPower.o  $(COMMON)/lu.o $(COMMON)/EquationSystem.o $(COMMON)/Matrix.o
	$(CC) $(FLAGS) -o $(EXE) despot.o shiftedPower.o $(COMMON)/sampleShiftedPower.o $(COMMON)/Matrix.o $(COMMON)/lu.o $(COMMON)/EquationSystem.o

shiftedPower.o : shiftedPower.cpp shiftedPower.h $(INCLUDES)/IMethod.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h $(COMMON)/lu.cpp $(COMMON)/lu.h $(COMMON)/EquationSystem.cpp $(COMMON)/EquationSystem.h
	$(CC) $(CFLAGS) -c shiftedPower.cpp $(COMMON)/Matrix.cpp $(COMMON)/lu.cpp

sampleShiftedPower.o : $(COMMON)/sampleShiftedPower.cpp $(COMMON)/sampleShiftedPower.h $(INCLUDES)/ISample.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleShiftedPower.cpp $(COMMON)/Matrix.cpp

lu.o :  $(COMMON)/lu.cpp $(COMMON)/lu.h $(COMMON)/EquationSystem.cpp $(COMMON)/EquationSystem.h
	$(CC) $(CFLAGS) -c $(COMMON)/lu.cpp $(COMMON)/EquationSytem.cpp

Matrix.o :  $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/Matrix.cpp

EquationSystem.o :  $(COMMON)/EquationSystem.cpp  $(COMMON)/EquationSystem.h
	$(CC) $(CFLAGS) -c $(COMMON)/EquationSystem.cpp
