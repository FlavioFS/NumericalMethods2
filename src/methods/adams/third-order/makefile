EXE		 = ../../../../adams3
INCLUDES = ../../../includes
COMMON   = ../../../common
RK		 = ../../runge-kutta
ADAMS = ..

CC = g++
FLAGS = -g

$(EXE) : adams3.o $(ADAMS)/Adams.o $(COMMON)/FunctionRn.o $(COMMON)/sample-initial-value.o $(RK)/RungeKutta.o
	$(CC) $(FLAGS) -o $(EXE) adams3.o $(ADAMS)/Adams.o $(COMMON)/FunctionRn.o $(COMMON)/sample-initial-value.o $(RK)/RungeKutta.o

RungeKutta.o : $(RK)/RungeKutta.cpp $(RK)/RungeKutta.h $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h $(INCLUDES)/point.h
	$(CC) $(FLAGS) -c $(RK)/RungeKutta.cpp $(RK)/FunctionRn.cpp

Adams.o : $(ADAMS)/Adams.cpp $(ADAMS)/Adams.h $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h $(INCLUDES)/point.h
	$(CC) $(CFLAGS) -c $(ADAMS)/Adams.cpp $(COMMON)/FunctionRn.cpp

FunctionRn.o : $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h
	$(CC) $(FLAGS) -c $(COMMON)/FunctionRn.cpp

sample-initial-value.o : $(COMMON)/sample-initial-value.cpp $(COMMON)/sample-initial-value.h $(INCLUDES)/ISample.h
	$(CC) $(FLAGS) -c $(COMMON)/sample-initial-value.cpp