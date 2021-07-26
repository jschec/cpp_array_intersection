/*
 * BinarySearchContainer.h 
 *
 * Declarations for BinarySearchContainer class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */

#pragma once
#include <unordered_set>
#include <vector>
#include "SearchContainerBase.h"

/**
 * This BinarySearchContainer class allows for the binary searching of 
 * common elements between the source and target vector of elements.
 */ 
template<typename T>
class BinarySearchContainer : public SearchContainerBase<T>
{
public:
	/**
	 * Constructor for BinarySearchContainer class, which initializes the source
	 * vector to search
	 * 
	 * @param    sourceVector        vector of elements to be searched
	 */
	BinarySearchContainer(const std::vector<T> &sourceVector);

	/**
	 * Leverage binary search to determine common values between 
	 * source and target vectors.
	 * 
	 * @param   targetVector the second vector of elements to be binary searched 
	 * 
	 * @pre     targetVector must be sorted
	 * 
	 * @return  Set of common elements shared between both vectors
	 */ 
	std::unordered_set<T> search(const std::vector<T> &targetVector) override;
private:
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
	int binarySearch(const std::vector<T> &vector, int leftIdx, int rightIdx,
		T soughtValue);
}; // end BinarySearchContainer.h