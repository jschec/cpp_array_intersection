#include <iostream>
#include <cassert>
#include <vector>
#include "intersection.h"

/**
 * Test linearSearch method for returning the correct index
 */ 
void testLinearSearchFindValue()
{
    bool foundVal = false;
    std::vector<char> testVect = {'a', 'd', 'e', 'd', 'j'};

    int foundIdx = linearSearch<char>(testVect, 0, testVect.size(), '1', foundVal);
    assert(foundIdx == -1);
    assert(foundVal == false);

    foundIdx = linearSearch<char>(testVect, 0, testVect.size(), 'a', foundVal);
    assert(foundIdx == 0);
    assert(foundVal == true);

    // reset found status
    foundVal = false;

    foundIdx = linearSearch<char>(testVect, 0, testVect.size(), 'd', foundVal);
    assert(foundIdx == 1);
    assert(foundVal == true);

    // reset found status
    foundVal = false;

    foundIdx = linearSearch<char>(testVect, 0, testVect.size(), 'j', foundVal);
    assert(foundIdx == 4);
    assert(foundVal == true);
    std::cout << "Passed testLinearSearchFindValue()" << std::endl;
}

/**
 * Test linearSearch method for handling invalid search ranges
 */ 
void testLinearSearchInvalidRange()
{
    bool foundVal = false;
    std::vector<char> testVect = {'a', 'd', 'e', 'd'};

    // start and end index are 0
    int testOneFoundIdx = linearSearch<char>(testVect, 0, 0, 'a', foundVal);
    assert(testOneFoundIdx == -1);
    assert(foundVal == false);

    // start index is greater than end index
    int testTwoFoundIdx = linearSearch<char>(testVect, 10, 0, 'a', foundVal);
    assert(testTwoFoundIdx == -1);
    assert(foundVal == false);

    std::cout << "Passed testLinearSearchFindValue()" << std::endl;
}

/**
 * Test bruteForceIntersection method for returning the correct
 * number of matching characters
 */ 
void testBruteForceIntersectionChar()
{
    std::vector<char> testVectOne = {'a', 'd', 'e', 'd'};
    std::vector<char> testVectTwo = {'a', 'e', 'e'};
    std::vector<char> testVectThree = {'d'};

    std::unordered_set<char> sharedCharsOne = bruteForceIntersection<char>(
        testVectOne, testVectTwo);
    assert(sharedCharsOne.size() == 2);

    std::unordered_set<char> sharedCharsTwo = bruteForceIntersection<char>(
        testVectOne, testVectThree);
    assert(sharedCharsTwo.size() == 1);

    std::cout << "Passed testBruteForceIntersectionChar()" << std::endl;
}

/**
 * Test bruteForceIntersection method for returning the correct
 * number of matching integers
 */ 
void testBruteForceIntersectionInt()
{
    std::vector<int> testVectOne = { 1, 4, 3, 2 };
    std::vector<int> testVectTwo = { 3, 2, 1, 2 };
    std::vector<int> testVectThree = { 1 };

    std::unordered_set<int> sharedCharsOne = bruteForceIntersection<int>(
        testVectOne, testVectTwo);
    assert(sharedCharsOne.size() == 3);

    std::unordered_set<int> sharedCharsTwo = bruteForceIntersection<int>(
        testVectOne, testVectThree);
    assert(sharedCharsTwo.size() == 1);

    std::cout << "Passed testBruteForceIntersectionInt()" << std::endl;
}


int main()
{
    //
    testLinearSearchFindValue();
    testLinearSearchInvalidRange();

    //
    testBruteForceIntersectionChar();
    testBruteForceIntersectionInt();
} // end test.cpp