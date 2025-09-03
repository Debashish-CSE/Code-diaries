#include <stdio.h>
#include <windows.h>
#include "utf8.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); // Set console to UTF-8 mode
    const utf8_int8_t* text = (const utf8_int8_t*)u8"Hello 😃 你好";
    const utf8_int8_t* p = text;

    while (*p) {
        utf8_int32_t codepoint;
        const utf8_int8_t* prev = p;
        p = utf8codepoint(p, &codepoint);  // decode codepoint

        int length = p - prev;
        printf("Char: ");
        for (int i = 0; i < length; i++) {
            putchar(prev[i]);
        }
        
        printf(" | Codepoint: U+%04X\n", codepoint);
        //printf("Char: %.*s | Codepoint: U+%04X\n", length, prev, codepoint);
    }
    intptr_t *ptr1 = malloc(10*sizeof(int));
    intptr_t *ptr2 = calloc(10,sizeof(int));
    free(ptr1);
    free(ptr2);
    return 0;
}

