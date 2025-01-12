#include <iostream>
using namespace std;

/* I. --- Loops ---

Loops are used to execute a block of code multiple times. They are essential for repetitive tasks and iterating over data structures. There are several types of loops in programming, each with its own use cases and syntax.

Remember whenever you see a code needs to be repeated nth times, you should use loops.

2. Types of Loops

There are mainly three types of loops in C++:

1.for loop: Executes a block of code a specified number of times. Syntax:

for (initialization; condition; update) {
  // code
}
*/


void forloop() {
  /* This loop will print 0, 1, 2, 3 */
  for (int i = 0; i < 4; i++) {
    cout << i << endl;
  }

  /* This loop will print 3, 2, 1, 0 */
  for (int i = 3; i >= 0; i--) {
    cout << i << endl;
  }
}

void whileloop() {
  /* while loop: Executes a block of code as long as a specified condition is true.

    Syntax:

    while (condition) {
      // code
    }

    Example: while i is less than 4, print i and increment i
  */

  int i = 0;
  while (i < 4) {
    cout << i << endl;
    i++;
  }

  /* This will print 0, 1, 2, 3 */
}

void dowhileloop() {
  /* 
      do...while loop: Similar to the while loop, but the code block is executed at least once before the condition is tested. sometimes it is useful when you want to execute the code block at least once. Syntax:

      do {
        // code
      } while (condition);

      Example: Print i and increment i as long as i is less than 4
  */

  /*  This will force the user to enter a positive number !
      Yopu can read it like: as long as the user enter negative number, loop will keep asking for a positive number. Here we need to use do...while because we want to execute the code block at least once to check what the user enter.
  */
  int a;
  do {
    cin >> a;
  } while (a <= 0);
}