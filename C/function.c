#include<stdio.h>

/*int f(int n){
    if(n <= 1) return 1;
    if(n%2 ==0) return f(n/2);
    return f(n/2) + f(n/2 + 1);
}
int main(){
    printf("%d",f(11));
    return 0;
}*/
/*int main(){
int i=5;
do{
    printf("%d\n",i);
    i++;
}
while(i<5);
return 0;

}*/
int main(){
    int i=8, j=5;
    float x = 0.005, y = -0.01;
    char c = 'c', d = 'd';
    int value = (i - 3*j)%(c + 2*d)/(x-y);
    printf("%d\n",value);

return 0;
}
