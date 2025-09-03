#include  <stdio.h>

int add(int a, int b) {
    return a + b;
}


typedef int (*fptrToSingleInt)(int);
typedef int (*fptrToTwoInts)(int,int);


fptrToTwoInts fptrFirst = add;
fptrToSingleInt fptrSecond = (fptrToSingleInt)(void*)fptrFirst;
fptrFirst = (fptrToTwoInts)(void*)fptrSecond;

int main(){
    // int result1 = fptrFirst(5, 10);
    // int result2 = fptrSecond(5);
    // printf("Result1: %d\n", result1);
    // printf("Result2: %d\n", result2);
    return 0;
}