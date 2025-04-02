#include <stdio.h>

int perfect(int n){
    int sum = 0;
    for (int i = 1; i < n; i++){
        if (n % i == 0){
            sum += i;
        }
    }

    if (sum == n) return n;
    return 0; // Return 0 if not a perfect number
}

int main(){
    for (int i = 1; i <= 100000; i++){
        int result = perfect(i);
        if (result != 0) printf("%d ", result);
    }
    printf("\n");
    return 0;
}
