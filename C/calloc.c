#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int*)calloc(5, sizeof(int)); // Allocate and initialize memory for 5 integers

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Use the allocated memory
    for (int i = 0; i < 5; i++) {
        ptr[i] = i+1;
        printf("%d ", ptr[i]); // All elements are initialized to 0
    }

    free(ptr); // Free the allocated memory
    return 0;
}
