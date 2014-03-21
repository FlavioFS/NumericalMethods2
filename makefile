
sources = main.cpp sampleClosed.cpp sampleOpen.cpp simpsons13.cpp simpsons38.cpp trapezoidal.cpp Function.cpp

objects = trapezoidal.o simpsons13.o simpsons38.o newtonCotes.o quadraturagaussiana.o sampleClosed.o sampleOpen.o Function.o

## ================ CLOSED NEWTON-COTES ================ ##
# Trapezoidal Rule exe
trapz : trapezoidal.o sampleClosed.o
	g++ -o trapz trapezoidal.o sampleClosed.o

trapezoidal.o : trapezoidalMain.cpp trapezoidal.cpp trapezoidal.h IMethod.h
	g++ -c trapezoidal.cpp

# 1/3 Simpson Rule exe
simp13 : simpsons13.o sampleClosed.o
	g++ -o simp13 simpsons13.o sampleClosed.o

simpsons13.o : simpsons13Main.cpp simpsons13.cpp simpsons13.h IMethod.h Function.h
	g++ -c simpsons13.cpp


# 3/8 Simpson Rule exe
simp38 : simpsons38.o sampleClosed.o
	g++ -o simp38 simpsons38.o sampleClosed.o

simpsons38.o : simpsons38Main.cpp simpsons38.cpp simpsons38.h IMethod.h
	g++ -c simpsons38.cpp
## ===================================================== ##


## ================ OPEN NEWTON-COTES ================ ##
# Open Newton-Cotes formulae
opnewton :  newtonCotes.o Function.o sampleOpen.o
	g++ -c opnewton newtonCotes.o Function.o sampleOpen.o

newtonCotes.o : newtonCotesMain.cpp newtonCotes.cpp newtonCotes.h IMethod.h
	g++ -c newtonCotes.cpp


# Gaussian quadrature exe
gaussquad : quadraturagaussiana.cpp
	g++ -o gaussquad quadraturagaussiana.o

quadraturagaussiana.o : quadraturagaussiana.cpp
	g++ -c quadraturagaussiana.cpp
## =================================================== ##


## ======================= UTILS ===================== ##
# Read from file - Samples
sampleClosed.o : sampleClosed.cpp sampleClosed.h function.h
	g++ -c sampleClosed.cpp

sampleOpen.o : sampleOpen.cpp sampleOpen.h function.h
	g++ -c sampleOpen.cpp

# Function class
Function.o : Function.cpp Function.h
	g++ -c Function.cpp
## =================================================== ##

clean :
	rm main $(objects)

# Old main code (developed by Inaciane)
#main : $(objects)
#	g++ -o main $(objects)
#main.o : main.cpp sample.h simpsons13.h simpsons38.h trapezoidal.h
#	g++ -c main.cpp