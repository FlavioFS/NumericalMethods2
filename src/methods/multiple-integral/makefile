EXE		 = ../../../int_dup
INCLUDES = ../../includes
COMMON   = ../../common
CLOSED_NEWTON_COTES = ../closed-newton-cotes


CC = g++
FLAGS = -g

$(EXE) : multipleIntegralMain.o multipleIntegral.o $(COMMON)/sampleMultipleIntegral.o $(CLOSED_NEWTON_COTES)/simpson13/simpsons13.o $(CLOSED_NEWTON_COTES)/trapz/trapezoidal.o
	$(CC) $(FLAGS) -o $(EXE) multipleIntegralMain.o multipleIntegral.o $(COMMON)/sampleMultipleIntegral.o $(CLOSED_NEWTON_COTES)/simpson13/simpsons13.o $(CLOSED_NEWTON_COTES)/trapz/trapezoidal.o

multipleIntegral.o : multipleIntegral.cpp multipleIntegral.h $(INCLUDES)/IMethod.h $(CLOSED_NEWTON_COTES)/simpson13/simpsons13.cpp $(CLOSED_NEWTON_COTES)/simpson13/simpsons13.h $(CLOSED_NEWTON_COTES)/trapz/trapezoidal.cpp $(CLOSED_NEWTON_COTES)/trapz/trapezoidal.h 
	$(CC) $(CFLAGS) -c newtonCotes.cpp $(COMMON)/Function.cpp

sampleMultipleIntegral.o : $(COMMON)/sampleMultipleIntegral.cpp $(COMMON)/sampleMultipleIntegral.h $(INCLUDES)/ISample.h 
	$(CC) $(CFLAGS) -c $(COMMON)/sampleMultipleIntegral.cpp

simpsons13.o : $(CLOSED_NEWTON_COTES)/simpson13/simpsons13.cpp $(CLOSED_NEWTON_COTES)/simpson13/simpsons13.h $(INCLUDES)/IMethod.h
	$(CC) $(CFLAGS) -c $(CLOSED_NEWTON_COTES)/simpson13/simpsons13.cpp

trapezoidal.o : $(CLOSED_NEWTON_COTES)/simpson13/trapezoidal.cpp $(CLOSED_NEWTON_COTES)/simpson13/trapezoidal.h $(INCLUDES)/IMethod.h
	$(CC) $(CFLAGS) -c $(CLOSED_NEWTON_COTES)/simpson13/trapezoidal.cpp