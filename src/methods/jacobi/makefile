EXE		 = ../../../jacobi
INCLUDES = ../../includes
COMMON   = ../../common

CC = g++
FLAGS = -g

$(EXE) : jacobiMain.o jacobi.o $(COMMON)/sampleJacobi.o $(COMMON)/Matrix.o
	$(CC) $(FLAGS) -o $(EXE) jacobiMain.o jacobi.o $(COMMON)/sampleJacobi.o $(COMMON)/Matrix.o

jacobi.o : jacobi.cpp jacobi.h $(INCLUDES)/IMethod.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c jacobi.cpp $(COMMON)/Matrix.cpp

sampleJacobi.o : $(COMMON)/sampleJacobi.cpp $(COMMON)/sampleJacobi.h $(INCLUDES)/ISample.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleJacobi.cpp $(COMMON)/Matrix.cpp

Matrix.o : $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/Matrix.cpp