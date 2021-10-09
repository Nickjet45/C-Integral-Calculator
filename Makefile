CXX = g++
CXXFLAGS = -Wall

main: main.o Integral.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

main.o : main.cpp Integral.hpp
	g++ -Wall -c main.cpp

Integral.o : Integral.hpp Integral.cpp
	g++ -Wall -c Integral.cpp


clean : 
	rm *.o