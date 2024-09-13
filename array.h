
//---------------------------------------------------------------------------
/** @file array.h
*   @authors Deitel/Deitel, Olson and Zander
*   @brief class Array (for integers)
*   @version 1.0
*   @date 2024-09-13
*   @see array.cpp for implementation details. */
/** @details This file declares the Array class, which include management for dynamic arrays .
*   @callgraph
*   @callergraph
---------------------------------------------------------------------------
Array class:  like an int array (retains all functionality) but also
  includes additional features:
  -- allows input and output of the whole array
  -- allows for comparison of 2 arrays, element by element
  -- allows for assignment of 2 arrays
  -- size is part of the class (so no longer needs to be passed)
  -- includes range checking, program terminates for out-of-bound subscripts

Implementation and assumptions:
  -- size defaults to a fixed size of 10 if size is not specified
  -- array elements are initialized to zero
  -- user must enter valid integers when using >>
  -- in <<, integers are displayed 10 per line
---------------------------------------------------------------------------
*/
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

/**
 * @class Array
 * @brief A simple dynamic array class for integers.
 * @details This class includes methods for initializing, accessing, and modifying elements of an array.
 */
class Array {
    //---------------------------------------------------------------------------
    // operator>>
    // Overloaded input operator for class Array; inputs values for entire array.
    // Preconditions:   a.ptr must point to an array with size at least a.size
    // Postconditions:  The first a.size elements of a.ptr are filled with
    //          integers read from the input istream
    friend istream& operator>>( istream&, Array& );

    //---------------------------------------------------------------------------
    // operator<<
    // Overloaded output operator for class Array
    // Preconditions:   a.ptr must point to an array with size at least a.size
    // Postconditions:  The first a.size elements of a.ptr are sent to the 
    // output istream 10 per line with a trailing endl
    friend ostream& operator<<( ostream&, const Array& );

public:
    /**
    @brief Default constructor
    @param[in] arraySize (optional) - The size of the array. If not provided, defaults to 10.
    @pre   None
    @post  ptr points to an array of size arraySize and all
            elements of the array have been initialized to zero.
            arrayCount is incremented.
            Negative input values result in the default size of 10
    */
    Array( int = 10 );
/** 
    @brief Copy constructor
    @param[in] init - An array to be copied into *this
    @pre   init.ptr points to an array of size at least init.size
    @post  init is copied into *this, arrayCount is incremented
*/
    Array( const Array& );
/**
    @brief Destructor 
    @pre   ptr points to memory on the heap
    @post  Array for ptr is deallocated, arrayCount is decremented
 */
    ~Array();
/**
    @brief Gets the size of the array
    @pre   None
    @post  Returns the size of the array
    @return  The size of the array
 */
    int getSize() const;
/**
    @brief operator=
    @param[in] right - An array to be assigned to *this
    @pre   right.ptr points to an array of size at least right.size
    @post  *this is assigned the same array as right
    @return  *this
 */
    const Array& operator=( const Array& );
/**
    @brief operator==, Determine if two arrays are equal
    @return true is returned if the arrays have the same size
    @pre   ptr and right.ptr point to arrays with size at least size and right.size, respectively
    @post  true is returned if the arrays have the same size and elements false is return otherwise
 */
    bool operator==( const Array& ) const;
/**
    @brief operator!=, Determine if two arrays are not equal
    @param[in] right - An array is compared
    @return false is returned if the arrays have the same size
    @pre ptr and right.ptr point to arrays with size at least size and right.size, respectively
    @post  false is returned if the arrays have the same size and elements true is return otherwise
*/
    bool operator!=( const Array& ) const;
/**
    @brief operator[], Overloaded subscript operator, terminates if subscript out of range error
    @param[in] subscript - The index of the array element to be accessed
    @pre  0 <= subscript < size
    @post  Returns the array value at position "subscript"
 */
    int& operator[]( int );

/**    
    @brief getArrayCount 
    @return Return the number of Array objects instantiated
    @pre   None
    @post  Returns the number of arrays
 */
    static int getArrayCount();

private:
    int* ptr;                          // pointer to first element of array
    int size;                          // size of the array
    static int arrayCount;             // # of Arrays instantiated
};

#endif
