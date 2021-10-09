CXX = g++
CXXFLAGS = -Wall

main: main.o Integral.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@

clean : 
	rm *.o