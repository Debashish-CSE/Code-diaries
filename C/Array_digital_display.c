#include<stdio.h>

int main()
{
    int digit[10][7]=
   {{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},
        {1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
    
    int i;
    printf("Input the number: ");
    scanf("%d",&i);
    printf("\nThe digital display of the number:\n");
    
    if(i>=0 && i<=9){
            if(digit[i][0]==1) printf(" - ");
            else printf("   ");
            printf("\n");
            
            if(digit[i][5]==1 && digit[i][1]==1) printf("| |");
            else if(digit[i][5]==1 && digit[i][1]!=1) printf("|  ");
            else if(digit[i][5]!=1 && digit[i][1]==1) printf("  |");
            printf("\n");
            
            if(digit[i][6]==1) printf(" - ");
            else printf("   ");
            printf("\n");
            
            if(digit[i][4]==1 && digit[i][2]==1) printf("| |");
            else if(digit[i][4]==1 && digit[i][2]!=1) printf("|  ");
            else if(digit[i][4]!=1 && digit[i][2]==1) printf("  |");
            printf("\n");
            
            if(digit[i][3]==1) printf(" - ");
            else printf("   ");
            printf("\n");
    }
    return 0;
}
