#include<stdio.h>

int fact1();

int main()
{
	int a;
	printf("Enter a number: ");
	scanf("%d",&a);
	printf("Factorial of %d is %d",a,fact1(a));
	return 0;
}

int fact1(int n)
{
	int fact=1;
       	for(int i=1;i<=n;i++){
	  fact*=i;
	}
	return fact;
}
