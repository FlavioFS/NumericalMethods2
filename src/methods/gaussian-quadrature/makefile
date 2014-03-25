EXE		 = ../../../quad_gauss
INCLUDES = ../../includes
COMMON   = ../../common

CC = g++
FLAGS = -g

$(EXE) : gaussianQuadratureMain.o gaussianQuadrature.o $(COMMON)/sampleOpen.o $(COMMON)/Function.o
	$(CC) $(FLAGS) -o $(EXE) gaussianQuadratureMain.o gaussianQuadrature.o $(COMMON)/sampleOpen.o $(COMMON)/Function.o

gaussianQuadrature.o : gaussianQuadrature.cpp gaussianQuadrature.h $(INCLUDES)/IMethod.h $(COMMON)/Function.cpp $(COMMON)/Function.h
	$(CC) $(CFLAGS) -c gaussianQuadrature.cpp $(COMMON)/Function.cpp

sampleOpen.o : $(COMMON)/sampleOpen.cpp $(COMMON)/sampleOpen.h $(INCLUDES)/ISample.h $(INCLUDES)/point.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleOpen.cpp

Function.o : $(COMMON)/Function.cpp $(COMMON)/Function.h $(INCLUDES)/IFunction.h
	$(CC) $(CFLAGS) -c $(COMMON)/Function.cpp