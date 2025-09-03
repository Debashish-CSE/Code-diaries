#include <stdio.h>
#include "utf8.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8); // Set console to UTF-8 mode
    utf8_int8_t buffer[100] = u8"Hi ";
    
    utf8cat(buffer, (const utf8_int8_t*)u8"👋");   // Append emoji
    utf8cat(buffer, (const utf8_int8_t*)u8" 世界"); // Append Chinese

    printf("Result: %s\n", buffer);
    return 0;
}
