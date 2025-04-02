#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int a){
    bool flag = true;
    if (a == 0) flag = false;
    if (a == 1) flag = false;
    for (int i=2; i<=sqrt(a); i++){
        if(a % i == 0){
        flag = false;
        break;
        }
    }
    return flag;
}

int main(){
    int n;
    cout <<"Enter a number: ";
    cin >>n;
        if(isprime(n)){
            cout<<n<< " is a prime"<<endl;
        }
        else cout <<n<< " is not a prime"<<endl;
        
    return 0;
}