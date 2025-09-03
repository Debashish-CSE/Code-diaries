#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* str = "hello";
    char* str2 = malloc(strlen(str)* sizeof(char));
    int* ptr = malloc(10 * sizeof(int));
    ptr[0] = 42;

    FILE *f_ptr = fopen("text.txt", "w");
    fprintf(f_ptr, "%s\n", "Hello, World!");
    
    fclose(f_ptr);  
    free(ptr);
    free(str2);

    // int x;
    // printf("%d",x); //uninitialized variable
    return 0;
}


