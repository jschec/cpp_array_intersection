#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "Intersection.h"

void timerOutput(std::time_t endTime,
    std::chrono::duration<double> elapsedSeconds)
{
    endTime = std::chrono::system_clock::to_time_t(end);
    std::cout << "finished computation at " << std::ctime(&endTime)
              << "elapsed time: " << elapsedSeconds.count() << "s\n";
}

int main()
{
    // Stores 
    std::vector<char> vectOne;
    std::vector<char> vectTwo;

    // Timer variables
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsedSeconds;
    std::time_t endTime;

    std::cout << "Designate relative path first text document:" << std::endl;
    
    std::string filePathOne << std::cin;
    std::ofstream myfile (filePathOne);
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }

    std::cout << "Designate relative path second text document:" << std::endl;
    // read in second file here

    std::cout << "===================================" << std::endl;
    std::cout << "/ Shared characters demonstration /" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Brute force (linear search): " << std::endl;
    start = std::chrono::system_clock::now();
    bruteForceIntersection(vectOne, vectTwo);
    end = std::chrono::system_clock::now();
    elapsedSeconds = end - start;
    endTime = std::chrono::system_clock::to_time_t(end);
    timerOutput(endTime, elapsedSeconds);

    std::cout << "Binary intersection (binary search): " << std::endl;
    start = std::chrono::system_clock::now();
    binaryIntersection(vectOne, vectTwo);
    end = std::chrono::system_clock::now();
    elapsedSeconds = end - start;
    endTime = std::chrono::system_clock::to_time_t(end);
    timerOutput(endTime, elapsedSeconds);

    std::cout << "Multi-threaded linear search: " << std::endl;
    start = std::chrono::system_clock::now();
    multiThreadedIntersection(vectOne, vectTwo);
    end = std::chrono::system_clock::now();
    elapsedSeconds = end - start;
    endTime = std::chrono::system_clock::to_time_t(end);
    timerOutput(endTime, elapsedSeconds);
}