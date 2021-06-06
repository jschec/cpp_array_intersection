/**
 * Intersection.h 
 *
 * Declarations and implementations for methods used for identifying common
 * elements between two vectors. Not seperated into .cpp file due to 
 * template compilation errors.
 * 
 * Joshua Scheck
 * 2021-06-10
 */
#pragma once
#include <vector>
#include <thread>
#include <pthread.h>
#include <unordered_set>
#include "container.h"

/**
 * Recursively searches a sorted vector by repeatedly dividing the search
 * interval in half.
 * 
 * @param   vector      vector to be searched
 * 
 * @param   leftIdx     starting position of search
 * 
 * @param   rightIdx    ending position of search
 * 
 * @param   soughtValue value to search for
 * 
 * @return  index of the first instance of the sought value, -1 otherwise
 */
template <typename T>
int binarySearch(const std::vector<T> &vector, int leftIdx, int rightIdx,
    T soughtValue)
{
    if (rightIdx >= leftIdx) 
    {
        int midIdx = (leftIdx + rightIdx) / 2;
 
        if (vector[midIdx] == soughtValue)
        {
            return midIdx;
        }
        
        // search left subarray if element is smaller than middle element
        if (vector[midIdx] > soughtValue)
        {
            return binarySearch(vector, leftIdx, midIdx - 1, soughtValue);
        }

        // otherwise search right subarray
        return binarySearch(vector, midIdx + 1, rightIdx, soughtValue);
    }
 
    // sought value has not been found
    return -1;
}

/**
 * Searches linearly through both vectors to find shared elements.
 * 
 * @param   vectOne the first vector of elements to be searched
 * 
 * @param   vectTwo the second vector of elements to be searched
 * 
 * @return  Set of common elements shared between both vectors
 */
template <typename T>
std::unordered_set<T> bruteForceIntersection(const std::vector<T> &vectOne,
    const std::vector<T> &vectTwo)
{
    // hash set containing shared elements between both vectors
    std::unordered_set<T> sharedElementSet;

    for (unsigned vectOneIdx = 0; vectOneIdx < vectOne.size();
        vectOneIdx++)
    {
        for (unsigned vectTwoIdx = 0; vectTwoIdx < vectTwo.size(); 
            vectTwoIdx++)
        {
            if (vectOne[vectOneIdx] == vectTwo[vectTwoIdx])
            {
                sharedElementSet.insert(vectOne[vectOneIdx]);
            }
        }
    }

    return sharedElementSet;
}

/**
 * Execute binary search iteratively to determine common values between 
 * both vectors.
 * 
 * @param   vectOne the first vector of elements to be linearly searched
 * 
 * @param   vectTwo the second vector of elements to be binary searched 
 * 
 * @pre     vectTwo must be sorted
 * 
 * @return  Set of common elements shared between both vectors
 */ 
template <typename T>
std::unordered_set<T> binaryIntersection(const std::vector<T> &vectOne, 
    const std::vector<T> &vectTwo)
{
    // hash set containing shared elements between both vectors
    std::unordered_set<T> sharedElementSet;

    for (unsigned vectOneIdx = 0; vectOneIdx < vectOne.size();
        vectOneIdx++)
    {
        T soughtVal = vectOne[vectOneIdx];
        
        int foundIdx = binarySearch(vectTwo, 0, vectTwo.size() - 1, soughtVal);

        // adds element to shared element set if a valid index is returned 
        // after conducting binary search
        if (foundIdx != -1)
        {
            sharedElementSet.insert(soughtVal);
        }
    }

    return sharedElementSet;
}

/**
 * Leverages multiple threads to speed up linear both vectors to find 
 * shared elements.
 * 
 * @param   vectOne the first vector of elements to be searched
 * 
 * @param   vectTwo the second vector of elements to be searched
 * 
 * @return  Set of common elements shared between both vectors
 */ 
std::unordered_set<char> multiThreadedIntersection(const std::vector<char> &vectOne, 
    const std::vector<char> &vectTwo)
{
     // hash set containing shared elements between both vectors
    std::unordered_set<char> sharedElementSet;

    Container<char> container(vectTwo, 5);

    for (unsigned idx = 0; idx < vectOne.size(); idx++) {
        char soughtVal = vectOne[idx];
        
        bool elementFound = container.search(soughtVal);

        if (elementFound) 
        {
            sharedElementSet.insert(soughtVal);
        }
    }

    return sharedElementSet;
} // end IntersectionMethods.h