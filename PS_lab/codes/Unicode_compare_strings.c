#include <stdio.h>
#include "utf8.h"

int main() {
    const utf8_int8_t* a = (const utf8_int8_t*)u8"नमस्ते";
    const utf8_int8_t* b = (const utf8_int8_t*)u8"नमस्ते";

    int cmp = utf8cmp(a, b);
    if (cmp == 0)
        printf("Strings are equal\n");
    else
        printf("Strings are different\n");

    return 0;
}
