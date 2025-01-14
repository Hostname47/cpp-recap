/*

  C-style strings are implemented as an array of characters terminated with a special null character \0.
  This is how strings were handled in the C language and are still supported in C++.

  The null character '\0' is used to mark the end of the string. It ensures functions like strlen know where the string stops.

  So if you have a string like "hello", it is stored as {'h', 'e', 'l', 'l', 'o', '\0'}.

  You always end up having N+1 bytes for a string of N characters. "hello" has 6 characters, but it needs 6+1 = 7 bytes in memory.

  A string is an array of characters, so you can access each character using the array index.

  To declare a string:
    -> char str[] = "hello";
    or
    -> char *str = "hello";
*/

#include <iostream>
#include <string.h>
using namespace std;

char* ex41_replace(char*, char*, char*);
void ex41_replace_all(char*, char*, char*);

void strings() {
  // Initialize str1 with  MOUAD as array of chars
  // Initialize str2 with  NASSRI as array of chars
  char str1[50] = {'M', 'O', 'U', 'A', 'D', ' ', '\0'};
  char str2[50] = {'N', 'A', 'S', 'S', 'R', 'I', '\0'};
  // -> or using pointer and dynamic allocation -> char *str = new char[50];

  // cin.getline(str1, 50); <- Read string from user

  /* String functions list */


  // 1. strlen(), which is used to get the length of a string.
  cout << "Length of str1: " << strlen(str1) << endl; // Output: 12

  // 2. strcat(): used to concatenate two strings and store the result in the first string.
  strcat(str1, str2); // Concatenate str2 to str1 => MOUAD NASSRI

  // 3. strncat(): used to concatenate a specified number of characters from one string to another.  ----str1-----3-
  strncat(str1, str2, 3); // Concatenate the first 3 characters of str2 to str1: MOUAD NASSRINAS => |MOUAD NASSRINAS|  <- only the first 3 characters of str2

  // 4. strcmp(): used to compare two strings. It returns 0 => equal, a positive value => s1 > s2, and a negative value => s1 < s2.
  cout << "Comparison: " << strcmp(str1, str2) << endl; // Output: 1 (M > N => ASCII => 77 - 78 = -1 => negative value => s1 < s2)

  // 5. strncmp(): used to compare a specified number of characters from two strings.
  cout << "Comparison: " << strncmp(str1, str2, 3) << endl; // Output: 0 (MOU == NAS => ASCII => 77 - 78 = -1 => negative value => s1 < s2)
  // Please note that the comparison is case-sensitive.

  // 6. stricmp(): used to compare two strings without considering the case.
  cout << "Comparison: " << stricmp(str1, "mouad") << endl; // Output: 0 (case-insensitive comparison)
  cout << "Comparison: " << strcmp(str1, "mouad") << endl; // Output: 1 (case-sensitive comparison)

  // 7. strcpy(): used to copy one string to another.
  char stra[50] = {'a', 'b', 'c', '\0'};
  char strb[50] = {'d', 'e', 'f', '\0'};

  strcpy(stra, strb); // Copy strb to stra

  cout << "stra: " << stra << endl; // Output: def (content of strb copied to stra)

  stra[0] = 'a';
  stra[0] = 'b';
  stra[0] = 'c';

  strncpy(stra, strb, 2); // Copy the first 2 characters of strb to stra

  cout << "stra: " << stra << endl; // Output: de (only the first 2 characters of strb copied to stra)

  // 8. strchr(): used to find the first occurrence of a character in a string.

  char str[] = "Hello, World!";
  char *ptr = strchr(str, 'W'); // Find the first occurrence of 'W' in str

  if(ptr) {
    cout << "Found at index: " << ptr - str << endl; // Output: 7
  } else {
    cout << "Not found" << endl;
  }

  // 9. strstr(): used to find the first occurrence of a substring in a string.

  char strc[] = "Hello, World!";

  char *ptrc = strstr(strc, "World"); // Find the first occurrence of "World" in str

  if(ptrc) {
    cout << "Found at index: " << ptrc - strc << endl; // Output: 7
  } else {
    cout << "Not found" << endl;
  }
}

void ex11() {
  char s[100];

  cout << "Enter a string: ";
  cin.getline(s, 50);
  int c = 0;
  for(int i = 0; i < strlen(s); i++) {
    if(s[i] == 'e') {
      c++;
    }
  }

  cout << "Number of e's: " << c << endl;
}

void ex12() {
  // The exercise said: write a program that eliminate all occurances of 'o' in a string given by the user.

  char s[100];

  cout << "Enter a string: ";

  cin.getline(s, 50);

  char* occurance;
  do {
    // First look if there is an occurance of 'o' in the string
    occurance =  strchr(s, 'o');

    if(occurance) {
      /*
        If we find an occurance of 'o', we will copy the string from the next character of the occurance to the end of the string to the occurance.
        example:
          M O U A D
        Let's remove all 'O' from the string above
        The first iteration of the loop will find the first occurance of 'O' at index 2
        We will copy the string from index 3 to the end of the string to index 2 => M U A D
        The second iteration will check if there is another occurance of 'O' in the string, and in case
        it does not find any, the loop will stop.
      */
      strcpy(occurance, occurance + 1);
    } else {
      
    }
  } while(occurance != NULL);

  cout << "String after removing all occurances of 'o': " << s << endl;
}

void ex13() {
  // Write a program that reads a string from the user and prints it in reverse order.

  char s[100];

  cout << "Enter a string: ";
  cin.getline(s, 50);

  for(int i = strlen(s) - 1; i >= 0; i--) {
    cout << s[i];
  }
}

// -----------------

void ex2() {
  // Write a program that take a verb in french from the first group and print all its conjugations in the present tense.

  char verb[50];
  char ending[3];

  cout << "Enter a verb in french from the first group: ";

  cin.getline(verb, 50);
  strcpy(ending, verb + strlen(verb) - 2);

  if(strcmp(ending, "er") != 0) {
    cout << "The verb is not from the first group" << endl;
    return;
  }

  verb[strlen(verb) - 2] = '\0'; // Remove er from the verb

  cout << "Je " << verb << "e" << endl;
  cout << "Tu " << verb << "es" << endl;
  cout << "Il/Elle " << verb << "e" << endl;
  cout << "Nous " << verb << "ons" << endl;
  cout << "Vous " << verb << "ez" << endl;
  cout << "Ils/Elles " << verb << "ent" << endl;
}

void ex3() {
  char s1[50];
  char *s2 = new char[50]; // This is the same as char s2[50]; :)

  cout << "Enter the first sentence: ";
  cin.getline(s1, 50);

  cout << "Enter the second sentence: ";
  cin.getline(s2, 50);

  char s3[50];

  /*
    First copy the half of s1 to s3
    s1 = MOUAD
    The first half of MOUAD is MO
  */
  strncpy(s3, s1, strlen(s1) / 2);

  // Add the null character to the end of the string
  s3[(strlen(s1) / 2) + 1] = '\0';
  /*
    Now s3 has already the half of s1, we will copy the half of s2 to s3, but hey, 
    we need first to add the length of half s1 to s3 by to start copying the half of s2, that's why I used s3 + (strlen(s1) / 2)
    If you don't add the length of half s1 to s3, you will override the first half of s1 with the half of s2 !

    s1 = MOUAD
    s2 = NASSRI
    s3 = MO
    The first half of NASSRI is NASS
    s3 = MONASS
  */

  strncpy(s3 + (strlen(s1) / 2), s2, strlen(s2) / 2); // Copy the half of s2 to s3
  
  s3[strlen(s1) / 2 + (strlen(s2) / 2)] = '\0'; // don't forget to put the null character at the end of the string

  cout << "The concatenated string: " << s3 << endl;
}

char* ex41_replace(char* text, char* ch1, char* ch2) {
  /*
    First lets search for ch1 inside text; occurance will return the position of the first
    occurance he found, otherwise NULL will be returned
  */
  char* occurance = strstr(text, ch1);

  /*
    If the occurance is not NULL => If we found the ch1, Now wa want to replace it with ch2.

    Actually the process engage many steps

    !! we cannot directly copy ch2 in place of ch1 because ch2 could be longer than ch1 and we
    end up loosing data from text

    1: we need to copy the content after ch1 in a temporary chars array
    2: sopy ch2 in place of ch1
    3: append the remaining text after ch2
  */
  if(occurance != NULL) {
    char temp[100];
    strcpy(temp, occurance + strlen(ch1));
    strcpy(occurance, ch2);
    strcpy(occurance + strlen(ch2), temp);

    return text;
  }

  return NULL;
}

void ex41_replace_all(char* text, char* ch1, char* ch2) {
  // As long as the replace operation is not NULL, keep replacing
  while(ex41_replace(text, ch1, ch2) != NULL) {}
}

void ex4() {
  char str1[51];
  char str2[51];
  char str3[51];

  cout << "enter a text: ";
  cin.getline(str1, 50); // Enter: hello world

  cout << "enter the word you want to replace: ";
  cin.getline(str2, 50); // Enter: hello

  cout << "enter the word to replace: ";
  cin.getline(str3, 50); // Enter: guys

  /*
    Please note that we pass the arrays and they get changed, because we
    pass them ad addresses to the pointer parameters of the function, since
    the array name is actually equal to the address of the first element.
  */

  // Replace only one occurance
  // ex41_replace(str1, str2, str3);

  // Replace all
  // ex41_replace_all(str1, str2, str3);

  /*
    If text: Hello mouad, what is the meaning of mouad in arabic ?
    and ch1: mouad
    and ch2: nassri

    result: Hello nassri, what is the meaning of nassri in arabic ?
  */

  cout << "text after the operation: " << str1; // <- 
}

int main() {
  // ex11();
  // ex12();
  // ex13();
  // ex2();
  // ex3();
  ex4();
}