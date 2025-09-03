#include <iostream>
using namespace std;

// Extended Euclidean Algorithm
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// Solving a·x + b·y = c
bool solveDiophantine(int a, int b, int c, int &x, int &y, int &g) {
    g = extendedGCD(abs(a), abs(b), x, y);

    // No solution if c is not divisible by gcd
    if (c % g != 0)
        return false;

    // Multiply by c / g to get solution for original equation
    x *= c / g;
    y *= c / g;

    // Adjust signs based on original signs of a and b
    if (a < 0) x = -x;
    if (b < 0) y = -y;

    return true;
}

int main() {
    int a, b, c;
    cout << "Enter a, b, c for equation a·x + b·y = c: ";
    cin >> a >> b >> c;

    int x, y, g;
    if (solveDiophantine(a, b, c, x, y, g)) {
        cout << "Particular solution (x, y): " << x << ", " << y << endl;
        cout << "General solution:" << endl;
        cout << "x = " << x << " + " << b/g << "*t" << endl;
        cout << "y = " << y << " - " << a/g << "*t" << endl;
    } else {
        cout << "No integer solutions exist." << endl;
    }

    return 0;
}
