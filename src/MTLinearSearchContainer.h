/*
 * MTLinearSearchContainer.h 
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

/**
 * This MTLinearSearchContainer class allows for searching of the provided vector.
 */ 
template<typename T>
class MTLinearSearchContainer : public SearchContainerBase<T>
{
public:
    /**
     * Constructor for MTLinearSearchContainer class, which initializes the searchVector
     * and number of threads to be used for linear searching.
     * 
     * @param    sourceVector        vector of elements to be searched
     * 
     * @param    assignedThreads     number of threads assigned to assist with
     *                               searching
     */
    MTLinearSearchContainer(const std::vector<T> &sourceVector,
        unsigned assignedThreads);

	/**
     * Constructor for MTLinearSearchContainer class, which initializes the 
	 * searchVector and number of threads to be used for linear searching.
     * 
     * @param    sourceVector        vector of elements to be searched
     * 
     * @param    assignedThreads     number of threads assigned to assist with
     *                               searching
     */
    MTLinearSearchContainer(const std::vector<T> &sourceVector,
        unsigned assignedThreads);
		
	/**
	 * Leverage multi-threaded linear search to determine common values between
	 * source and target vectors.
	 * 
	 * @param   targetVector the second vector of elements to be binary searched 
	 * 
	 * @return  Set of common elements shared between both vectors
	 */ 
	std::unordered_set<T> search(const std::vector<T> &targetVector) override;
private:
    /** number of threads available */
    unsigned numThreads;
}; // end LinearSearchContainer.h