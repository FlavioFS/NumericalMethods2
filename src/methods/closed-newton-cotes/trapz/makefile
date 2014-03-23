EXE		 = ../../../../trapz
INCLUDES = ../../../includes
COMMON   = ../../../common

CC = g++
FLAGS = -g

$(EXE) : trapezoidalMain.o trapezoidal.o $(COMMON)/sampleClosed.o
	$(CC) $(FLAGS) -o $(EXE) trapezoidalMain.o trapezoidal.o $(COMMON)/sampleClosed.o

trapezoidal.o : trapezoidal.cpp trapezoidal.h $(INCLUDES)/IMethod.h
	$(CC) $(CFLAGS) -c trapezoidal.cpp

sampleOpen.o : $(COMMON)/sampleOpen.cpp $(COMMON)/sampleOpen.h $(INCLUDES)/ISample.h $(INCLUDES)/point.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleOpen.cpp
