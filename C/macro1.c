#include<stdio.h>

//swap a and b using x-or bit operators in macro
#define SWAP(A,B) A^=B^=A^=B

//command line arguments for main function
//int argc : total argument number
//char *argv : argument names
int main(int argc, char *argv){
    int a=5,b=3;
    printf("a: %d\nb: %d\n",a,b);
    SWAP(a,b);
    printf("After swapping\na: %d\nb: %d\n",a,b);


return 0;
}
