EXE		 = ../../../../qrHouseholder
INCLUDES = ../../../includes
COMMON   = ../../../common
QR		 = ../simple

CC = g++
FLAGS = -g

Matrix.o : $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/Matrix.cpp

qr.o : $(QR)/qr.h $(QR)/qr.cpp $(INCLUDES)/IMethod.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(QR)/qr.cpp $(COMMON)/Matrix.cpp

qrHouseholder.o : $(INCLUDES)/IMethod.h $(QR)/qr.h $(QR)/qr.cpp $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c qrHouseholder.cpp $(COMMON)/Matrix.cpp $(QR)/qr.cpp

sampleQr.o : $(COMMON)/sampleQr.cpp $(COMMON)/sampleQr.h $(INCLUDES)/ISample.h $(COMMON)/Matrix.cpp $(COMMON)/Matrix.h
	$(CC) $(CFLAGS) -c $(COMMON)/sampleQr.cpp $(COMMON)/Matrix.cpp

$(EXE) : qrHouseholderMain.o qrHouseholder.o $(COMMON)/sampleQr.o $(COMMON)/Matrix.o
	$(CC) $(FLAGS) -o $(EXE) qrHouseholderMain.o qr.o $(COMMON)/sampleQr.o $(COMMON)/Matrix.o