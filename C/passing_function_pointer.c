#include <stdio.h>

//function pointer with two parameters
int (*fptr) (int, int);

//using typedef for (int) parameter functions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}



typedef int (*fptr_operation)(int, int);

int compute(fptr_operation operation, int a, int b){
    return operation(a, b);
}


int main(){

    printf("%d\n", compute(add, 5, 6));
    printf("%d\n", compute(subtract, 5, 6));
    
    fptr = add;
    printf("%d\n", compute(fptr, 5, 6));
}