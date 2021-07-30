/*
 * MTLinearSearchContainer.cpp 
 *
 * Declarations for MTLinearSearchContainer class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */

#pragma once
#include <unordered_set>
#include <vector>
#include "SearchContainerBase.h"
#include "SearchContainer.h"

/**
 * Constructor for MTLinearSearchContainer class, which initializes the searchVector
 * and number of threads to be used for linear searching.
 * 
 * @param    sourceVector        vector of elements to be searched
 * 
 * @param    assignedThreads     number of threads assigned to assist with
 *                               searching
 */
template<typename T>
MTLinearSearchContainer<T>::MTLinearSearchContainer(const std::vector<T> &sourceVector,
	unsigned assignedThreads)
{
	searchVector = sourceVector;
	numThreads = assignedThreads;
}

/**
 * Leverages multiple threads to speed up linear both vectors to find 
 * shared elements.
 * 
 * @param   targetVector the second vector of elements to be searched
 * 
 * @return  Set of common elements shared between both vectors
 */ 
template <typename T>
std::unordered_set<T> MTLinearSearchContainer<T>::search(
    const std::vector<T> &targetVector)
{
     // hash set containing shared elements between both vectors
    std::unordered_set<T> sharedElementSet;

    SearchContainer<T> searchContainer(targetVector, numThreads);

    for (unsigned idx = 0; idx < sourceVector.size(); idx++) {
        T soughtVal = sourceVector[idx];
        
        bool elementFound = searchContainer.searchValue(soughtVal);

        if (elementFound) 
        {
            sharedElementSet.insert(soughtVal);
        }
    }

    return sharedElementSet;
}

template class MTLinearSearchContainer<int>;
template class MTLinearSearchContainer<char>;
// end MTLinearSearchContainer.cpp