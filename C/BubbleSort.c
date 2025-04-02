#include<stdio.h>

int main(){
    //int marks[10]={95,88,87,75,43,90,100,87,78,82};
    int marks[10];
    int n = sizeof(marks) / sizeof(int);
    printf("Enter the array: ");
    for (int i=0; i<n; i++){
        scanf("%d",&marks[i]);
    }
    //bubble sort from smallest to largest integer
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (marks[i]>marks[j]){
                int temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i=0; i<n; i++){
        printf("%d ",marks[i]);
    }

    return 0;
}
