#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int num){
    if(num <= 1) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    for(int i=3; i*i <= num; i+=2){
        if(num % i == 0) return false;
    }
    return true;
    }

int nthPrime(int n){
    int count = 0, num = 2;
    while(count < n){
        if(isprime(num)){
            ++count;
        }
        ++num;
    }
    return (num-1);
}

int main(){
    int t;
    cin>>t;
    int n,output[t];
    for(int i=0; i<t; i++){
        cin>>n;
        output[i] = nthPrime(n);
    }

    for(int i=0; i<t; i++){
        cout<<output[i]<<endl;
    }
}
