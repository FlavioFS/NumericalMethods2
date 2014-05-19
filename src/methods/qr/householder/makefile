EXE		 = ../../../../qrHouseholder
INCLUDES = ../../../includes
COMMON   = ../../../common
QR		 = ../simple

CC = g++
FLAGS = -g

$(EXE) : qrHouseholderMain.o qr.o qrHouseholder.o $(COMMON)/sampleQr.o $(COMMON)/Matrix.o
	$(CC) $(FLAGS) -o $(EXE) qrHouseholderMain.o qr.o qrHouseholder.o $(COMMON)/sampleQr.o $(COMMON)/Matrix.o

qr.o : $(QR)/qr.h $(QR)/qr.cpp $(INCLUDES)/IMethod.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(QR)/qr.cpp $(COMMON)/Matrix.cpp

qrHouseholder.o :  $(QR)/qr.h $(QR)/qr.cpp qrHouseholder.h qrHouseholder.cpp $(INCLUDES)/IMethod.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c qrHouseholder.cpp $(QR)/qr.cpp $(COMMON)/Matrix.cpp

sampleQr.o : $(COMMON)/sampleQr.cpp $(COMMON)/sampleQr.h $(INCLUDES)/ISample.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleQr.cpp $(COMMON)/Matrix.cpp

Matrix.o : $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/Matrix.cpp