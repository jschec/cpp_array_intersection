/**
 * SearchContainerBase.cpp
 *
 * Declarations for SearchContainerBase class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */

#include "SearchContainer.h"
#include <vector>
#include <thread>
#include <math.h>

/**
 * Constructor for SearchContainerBase class, which initializes the source
 * vector to search
 * 
 * @param    sourceVector        vector of elements to be searched
 */
template<typename T>
SearchContainerBase<T>::SearchContainerBase(const std::vector<T> &sourceVector)
{
	searchVector = sourceVector;
}

// Specify data types that SearchContainerBase class can be used for
template class SearchContainerBase<int>;
template class SearchContainerBase<char>;
// end SearchContainerBase.cpp