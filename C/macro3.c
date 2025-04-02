#include <stdio.h>
#define A(a,b) a##b
#define B(a) #a
#define C(a) B(a)

int main(int argc, char *argv)
{
 printf("%s\n",C(A(1,2)));
 printf("%s\n",B(A(1,2)));
}

/*#define A(a,b) a##b will concatenate a with b returning ab as string.
so A(1,2) will return 12
#define B(a) #a  will return a as string
#define C(a) B(a) will call previous one and return a as string.
so C(A(1,2)) = C(12) = B(12) = 12 (as string)
B(A(1,2)) = A(1,2) because A(1,2) is taken as an argument and returned as string A(1,2) */
