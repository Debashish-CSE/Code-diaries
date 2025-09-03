#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1) count++;
    }

    cout << "Number of integers coprime with " << n << " is: " << count << endl;
    return 0;
}
