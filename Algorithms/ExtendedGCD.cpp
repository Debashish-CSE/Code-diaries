#include <iostream>
using namespace std;

// Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; // when b is 0, gcd(a, 0) = a => a*1 + 0*0 = a
        y = 0;
        return a;
    }

    int x1, y1; // To store results of recursive call
    int gcd = extendedGCD(b, a % b, x1, y1);

    // Update x and y using results from recursion
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    int x, y;
    int gcd = extendedGCD(a, b, x, y);

    cout << "GCD: " << gcd << endl;
    cout << "Coefficients x and y such that a*x + b*y = gcd: ";
    cout << "x = " << x << ", y = " << y << endl;

    // Optional: Verify the identity
    cout << "Verification: " << a << "*" << x << " + " << b << "*" << y << " = " << (a*x + b*y) << endl;

    return 0;
}
