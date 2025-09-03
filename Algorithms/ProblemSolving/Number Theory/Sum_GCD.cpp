#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    long long n;
    cin >> n;

    long long total = 0;
    for (long long i = 1; i <= n; i++) {
        total += gcd(n, i);
    }

    cout << total << endl;  
    return 0;
}
