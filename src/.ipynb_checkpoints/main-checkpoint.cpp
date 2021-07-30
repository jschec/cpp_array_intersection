/**
 * main.cpp
 *
 * Demonstrates a few approaches in identifying shared character values between
 * two vectors
 * 
 * Joshua Scheck
 * 2021-06-10
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <string>
#include <algorithm>
#include "Intersection.h"
#include "LinearSearchContainer.h"
#include "BinarySearchContainer.h"
#include "MTLinearSearchContainer.h"

/**
 * Stops the timer and outputs the executation time and the current time to the
 * output stream
 * 
 * @param   start   start time
 */ 
void timerOutput(std::chrono::time_point<std::chrono::system_clock> &start)
{
    // timer variables
    std::chrono::time_point<std::chrono::system_clock> end =
        std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedSeconds = end - start;

    std::cout << "elapsed time - " << elapsedSeconds.count() << "s"
        << std::endl;
}

/**
 * Entry point to the program
 */ 
int main()
{
    std::chrono::time_point<std::chrono::system_clock> start;
    std::vector<char> vectOne;
    std::vector<char> vectTwo;
    std::string fileOnePath;
    std::string fileTwoPath;
    char input;

    std::cout << std::endl;
    std::cout << "Designate path first text document:" << std::endl;
    std::cin >> fileOnePath;

    // read file one into char vector
    std::ifstream textFileOne;
    textFileOne.open(fileOnePath);
    while (textFileOne.peek() != EOF)
    {
        textFileOne.get(input);
        vectOne.push_back(input);
    }
    textFileOne.close();
    
    std::cout << "Designate path second text document:" << std::endl;
    std::cin >> fileTwoPath;

    // read file two into another char vector
    std::ifstream textFileTwo;
    textFileTwo.open(fileTwoPath);
    while (textFileTwo.peek() != EOF)
    {
        textFileTwo.get(input);
        vectTwo.push_back(input);
    }
    textFileTwo.close();

    std::cout << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "/ Shared characters demonstration /" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;

    // demonstrate time effeciency between approaches
    std::cout << "Brute force (linear search): " << std::endl;
    start = std::chrono::system_clock::now();
	LinearSearchContainer searchContainer = LinearSearchContainer(vectOne);
    std::unordered_set<char> bruteForceCommonChar = 
        searchContainer.search(vectTwo);
    timerOutput(start);
    std::cout << "common char count - " << bruteForceCommonChar.size()
        << std::endl << std::endl;
    
    std::cout << "Multi-threaded linear search: " << std::endl;
    start = std::chrono::system_clock::now();
	MTLinearSearchContainer searchContainer = MTLinearSearchContainer(vectOne);
    std::unordered_set<char> multiThreadedCommonChar = 
        searchContainer.search(vectTwo);
    timerOutput(start);
    std::cout << "common char count - " << multiThreadedCommonChar.size()
        << std::endl << std::endl;

    std::cout << "Binary intersection (binary search): " << std::endl;
    start = std::chrono::system_clock::now();
    std::sort(vectTwo.begin(), vectTwo.end());
	BinarySearchContainer searchContainer = BinarySearchContainer(vectOne);
    std::unordered_set<char> binaryCommonChar = 
        searchContainer.search(vectTwo);
    timerOutput(start);
    std::cout << "common char count - " << binaryCommonChar.size()
        << std::endl << std::endl;

    // write common characters out to ./common_characters.txt
    std::ofstream outfile("./common_characters.txt");
    for (auto itr = binaryCommonChar.begin(); itr != binaryCommonChar.end();
        ++itr) {
        outfile << *itr;
    }
    outfile.close();

    return 0;
}