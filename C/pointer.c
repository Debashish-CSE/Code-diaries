#include <stdio.h>

int main(){
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    printf("%u\n", *a[0]);
    printf("%u\n", *(*a+2));

    printf("%u %u %u\n", a[0]+1, *(a[0]+1), *(*(a+0)+1));
    return 0;
}