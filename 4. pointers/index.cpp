#include <iostream>
using namespace std;

/* I. --- Pointers ---

Pointers are variables that store the memory address of another variable. They are used to store and manage memory dynamically, and to pass data by reference. Pointers are a powerful feature of C++ that allows you to work with memory at a low level.

If the variable to which points to is occupied more than 1 case, the pointer will point to the first case. (case of arrays)

Pointer type must be the same as the variable type it points to.

Pointer could also hold the address of a function. It allows you to call the function indirectly, pass functions as arguments to other functions, or implement callback mechanisms.

*/

/*

  a (global)
  +------+
  |  42  |  <- Value of `a`
  +------+
  Address: 0x100

          ^
          |
  ptr (main)
  +------------+
  |  0x100     |  <- Address of `a` stored in `ptr`
  +------------+
  Address: 0x200

*/

void pointer() {
  /**
   * Please note that the first * in declaration part, means that the varaible declared is a pointer.
   * 
   * But after the declaration, * is used to dereference the pointer, which means to get the
   * value stored in the address the pointer is pointing to.
   * 
   * We use & symbole to gezt address of a variable.
   * 
   * In the following example, we declare a pointer to an integer, store the address of an integer
   * variable in the pointer, and then access the value of the variable using the pointer.
   */
  int *ptr; // Pointer to an integer

  int a = 42; // Integer variable

  ptr = &a; // Store the address of `a` in `ptr`

  cout << "Value of a: " << a << endl; // Output: Value of a: 42
  cout << "Address of a: " << &a << endl; // Output: Address of a: 0x100
  cout << "Value of ptr: " << ptr << endl; // Output: Value of ptr: 0x100
  cout << "Address of ptr: " << &ptr << endl; // Output: Address of ptr: 0x200
}

void areithmetic() {
  /**
   * when we work on variables that have more than one case in memory, we can perform arithmetic
   * operations on pointers to deplace them and move them the way we want.
   * 
   * For example, if a pointer point to an array, it can be incremented to point to the next element
   */
  int arr[] = {1, 2, 3, 4, 5}; // Array of integers

  int *ptr = arr; // Pointer to the first element of the array

  cout << *ptr; // Output: First element: 1 [*ptr is same as arr[0] is equivalent to *(ptr + 0)]

  ptr++; // Move the pointer to the next element

  cout << *ptr << endl; // Output: Second element: 2

  ptr += 2; // Move the pointer two elements forward

  cout << *ptr << endl; // Output: Fourth element: 4

  // We'll will cover examples of traversing arrays using pointers in the next sections.
}

/*
  We cannot use an integer pointer to point to a float variable, or vice versa, because the types are different.

  int a = 42;
  float *ptr = &a; // Error: Cannot convert 'int*' to 'float*'

  but we can use void pointer to point to any type of variable or convert it to any type of pointer.

  int c = 65;
  char* ptr = (*int) &c; // convert chat to int pointer

  Please note that we cannot use * to get value from a void pointer, because it is not a type.

  We need to cast it to the correct type before dereferencing it.

  int a = 42;
  int* x = &a;
  void *y = x;
  x = y; // Error: Cannot convert 'void*' to 'int*'
  x = (int*) y; // Correct: Cast void pointer to int pointer
  cout << *x; // Output: 42
  cout << *y; // Error: Invalid use of void expression
  cout << *((*int) y); // Output: 42
 */


/*
  - - - Arrays & pointers - - -

  Arrays are a data structure that store a collection of elements of the same type. Syntax:

  type name[size];

  Example: Array of integers with 5 elements -> int arr[5];

  Initializing an array -> int arr[5] = {1, 2, 3, 4, 5};

  In this example, the compiler will allocate memory for 5 integers in a contiguous block of memory. Please ntice that the size here is required.

   -------------------
  | 1 | 2 | 3 | 4 | 5 |
   -------------------
    0   1   2   3   4

  The name of the array is a pointer to the first element of the array. We can use this pointer to access the elements of the array.

  The previous array is one dimensional array, but we can have multi-dimensional arrays.

  int arr[dim1][dim2];

  Initializing the array -> int arr[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
  };
*/

void arraysAndPointers() {
  // ---- Arrays and pointers ----

  int arr[] = {1, 2, 3, 4, 5}; // Array of integers
  
  // Here arr is a pointer to the first element of the array.

  cout << arr[0] << endl; // Output: 1
  cout << arr[1] << endl; // Output: 2
  cout << *(arr + 0) << endl; // Output: 1
  cout << *(arr + 1) << endl; // Output: 2

  // We can use a pointer to point to the first element of the array
  int *ptr = arr;

  // Now ptr also point to the first element of the array

  cout << *ptr << endl; // Output: 1
  cout << *(ptr + 1) << endl; // Output: 2

  /*
    There is a difference between pointers and array pointers. When we declare an array, the name of the array is a pointer to the first element of the array, but we cannot change the address of the array pointer.

    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    ptr++; // Correct: Move the pointer to the next element
    ptr--; // Correct: Move the pointer to the previous element

    arr++; // Error: we cannot move arr pointer to point to the next element of the array

    for example if we do the following:
      *(arr+2) = 15; // Change the value of the 3rd element of the array
      *(ptr+2) = 15; // Same as the previous line
      arr[2] = 15; // Same as the previous line

    Array pointers are considered as constant pointers, which means that we cannot change the address of the array pointer.
  */


  int *ptr = arr; // Pointer to the first element of the array
}

void dynamicAllocation() {
  /*
    // ---- Dynamic memory allocation ----

    In C++, we can allocate memory dynamically using the new operator. This allows us to allocate memory at runtime and free it when it is no longer needed.

    Using dynamic memory allocation, we can allocate memory for arrays, objects, and other data structures, only when we need them.

    In case of arrays, instead of specifying the size of the array at compile time, we can allocate memory for the array at runtime.

    Using new operator to allocate memory for an array of integers:
  */
  int *arr = new int[5]; // Allocate memory for 5 integers

  // New operator returns a pointer to the first element of the array, otherwise it returns NULL if the memory allocation fails.

  // Now lets loop through them and let the user assign values to them:
  int *P;
  for(P = arr; P - arr < 5; P++) {
    cout << "Enter arr[" << P - arr << "]: ";
    // P - arr => is the index of the current element <- this is so important
    cin >> *P;
  }

  // Now let's loop through the array and output the values:
  for(P = arr; P - arr < 5; P++) {
    cout << *P << "\t"; // Output: 1  2  3  4  5  for example
  }

  // To allocate memory for a single integer:
  int *O = new int;
  *O = 42; // Assign a value to the integer
  cout << *O << endl; // Output: 42

  // The above code can also be written as:
  int* O = new int(42); // Allocate memory for an integer and assign a value of 42

  // To deallocate memory, we use the delete operator:

  delete[] arr; // Deallocate memory for the array

  delete O; // Deallocate memory for the integer

  // --- 2 dim array and pointers ---

  /*
    Two dimensional arrays are arrays0 of arrays in C++. We can allocate memory for a two-dimensional array dynamically using the new operator.
  */

  int arr[2][3] = { {1, 2, 3}, {4, 5, 6}};

  // To allocate memory to a simple array:
  int *arr1 = new int[2]; // Allocate memory for 2 integer pointers
  // For 2 dim array, we need to allocate memory for each row
  int **arr2 = new int*[2]; // Allocate memory for 2 integer pointers

  // arr2 is a pointer point to the first array (first row) which is also a pointer to the first element of the array = &arr[0][0].
  cout << arr2 << endl; // Output: 0x100

  // So arr2 is a pointer to a pointer to an integer (int**)
  // Up until now, we have allocated memory for the first dimension of the array, which is the rows of the array.

  // Now for each row, we need to allocate memory for the columns of the array:

  for(int i = 0; i < 2; i++) { // 2 iterations = 2 rows
    arr2[i] = new int[3]; // Allocate memory for 3 integers for each row
  }

  // Now we can access the elements of the 2 dim array using the pointers

  arr2[0][0] = 1;
  arr2[0][1] = 2;
  arr2[0][2] = 3;

  // The above code can also be written as:
  
  *(*(arr2 + 0) + 0) = 1;
  *(*(arr2 + 0) + 1) = 2;
  *(*(arr2 + 0) + 2) = 3;

  // For example, create a 2 dimensional array of 3 lines and 4 columns and let the user assign values to it:

  int **T = new int*[3]; // Allocate memory for 3 integer pointers

  for(int i = 0; i < 3; i++) {
    T[i] = new int[4]; // Allocate memory for 4 integers for each row
  }

  // Now let the user assign values to the array:

  for(int i = 0; i < 3; i++) { // Loop over rows
    for(int j = 0; j < 4; j++) { // In each row, we need to loop to each column
      cout << "Enter T[" << i << "][" << j << "]: ";
      cin >> T[i][j]; // Or: cin >> *(*(T + i) + j);
    }
  }

  // For example calculate the sum of all matrix elements
  int sum = 0;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 4; j++) {
      sum += T[i][j]; // Or: sum += *(*(T + i) + j);
    }
  }

  cout << "Sum of all elements: " << sum << endl;

  delete[] arr1; // Deallocate memory for the simple array
  delete[] arr2; // Deallocate memory for the 2 dim array
  delete[] T; // Deallocate memory for the 2 dim array

} 

