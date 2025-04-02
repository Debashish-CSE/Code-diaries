#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int*)malloc(5 * sizeof(int)); // Allocate memory for 5 integers

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize the allocated memory
    for (int i = 0; i < 5; i++) {
        ptr[i] = i + 1;
    }

    // Reallocate memory to hold 10 integers
    ptr = (int*)realloc(ptr, 10 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Initialize the new memory
    for (int i = 5; i < 10; i++) {
        ptr[i] = i + 1;
    }

    // Use the reallocated memory
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr[i]);
    }

    free(ptr); // Free the allocated memory
    return 0;
}
