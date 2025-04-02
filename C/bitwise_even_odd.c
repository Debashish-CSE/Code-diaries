#include <stdio.h>
int main(){
    int a;
    printf("Enter a number: ");
    scanf("%d",&a);
    
    /* 1's last bit is 1, every other bit is 0. If the given number is even, the last bit of that number is 0.
    If the given number is odd, the last bit of that number is 1. When doing & operation with 1, the last bit becomes 0 if it is even,
    otherwise 1(if it is odd). And every other bit becomes 0, because they are doing & operation with 0. */

    if(a & 1) printf("%d is odd\n",a);
    else printf("%d is even\n",a);
    
    return 0;
}