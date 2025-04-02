#include <stdio.h>

//Check perfect number(sum of proper divisors of n = n)
int main(){
    int n, count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);

    int series[n];
    for (int i = 1; i <= n; i++){
        if (n % i == 0){
            series[count] = i;
            count++;
        }
    }
    printf("Total divisors: %d\n",count);

    int sum = 0;
    for (int i = 0; i < count; i++){
        printf("%d ", series[i]);
        if (series[i] != n) sum += series[i];
    }

    printf("\nSum of proper divisors: %d",sum);
    printf("\nIs it a perfect number?\n");
    if(sum == n) printf("YES\n");
    else printf("NO\n");
 
    return 0;
}