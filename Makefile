main.exe : main.o Integral.o
	g++ -Wall main.o Integral.o -o main.exe

main.o : main.cpp Integral.hpp
	g++ -Wall -c main.cpp

Integral.o : Integral.hpp Integral.cpp
	g++ -Wall -c Integral.cpp


clean : 
	rm *.o