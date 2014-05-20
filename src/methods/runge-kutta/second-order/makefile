EXE		 = ../../../../rk2
INCLUDES = ../../../includes
COMMON   = ../../../common
RK		 = ..

CC = g++
FLAGS = -g

$(EXE) : rk2.o $(COMMON)/FunctionRn.o $(COMMON)/sample-initial-value.o $(RK)/RungeKutta.o
	$(CC) $(FLAGS) -o $(EXE) rk2.o $(RK)/RungeKutta.o $(COMMON)/FunctionRn.o $(COMMON)/sample-initial-value.o

RungeKutta.o : $(RK)/RungeKutta.cpp $(RK)/RungeKutta.h $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h $(INCLUDES)/point.h
	$(CC) $(FLAGS) -c $(RK)/RungeKutta.cpp $(RK)/FunctionRn.cpp

FunctionRn.o : $(COMMON)/FunctionRn.cpp $(COMMON)/FunctionRn.h
	$(CC) $(FLAGS) -c $(COMMON)/FunctionRn.cpp

sample-initial-value.o : $(COMMON)/sample-initial-value.cpp $(COMMON)/sample-initial-value.h $(INCLUDES)/ISample.h
	$(CC) $(FLAGS) -c $(COMMON)/sample-initial-value.cpp