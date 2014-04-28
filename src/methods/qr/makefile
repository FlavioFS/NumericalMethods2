EXE		 = ../../../qr
INCLUDES = ../../includes
COMMON   = ../../common

CC = g++
FLAGS = -g

$(EXE) : qrMain.o qr.o $(COMMON)/sampleQr.o $(COMMON)/Matrix.o
	$(CC) $(FLAGS) -o $(EXE) qrMain.o qr.o $(COMMON)/sampleQr.o $(COMMON)/Matrix.o

qr.o : qr.cpp qr.h $(INCLUDES)/IMethod.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c qr.cpp $(COMMON)/Matrix.cpp

sampleQr.o : $(COMMON)/sampleQr.cpp $(COMMON)/sampleQr.h $(INCLUDES)/ISample.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleQr.cpp $(COMMON)/Matrix.cpp

Matrix.o : $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/Matrix.cpp