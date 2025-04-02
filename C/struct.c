#include<stdio.h>

int main(){
    struct world{
        int a[3];
        char b;
        struct Bangladesh{
            char c;
            float d;
        }khulna;
    };

    struct world country;
    country.a[1]=1;
    country.khulna.d = 5.0;

    printf("%d\n",country.a[1]);
    printf("%f\n",country.khulna.d);

return 0;
}
