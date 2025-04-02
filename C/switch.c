#include <stdio.h>

int main(){
    int k=10;

    switch (k%2)
    {
    case 0: k += 2;
    case 1: k = 0;
    case 5: k = 1;
    };
    
    printf("k: %d\n",k);

}