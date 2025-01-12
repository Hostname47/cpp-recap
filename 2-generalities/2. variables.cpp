/**
 * Variable is a place in memory that has the following properties:
 *  1. name (ex: age)
 *  2. type (int)
 *  3. value (90)
 *  4. address (0x7ffee5b49b8c)
 *  5. lifetime (local: function lifetime)
 *  6. scope: (place where it gets defined: if it gets declared inside a function 
 *     its scope is that function only)
 */


/**
 * Types in c++:
 *  void -> empty type (no type)
 *  bool: boolean (true / false)
 *  char: character / unsigned char
 *  int: integer / unsigned int / short unsigned short
 *  float: floating-point number
 *  double: double-precision number
 *  arrays
 *  pointers
 *  wchar_t: wwide characters used for long texts
 */

// int g;
// g = 98; <- this is not allowed outside function

// Declare a variable:
int w = 54;

// in hexadecimal, numbers are preceeded by 0x like:
int v = 0x7f; // 127

// c++ has 2 types of real data types: float (4 bytes) and double (8 bytes)
int a;

// -- varaibles scopes (portée) --

/**
 * 1. Global
 *    -> global vars are declared outside functions. They are allocated before entring main
 *       function, and they get destroyed at the finish of main function.
 * 2. Local
 *    -> are varaibles that are declared inside a block, in which they get declared and 
 *       initialized. They get destroyed when the block reach its end.
 * 3. Dynamic
 *    -> are literally dynamic and fully controlled by the programmer
 */

// -- type storage specifiers / type specifiers

/**
 *  auto: variables scope is the scope of the block where they get defined
 * 
 *  "static": make variable declared within the static zone. (It does not get destroyed when 
 *  its block reach its end !)
 * 
 *  "const": make the varaible constant to any change
 * 
 *  "extern": declared a variable or function that is defined elsewhere (in another file or scope) 
 *  to allow sharing vars or functions across multiple files.
 * 
 *  "volatile": indicates that a varaible's value may change unexpectedly (ex: hardware or another thread)
 * 
 *  "register": Suggests to the compiler to store the variable in a CPU register for faster access. Use Case: 
 *  Used for performance-critical variables (less relevant today due to modern compiler optimizations).
 */

#include <iostream>
using namespace std;

void foo() {
  // To print something in the console
  cout << "Hello world";

  int a;
  // To take user input
  cin >> a;

  // To return to a new line, use \n
  std::cout << "return to line after this:\n";
  // Or you can use endl like following:
  cout << "return to line after this:" << endl;
}

void operators() {
  int a = 4;
  int b = 4;
  // Addition => a + b
  int c = a + b;
  // same for / * -

  //Logical operator
  if(a > 0 && b > 0) {
     // If a > 0 AND b > 0 execute this code
     // ||  : OR
     // == : equal
     // !=  : NOT equal
     // !  : NOT (negation)
     // >= , <= : greather/less than or equal
  }
}

void incdec() {
  // To increment a varaible
  int a = 5;
  a++; // 6 -> this is exactyly like a = a + 1;

  cout << a++; // this will show 5
  cout << ++a; // This will show 6

  a+= 5; // This is same as:
  a = a + 5;
}

// Declare a constant:
const float PI = 3.14159;

// You can also declare a constant using the following way:
#define PIO = 1.16894;

int x = 10;
/**
 * Variable: x (global scope)
      +---------------------+
      |   Value: 10         |
      |                     |
      +---------------------+
               |
               v
       Address: 0x7fff123
 */