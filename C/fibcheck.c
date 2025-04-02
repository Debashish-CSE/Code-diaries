#include<stdio.h>

int fib(int a){
    if(a == 0) return 0;
    if(a == 1) return 1;
    return fib(a-1)+fib(a-2);
}
int main(){
    int N,i=0;
    printf("Enter N: ");
    scanf("%d",&N);
    printf("Is N in the fibonacci sequence?\n");
    while(1){
        if(N==fib(i)){
            printf("Yes\n");
            break;
            }
        else if(N<fib(i)){
            printf("NO\n");
            break;
            }
        i++;
    }

    return 0;
}


