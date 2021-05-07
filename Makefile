CXX = g++

mergesort: mergesort.o
	$(CXX) -o mergesort mergesort.o

mergesort.o: mergesort.cpp mergesort.hpp
	$(CXX) -std=c++98 -g -c mergesort.cpp

clean:
	rm mergesort mergesort.o
