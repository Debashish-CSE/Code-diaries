/*
*Lab Test - 02
*Set - B
*Problem - 01
*/
#include<stdio.h>
int main(){
    int row,col;
    printf("Row: ");
    scanf("%d",&row);
    printf("Column: ");
    scanf("%d",&col);

    int mid=(1+col)/2;
    printf("\n");

    for (int i=1; i<=row; i++){
        for (int j=1; j<=col; j++){
            if((i%2!=0) && j==mid) printf("O ");
            if((i%2!=0) && j!=mid) printf("$ ");
            if((i%2==0) && j==mid) printf("$ ");
            if((i%2==0) && j!=mid) printf("* ");
        }

        printf("\n");
    }
    return 0;
}
