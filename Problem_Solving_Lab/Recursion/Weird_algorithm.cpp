#include <iostream>
using namespace std;

// Recursive function to print the Collatz sequence
void collatz_sequence(int n) {
    cout << n << " ";  // Print the current value of n
    
    if (n == 1) return;  // Base case: when n reaches 1, stop the recursion
    
    if (n % 2 == 0) {
        collatz_sequence(n / 2);  // If n is even, recurse with n / 2
    } else {
        collatz_sequence(3 * n + 1);  // If n is odd, recurse with 3 * n + 1
    }
}

int main() {
    int n;
    cin >> n;  // Read the input number
    
    collatz_sequence(n);  // Call the recursive function to print the sequence
    cout << endl;  // Ensure the output ends with a new line
    
    return 0;
}
