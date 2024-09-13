//---------------------------------------------------------------------------
// ARRAY.CPP
// Member function definitions for class Array
// Author:  Deitel/Deitel  (Additional comments by Olson and Zander)
//---------------------------------------------------------------------------
// Array class:  like an int array (retains all functionality) but also
//   includes additional features:
//   -- allows input and output of the whole array
//   -- allows for comparison of 2 arrays, element by element
//   -- allows for assignment of 2 arrays
//   -- size is part of the class (so no longer needs to be passed)
//   -- includes range checking, program terminates for out-of-bound subscripts
//
// Assumptions:
//   -- size defaults to a fixed size of 10 if size is not specified
//   -- array elements are initialized to zero
//   -- user must enter valid integers when using >>
//   -- in <<, integers are displayed 10 per line
//---------------------------------------------------------------------------

#include "array.h"
#include <cassert>

// Initialize static data member at file scope
int Array::arrayCount = 0;


//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  ptr points to an array of size arraySize and all
//        elements of the array have been initialized to zero.
//        arrayCount is incremented.
//        Negative input values result in the default size of 10
Array::Array(int arraySize) {
   ++arrayCount;                            
   size = (arraySize > 0 ? arraySize : 10); 
   ptr = new int[size];                     
   assert(ptr != NULL);                     

   for (int i = 0; i < size; i++)
      ptr[i] = 0;                          
}


//---------------------------------------------------------------------------
// Copy constructor 
// Preconditions:   init.ptr points to an array of size at least init.size
// Postconditions:  init is copied into *this, arrayCount is incremented
Array::Array(const Array &init) {
   ++arrayCount;                        
   size = init.size;                    
   ptr = new int[size];                
   assert(ptr != NULL);               

   for (int i = 0; i < size; i++)
      ptr[i] = init.ptr[i];          
}

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   ptr points to memory on the heap
// Postconditions:  Array for ptr is deallocated, arrayCount is decremented
Array::~Array() {
   --arrayCount;  
   delete [] ptr;
}


//----------------------------- getSize -------------------------------------
// getSize 
// Get the size of the array
// Preconditions:   None
// Postconditions:  Returns the size of the array
int Array::getSize() const { return size; }


//---------------------------------------------------------------------------
// operator=
// Preconditions:   right.ptr points to an array of size at least right.size
// Postconditions:  *this is assigned the same array as right
const Array& Array::operator=(const Array& right) {
   if (&right != this) {  
      delete [] ptr;     
      size = right.size;    
      ptr = new int[size]; 
      assert(ptr != NULL);

      for (int i = 0; i < size; i++)
         ptr[i] = right.ptr[i];  
   }

   return *this;  
}


//---------------------------------------------------------------------------
// operator==  
// Determine if two arrays are equal.
// Preconditions:  ptr and right.ptr point to arrays with size at least
//          size and right.size, respectively
// Postconditions:  true is returned if the arrays have the same size and 
//          elements false is return otherwise
bool Array::operator==(const Array& right) const {
   if (size != right.size)
      return false;

   for (int i = 0; i < size; i++)
      if (ptr[i] != right.ptr[i])
         return false;                 
   return true;                       
}


//---------------------------------------------------------------------------
// operator!=  
// Determine if two arrays are not equal.
// Preconditions:   ptr and right.ptr point to arrays with size at least
//          size and right.size, respectively
// Postconditions:  false is returned if the arrays have the same size and 
//          elements true is return otherwise
bool Array::operator!=(const Array& right) const {
   return !(*this == right);
}


//---------------------------------------------------------------------------
// operator[]  
// Overloaded subscript operator, terminates if subscript out of range error
// Preconditions:   0 <= subscript < size
// Postconditions:  Returns the array value at position "subscript"
int& Array::operator[](int subscript) {
   assert(0 <= subscript && subscript < size);
   return ptr[subscript];
}


//---------------------------------------------------------------------------
// getArrayCount 
// Return the number of Array objects instantiated
// Preconditions:   None
// Postconditions:  Returns the number of arrays
int Array::getArrayCount() { return arrayCount; }



//---------------------------------------------------------------------------
// operator>>  
// Overloaded input operator for class Array; inputs values for entire array.
// Preconditions:   a.ptr must point to an array with size at least a.size
// Postconditions:  The first a.size elements of a.ptr are filled with
//           integers read from the input istream
istream& operator>>(istream &input, Array &a) {
   for (int i = 0; i < a.size; i++)
      input >> a.ptr[i];
   return input;
}


//---------------------------------------------------------------------------
// operator<<  
// Overloaded output operator for class Array
// Preconditions:   a.ptr must point to an array with size at least a.size
// Postconditions:  The first a.size elements of a.ptr are sent to the 
//            output istream 10 per line with a trailing endl
ostream& operator<<(ostream &output, const Array &a) {
   int i;
   for (i = 0; i < a.size; i++) {
      output << a.ptr[i] << ' ';
      if ((i + 1) % 10 == 0)
         output << endl;
   }

   if (i % 10 != 0)
      output << endl;
   return output;
}
