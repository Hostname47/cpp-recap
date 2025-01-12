#include <iostream>
using namespace std;

/**
    Look that we define a function foo with same name but in different namespaces which is not a problem at all.
  */
namespace A {

  void foo() {
    cout << "Hello from A::foo\n";
  }
}

namespace B {
  void foo() {
    cout << "Hello from B::foo\n";
  }
}

// foo(); <- this generate an error because you cannot use foo outside its namespace

// Instead of use A:: everytime, you can specify all functions you need:
using B::foo;

int main() {
  // You cannot use foo if you specified it namespace
  A::foo(); // Use foo function inside A namespace
  foo(); // This is B::foo because we used using B::foo
}