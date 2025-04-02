#include<stdio.h>
typedef struct data
    {
        char *name;
        int roll;
    }data;

int main()
{
    data s1;
    // s1.name = "Debashish";
    //gets(s1.name);
    s1.name = "Debashish";
    s1.roll = 34;
    printf("Name: %s\n",s1.name);
    printf("Roll: %d\n",s1.roll);
    return 0;
}


