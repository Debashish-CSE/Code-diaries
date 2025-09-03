#include <stdio.h>
#include <windows.h> // For SetConsoleOutputCP
#include "utf8.h"

int main() {
    SetConsoleOutputCP(CP_UTF8); // Set console to UTF-8 mode

    //printf("Smiley: \xF0\x9F\x98\x8A\n"); //using UTF-8 encoding for the smiley emoji
    //printf("Smiley: 😊\n");
    printf(u8"Smiley: 😊");
    return 0;
}
