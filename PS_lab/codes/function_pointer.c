#include <stdio.h>

//function pointer
int (*fptr)(int);

int square(int n){
    int sq = n*n;
    return sq;
}

int main(){

    fptr = square; 
    //fptr = &square is also valid but not necessary in C

    int result = fptr(5);
    printf("Square of 5 is: %d\n", result);
    
    return 0;
}