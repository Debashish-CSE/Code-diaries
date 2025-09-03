#include <iostream>
using namespace std;


long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    long long x1, y1;
    long long d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}


long long modinv(long long a, long long m) {
    long long x, y;
    extended_gcd(a, m, x, y);
    x = (x % m + m) % m; 
}

int main() {
    long long a1, m1, a2, m2;
    cin >> a1 >> m1 >> a2 >> m2;

    long long M = m1 * m2;
    long long M1 = m2; 
    long long M2 = m1; 

    long long y1 = modinv(M1, m1);
    long long y2 = modinv(M2, m2);

    long long x = (a1 * M1 * y1 + a2 * M2 * y2) % M;
    cout << x << endl;

    return 0;
}
