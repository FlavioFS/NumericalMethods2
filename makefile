
sources = main.cpp sample.cpp simpsons13.cpp simpsons38.cpp trapezoidal.cpp Function.cpp

objects = main.o sample.o simpsons13.o simpsons38.o trapezoidal.o Function.o

main : $(objects)
	g++ -o main $(objects)
     
main.o : main.cpp sample.h simpsons13.h simpsons38.h trapezoidal.h
	g++ -c main.cpp
sampleClosed.o : sampleClosed.cpp sampleClosed.h function.h
	g++ -c sampleClosed.cpp
sampleOpen.o : sampleOpen.cpp sampleOpen.h function.h
	g++ -c sampleOpen.cpp
newtoncotes.o : newtonCotes.cpp newtonCotes.h IMethod.h
	g++ -c newtonCotes.cpp
simpsons38.o : simpsons38.cpp simpsons38.h IMethod.h
	g++ -c simpsons38.cpp
simpsons13.o : simpsons13.cpp simpsons13.h IMethod.h
	g++ -c simpsons13.cpp
trapezoidal.o : trapezoidal.cpp trapezoidal.h IMethod.h
	g++ -c trapezoidal.cpp
Function.o : Function.cpp Function.h
	g++ -c Function.cpp
clean :
	rm main $(objects)

