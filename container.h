/**
 * container.h 
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
#include <mutex>

template<typename T>
class Container
{
public:
    /**
    * Constructor for Container class, which initializes the searchVector
    * and number of threads to be used for searching.
    * 
    * @param    sourceVector        vector of elements to be searched
    * 
    * @param    assignedThreads     number of threads assigned to assist with
    *                               searching
    */
    Container(const std::vector<T> &sourceVector, unsigned assignedThreads) 
    {
        searchVector = sourceVector;
        numThreads = assignedThreads;
        threads = threads(numThreads);
        jobSize =  sourceVector.size() / numThreads;
    }

    /**
     * 
     */ 
    bool search(T searchValue)
    {
        soughtValue = searchValue;

        // initiate multi-threaded linear search
        for (unsigned idx = 0; idx < numThreads; idx++)
        {
            threads[idx] = std::thread(linearSearchThreaded, idx);
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
     * 
     */
    void linearSearchThreaded(int threadIdx)
    {
        // locks thread
        std::unique_lock<std::mutex> lock(mtx);

        int startSearchPos = threadIdx * jobSize;
        int endSearchPos;

        // adjusts ending search position depending on thread number
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
};