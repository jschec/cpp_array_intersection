/*
 * LinearSearchContainer.h 
 *
 * Declarations for LinearSearchContainer class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */

#pragma once
#include <unordered_set>
#include <vector>
#include "SearchContainerBase.h"

/**
 * This LinearSearchContainer class allows for searching of the provided vector.
 */ 
template<typename T>
class LinearSearchContainer : public SearchContainerBase<T>
{
public:
	/**
	 * Constructor for LinearSearchContainer class, which initializes the source
	 * vector to search
	 * 
	 * @param    sourceVector        vector of elements to be searched
	 */
	LinearSearchContainer(const std::vector<T> &sourceVector);

	/**
	 * Leverages linear search to determine common values between 
	 * source and target vectors.
	 * 
	 * @param   targetVector the second vector of elements to be linearly searched 
	 * 
	 * @return  Set of common elements shared between both vectors
	 */ 
	std::unordered_set<T> search(const std::vector<T> &targetVector) override;
}; // end LinearSearchContainer.h