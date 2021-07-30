/*
 * BinarySearchContainer.cpp
 *
 * Implementations for BinarySearchContainer class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */

#include <unordered_set>
#include <vector>
#include "BinarySearchContainer.h"

/**
 * Constructor for BinarySearchContainer class, which initializes the source
 * vector to search
 * 
 * @param    sourceVector        vector of elements to be searched
 */
template<typename T>
BinarySearchContainer<T>::BinarySearchContainer(const std::vector<T> &sourceVector) :
    SearchContainerBase(sourceVector) {}

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
template<typename T>
std::unordered_set<T> BinarySearchContainer<T>::search(const std::vector<T> &targetVector)
{
	// hash set containing shared elements between both vectors
	std::unordered_set<T> sharedElementSet;

	for (unsigned sourceVectorIdx = 0; sourceVectorIdx < sourceVector.size();
		sourceVectorIdx++)
	{
		T soughtVal = sourceVector[sourceVectorIdx];

		int foundIdx = binarySearch(targetVector, 0, targetVector.size() - 1, soughtVal);

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
int BinarySearchContainer<T>::binarySearch(const std::vector<T> &vector, int leftIdx, int rightIdx,
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
} // end BinarySearchContainer.cpp