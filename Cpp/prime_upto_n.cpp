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
    int n = 1000;
    int count = 0;
    for (int i=0; i<=n; i++){
        if(isprime(i)){
            cout<< i <<" ";
            count++;
        }
    }
    cout<<endl<<"Total prime number upto "<<n<<": "<<count<<endl;
    return 0;
}