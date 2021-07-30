/**
 * Intersection.h 
 *
 * Declarations for methods used for identifying common
 * elements between two vectors.
 * 
 * Joshua Scheck
 * 2021-06-10
 */
#pragma once
#include <vector>
#include <thread>
#include <unordered_set>
#include "SearchContainer.h"

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
    T soughtValue);

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
    const std::vector<T> &vectTwo);

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
    const std::vector<T> &vectTwo);

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
template <typename T>
std::unordered_set<T> multiThreadedIntersection(const std::vector<T> &vectOne, 
    const std::vector<T> &vectTwo);
// end Intersection.h