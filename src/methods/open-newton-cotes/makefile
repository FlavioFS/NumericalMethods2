EXE		 = ../../../open_nc
INCLUDES = ../../includes
COMMON   = ../../common

CC = g++
FLAGS = -g

$(EXE) : newtonCotesMain.o newtonCotes.o $(COMMON)/sampleOpen.o $(COMMON)/Function.o
	$(CC) $(FLAGS) -o $(EXE) newtonCotesMain.o newtonCotes.o $(COMMON)/sampleOpen.o $(COMMON)/Function.o

newtonCotes.o : newtonCotes.cpp newtonCotes.h $(INCLUDES)/IMethod.h $(COMMON)/Function.cpp $(COMMON)/Function.h
	$(CC) $(CFLAGS) -c newtonCotes.cpp $(COMMON)/Function.cpp

sampleOpen.o : $(COMMON)/sampleOpen.cpp $(COMMON)/sampleOpen.h $(INCLUDES)/ISample.h $(INCLUDES)/point.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleOpen.cpp

Function.o : $(COMMON)/Function.cpp $(COMMON)/Function.h $(INCLUDES)/IFunction.h
	$(CC) $(CFLAGS) -c $(COMMON)/Function.cpp