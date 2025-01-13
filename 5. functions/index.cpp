/*

  // ------ Functions ------

  A function is basically a box that takes some input, does something with it, and then gives you some output.

            Input
            |
   +-----------------+
   |                 |
   |  Process/Input  |  <-- Function Body
   |                 |
   +-----------------+
             |
          Output

  In C++, a function is defined using the following syntax:

  type name(parameters) {
    // Function body
  }

*/

#include <iostream>
using namespace std;

// Function declaration
void printHello(void); // when a function doesn't take any arguments, we write `void` in the parentheses
int add(int a, int b); // add takes two integers and returns an integer
void greet(string name); // greet takes a string and returns nothing

// Function definition
void printHello() {
  cout << "Hello, World!" << endl;
}

int add(int a, int b) {
  return a + b;
}

// When a function returns nothing, the return type is `void`.

void greet(string name) { // `name` is an argument muet (formal parameter)
    cout << "Hello, " << name << "!" << endl;
}

/*
  Recursive functions are functions that call themselves. They are useful for solving problems that can be broken down into smaller, similar subproblems. an exampe of recursive function is the factorial function.

  To fully understand recursion, you must first understand recursion.

  Watch this: https://www.youtube.com/watch?v=ygK0YON10sQ
*/

int factorial(int n) {
  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}

int main() {
  printHello(); // Call the function
  add(5, 3); // Call the function
  greet("Alice"); // here Alice is an argument (actual argument - effectif parameter)
  /*
    Please notice that we call add which add two numbers but we don't store the result in a variable.
    We can store the result in a variable like this:
  */
  int sum = add(5, 3);
  cout << "Sum: " << sum << endl; // Output: Sum: 8
  return 0;
}


