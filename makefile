
sources = main.cpp sample.cpp simpsons13.cpp simpsons38.cpp trapezoidal.cpp Function.cpp

objects = main.o sample.o simpsons13.o simpsons38.o trapezoidal.o Function.o

main : $(objects)
	g++ -o main $(objects)
     
main.o : main.cpp sample.h simpsons13.h simpsons38.h trapezoidal.h
	g++ -c main.cpp
sample.o : sample.cpp sample.h function.h
	g++ -c sample.cpp
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

