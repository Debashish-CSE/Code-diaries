#include <iostream>
using namespace std;

// Function to count trailing zeros in n!
int countTrailingZeros(int n) {
    int count = 0;

    // Count number of times 5, 25, 125, etc., divide n
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = countTrailingZeros(n);
    cout << "Number of trailing zeros in " << n << "! is: " << result << endl;

    return 0;
}
