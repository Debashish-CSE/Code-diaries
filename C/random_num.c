#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    time_t t;
    srand((unsigned) time(&t)); // time is always changing. so the random number generated after each run won't be same.

    /*for (int i=0; i<5; i++){
        printf("Random number: %d\n", rand()%6+1); //random number will generate from 1 to 6 (can be used for ludo game)
    }*/

    // Heads or tails using rand function 
    for (int i=0; i<5; i++){
        int num = rand()%2+1;
        if (num%2 == 0) printf("Heads\n");
        else printf("Tails\n");
    }

    return 0;
}