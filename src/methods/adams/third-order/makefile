EXE		 = ../../../../adams3
INCLUDES = ../../../includes
COMMON   = ../../../common
ADAMS = ..

CC = g++
FLAGS = -g

$(EXE) : Adams3.o $(ADAMS)/Adams.o $(COMMON)/FunctionRn.o $(COMMON)/sample-initial-value.o
	$(CC) $(FLAGS) -o $(EXE) Adams3.o $(ADAMS)/Adams.o $(COMMON)/FunctionRn.o $(COMMON)/sample-initial-value.o

Adams.o : $(ADAMS)/Adams.cpp $(ADAMS)/Adams.h $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h
	$(CC) $(CFLAGS) -c $(ADAMS)/Adams.cpp $(COMMON)/FunctionRn.cpp

FunctionRn.o : $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h
	$(CC) $(FLAGS) -c $(COMMON)/FunctionRn.cpp

sample-initial-value.o : $(COMMON)/sample-initial-value.cpp $(COMMON)/sample-initial-value.h $(INCLUDES)/ISample.h
	$(CC) $(FLAGS) -c $(COMMON)/sample-initial-value.cpp