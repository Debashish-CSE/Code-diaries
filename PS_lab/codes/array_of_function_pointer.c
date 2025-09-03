#include <stdio.h>

//array of function pointers
typedef int (*operation)(int, int);
operation operations[128] = {NULL};

// int (*operations[128])(int, int) = {NULL};

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}


typedef int (*fptrOperation)(int, int);

// fptrOperation select(char opcode) {
//     switch(opcode) {
//         case '+': return add;
//         case '-': return subtract;
//     }
//  }

 void initializeOperationsArray() {
    operations['+'] = add;
    operations['-'] = subtract;
}

int evaluateArray(char opcode, int num1, int num2) {
    fptrOperation operation;
    operation = operations[opcode];
    return operation(num1, num2);
}

int main() {

    initializeOperationsArray();
    
    printf("%d\n",evaluateArray('+', 5, 6));
    printf("%d\n",evaluateArray('-', 5, 6));
}