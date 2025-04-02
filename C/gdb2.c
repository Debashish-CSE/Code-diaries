#include <stdio.h>

int main(){
    int i, j, s, w;
    int n[5];
    for(i=0; i<5; i++){
        printf("Enter any number: ");
        scanf("%d", &(n[i]));
        s=0;
        for(j=1; j<=i; j++){
            if(n[j] < n[s]){
                s = j;
            }   
        }
        w = n[i];
        n[i] = n[s];
        n[s] = w;
    }
    for(i=0; i<5; i++){
        printf("%d ",n[i]);
    }
}