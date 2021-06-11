CXX = g++
CXXFLAGS = -g -Wall -std=c++11

main: main.o
	$(CXX) $(CXXFLAGS) -o main main.o
test_unit: test_unit.o
	$(CXX) $(CXXFLAGS) -o test_unit test_unit.o
clean:
	rm -f core *.o main test_unit