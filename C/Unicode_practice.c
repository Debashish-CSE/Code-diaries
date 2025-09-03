#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#define PLATFORM "Windows"
#define PATH_SEPARATOR "\\"
#endif

#include "utf8.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    const utf8_int8_t *str = (const utf8_int8_t *)u8"👍🏿_";

    printf("%s\n", str);

    utf8_int32_t codepoint;
    utf8codepoint(str, &codepoint);

    printf("U+%04X\n", codepoint);
    return 0;
}