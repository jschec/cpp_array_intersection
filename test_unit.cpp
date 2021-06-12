#include <iostream>
#include <cassert>
#include <vector>
#include "intersection.h"
#include <algorithm>    // std::sort

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

    std::cout << "Passed testLinearSearchInvalidRange()" << std::endl;
}

/**
 * Test binarySearch method for returning the correct index
 */ 
void testBinarySearchFindValue()
{
    std::vector<char> testVect = {'a', 'c', 'd', 'e', 'j'};

    int foundIdx = binarySearch<char>(testVect, 0, testVect.size() - 1, '1');
    assert(foundIdx == -1);

    foundIdx = binarySearch<char>(testVect, 0, testVect.size() - 1, 'a');
    assert(foundIdx == 0);

    foundIdx = binarySearch<char>(testVect, 0, testVect.size() - 1, 'd');
    assert(foundIdx == 2);

    foundIdx = binarySearch<char>(testVect, 0, testVect.size() - 1, 'j');
    assert(foundIdx == 4);
    std::cout << "Passed testBinarySearchFindValue()" << std::endl;
}

/**
 * Test binarySearch method for handling invalid search ranges
 */ 
void testBinarySearchInvalidRange()
{
    std::vector<char> testVect = {'a', 'd', 'd', 'e'};

    // start index is greater than end index
    int testTwoFoundIdx = binarySearch<char>(testVect, 10, 0, 'a');
    assert(testTwoFoundIdx == -1);

    std::cout << "Passed testBinarySearchInvalidRange()" << std::endl;
}

/**
 * Test bruteForceIntersection method with char vectors for returning the 
 * correct number of matching characters
 */
void testBruteForceIntersectionChar()
{
    std::vector<char> testVectOne = {'a', 'd', 'e', 'd'};
    std::vector<char> testVectTwo = {'a', 'e', 'e'};
    std::vector<char> testVectThree = {'d'};

    std::unordered_set<char> sharedElementsOne = bruteForceIntersection<char>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 2);
    assert(sharedElementsOne.count('a') == 1);
    assert(sharedElementsOne.count('e') == 1);

    std::unordered_set<char> sharedElementsTwo = bruteForceIntersection<char>(
        testVectOne, testVectThree);
    assert(sharedElementsTwo.size() == 1);
    assert(sharedElementsTwo.count('d') == 1);

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

    std::unordered_set<int> sharedElementsOne = bruteForceIntersection<int>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 3);
    assert(sharedElementsOne.count(1) == 1);
    assert(sharedElementsOne.count(2) == 1);
    assert(sharedElementsOne.count(3) == 1);

    std::unordered_set<int> sharedElementsTwo = bruteForceIntersection<int>(
        testVectOne, testVectThree);
    assert(sharedElementsTwo.size() == 1);
    assert(sharedElementsTwo.count(1) == 1);

    std::cout << "Passed testBruteForceIntersectionInt()" << std::endl;
}

/**
 * Test binaryIntersection method for returning the correct
 * number of matching characters
 */ 
void testBinaryIntersectionChar()
{
    std::vector<char> testVectOne = {'a', 'd', 'd', 'e'};
    std::vector<char> testVectTwo = {'a', 'e', 'e'};
    std::vector<char> testVectThree = {'d'};

    std::unordered_set<char> sharedElementsOne = binaryIntersection<char>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 2);
    assert(sharedElementsOne.count('a') == 1);
    assert(sharedElementsOne.count('e') == 1);

    std::unordered_set<char> sharedElementsTwo = binaryIntersection<char>(
        testVectOne, testVectThree);
    assert(sharedElementsTwo.size() == 1);
    assert(sharedElementsTwo.count('d') == 1);
    std::cout << "Passed testBinaryIntersectionChar()" << std::endl;
}

void testBinaryIntersectionInt()
{
    std::vector<int> testVectOne = { 1, 2, 3, 4 };
    std::vector<int> testVectTwo = { 1, 2, 2, 3 };
    std::vector<int> testVectThree = { 1 };

    std::unordered_set<int> sharedElementsOne = binaryIntersection<int>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 3);
    assert(sharedElementsOne.count(1) == 1);
    assert(sharedElementsOne.count(2) == 1);
    assert(sharedElementsOne.count(3) == 1);

    std::unordered_set<int> sharedElementsTwo = binaryIntersection<int>(
        testVectOne, testVectThree);
    assert(sharedElementsTwo.size() == 1);
    assert(sharedElementsTwo.count(1) == 1);

    std::cout << "Passed testBinaryIntersectionInt()" << std::endl;
}



int main()
{
    // Linear search unit testing
    testLinearSearchFindValue();
    testLinearSearchInvalidRange();

    // Binary search unit testing
    testBinarySearchFindValue();
    testBinarySearchInvalidRange();

    // bruteForceIntersection unit testing
    testBruteForceIntersectionChar();
    testBruteForceIntersectionInt();

    // binaryIntersection unit testing
    testBinaryIntersectionChar();
    testBinaryIntersectionInt();


} // end test.cpp