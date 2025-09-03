// if we define NDEBUG assertions will be turned off!
// #define NDEBUG

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void print_string(char *s);
int fn_assert2();

int main(void)
{
  fn_assert2();

  // if we dynamically allocate space for string, it won't be set to NULL
   char *string = malloc(sizeof(char) * 10);
   strcpy(string, "abc");
   print_string(string);
   free(string);
   // The above should work without triggering assert().

   // if we don't dynamically allocate space for a string, it may well be NULL
   char *bad_string;
   // we could call a function that depends on a dynamically allocated string
   // and forget to allocate it as we have above...
   print_string(bad_string);

  return 0;
}

int fn_assert2() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);
    // Assert that the age is a positive value
    assert(age > 0);
    // Assert that the age is less than or equal to 120 (a reasonable upper limit)
    assert(age <= 120);
    printf("Your age is: %d\n", age);
    return 0;
}


// Following function prints string s, but uses an assertion to ensure s is not NULL first
 void print_string(char *s)
{
  // if s is NULL our program will abort with a descriptive message as to
  // what assertion failed and where
  assert(s != NULL);

  // We would not normally want to ever abruptly abort our program for the end user of the program.
  // Accordingly, in Release version we would rather like to "fail gracefully" with a friendlier message as follows.
  if (s == NULL)
  {
    printf("Problem with program, let admin know!\n");
    exit(1);
  }
  // In this example, you may never see the above message being output though. Why?
  // Because the assertion will abort the program before we reach this point.

  // prints the string
  printf("<<<%s>>>\n", s);
}