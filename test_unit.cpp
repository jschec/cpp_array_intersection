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
    std::vector<char> testVect = {'a', 'd', 'e'};

    int foundIdx = linearSearch<char>(testVect, 0, testVect.size(), '1', foundVal);
    assert(foundIdx == -1);
    assert(foundVal == false);

    foundIdx = linearSearch<char>(testVect, 0, testVect.size(), 'a', foundVal);
    assert(foundIdx == 0);
    assert(foundVal == true);

    // reset found status
    foundVal = false;
}


int main()
{
    testLinearSearchFindValue();

} // end test.cpp