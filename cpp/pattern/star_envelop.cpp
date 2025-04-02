#include<stdio.h>
int main()
{
    int r, c, i;
    printf("Enter the row number: ");
    scanf("%d", &i);
    for(r=1; r<i; r++)
    {
        for(c=1; c<=r; c++)
        {
            printf("*");
        }
        for(c=1; c<=i-r; c++)
        {
            printf(" ");
        }
        for(c=1; c<i-r; c++)
        {
            printf(" ");
        }
        for(c=1; c<=r; c++)
        {
            printf("*");
        }
        printf("\n");
    }//for middle line

    for(int m=1; m<=(i*2-1); m++) printf("*");
    printf("\n");

    for(r=i-1; r>=1; r--)
    {
        {
            for(c=r; c>=1; c--)
            {
                printf("*");
            }
            for(c=1; c<=i-r; c++)
        {
            printf(" ");
        }
        for(c=1; c<i-r; c++)
        {
            printf(" ");
        }
        for(c=1; c<=r; c++)
        {
            printf("*");
        }
            printf("\n");
        }
    }
    
    return 0;
}