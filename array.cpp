//---------------------------------------------------------------------------
/**
    @file array.cpp
    @brief Member function definitions for class Array
    @author Deitel/Deitel  (Additional comments by Olson and Zander)
    @version 1.0
    @date 2024-09-13
    @see arraydriver.cpp for tested functionality
---------------------------------------------------------------------------
    @details Array class:  like an int array (retains all functionality) but also
  includes additional features:
  -- allows input and output of the whole array
  -- allows for comparison of 2 arrays, element by element
  -- allows for assignment of 2 arrays
  -- size is part of the class (so no longer needs to be passed)
  -- includes range checking, program terminates for out-of-bound subscripts

Assumptions:
  -- size defaults to a fixed size of 10 if size is not specified
  -- array elements are initialized to zero
  -- user must enter valid integers when using >>
  -- in <<, integers are displayed 10 per line
---------------------------------------------------------------------------
*   @callgraph
*   @callergraph
 */
#include "array.h"
#include <cassert>

 // Initialize static data member at file scope
int Array::arrayCount = 0;


/**
    @brief Default constructor
    @param[in] arraySize (optional) - The size of the array. If not provided, defaults to 10.
    @pre   None
    @post  ptr points to an array of size arraySize and all
            elements of the array have been initialized to zero.
            arrayCount is incremented.
            Negative input values result in the default size of 10
    */
Array::Array( int arraySize ) {
    ++arrayCount;
    size = ( arraySize > 0 ? arraySize : 10 );
    ptr = new int[ size ];
    assert( ptr != NULL );

    for ( int i = 0; i < size; i++ )
        ptr[ i ] = 0;
}


/**
    @brief Copy constructor
    @param[in] init - An array to be copied into *this
    @pre   init.ptr points to an array of size at least init.size
    @post  init is copied into *this, arrayCount is incremented
*/
Array::Array( const Array& init ) {
    ++arrayCount;
    size = init.size;
    ptr = new int[ size ];
    assert( ptr != NULL );

    for ( int i = 0; i < size; i++ )
        ptr[ i ] = init.ptr[ i ];
}

/**
    @brief Destructor 
    @pre   ptr points to memory on the heap
    @post  Array for ptr is deallocated, arrayCount is decremented*/
Array::~Array() {
    --arrayCount;
    delete[] ptr;
}


/**
    @brief Gets the size of the array
    @pre   None
    @post  Returns the size of the array
    @return  The size of the array
 */
int Array::getSize() const { return size; }


/**
    @brief operator=
    @param[in] right - An array to be assigned to *this
    @pre   right.ptr points to an array of size at least right.size
    @post  *this is assigned the same array as right
    @return  *this
 */
const Array& Array::operator=( const Array& right ) {
    if ( &right != this ) {
        delete[] ptr;
        size = right.size;
        ptr = new int[ size ];
        assert( ptr != NULL );

        for ( int i = 0; i < size; i++ )
            ptr[ i ] = right.ptr[ i ];
    }

    return *this;
}


/**
    @brief operator==, Determine if two arrays are equal
    @return true is returned if the arrays have the same size
    @pre   ptr and right.ptr point to arrays with size at least size and right.size, respectively
    @post  true is returned if the arrays have the same size and elements false is return otherwise
 */
bool Array::operator==( const Array& right ) const {
    if ( size != right.size )
        return false;

    for ( int i = 0; i < size; i++ )
        if ( ptr[ i ] != right.ptr[ i ] )
            return false;
    return true;
}


/**
    @brief operator!=, Determine if two arrays are not equal
    @param[in] right - An array is compared
    @return false is returned if the arrays have the same size
    @pre ptr and right.ptr point to arrays with size at least size and right.size, respectively
    @post  false is returned if the arrays have the same size and elements true is return otherwise
*/
bool Array::operator!=( const Array& right ) const {
    return !( *this == right );
}


/**
    @brief operator[], Overloaded subscript operator, terminates if subscript out of range error
    @param[in] subscript - The index of the array element to be accessed
    @pre  0 <= subscript < size
    @post  Returns the array value at position "subscript"
 */
int& Array::operator[]( int subscript ) {
    assert( 0 <= subscript && subscript < size );
    return ptr[ subscript ];
}


/**
    @brief getArrayCount
    @return Return the number of Array objects instantiated
    @pre   None
    @post  Returns the number of arrays
 */
int Array::getArrayCount() { return arrayCount; }



//---------------------------------------------------------------------------
// operator>>  
// Overloaded input operator for class Array; inputs values for entire array.
// Preconditions:   a.ptr must point to an array with size at least a.size
// Postconditions:  The first a.size elements of a.ptr are filled with
//           integers read from the input istream
istream& operator>>( istream& input, Array& a ) {
    for ( int i = 0; i < a.size; i++ )
        input >> a.ptr[ i ];
    return input;
}


//---------------------------------------------------------------------------
// operator<<  
// Overloaded output operator for class Array
// Preconditions:   a.ptr must point to an array with size at least a.size
// Postconditions:  The first a.size elements of a.ptr are sent to the 
//            output istream 10 per line with a trailing endl
ostream& operator<<( ostream& output, const Array& a ) {
    int i;
    for ( i = 0; i < a.size; i++ ) {
        output << a.ptr[ i ] << ' ';
        if ( ( i + 1 ) % 10 == 0 )
            output << endl;
    }

    if ( i % 10 != 0 )
        output << endl;
    return output;
}
