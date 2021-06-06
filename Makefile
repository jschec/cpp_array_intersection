CXX = g++
CXXFLAGS = -g -Wall -pthread -std=c++11

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o
test: test.o
	$(CXX) $(CXXFLAGS) -o test test.o 
clean:
	rm -f core *.o main test common_characters.txt