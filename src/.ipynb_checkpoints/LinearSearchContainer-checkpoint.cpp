/*
 * LinearSearchContainer.cpp 
 *
 * Implementations for LinearSearchContainer class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */

#include <unordered_set>
#include <vector>
#include "LinearSearchContainer.h"

/**
 * Leverages linear search to determine common values between 
 * source and target vectors.
 * 
 * @param   targetVector the second vector of elements to be linearly searched 
 * 
 * @return  Set of common elements shared between both vectors
 */ 
std::unordered_set<T> LinearSearchContainer::search(const std::vector<T> &targetVector)
{
	// hash set containing shared elements between both vectors
	std::unordered_set<T> sharedElementSet;

	for (unsigned sourceVectorIdx = 0; sourceVectorIdx < sourceVector.size();
		sourceVectorIdx++)
	{
		for (unsigned targetVectorIdx = 0; targetVectorIdx < targetVector.size(); 
            targetVectorIdx++)
        {
            if (sourceVector[sourceVectorIdx] == targetVector[targetVectorIdx])
            {
                sharedElementSet.insert(sourceVector[sourceVectorIdx]);
            }
        }
		
	}

	return sharedElementSet;
} // end LinearSearchContainer.cpp