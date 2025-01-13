/*

  // ------ References ------

  In C++, references are a way to give a variable another name. They are useful for passing
  arguments to functions without copying the value of the argument. This is useful when the
  argument is large and copying it would be inefficient.

  References are exists only in C++ and are not available in C.

  If you create a reference to a variable, you can use the reference as if it were the variable

*/

#include <iostream>
using namespace std;

void swap(int, int);
void swapUsingReferences(int &a, int &b);

void references() {
  int a = 54;
  int &b = a; // b is a reference to a

  b = 42;

  cout << a << endl; // 42
  cout << b << endl; // 42

  // You cannot declare a reference without initializing it
  // int &c; // Error

  // You cannot change the reference to refer to another variable

  // int &v = 45; <- Error

  const int& r = 6; // This should be a const reference

  // --- Types of passing arguments to functions ---

  // 1. Pass by value

  int x = 5;
  int y = 3;

  cout << "Before: x = " << x << ", y = " << y << endl; // x = 5, y = 3

  swap(x, y);

  cout << "After: x = " << x << ", y = " << y << endl; // x = 5, y = 3

  // So the values of x and y are not swapped, and only the copies of x and y are swapped in the function
  
  // ----------------------------

  /* 2. Pass by reference */

  cout << "Before: x = " << x << ", y = " << y << endl; // x = 5, y = 3

  swapUsingReferences(x, y);

  cout << "After: x = " << x << ", y = " << y << endl; // x = 3, y = 5

  // So the values of x and y are swapped, and the original variables are swapped in the function

  // References are useful when you want to modify the original variable in a function

  // References are also useful when you want to avoid copying large objects

  // References are also useful when you want to avoid null pointers

  // References are also useful when you want to avoid using pointers :)

  // --> Remember that when you instanciate a reference to a variable, you cannot change the reference to refer to another variable <---

  // ----------------------------

  /* 3. Pass by pointer (pass by varaible) */

  // In this passage, you pass the address of variable itself to the function 

  // The function can then modify the variable using the address

  // x = 5
  incrementPtr(&x);
  // x = 6

  // ----------------------------

  // References are useful when you want to modify the original variable in a function
  // Also, they don't create copies if the original variable is large.
  // Sometimes, you don't want the function to modify the original variable, in this case, you can use const references

  // Example -> void print(const string& str) {}

  const double PI = 3.14;

  const double* d = &PI;
  d++;
  cout << *d << endl; // 3.14
  // *d = 4.5; <- error

}

void constants() {
  // To define a constant in C++, you use the `const` keyword
  const int a = 4;
  // a = 45; <-- error: you cannot change the value of a constant
  // const int b; <-- error: you must initialize a constant when you declare it

  // To create a pointer to constant
  const int* ptr = &a;

  cout << *ptr << endl; // 4

  int b = 3;

  ptr = &b; // Weird but valid

  // *ptr = 45; <-- error

  /*
    ptr itself is not a constant, so you can change the pointer to point to another variable

    You can assign the address of a non-constant variable to a pointer to a constant variable

    This is allowed because of the way const-correctness works in C++:

    It means that the value being pointed to by ptr is treated as constant. However:

      -> The variable itself (the one being pointed to) does not need to be constant.
      -> ptr just promises not to modify the value it points to.
  
    But if you want to change the value of b using ptr, you should cast the pointer to a non-constant pointer:
  */
  
  int* nonConstPtr = const_cast<int*>(ptr);

  *nonConstPtr = 45; // This is valid and it will change the value of b

  cout << b << endl; // 45

  // -- constant pointers --
  int y = 1;
  int z = 2;
  int *const cptr = &y; // cptr is a constant pointer to an integer
  // cptr = &z; <-- error: you cannot change the address of a constant pointer

  // But we can change the value of the variable it points to
  (*cptr)++;
  cout << y << endl; // 2

  /* --> You should not confuse between constant pointers and pointers to constants <-- */

  /* -- There is also constant pointers that point to constants :) */

  const int cnst = 4;
  const int* const cptr2 = &cnst; // cptr2 is a constant pointer to a constant integer

  /*
    Here, we cannot neither change the address of the pointer nor the value of the variable it points to
    cptr2 = &z;  <-- error
    (*cptr2)++;  <-- error
  */
 
}

void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

void swapUsingReferences(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

void incrementPtr(int *var) {
  (*var)++;
}



