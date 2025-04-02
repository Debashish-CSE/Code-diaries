#include<stdio.h>

// Euclidean algorithm for gcd
int gcd(int a, int b){
    int rem;
    while (b != 0){
        rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

int main(){
    int n1, n2;
    printf("Enter n1: ");
    scanf("%d",&n1);
    printf("Enter n2: ");
    scanf("%d",&n2);
    int result = gcd(n1,n2);
    printf("GCD(n1,n2): %d\n", result);
    int lcm = (n1 * n2)/ result;
    printf("LCM(n1,n2): %d\n", lcm);

    return 0;
}