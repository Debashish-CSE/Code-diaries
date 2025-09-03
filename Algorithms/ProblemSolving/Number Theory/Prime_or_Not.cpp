#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;

    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            return false; 
        }
    }
    return true; 
}

int main() {
    cout<<"Enter any number n:";
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is prime\n";
    } else {
        cout << n << " is not prime\n";
    }

    return 0;
}
