EXE		 = ../../../../adams4
COMMON   = ../../../common
ADAMS = ..

CC = g++
FLAGS = -g

SampleInitialValue.o : $(COMMON)/sample-initial-value.cpp $(COMMON)/sample-initial-value.h
	$(CC) $(CFLAGS) -c $(COMMON)/sample-initial-value.cpp

FunctionRn.o : $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h
	$(CC) $(CFLAGS) -c $(COMMON)/FunctionRn.cpp

Adams.o : $(ADAMS)/Adams.cpp $(ADAMS)/Adams.h $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h
	$(CC) $(CFLAGS) -c $(ADAMS)/Adams.cpp $(COMMON)/FunctionRn.cpp

$(EXE) : adams4.o $(ADAMS)/Adams.o $(COMMON)/FunctionRn.o $(COMMON)/SampleInitialValue.o
	$(CC) $(FLAGS) -o $(EXE) adams4.o $(ADAMS)/Adams.o $(COMMON)/FunctionRn.o $(COMMON)/SampleInitialValue.o