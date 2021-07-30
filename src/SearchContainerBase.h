/**
 * SearchContainerBase.h 
 *
 * Declarations for SearchContainerBase class.
 * 
 * Joshua Scheck
 * 2021-06-11
 */
#pragma once
#include <vector>

/**
 * This SearchContainerBase class allows for searching of the provided vector.
 */ 
template<typename T>
class SearchContainerBase
{
public:
	/**
	 * Constructor for SearchContainer class, which initializes the source
     * vector to search
     * 
     * @param    sourceVector        vector of elements to be searched
     */
    SearchContainerBase(const std::vector<T> &sourceVector);
	
	/**
	 * Destructor for SearchContainerBase class
	 */
	virtual ~SearchContainerBase() = 0;

    /**
     * Looks for the matching elements between source and target vectors
     * 
     * @param   targetVector the second vector of elements to be searched 
     * 
     * @return  true if one of the threads has found the searchValue, false
     *          otherwise
     */ 
    virtual bool search(const std::vector<T> &targetVector) = 0;
protected:
    /** vector to be searched */
    std::vector<T> searchVector;
}; // end SearchContainerBase.h