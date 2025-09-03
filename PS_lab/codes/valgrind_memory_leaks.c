#include <stdio.h>
#include <stdlib.h>

int *still_reachable_ptr;

void trigger_definitely_lost() {
    int *ptr = malloc(20);  // Definitely lost
    ptr[0] = 1;
}

void trigger_indirectly_lost() {
    typedef struct {
        int *inner_ptr;
    } Box;

    Box *box = malloc(sizeof(Box));          // Definitely lost
    box->inner_ptr = malloc(30);             // Indirectly lost
    box->inner_ptr[0] = 42;
}

void trigger_possibly_lost() {
    char *ptr = malloc(10);
    char *shifted = ptr + 1;  // shift the pointer
    shifted[0] = 'A';         // access it
    // original ptr is lost => "possibly lost"
}

void trigger_still_reachable() {
    still_reachable_ptr = malloc(100);       // Still reachable
    still_reachable_ptr[0] = 7;
}

int main() {
    trigger_definitely_lost();
    trigger_indirectly_lost();
    trigger_possibly_lost();
    trigger_still_reachable();
    return 0;
}
// Compile with: gcc -g -o valgrind_memory_leaks.exe valgrind_memory_leaks.c
// Run with: valgrind --leak-check=full ./valgrind_memory_leaks.exe

