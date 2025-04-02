#include<stdio.h>

//square of a number using macro
#define VALUE(X) printf(#X": %d\n",X)
#define SQUARE(X)\
        printf("Square of " #X ": %d\n",(X)*(X))
//#X is a string, so we don't have to use "#X", we just use #X

int main(int argc, char *argv){
    int a=13;
    VALUE(a);
    SQUARE(a);
    return 0;
}
