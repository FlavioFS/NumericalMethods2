EXE		 = ../../../romberg
INCLUDES = ../../includes
COMMON   = ../../common

CC = g++
FLAGS = -g

$(EXE) : rombergMain.o romberg.o $(COMMON)/sampleOpen.o $(COMMON)/Function.o
	$(CC) $(FLAGS) -o $(EXE) rombergMain.o romberg.o $(COMMON)/sampleRomberg.o $(COMMON)/Function.o

romberg.o : romberg.cpp romberg.h $(INCLUDES)/IMethod.h $(COMMON)/Function.cpp $(COMMON)/Function.h
	$(CC) $(CFLAGS) -c romberg.cpp $(COMMON)/Function.cpp

sampleRomberg.o : $(COMMON)/sampleRomberg.cpp $(COMMON)/sampleRomberg.h $(INCLUDES)/ISample.h $(INCLUDES)/point.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleRomberg.cpp

Function.o : $(COMMON)/Function.cpp $(COMMON)/Function.h $(INCLUDES)/IFunction.h
	$(CC) $(CFLAGS) -c $(COMMON)/Function.cpp