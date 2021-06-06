/**
 * SearchContainer.h 
 *
 * Declarations and implementations for SearchContainer class. 
 * 
 * Joshua Scheck
 * 2021-06-11
 */
#pragma once
#include <vector>
#include <thread>
#include <mutex>

/**
 * This class can be used for leveraging multi-thread linear searching of a vector
 */ 
template<typename T>
class SearchContainer
{
public:
    /**
    * Constructor for SearchContainer class, which initializes the searchVector
    * and number of threads to be used for linear searching.
    * 
    * @param    sourceVector        vector of elements to be searched
    * 
    * @param    assignedThreads     number of threads assigned to assist with
    *                               searching
    */
    SearchContainer(const std::vector<T> &sourceVector, unsigned assignedThreads) 
    {
        searchVector = sourceVector;
        numThreads = assignedThreads;
        jobSize =  sourceVector.size() / numThreads;
    }

    /**
     * Looks for the search value in the vector referenced in this SearchContainer
     * 
     * @param   searchValue     value to search for
     * 
     * @return  true if one of the threads has found the searchValue, false
     *          otherwise
     */ 
    bool search(T searchValue)
    {
        // resets search params
        found = false;
        soughtValue = searchValue;

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
private:
    /**
     * Uses thread number to dynamically calculate the search range and
     * assign a thread to linearly search that subset of the search vector
     * 
     * @param   threadIdx   current thread number
     */
    void linearSearchThreaded(unsigned threadIdx)
    {
        // locks thread
        std::unique_lock<std::mutex> lock(mtx);
        
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
            endSearchPos = (threadIdx + 1) * jobSize;
        }

        for (int idx = startSearchPos; idx < endSearchPos; idx++)
        {
            if (searchVector[idx] == soughtValue)
            {
                // flags that the sought value was found
                found = true;
                break;
            }
        }

        // unlocks thread
        mtx.unlock();
    }
    /** Value to be searched for */
    T soughtValue;
    /** vector to be searched */
    std::vector<T> searchVector;
    /** for locking threads */
    std::mutex mtx;
    /** number of threads available */
    unsigned numThreads;
    /** length of elements assigned to each thread */
    int jobSize;
    /** vector containing worker threads */
    std::vector<std::thread> threads;
    /** true if soughtValue was found in searchVector, otherwise false*/
    bool found;
}; // end SearchContainer.h