#include <stdio.h>

int main() {
    unsigned int x;
    printf("Enter an integer: ");
    scanf("%u",&x);

    unsigned int evenbits = x & 0xAAAAAAAA;
    unsigned int oddbits = x & 0x55555555;
    evenbits >>= 1;
    oddbits <<= 1;

    unsigned int result = evenbits | oddbits;

    printf("Input value: %u (in decimal)\n",x);
    printf("Interchanged x: %u(in decimal)\n", result);

    return 0;
}
