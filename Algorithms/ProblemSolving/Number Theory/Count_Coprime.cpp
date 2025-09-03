#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout<<"Enter the number:";
    cin >> n;
    vector<int> v;

    
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) v.push_back(i);
    }

    int c = 0;
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j <= i; j++) { 
            if (1LL * v[i] * v[j] <= n) {
                c++;
            }
        }
    }

    cout << c << endl;
    return 0;
}