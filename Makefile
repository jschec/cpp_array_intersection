CXX         = g++
CXXFLAGS    = -g -Wall -pthread -std=c++11

PROG_NAME   = prog
SRC_DIR     = ./src
BUILD_DIR   = ./build
BIN_DIR     = ./bin

CXXFLAGS = -g -Wall -pthread -std=c++11

main: main.o
	$(CXX) $(CXXFLAGS) -o $(SRC_DIR)/main main.o
test: test.o
	$(CXX) $(CXXFLAGS) -o $(SRC_DIR)/test test.o 
clean:
	rm -f core *.o main test common_characters.txt
	