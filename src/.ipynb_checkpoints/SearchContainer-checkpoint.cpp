/**
 * SearchContainer.h 
 *
 * Implementations for SearchContainer class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */
#pragma once
#include <vector>
#include <thread>
#include <math.h>

/**
 * Constructor for SearchContainer class, which initializes the searchVector
 * and number of threads to be used for linear searching.
 * 
 * @param    sourceVector        vector of elements to be searched
 * 
 * @param    assignedThreads     number of threads assigned to assist with
 *                               searching
 */
template<typename T>
SearchContainer<T>::SearchContainer(const std::vector<T> &sourceVector,
        unsigned assignedThreads)
{
    searchVector = sourceVector;
    numThreads = assignedThreads;
    jobSize = std::round(sourceVector.size() / (float) numThreads);
} 

/**
 * Looks for the search value in the vector referenced in this
 * SearchContainer
 * 
 * @param   value     value to search for
 * 
 * @return  true if one of the threads has found the value, false
 *          otherwise
 */
template<typename T>
bool SearchContainer<T>::searchValue(T value)
{
    // resets search params
    found = false;
    soughtValue = value;

    // initiate multi-threaded linear search
    for (unsigned idx = 0; idx < numThreads; idx++)
    {
        if (threads.size() < numThreads) 
        {
            threads.push_back(std::thread(&SearchContainer<T>::linearSearchThreaded, this, idx));
        } 
        else
        {
            threads[idx] = std::thread(&SearchContainer<T>::linearSearchThreaded, this, idx);
        }
    }
    // synchronize threads
    for (unsigned idx = 0; idx < numThreads; idx++)
    {
        threads[idx].join();
    }

    return found;
}


/**
 * Uses thread number to dynamically calculate the search range and
 * assign a thread to linearly search that subset of the search vector
 * 
 * @param   threadIdx   current thread number
 */
template<typename T>
void SearchContainer<T>::linearSearchThreaded(unsigned threadIdx)
{
    // calculate search ranges for each thread
    int startSearchPos = threadIdx * jobSize;
    int endSearchPos;

    // adjusts ending search position in accordance to thread number
    if (threadIdx + 1 == numThreads)
    {
        endSearchPos = searchVector.size() - 1;
    }
    else 
    {
        endSearchPos = startSearchPos + jobSize - 1;
    }

    for (int idx = startSearchPos; idx <= endSearchPos; idx++)
    {
        if (searchVector[idx] == soughtValue)
        {
            // flags that the sought value was found
            found = true;
            break;
        }
    }
}

template class SearchContainer<int>;
template class SearchContainer<char>;
// end SearchContainer.cpp