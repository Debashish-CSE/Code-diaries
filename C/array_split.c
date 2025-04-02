#include <stdio.h>

int main(){
    int arr[9] = {7,9,4,6,5,3,2,10,18},even[9],odd[9];
    int count_even=0,count_odd=0;
    int even_index = 0, odd_index = 0;
    
    for (int i=0; i<9; i++){
            if(arr[i] % 2 == 0){
                count_even++;
                even[even_index++] = arr[i];
            }
            else{
                count_odd++;
                odd[odd_index++] = arr[i];
            }
    }
    
    printf("Odd array: ");
    for (int i=0; i<count_odd; i++){
        printf("%d ",odd[i]);
    }
    printf("\n");

    printf("Even array: ");
    for (int i=0; i<count_even; i++){
        printf("%d ",even[i]);
    }
    printf("\n");

}