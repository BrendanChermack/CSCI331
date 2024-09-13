//---------------------------------------------------------------------------
// ARRAY.H
// Simple class Array (for integers)
// Authors: Deitel/Deitel (Additional comments by Olson and Zander)
//---------------------------------------------------------------------------
// Array class:  like an int array (retains all functionality) but also
//   includes additional features:
//   -- allows input and output of the whole array
//   -- allows for comparison of 2 arrays, element by element
//   -- allows for assignment of 2 arrays
//   -- size is part of the class (so no longer needs to be passed)
//   -- includes range checking, program terminates for out-of-bound subscripts
//
// Implementation and assumptions:
//   -- size defaults to a fixed size of 10 if size is not specified
//   -- array elements are initialized to zero
//   -- user must enter valid integers when using >>
//   -- in <<, integers are displayed 10 per line
//---------------------------------------------------------------------------

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;


class Array {
//---------------------------------------------------------------------------
// operator>>
// Overloaded input operator for class Array; inputs values for entire array.
// Preconditions:   a.ptr must point to an array with size at least a.size
// Postconditions:  The first a.size elements of a.ptr are filled with
//          integers read from the input istream
friend istream& operator>>(istream &, Array &);

//---------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
// Preconditions:   a.ptr must point to an array with size at least a.size
// Postconditions:  The first a.size elements of a.ptr are sent to the 
// output istream 10 per line with a trailing endl
friend ostream& operator<<(ostream &, const Array &);

public:
//----------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  ptr points to an array of size arraySize and all
//         elements of the array have been initialized to zero.
//         arrayCount is incremented.
//         Negative input values result in the default size of 10
Array(int = 10); 

//---------------------------------------------------------------------------
// Copy constructor 
// Preconditions:   init.ptr points to an array of size at least init.size
// Postconditions:  init is copied into *this, arrayCount is incremented
Array(const Array &); 

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   ptr points to memory on the heap
// Postconditions:  Array for ptr is deallocated, arrayCount is decremented
~Array(); 

//---------------------------------------------------------------------------
// getSize 
// Get the size of the array
// Preconditions:   None
// Postconditions:  Returns the size of the array
int getSize() const; 

//---------------------------------------------------------------------------
// operator=
// Preconditions:   right.ptr points to an array of size at least right.size
// Postconditions:  *this is assigned the same array as right
const Array& operator=(const Array &); 

//---------------------------------------------------------------------------
// operator==
// Determine if two arrays are equal
// Preconditions:   ptr and right.ptr point to arrays with size at least
//          size and right.size, respectively
// Postconditions:  true is returned if the arrays have the same size and 
//          elements false is return otherwise
bool operator==(const Array &) const; 

//---------------------------------------------------------------------------
// operator!=
// Determine if two arrays are not equal
// Preconditions:   ptr and right.ptr point to arrays with size at least
//          size and right.size, respectively
// Postconditions:  false is returned if the arrays have the same size and 
//          elements true is return otherwise
bool operator!=(const Array &) const;

//---------------------------------------------------------------------------
// operator[]
// Overloaded subscript operator, terminates if subscript out of range error
// Preconditions:   0 <= subscript < size
// Postconditions:  Returns the array value at position "subscript"
int& operator[](int); 

//---------------------------------------------------------------------------
// getArrayCount 
// Return the number of Array objects instantiated
// Preconditions:   None
// Postconditions:  Returns the number of arrays
static int getArrayCount(); 

private:
   int* ptr;                          // pointer to first element of array
   int size;                          // size of the array
   static int arrayCount;             // # of Arrays instantiated
};

#endif
