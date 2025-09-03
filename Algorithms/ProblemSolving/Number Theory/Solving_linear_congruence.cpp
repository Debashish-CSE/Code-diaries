#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm
int extended_gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}


void solve_congruence(int a, int b, int m) {
    int x, y;
    int g = extended_gcd(a, m, x, y);

    if (b % g != 0) {
        cout << "No solution exists\n";
        return;
    }

    // Reduce the value of a,b
    a /= g;
    b /= g;
    m /= g;

    // Find modular inverse of a mod m
    int inv = (x % m + m) % m;    // modular inverse
    int x0 = (1LL * b * inv) % m;
cout <<"Solution of x:"<<x0<<endl;
    cout << "One solution: x ≡ " << x0 << " (mod " << m << ")\n";
    
}

int main() {
    int a, b, m;
    cout << "Enter a, b, m for equation a*x ≡ b (mod m): ";
    cin >> a >> b >> m;
    solve_congruence(a, b, m);
    return 0;
}
