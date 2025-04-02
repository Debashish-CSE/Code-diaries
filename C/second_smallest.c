#include <stdio.h>

int main(){
    /*int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n],smallest,second_smallest;
    for (int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }*/
    int n = 5, arr[5] = {3,5,2,1,4}, smallest, second_smallest;
    /*for (int i=0; i<n; i++){
        if(i==0) smallest = arr[0];
        else if (smallest > arr[i]) smallest = arr[i];
        printf("smallest: %d\n",smallest);
    }*/
    

    // Find the smallest and second smallest integers
    for (int i=0; i<n; i++) {
        if (arr[i] < smallest){
            second_smallest = smallest;
            smallest = arr[i];
        } 
        else if (arr[i] < second_smallest && arr[i] != smallest) {
            second_smallest = arr[i];
        }
    }
    printf("smallest number in the array: %d\n",smallest);
    printf("The second smallest integer in the array: %d\n", second_smallest);


    return 0;
}