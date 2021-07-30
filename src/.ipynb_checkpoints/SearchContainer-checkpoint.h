/**
 * SearchContainer.h 
 *
 * Declarations for SearchContainer class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */
#pragma once
#include <vector>
#include <thread>
#include <math.h>

/**
 * This SearchContainer class allows for multi-threaded linear searching of
 * the provided vector.
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
    SearchContainer(const std::vector<T> &sourceVector,
        unsigned assignedThreads);

    /**
     * Looks for the search value in the vector referenced in this
     * SearchContainer
     * 
     * @param   value     value to search for
     * 
     * @return  true if one of the threads has found the value, false
     *          otherwise
     */ 
    bool searchValue(T value);
private:
    /**
     * Uses thread number to dynamically calculate the search range and
     * assign a thread to linearly search that subset of the search vector
     * 
     * @param   threadIdx   current thread number
     */
    void linearSearchThreaded(unsigned threadIdx);
   
    /** value to be searched for */
    T soughtValue;
    /** vector to be searched */
    std::vector<T> searchVector;
    /** number of threads available */
    unsigned numThreads;
    /** length of elements assigned to each thread */
    int jobSize;
    /** vector containing worker threads */
    std::vector<std::thread> threads;
    /** true if soughtValue was found in searchVector, otherwise false*/
    bool found;
}; // end SearchContainer.h