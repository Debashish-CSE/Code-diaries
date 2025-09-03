#include <stdio.h>

typedef int (*foo)(int, int);

int add(int a, int b)
{
    return a + b;
}

foo fptr = add;

int main(void)
{
    int a = fptr(3, 4);
    printf("%d\n", a);
    return 0;
}