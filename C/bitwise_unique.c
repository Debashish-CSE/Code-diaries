#include <stdio.h>

int main(){
    int arr[7] = {1,2,3,4,3,2,1};
    int unique = 0;
    for (int i=0; i<7; i++){
        unique ^= arr[i];
        printf("Unique = %d\n",unique);
    }
    
    printf("Unique number in the array: %d\n",unique);

    return 0;
}