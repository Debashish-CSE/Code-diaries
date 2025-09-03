#include <stdio.h>
#include "utf8.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8); // Set console to UTF-8 mode
    const utf8_int8_t* text = u8"আমি বাংলায় গান গাই";  // Bengali string

    size_t count = utf8len(text);
    printf("%s\n",text);
    printf("Number of Unicode characters: %zu\n", count); // Should count Bengali chars
    return 0;
}