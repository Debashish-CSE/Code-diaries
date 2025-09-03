#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cout<<"Enter the value of n:";
    cin >> n;


    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    
    if (n > 1) {
        cout << n;
    }

    cout << endl;
    return 0;
}
