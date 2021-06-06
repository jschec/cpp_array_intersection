/**
 * test.cpp
 *
 * Unit tests for Intersection.h and SearchContainer.h methods
 * 
 * Joshua Scheck
 * 2021-06-10
 */

#include <iostream>
#include <cassert>
#include <vector>
#include "Intersection.h"
#include "SearchContainer.h"

/**
 * Test binarySearch method for returning the correct index when sought value
 * is NOT available.
 */
void testBinarySearchNotAvailValue()
{
    std::vector<char> testVect = {'a', 'c', 'd', 'e', 'j'};
    int foundIdx = binarySearch<char>(testVect, 0, testVect.size() - 1, '1');
    assert(foundIdx == -1);
    std::cout << "Passed testBinarySearchNotAvailValue()" << std::endl;
}

/**
 * Test binarySearch method for returning the correct index when sought value
 * is available.
 */
void testBinarySearchAvailValue()
{
    std::vector<char> testVect = {'a', 'c', 'd', 'e', 'j'};

    int foundIdx = binarySearch<char>(testVect, 0, testVect.size() - 1, 'a');
    assert(foundIdx == 0);

    foundIdx = binarySearch<char>(testVect, 0, testVect.size() - 1, 'd');
    assert(foundIdx == 2);

    foundIdx = binarySearch<char>(testVect, 0, testVect.size() - 1, 'j');
    assert(foundIdx == 4);
    std::cout << "Passed testBinarySearchAvailValue()" << std::endl;
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
 * Test bruteForceIntersection method with int vectors for returning the
 * correct number of matching integers
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
 * Test bruteForceIntersection method with char vectors for returning the
 * correct number of matching characters when one of the vectors is empty
 */
void testBruteForceIntersectionEmpty()
{
    std::vector<char> testVectOne = {'a', 'd', 'e', 'd'};
    std::vector<char> testVectTwo = {};
    std::vector<char> testVectThree = {};

    std::unordered_set<char> sharedElementsOne = bruteForceIntersection<char>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 0);

    std::unordered_set<char> sharedElementsTwo = bruteForceIntersection<char>(
        testVectTwo, testVectThree);
    assert(sharedElementsTwo.size() == 0);

    std::cout << "Passed testBruteForceIntersectionEmpty()" << std::endl;
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

/**
 * Test binaryIntersection method for returning the correct
 * number of matching integers
 */ 
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

/**
 * Test binaryIntersection method with char vectors for returning the
 * correct number of matching characters when one of the vectors is empty
 */
void testBinaryIntersectionEmpty()
{
    std::vector<char> testVectOne = {'a', 'd', 'e', 'd'};
    std::vector<char> testVectTwo = {};
    std::vector<char> testVectThree = {};

    std::unordered_set<char> sharedElementsOne = binaryIntersection<char>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 0);

    std::unordered_set<char> sharedElementsTwo = binaryIntersection<char>(
        testVectTwo, testVectThree);
    assert(sharedElementsTwo.size() == 0);

    std::cout << "Passed testBinaryIntersectionEmpty()" << std::endl;
}

/**
 * Test find method from SearchContainer class in finding the sought character
 * value in an odd lengthed vector
 */
void testSearchContainerFindCharOdd()
{
    std::vector<char> testVectOne = {'a', 'l', 'e', 'z', 'q'};

    SearchContainer<char> container(testVectOne, 3);
    bool found = container.search('a');
    assert(found == true);

    found = container.search('1');
    assert(found == false);

    found = container.search('e');
    assert(found == true);

    found = container.search('q');
    assert(found == true);
    std::cout << "Passed testSearchContainerFindCharOdd()" << std::endl;
}

/**
 * Test find method from SearchContainer class in finding the sought character
 * value in an even lengthed vector
 */
void testSearchContainerFindCharEven()
{
    std::vector<char> testVectOne = {'a', 'l', 'e', 'z', 's', 'q'};

    SearchContainer<char> container(testVectOne, 3);
    bool found = container.search('a');
    assert(found == true);

    found = container.search('1');
    assert(found == false);

    found = container.search('e');
    assert(found == true);

    found = container.search('q');
    assert(found == true);
    std::cout << "Passed testSearchContainerFindCharEven()" << std::endl;
}

/**
 * Test find method from SearchContainer class in finding the sought integer
 * value
 */
void testSearchContainerFindInt()
{
    std::vector<int> testVectOne = { 5, 4, 92, 21, 1};

    SearchContainer<int> container(testVectOne, 3);
    bool found = container.search(5);
    assert(found == true);

    found = container.search(4);
    assert(found == true);

    found = container.search(3);
    assert(found == false);

    found = container.search(1);
    assert(found == true);
    std::cout << "Passed testSearchContainerFindInt()" << std::endl;
}

/**
 * Test multiThreadedIntersection method for returning the correct
 * number of matching characters
 */ 
void testMultiThreadedIntersectionChar()
{
    std::vector<char> testVectOne = {'a', 'd', 'd', 'e'};
    std::vector<char> testVectTwo = {'a', 'e', 'e'};
    std::vector<char> testVectThree = {'d'};

    std::unordered_set<char> sharedElementsOne = multiThreadedIntersection<char>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 2);
    assert(sharedElementsOne.count('a') == 1);
    assert(sharedElementsOne.count('e') == 1);

    std::unordered_set<char> sharedElementsTwo = multiThreadedIntersection<char>(
        testVectOne, testVectThree);
    assert(sharedElementsTwo.size() == 1);
    assert(sharedElementsTwo.count('d') == 1);
    std::cout << "Passed testMultiThreadedIntersectionChar()" << std::endl;
}

/**
 * Test multiThreadedIntersection method for returning the correct
 * number of matching integers
 */ 
void testMultiThreadedIntersectionInt()
{
    std::vector<int> testVectOne = { 1, 2, 3, 4 };
    std::vector<int> testVectTwo = { 1, 2, 2, 3 };
    std::vector<int> testVectThree = { 1 };

    std::unordered_set<int> sharedElementsOne = multiThreadedIntersection<int>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 3);
    assert(sharedElementsOne.count(1) == 1);
    assert(sharedElementsOne.count(2) == 1);
    assert(sharedElementsOne.count(3) == 1);

    std::unordered_set<int> sharedElementsTwo = multiThreadedIntersection<int>(
        testVectOne, testVectThree);
    assert(sharedElementsTwo.size() == 1);
    assert(sharedElementsTwo.count(1) == 1);

    std::cout << "Passed testMultiThreadedIntersectionInt()" << std::endl;
}

/**
 * Test multiThreadedIntersection method with char vectors for returning the
 * correct number of matching characters when one of the vectors is empty
 */
void testMultiThreadedIntersectionEmpty()
{
    std::vector<char> testVectOne = {'a', 'd', 'e', 'd'};
    std::vector<char> testVectTwo = {};
    std::vector<char> testVectThree = {};

    std::unordered_set<char> sharedElementsOne = multiThreadedIntersection<char>(
        testVectOne, testVectTwo);
    assert(sharedElementsOne.size() == 0);

    std::unordered_set<char> sharedElementsTwo = multiThreadedIntersection<char>(
        testVectTwo, testVectThree);
    assert(sharedElementsTwo.size() == 0);

    std::cout << "Passed testMultiThreadedIntersectionEmpty()" << std::endl;
}

int main()
{
    std::cout << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "/       Executing unit tests      /" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;

    // Binary search unit testing
    testBinarySearchNotAvailValue();
    testBinarySearchAvailValue();
    testBinarySearchInvalidRange();

    // binaryIntersection unit testing
    testBinaryIntersectionChar();
    testBinaryIntersectionInt();
    testBinaryIntersectionEmpty();

    // bruteForceIntersection unit testing
    testBruteForceIntersectionChar();
    testBruteForceIntersectionInt();
    testBruteForceIntersectionEmpty();

    // SearchContainer find method unit testing
    testSearchContainerFindCharOdd();
    testSearchContainerFindCharEven();
    testSearchContainerFindInt();

    // multiThreadedIntersection unit testing
    testMultiThreadedIntersectionChar();
    testMultiThreadedIntersectionInt();
    testMultiThreadedIntersectionEmpty();
    std::cout << std::endl;
} // end test.cpp