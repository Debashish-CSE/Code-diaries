#include<iostream>
using namespace std;
long long gcd(long long a,long long b){
    while (b!=0)
    {
    long long r=a%b;
    a=b;
    b=r;
    }
    
    return a;
}

long long lcm(long long a,long long b){
    return (a/gcd(a,b))*b;
}
int main()
{  cout<<"Input A & B:";
    long long a,b;
    cin>>a>>b;
    cout<<"GCD:"<<gcd(a,b)<<endl;
    cout<<"LCM:"<<lcm(a,b)<<endl;
    return 0;
}